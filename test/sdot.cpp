
#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_sdot()
{
  cout << __FUNCTION__ <<endl;
  {
    double d =0.0;
    cppmkl::matrix<float> x(10,1);
    cppmkl::matrix<float> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*3.0;
      y(i,0) = i*2.0;
      d+=x(i,0)*y(i,0);
    }
    float res = cppmkl::cblas_sdot(x,y);
    assert( res == d); 
  }

}  
