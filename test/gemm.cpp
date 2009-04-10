#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"

#include "matrix_utils.h"

using namespace std;

int test_gemm()
{
  cout << __FUNCTION__ <<endl;
  {
    cppmkl::matrix<float> A(2,2);
    cppmkl::matrix<float> B(2,2);
    cppmkl::matrix<float> C(2,2);
    initm(A, "1.2 2.3; 3.4 4.5");
    initm(B, "1.2 2.3; 3.4 4.5");
    cppmkl::cblas_gemm(A, B, C);
    assert(fabs(C(0,0) - 9.26 ) < 0.0001);   
    assert(fabs(C(0,1) - 13.11 ) < 0.0001);   
    assert(fabs(C(1,0) - 19.38 ) < 0.0001);   
    assert(fabs(C(1,1) - 28.07 ) < 0.0001);   
  }
  {
    cppmkl::matrix<double> A(2,2);
    cppmkl::matrix<double> B(2,2);
    cppmkl::matrix<double> C(2,2);
    initm(A, "1.2 2.3; 3.4 4.5");
    initm(B, "1.2 2.3; 3.4 4.5");
    cppmkl::cblas_gemm(A, B, C);
    assert(fabs(C(0,0) - 9.26 ) < 0.0001);   
    assert(fabs(C(0,1) - 13.11 ) < 0.0001);   
    assert(fabs(C(1,0) - 19.38 ) < 0.0001);   
    assert(fabs(C(1,1) - 28.07 ) < 0.0001);   
  }
  {
    cppmkl::matrix<MKL_Complex8> A(2,2);
    cppmkl::matrix<MKL_Complex8> B(2,2);
    cppmkl::matrix<MKL_Complex8> C(2,2);
    initcm(A, true, "1.2 2.3; 3.4 4.5");
    initcm(A, false, "1.2 2.3; 3.4 4.5");
    initcm(B, true, "1.2 2.3; 3.4 4.5");
    initcm(B, false, "1.2 2.3; 3.4 4.5");
    cppmkl::cblas_gemm(A, B, C);
    assert(fabs(C(0,0).real - 0.0 ) < 0.0001);   
    assert(fabs(C(0,1).real - 0.0 ) < 0.0001);   
    assert(fabs(C(1,0).real - 0.0 ) < 0.0001);   
    assert(fabs(C(1,1).real - 0.0 ) < 0.0001);   
    assert(fabs(C(0,0).imag - 18.520 ) < 0.0001);   
    assert(fabs(C(0,1).imag - 26.22 ) < 0.0001);   
    assert(fabs(C(1,0).imag - 38.76 ) < 0.0001);   
    assert(fabs(C(1,1).imag - 56.14 ) < 0.0001);   
  }
  return 0; 
}

