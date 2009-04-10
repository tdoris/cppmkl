
#include <assert.h>
#include <iostream>
#include <cmath>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_dcabs1()
{
  cout << __FUNCTION__ <<endl;
  {
    MKL_Complex16 z;
    z.real = 2.0;
    z.imag = -1.2;
    double res = cppmkl::cblas_cabs1(z);

    assert( fabs(res - 3.2) < 0.001);
  }
}  
