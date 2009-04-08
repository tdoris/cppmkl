
#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_axpy()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<double> x(10,1);
    cppmkl::matrix<double> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*1.0;
      y(i,0) = i*2.0;
    }
    cppmkl::cblas_axpy(x,y, 5.0);
    for(size_t i=0;i<10;++i)
    {
      //x should be unchanged
      assert( x(i,0) == i*1.0 );
      assert( y(i,0) == i*7.0 );
    }
  }

  {
    cppmkl::matrix<float> x(10,1);
    cppmkl::matrix<float> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*1.0;
      y(i,0) = i*2.0;
    }
    cppmkl::cblas_axpy(x,y, 5.0);
    for(size_t i=0;i<10;++i)
    {
      //x should be unchanged
      assert( x(i,0) == i*1.0 );
      assert( y(i,0) == i*7.0 );
    }
  }

  {
    cppmkl::matrix<MKL_Complex8> x(10,1);
    cppmkl::matrix<MKL_Complex8> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*1.0;
      x(i,0).imag = i*1.0;
      y(i,0).real = i*2.0;
      y(i,0).imag = i*2.0;
    }
    cppmkl::cblas_axpy(x,y,5.0);
    for(size_t i=0;i<10;++i)
    {
      //x should be unchanged
      assert( x(i,0).real == i*1.0 );
      assert( x(i,0).imag == i*1.0 );
      assert( y(i,0).real == i*7.0 );
      assert( y(i,0).imag == i*7.0 );
    }
  }
  {
    cppmkl::matrix<MKL_Complex16> x(10,1);
    cppmkl::matrix<MKL_Complex16> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0).real = i*1.0;
      x(i,0).imag = i*1.0;
      y(i,0).real = i*2.0;
      y(i,0).imag = i*2.0;
    }
    cppmkl::cblas_axpy(x,y,5.0);
    for(size_t i=0;i<10;++i)
    {
      //x should be unchanged
      assert( x(i,0).real == i*1.0 );
      assert( x(i,0).imag == i*1.0 );
      assert( y(i,0).real == i*7.0 );
      assert( y(i,0).imag == i*7.0 );
      
    }
  }
  {
    //try with incX =2
    cppmkl::matrix<double> x(10,1);
    cppmkl::matrix<double> y(10,1);
    for(size_t i=0;i<10;++i)
    {
      x(i,0) = i*1.0;
      y(i,0) = 0.0;
    }
    cppmkl::cblas_axpy(x,y, 1.0, 2);
    for(size_t i=0;i<5;++i)
    {
      assert( x(i,0) == i*1.0 );
      assert( y(i,0) == i*2.0 );
    }
  }
}  
