#include <assert.h>
#include <iostream>
#include <cmath>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_rot()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<float> x(10,1);
    cppmkl::matrix<float> y(10,1);
    cppmkl::matrix<float> xp(10,1);
    cppmkl::matrix<float> yp(10,1);
    float c = 2.2;
    float s = 3.3;
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*3.0;
      y(i,0) = i*2.0;
      xp(i,0) = c*x(i,0) + s*y(i,0);
      yp(i,0) = c*y(i,0) - s*x(i,0);
    }
    cppmkl::cblas_rot(x,y, c, s);
    for(size_t i=0;i<10;++i)
    {
      assert( fabs(x(i,0) - xp(i,0)) < 0.00001);
      assert( fabs(y(i,0) - yp(i,0)) < 0.00001);
    }
  }
  {
    cppmkl::matrix<double> x(10,1);
    cppmkl::matrix<double> y(10,1);
    cppmkl::matrix<double> xp(10,1);
    cppmkl::matrix<double> yp(10,1);
    double c = 2.2;
    double s = 3.3;
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*3.0;
      y(i,0) = i*2.0;
      xp(i,0) = c*x(i,0) + s*y(i,0);
      yp(i,0) = c*y(i,0) - s*x(i,0);
    }
    cppmkl::cblas_rot(x,y, c, s);
    for(size_t i=0;i<10;++i)
    {
      assert( fabs(x(i,0) - xp(i,0)) < 0.00001);
      assert( fabs(y(i,0) - yp(i,0)) < 0.00001);
    }
  }
  {
    cppmkl::matrix<MKL_Complex8> x(10,1);
    cppmkl::matrix<MKL_Complex8> y(10,1);
    cppmkl::matrix<MKL_Complex8> xp(10,1);
    cppmkl::matrix<MKL_Complex8> yp(10,1);
    float c = 2.2;
    float s = 3.3;
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*3.0;
      x(i,0).imag = i*3.0;
      y(i,0).real = i*2.0;
      y(i,0).imag = i*2.0;
      xp(i,0).real = c*x(i,0).real + s*y(i,0).real;
      xp(i,0).imag = c*x(i,0).imag + s*y(i,0).imag;
      yp(i,0).real = c*y(i,0).real - s*x(i,0).real;
      yp(i,0).imag = c*y(i,0).imag - s*x(i,0).imag;
    }
    cppmkl::cblas_rot(x,y, c, s);
    for(size_t i=0;i<10;++i)
    {
      assert( fabs(x(i,0).real - xp(i,0).real) < 0.00001);
      assert( fabs(x(i,0).imag - xp(i,0).imag) < 0.00001);
      assert( fabs(y(i,0).real - yp(i,0).real) < 0.00001);
      assert( fabs(y(i,0).imag - yp(i,0).imag) < 0.00001);
    }
  }
  {
    cppmkl::matrix<MKL_Complex16> x(10,1);
    cppmkl::matrix<MKL_Complex16> y(10,1);
    cppmkl::matrix<MKL_Complex16> xp(10,1);
    cppmkl::matrix<MKL_Complex16> yp(10,1);
    float c = 2.2;
    float s = 3.3;
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*3.0;
      x(i,0).imag = i*3.0;
      y(i,0).real = i*2.0;
      y(i,0).imag = i*2.0;
      xp(i,0).real = c*x(i,0).real + s*y(i,0).real;
      xp(i,0).imag = c*x(i,0).imag + s*y(i,0).imag;
      yp(i,0).real = c*y(i,0).real - s*x(i,0).real;
      yp(i,0).imag = c*y(i,0).imag - s*x(i,0).imag;
    }
    cppmkl::cblas_rot(x,y, c, s);
    for(size_t i=0;i<10;++i)
    {
      assert( fabs(x(i,0).real - xp(i,0).real) < 0.00001);
      assert( fabs(x(i,0).imag - xp(i,0).imag) < 0.00001);
      assert( fabs(y(i,0).real - yp(i,0).real) < 0.00001);
      assert( fabs(y(i,0).imag - yp(i,0).imag) < 0.00001);
    }
  }
}  
