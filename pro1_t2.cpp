/* Project 1 - Task 2, SF2565, KTH, 2016
 * Hanna Hultin & Mikael Persson
 */


// libraries	::	::	::	::	::

#include<iostream>
#include<cmath>

// function declarations	::	::	::

double f(double x);
double iSimpson(double a, double b);

// function definitions	::	::	::	::

using namespace std;

int main(int argc, char *argv[]) 
{
  // main function.

  double a = -1.0,b = 1.0,tol = 1e-2;

  double x,y,I;

  x = f(a);
  y = f(b);
  I = iSimpson(a,b);

  cout << I << endl;
  cout << "Matlab: I = 2.500809110336167" << endl;

  cout << x << endl;
  cout << y << endl;
  cout << tol << endl;
  return 0;
}

double iSimpson(double a, double b)
{
  return ((b-a)/6.0)*(f(a)+4.0*f(0.5*(a+b)) + f(b));
}

double f(double x) 
{
  return 1.0+sin(exp(3*x));
}

