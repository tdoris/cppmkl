#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_asum()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<double> A(10,1);
    for(size_t i=0;i<10;++i)
    {
      A(i,0) = i*1.0;
    }
    double sum = cppmkl::cblas_asum(A);
    assert(sum == 45);
  }
  
  {
    cppmkl::matrix<float> A(10,1);
    for(size_t i=0;i<10;++i)
    {
      A(i,0) = i*1.0;
    }
    double sum = cppmkl::cblas_asum(A);
    assert(sum == 45);
  }
  
  {
    cppmkl::matrix<MKL_Complex8> A(10,1);
    for(size_t i=0;i<10;++i)
    {
      A(i,0).real = i*1.0;
      A(i,0).imag = i*2.0;
    }
    double sum = cppmkl::cblas_asum(A);
    assert(sum == 135);
  }
  {
    cppmkl::matrix<MKL_Complex16> A(10,1);
    for(size_t i=0;i<10;++i)
    {
      A(i,0).real = i*1.0;
      A(i,0).imag = i*2.0;
    }
    double sum = cppmkl::cblas_asum(A);
    assert(sum == 135);
  }
}

