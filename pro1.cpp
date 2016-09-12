/* Project 1, SF2565, KTH
 * comparison of taylor series for sin(x) and cos(x)
 * by cmath functions sin(x) and cos(x)
 */


// libraries	::	::	::	::	::

#include<iostream>
#include<cmath>


// function declarations	::	::	::

double sinTaylor(int N, double x);
double cosTaylor(int N, double x);
long long int factorial(int K);


// function definitions	::	::	::	::

using namespace std;

int main(int argc, char *argv[]) {
  // main function, i.e. the program..

  int K;
  long long int fac;
  cout << "K = ";
  cin >> K;
  fac = factorial(K);
  cout << "K! = " << fac << endl;

  return 0;
}

/*

double sinTaylor(int N, double x) {
  // returns value of N:th degree taylor polynomial for
  // sin function evaluated at x
  double sinT;

  return sinT;
}
*/



/*

double horner(int a,double x) {

  double h;
  // Horners algorithm:
  // p(x) = a0 + a1*x + ... + aN*x^N
  // rewrite:
  // p(x) = a0 + x*(a1 + x*(a2 + ... + x*(aN-1 + x*aN)))...)
  // so we define a sequence:
  // bN = aN; bN-1 = aN-1 + bN*x; ... ; b0 = a0 + b1*x = p(x)

  return h;
}
*/


long long int factorial(int K) {
  // returns factorial(K), e.g. factorial(3) = 1*2*3 = 6
  // seems to work only up to 20!

  long long int fac = 1;

  for (int k = 1; k <= K; k++)
    fac *= k;

  return fac;
}

