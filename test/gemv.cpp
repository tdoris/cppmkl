
#include <assert.h>
#include <iostream>

#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
#include "matrix_utils.h"

using namespace std;
void test_gemv()
{
  cout << __FUNCTION__ << endl;
  {
    cppmkl::matrix<double> A(3,3);
    initm(A, "1 2 3; 4 5 6; 7 8 9");
    cppmkl::matrix<double> x(3,1);
    initm(x, "1 2 3");
    cppmkl::matrix<double> y(3,1);

    cppmkl::cblas_gemv(A, x, y, 1.0, 0.0);
    assert(y(0,0) == 14);
    assert(y(1,0) == 32);
    assert(y(2,0) == 50);
  
  }
  {
    cppmkl::matrix<float> A(3,3);
    initm(A, "1 2 3; 4 5 6; 7 8 9");
    cppmkl::matrix<float> x(3,1);
    initm(x, "1 2 3");
    cppmkl::matrix<float> y(3,1);

    cppmkl::cblas_gemv(A, x, y, 1.0, 0.0);
    assert(y(0,0) == 14);
    assert(y(1,0) == 32);
    assert(y(2,0) == 50);
  
  }
  {
    MKL_Complex8 alpha;
    alpha.real = 1.0;
    alpha.imag = 0.0;
    MKL_Complex8 beta;
    beta.real=0.0;
    beta.imag=0.0;
    cppmkl::matrix<MKL_Complex8> A(2,2);
    initcm(A, true, "2 2; 2 2");
    initcm(A, false, "3 3; 3 3");
    cppmkl::matrix<MKL_Complex8> x(2,1);
    x(0,0).real = 1;
    x(0,0).imag = 1;
    x(1,0).real = 1;
    x(1,0).imag = 1;
    cppmkl::matrix<MKL_Complex8> y(2,1);

    cppmkl::cblas_gemv(A, x, y, alpha, beta);
    assert(y(0,0).real == -2);
    assert(y(0,0).imag == 10);
    assert(y(1,0).real == -2);
    assert(y(1,0).imag == 10);
  }
  {
    MKL_Complex16 alpha;
    alpha.real = 1.0;
    alpha.imag = 0.0;
    MKL_Complex16 beta;
    beta.real=0.0;
    beta.imag=0.0;
    cppmkl::matrix<MKL_Complex16> A(2,2);
    initcm(A, true, "2 2; 2 2");
    initcm(A, false, "3 3; 3 3");
    cppmkl::matrix<MKL_Complex16> x(2,1);
    x(0,0).real = 1;
    x(0,0).imag = 1;
    x(1,0).real = 1;
    x(1,0).imag = 1;
    cppmkl::matrix<MKL_Complex16> y(2,1);

    cppmkl::cblas_gemv(A, x, y, alpha, beta);
    assert(y(0,0).real == -2);
    assert(y(0,0).imag == 10);
    assert(y(1,0).real == -2);
    assert(y(1,0).imag == 10);
  }
}
