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
int factorial(int K);


// function definitions	::	::	::	::

using namespace std;

int main(int argc, char *argv[]) {
  // main function, i.e. the program..

  int K,fac;
  cout << "K = ";
  cin >> K;
  fac = factorial(K);
  cout << "K! = " << fac << endl;

  return 0;
}

int factorial(int K) {
  // returns factorial(K), e.g. factorial(3) = 1*2*3 = 6

  int fac;
  fac = 1;

  for (int k = 1; k <= K; k++)
    fac = fac*k;

  return fac;
}

