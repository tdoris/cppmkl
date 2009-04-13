#include <assert.h>
#include <iostream>
#include <cmath>

#include "cppmkl/cppmkl_vml.h"
#include "cppmkl/matrix.h"

using namespace std;

void test_vmul()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<float> a(10,1);
    cppmkl::matrix<float> b(10,1);
    cppmkl::matrix<float> r(10,1);
    for(size_t i=0;i<10;++i)
    {
      a(i,0) = i*2;
      b(i,0) = i*3;
    }
    cppmkl::vmul(a, b, r);
    for(size_t i=0;i<10;++i)
    {
      assert(fabs(r(i,0) - a(i,0)*b(i,0)) < 0.0001);
    }
  }
  {
    cppmkl::matrix<double> a(10,1);
    cppmkl::matrix<double> b(10,1);
    cppmkl::matrix<double> r(10,1);
    for(size_t i=0;i<10;++i)
    {
      a(i,0) = i*2;
      b(i,0) = i*3;
    }
    cppmkl::vmul(a, b, r);
    for(size_t i=0;i<10;++i)
    {
      assert(fabs(r(i,0) - a(i,0)*b(i,0)) < 0.0001);
    }
  }
  {
    cppmkl::matrix<MKL_Complex8> a(10,1);
    cppmkl::matrix<MKL_Complex8> b(10,1);
    cppmkl::matrix<MKL_Complex8> r(10,1);
    for(size_t i=0;i<10;++i)
    {
      a(i,0).real = i*2;
      a(i,0).imag = i*2;
      b(i,0).real = i*3;
      b(i,0).imag = i*3;
    }
    cppmkl::vmul(a, b, r);
    for(size_t i=0;i<10;++i)
    {
      assert(fabs(r(i,0).real - (a(i,0).real*b(i,0).real - a(i,0).imag*b(i,0).imag)) < 0.0001);
      assert(fabs(r(i,0).imag - (a(i,0).real*b(i,0).imag + a(i,0).imag*b(i,0).real)) < 0.0001);
    }
  }
  {
    cppmkl::matrix<MKL_Complex16> a(10,1);
    cppmkl::matrix<MKL_Complex16> b(10,1);
    cppmkl::matrix<MKL_Complex16> r(10,1);
    for(size_t i=0;i<10;++i)
    {
      a(i,0).real = i*2;
      a(i,0).imag = i*2;
      b(i,0).real = i*3;
      b(i,0).imag = i*3;
    }
    cppmkl::vmul(a, b, r);
    for(size_t i=0;i<10;++i)
    {
      assert(fabs(r(i,0).real - (a(i,0).real*b(i,0).real - a(i,0).imag*b(i,0).imag)) < 0.0001);
      assert(fabs(r(i,0).imag - (a(i,0).real*b(i,0).imag + a(i,0).imag*b(i,0).real)) < 0.0001);
    }
  }
}
