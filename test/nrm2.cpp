
#include <assert.h>
#include <iostream>
#include <cmath>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_nrm2()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<float> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*1.0;
    }
    double nrm = cppmkl::cblas_nrm2(x);
    assert(nrm - 16.882 < 0.0001);
  }
  {
    cppmkl::matrix<double> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*1.0;
    }
    double nrm = cppmkl::cblas_nrm2(x);
    assert(nrm - 16.882 < 0.0001);
  }
  {
    double sum=0.0;
    cppmkl::matrix<MKL_Complex8> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*1.0;
      x(i,0).imag = i*1.0;
      sum += x(i,0).real*x(i,0).real + x(i,0).imag*x(i,0).imag + 2*x(i,0).real*x(i,0).imag;
    }
    double nrm = cppmkl::cblas_nrm2(x);
    assert(nrm - sqrt(sum) < 0.0001);
  }
  {
    double sum=0.0;
    cppmkl::matrix<MKL_Complex16> x(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*1.0;
      x(i,0).imag = i*1.0;
      sum += x(i,0).real*x(i,0).real + x(i,0).imag*x(i,0).imag + 2*x(i,0).real*x(i,0).imag;
    }
    double nrm = cppmkl::cblas_nrm2(x);
    assert(nrm - sqrt(sum) < 0.0001);
  }
}
