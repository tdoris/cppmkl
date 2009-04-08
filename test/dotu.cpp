
#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_dotu()
{
  cout << __FUNCTION__ <<endl;
  {
    MKL_Complex8 sum;
    sum.real =0.0;
    sum.imag =0.0;
    cppmkl::matrix<MKL_Complex8> x(10,1);
    cppmkl::matrix<MKL_Complex8> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*2.0;
      x(i,0).imag = i*2.0; 
      y(i,0).real = i*3.0;
      y(i,0).imag = i*1.0;
      double a, b, c, d;
      a = x(i,0).real;
      b = x(i,0).imag; 
      c = y(i,0).real;
      d = y(i,0).imag;
      sum.real += (a*c-b*d);
      sum.imag += (b*c+a*d);
    }
    MKL_Complex8 result;
    cppmkl::cblas_dotu(x,y, result);
    assert( result.real == sum.real);
    assert( result.imag == sum.imag); 
  }

  {
    MKL_Complex16 sum;
    sum.real =0.0;
    sum.imag =0.0;
    cppmkl::matrix<MKL_Complex16> x(10,1);
    cppmkl::matrix<MKL_Complex16> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*2.0;
      x(i,0).imag = i*2.0; 
      y(i,0).real = i*3.0;
      y(i,0).imag = i*1.0;
      double a, b, c, d;
      a = x(i,0).real;
      b = x(i,0).imag; 
      c = y(i,0).real;
      d = y(i,0).imag;
      sum.real += (a*c-b*d);
      sum.imag += (b*c+a*d);
    }
    MKL_Complex16 result;
    cppmkl::cblas_dotu(x,y, result);
    assert( result.real == sum.real);
    assert( result.imag == sum.imag); 
  }
}  
