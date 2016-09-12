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


// function definitions	::	::	::	::

using namespace std;

int main(int argc, char *argv[]) {
  // main function, i.e. the program..

  double sx, sTx, cx, cTx;	// sinx/cosx from cmath & Taylor polyn.
  double x = 0.3;

  /* to check the factorial function:
  int K;
  long long int fac;
  cout << "K = ";
  cin >> K;
  fac = fac(K);
  cout << "K! = " << fac << endl;
  */

  sx = sin(x);
  cout << "cmath gives sin(x) = " << sx << endl;
  sTx = sinTaylor(7,x);
  cout << "Taylor gives sin(x) = " << sTx << endl;
  
  cx = cos(x);
  cout << "cmath gives cos(x) = " << cx << endl;
  cTx = cosTaylor(7,x);
  cout << "Taylor gives cos(x) = " << cTx << endl;

  return 0;
}



double sinTaylor(int N, double x) {
  // returns value of N:th degree taylor polynomial for
  // sin function evaluated at x.
  // Horners algorithm is used to compute the series:
  // p(x) = a0 + a1*x + ... + aN*x^N
  // rewrite:
  // p(x) = a0 + x*(a1 + x*(a2 + ... + x*(aN-1 + x*aN)))...)
  // so we define a sequence:
  // bN = aN; bN-1 = aN-1 + bN*x; ... ; b0 = a0 + b1*x = p(x)

 
  double sinT;

  sinT = ((double)(N % 2)/(double)fac(N));	// The aN term in the series

  for (int i = N-1; i >= 0; i--)
  {
    sinT = (double)(i % 2)*		// 1 for odd i, 0 for even i
      (double)(1 - 2*((i-1)/2 % 2))/	// 1 for i=1,5,9,.. and -1 when i=3,7,11,...
      (double)fac(i)			// TODO finns det bättre sätt an att casta?
      + sinT*x;
  }

  return sinT;
}


double cosTaylor(int N, double x) {
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


long long int fac(int K) {
  // returns factorial(K), e.g. factorial(3) = 1*2*3 = 6
  // seems to work only up to 20!

  long long int ans = 1;

  for (int k = 1; k <= K; k++)
    ans *= k;

  return ans;
}

