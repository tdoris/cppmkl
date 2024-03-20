#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
#include "matrix_utils.h"

int main()
{
  cppmkl::matrix<double> A;
  initm(A, "2 -1; 4 5");
  
  cppmkl::matrix<double> B;
  initm(B, "2 4; 7 8");

  cppmkl::matrix<double> C(2,2);

  cppmkl::cblas_gemm(A, B, C);

  assert( C(0,0) == -3 );
  assert( C(0,1) == 0 );
  assert( C(1,0) == 43 );
  assert( C(1,1) == 56 );

  CBLAS_TRANSPOSE transa = CblasTrans;   
  cppmkl::cblas_gemm(A, B, C, transa);
  
  assert( C(0,0) == 32 );
  assert( C(0,1) == 40 );
  assert( C(1,0) == 33 );
  assert( C(1,1) == 36 );

  CBLAS_TRANSPOSE transb = CblasNoTrans;
  double alpha = 2.0;
  cppmkl::cblas_gemm(A, B, C, transa, transb, alpha);
    
  assert( C(0,0) == 64 );
  assert( C(0,1) == 80 );
  assert( C(1,0) == 66 );
  assert( C(1,1) == 72 );
  std::cout << "Tests complete" << std::endl;
  return 0;   
}
