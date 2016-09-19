/* Project 1 - Task 2, SF2565, KTH, 2016
 * Hanna Hultin & Mikael Persson
 */


// libraries	::	::	::	::	::

#include<iostream>
#include<cmath>

// function declarations	::	::	::

double f(double x);
double iSimpson(double a, double b);
double mid(double x, double y);
double i2Simpson(double a, double b);
double iRecursive(double a, double b, double tol);

// function definitions	::	::	::	::

using namespace std;

int main(int argc, char *argv[]) 
{
  // main function.

  double a = -1.0,b = 1.0,tol = 1e-2;
  double I;

  I = iRecursive(a,b,tol);

  cout << I << endl;
  cout << "Matlab: I = 2.500809110336167" << endl;

  cout << tol << endl;
  return 0;
}

double iRecursive(double a, double b, double tol)
{
  double I = iSimpson(a,b);
  double I2 = i2Simpson(a,b);
  double errest = abs(I-I2);
  if (errest < 15*tol)
    return I2;
  return iRecursive(a, mid(a,b),0.5*tol) + iRecursive(mid(a,b),b,0.5*tol);
}

double i2Simpson(double a, double b)
{
  return iSimpson(a,mid(a,b)) + iSimpson(mid(a,b),b);
}

double mid(double x, double y)
{
  // returns the midpoint of x & y
  return 0.5*(x+y);
}

double iSimpson(double a, double b)
{
  return ((b-a)/6.0)*(f(a)+4.0*f(0.5*(a+b)) + f(b));
}

double f(double x) 
{
  return 1.0+sin(exp(3*x));
}

