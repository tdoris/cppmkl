
#include <assert.h>
#include <iostream>
#include <cmath>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_scal()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<float> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*1.0;
    }
    cppmkl::cblas_scal(x, 2.5);
    for(size_t i=0;i<10;++i)
    {
      assert( fabs(x(i,0) - i*2.5) < 0.001);
    }
  }
}  
