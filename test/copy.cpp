
#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_copy()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<float> x(10,1);
    cppmkl::matrix<float> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*3.0;
      y(i,0) = i*2.0;
    }
    cppmkl::cblas_copy(x,y);
    for(size_t i=0;i<10;++i)
    {
      assert( x(i,0) == i*3.0 );
      assert( y(i,0) == i*3.0 );
    }
  }
 
  {
    cppmkl::matrix<double> x(10,1);
    cppmkl::matrix<double> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*3.0;
      y(i,0) = i*2.0;
    }
    cppmkl::cblas_copy(x,y);
    for(size_t i=0;i<10;++i)
    {
      assert( x(i,0) == i*3.0 );
      assert( y(i,0) == i*3.0 );
    }
  }


  {
    cppmkl::matrix<MKL_Complex8> x(10,1);
    cppmkl::matrix<MKL_Complex8> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*3.0;
      x(i,0).imag = i*3.0;
      y(i,0).real = i*2.0;
      y(i,0).imag = i*2.0;
    }
    cppmkl::cblas_copy(x,y);
    for(size_t i=0;i<10;++i)
    {
      assert( x(i,0).real == i*3.0 );
      assert( x(i,0).imag == i*3.0 );
      assert( y(i,0).real == i*3.0 );
      assert( y(i,0).imag == i*3.0 );
    }
  }
  {
    cppmkl::matrix<MKL_Complex16> x(10,1);
    cppmkl::matrix<MKL_Complex16> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*3.0;
      x(i,0).imag = i*3.0;
      y(i,0).real = i*2.0;
      y(i,0).imag = i*2.0;
    }
    cppmkl::cblas_copy(x,y);
    for(size_t i=0;i<10;++i)
    {
      assert( x(i,0).real == i*3.0 );
      assert( x(i,0).imag == i*3.0 );
      assert( y(i,0).real == i*3.0 );
      assert( y(i,0).imag == i*3.0 );
      
    }
  }
}  
