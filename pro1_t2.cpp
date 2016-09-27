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
double asi(double a, double b, double tol);

// function definitions	::	::	::	::

using namespace std;

int main(int argc, char *argv[]) 
{
  // main function.

  double a = -1.0,b = 1.0,tol = 1e-8;
  double I, I_wr;

  I = iRecursive(a,b,tol);
  I_wr = asi(a,b,tol);

  cout << "With recursion: "<< I << endl;
  cout << "Without recursion: " << I_wr << endl;
  cout << "Matlab: I = 2.500809110336167" << endl << flush;

  cout << "Tol: " << tol << endl;
  return 0;
}

/* Ser rekursionen som ett träd istället för rekursivt
 * Roten: node 1. 
 * Varje node k har (max) två barn:
 *  node 2*k (den vänstra) och node 2*k+1 (den högra)
 * I den vänstra ändras b till mid(a,b) och i högra blir a mid(a,b)
 * Föräldern till en node fås av floor(node/2) om node!=1
 */
double asi(double a, double b, double tol) {
    double I = 0, I1, I2;
    double errest;
    int node = 1;
    while (true) {
        I1 = iSimpson(a, b);
        I2 = i2Simpson(a, b);
        errest = abs(I1 - I2);
        if (errest < 15 * tol) {
            I += I2;
            /* Om ojämn node: 
             *  Fortsätt upp till  1a jämna
             *  För varje hopp upp från ojämn node: 
             *     node = floor(0.5*node), byt tillbaks a
             */
            while (node % 2 != 0) {
                if (node == 1) {
                    return I; // return om vi är uppe i roten igen
                }
                node = floor(0.5 * node);
                a = 2 * a - b;
            }
            /* Om jämn: 
             *  En upp: node = 0.5*node, byt tillbaks b 
             *  Gå till höger: node = 2*node +1, ändra a
             */
            node = 0.5 * node;
            b = 2 * b - a;
            node = 2 * node + 1;
            a = mid(a,b);
        }            
        // Gå till vänster: node*=2, ändra b
        else {
            node *= 2;
            b = mid(a,b);
        }
    }
    return I;
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
  // Simpson of left half interval and right half interval
  return iSimpson(a,mid(a,b)) + iSimpson(mid(a,b),b);
}

double mid(double x, double y)
{
  // returns the midpoint of x & y
  return 0.5*(x+y);
}

double iSimpson(double a, double b)
{
  // Simpson
  return ((b-a)/6.0)*(f(a)+4.0*f(0.5*(a+b)) + f(b));
}

double f(double x) 
{
  // The function to be integrated
  return 1.0+sin(exp(3*x));
}

