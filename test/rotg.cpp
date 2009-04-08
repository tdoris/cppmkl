#include <assert.h>
#include <iostream>
#include <cmath>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_rotg()
{
  cout << __FUNCTION__ <<endl;
  {
    float a, b, c, s;
    a = 1.0;
    b = 2.0;
  
    cppmkl::cblas_rotg(a, b, c, s); 
    assert( fabs(a - 2.23607) < 0.001);
    assert( fabs(b - 2.23607) < 0.001);
    assert( fabs(c - 0.447214) < 0.001);
    assert( fabs(s - 0.894427) < 0.001);
  }
}  
