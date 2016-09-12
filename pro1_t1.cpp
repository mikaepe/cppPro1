/* Project 1, SF2565, KTH
 * comparison of taylor series for sin(x) and cos(x)
 * by cmath functions sin(x) and cos(x)
 */


// libraries	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>


// function declarations	::	::	::

double sinTaylor(int N, double x);
double cosTaylor(int N, double x);
long long int fac(int K);
void errorBound(int N,double x,double sx,double sTx,double cx,double cTx);


// function definitions	::	::	::	::

using namespace std;

int main(int argc, char *argv[]) 
{
  // main function, i.e. the program..

  double sx, sTx, cx, cTx;	// sinx/cosx from cmath & Taylor polyn.
  double x; int N;

  cout << "x = "; cin >> x;	// Promt user for x and N
  cout << "N = "; cin >> N;

  sx = sin(x);
  cout << fixed << setprecision(15);	// Print more decimals
  cout << "cmath gives sin(x) = " << sx << endl;
  sTx = sinTaylor(N,x);
  cout << "Taylor gives sin(x) = " << sTx << endl;
  
  cx = cos(x);
  cout << "cmath gives cos(x) = " << cx << endl;
  cTx = cosTaylor(N,x);
  cout << "Taylor gives cos(x) = " << cTx << endl;

  errorBound(N,x,sx,sTx,cx,cTx);	// Compute and display errors etc

  return 0;
}



double sinTaylor(int N, double x) 
{
  // returns value of N:th degree taylor polynomial for
  // sin function evaluated at x.
  // Horners algorithm is used to compute the series:
  // p(x) = a0 + a1*x + ... + aN*x^N
  // rewrite:
  // p(x) = a0 + x*(a1 + x*(a2 + ... + x*(aN-1 + x*aN)))...)
  // so we define a sequence:
  // bN = aN; bN-1 = aN-1 + bN*x; ... ; b0 = a0 + b1*x = p(x)

 
  double sinT;

  // TODO finns det ett sätt utan att använda division med factorial-funktionen?
  sinT = ((double)(N % 2)/(double)fac(N));	// The aN term in the series

  for (int i = N-1; i >= 0; i--)	// loops backward acc. Horners alg.
  {
    sinT = (double)(i % 2)*		// 1 for odd i, 0 for even i
      (double)(1 - 2*((i-1)/2 % 2))/	// 1 for i=1,5,9,.. and -1 when i=3,7,11,...
      (double)fac(i)			// TODO finns det bättre sätt än att casta?
      + sinT*x;
  }

  return sinT;
}


double cosTaylor(int N, double x) 
{
  // returns value of N:th degree taylor polynomial for
  // cos function evaluated at x.
  // Horners algorithm is used.
  
  double cosT;

  cosT= ((double)((N+1) % 2)/(double)fac(N));

  for (int i = N-1; i >= 0; i--)
  {
    cosT = (double)((i+1) % 2)*		// analogous to sinx 
      (double)(1 - 2*((i/2) % 2))/
      (double)fac(i)
      + cosT*x;
  }

  return cosT;
}


long long int fac(int K) 
{
  // returns factorial(K), e.g. factorial(3) = 1*2*3 = 6
  // seems to work only up to 20! ~ 2.4e18

  long long int ans = 1;

  for (int k = 1; k <= K; k++)
    ans *= k;

  return ans;
}

void errorBound(int N,double x,double sx,double sTx,double cx,double cTx)
{
  // TODO, har jag gjort rätt här?...

  double  sinTermN, cosTermN;

  sinTermN = sinTaylor(N+1,x) - sinTaylor(N,x);
  cosTermN = cosTaylor(N+1,x) - cosTaylor(N,x);
  // fel?? tycker att man borde kanske ta sinTaylor(N+2,x)-sinT(N,x)...

  //sinTermN = pow(x,N+1)/(double)fac(N+1);

  cout << "sin N+1-term = " << sinTermN << endl;
  cout << "cos N+1-term = " << cosTermN << endl;
  
  cout << "sin err/N+1-term = " << abs((sx-sTx)/sinTermN) << endl;
  cout << "cos err/N+1-term = " << abs((cx-cTx)/cosTermN) << endl;


  // no return statement fctn type void
 
}








