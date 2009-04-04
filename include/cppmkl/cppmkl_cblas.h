#ifndef __CPPMKL_CBLAS_H__
#define __CPPMKL_CBLAS_H__

#include <mkl_cblas.h>
#include "cppmkl/matrix.h"

namespace cppmkl
{

  /** cppmkl wrapper for cblas_dgemm, BLAS level 3 matrix multiplication
   * MATRIX_T can be any row-major matrix type that has functions size1(), size2() 
   * giving row count and column count respectively and data()
   * which should return a pointer to the first data element
   */

  template <typename MATRIX_T>
    void cblas_dgemm(const MATRIX_T& A, const MATRIX_T& B, MATRIX_T& C,
        const CBLAS_TRANSPOSE TransA=CblasNoTrans, const CBLAS_TRANSPOSE TransB=CblasNoTrans,
        const double alpha=1.0, const double beta=0.0)
    {
      CBLAS_ORDER order = CblasRowMajor;
      bool doTransA = TransA != CblasNoTrans;
      bool doTransB = TransB != CblasNoTrans;
      const MKL_INT M = doTransA == false ? A.size1() : A.size2();//rows of op(A)
      const MKL_INT N = doTransB == false ? B.size2() : B.size1();//cols of op(B) 
      const MKL_INT K = doTransA == false ? A.size2() : A.size1();//cols of op(A)
      const MKL_INT lda = doTransA == false ? K : M;
      const MKL_INT ldb = doTransB == false ? N : K;
      const MKL_INT ldc = N; 
      cblas_dgemm(order, TransA, TransB, M, N, K, alpha, A.data(), lda, B.data(), ldb, beta, C.data(), ldc);     
    }

}

#endif
