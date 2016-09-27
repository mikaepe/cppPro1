/* Project 1 - Task 2, SF2565, KTH, 2016
 * Hanna Hultin & Mikael Persson
 */


// libraries	::	::	::	::	::

#include<iostream>
#include<cmath>
#include<iomanip>

// function declarations	::	::	::

double f(double x);
double iSimpson(double a, double b);
double mid(double x, double y);
double i2Simpson(double a, double b);
double iRecursive(double a, double b, double tol);
double asi(double a, double b, double tol);

// function definitions	::	::	::	::

using namespace std;

// main function
int main(int argc, char *argv[]) 
{
  double a = -1.0,b = 1.0,tol = 1e-8;
  double I, I_wr;

  I = iRecursive(a,b,tol);
  I_wr = asi(a,b,tol);

  cout << fixed << setprecision(15);		// more decimals
  cout << "With recursion: "<< I << endl;
  cout << "Without recursion: " << I_wr << endl;
  cout << "Matlab: I = 2.500809110336167" << endl << flush;

  cout << "Tol: " << tol << endl;
  return 0;
}

/* asi: Adaptive Simpson Integration
 * Use a tree instead of recursion
 * The root is node number 1, and each node k has at most 2 children:
 *  node 2k (the left one) and node 2k+1 (the right one
 * In the left child b is changed to mid(a,b)
 * In the right child a is changed to mid(a,b)
 * The parent of a node is given by floor(0.5*node) if node!=1
 */

double asi(double a, double b, double tol) {
    double I = 0, I1, I2, errest;
    int node = 1;

    while (true) {
        I1 = iSimpson(a, b);
        I2 = i2Simpson(a, b);
        errest = abs(I1 - I2);
        if (errest < 15 * tol) { //if leaf
            I += I2;
            /* while uneven node: 
             * go up until first even node
             */
            while (node % 2 != 0) {
                if (node == 1) {
                    return I; // return if we are back in the root again
                }
                node = floor(0.5 * node);
                a = 2 * a - b;
                tol *= 2;
            }
            /* first even node: 
             * - go one node up
             * - go to the right child 
             */
            node = 0.5 * node;
            b = 2 * b - a;
            node = 2 * node + 1;
            a = mid(a,b);
        }            
        // If not a leaf: go to the left child
        else {
            node *= 2;
            b = mid(a,b);
            tol *= 0.5;
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

// Simpson of left half interval and right half interval
double i2Simpson(double a, double b)
{
  return iSimpson(a,mid(a,b)) + iSimpson(mid(a,b),b);
}

// returns the midpoint of x & y
double mid(double x, double y)
{
  return 0.5*(x+y);
}

// Simpson quadrature
double iSimpson(double a, double b)
{
  return ((b-a)/6.0)*(f(a)+4.0*f(0.5*(a+b)) + f(b));
}

// The function to be integrated
double f(double x) 
{
  return 1.0+sin(exp(3*x));
}

