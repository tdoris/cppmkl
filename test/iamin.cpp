
#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_iamin()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<float> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = 3.0;
    }
    x(5,0) = 1.0;
    MKL_INT index = cppmkl::cblas_iamin(x);
    assert( index == 5);
  }
  {
    cppmkl::matrix<double> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = 3.0;
    }
    x(5,0) = 1.0;
    MKL_INT index = cppmkl::cblas_iamin(x);
    assert( index == 5);
  }
  {
    cppmkl::matrix<MKL_Complex8> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = 3.0;
    }
    x(5,0).real = 1.0;
    MKL_INT index = cppmkl::cblas_iamin(x);
    assert( index == 5);
  }
  {
    cppmkl::matrix<MKL_Complex16> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = 3.0;
    }
    x(5,0).real = 1.0;
    MKL_INT index = cppmkl::cblas_iamin(x);
    assert( index == 5);
  }
}  
