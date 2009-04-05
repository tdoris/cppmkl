#ifndef __CPPMKL_CBLAS_H__
#define __CPPMKL_CBLAS_H__

#include <mkl_cblas.h>
#include "cppmkl/matrix.h"

namespace cppmkl
{

  /** cppmkl wrapper for cblas_dgemm, BLAS level 3 matrix multiplication
   * MATRIX_T can be any row-major matrix type that has functions size1(), size2() 
   * giving row count and column count respectively and data()
   * which returns a pointer to the first data element
   */

  void cblas_gemm(const  CBLAS_ORDER Order, const  CBLAS_TRANSPOSE TransA,
                 const  CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const double alpha, const double *A,
                 const MKL_INT lda, const double *B, const MKL_INT ldb,
                 const double beta, double *C, const MKL_INT ldc)
  {
    cblas_dgemm(Order, TransA, TransB, M, N,K, alpha, A, lda, B, ldb,
                beta, C, ldc);
  }
  void cblas_gemm(const  CBLAS_ORDER Order, const  CBLAS_TRANSPOSE TransA,
                 const  CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const float alpha, const float *A,
                 const MKL_INT lda, const float *B, const MKL_INT ldb,
                 const float beta, float *C, const MKL_INT ldc)
  {
    cblas_sgemm(Order, TransA, TransB, M, N,K, alpha, A, lda, B, ldb,
                beta, C, ldc);
  }
  void cblas_gemm(const  CBLAS_ORDER Order, const  CBLAS_TRANSPOSE TransA,
                 const  CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const MKL_Complex8 alpha, const MKL_Complex8 *A,
                 const MKL_INT lda, const MKL_Complex8 *B, const MKL_INT ldb,
                 const MKL_Complex8 beta, MKL_Complex8 *C, const MKL_INT ldc)
  {
    cblas_cgemm(Order, TransA, TransB, M, N,K, 
        static_cast<const void*>(&alpha), 
        static_cast<const void*>(A), lda, 
        static_cast<const void*>(B), ldb,
        static_cast<const void*>(&beta), 
        static_cast<void*>(C), ldc);
  }
  void cblas_gemm(const  CBLAS_ORDER Order, const  CBLAS_TRANSPOSE TransA,
                 const  CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const MKL_Complex16 alpha, const MKL_Complex16 *A,
                 const MKL_INT lda, const MKL_Complex16 *B, const MKL_INT ldb,
                 const MKL_Complex16 beta, MKL_Complex16 *C, const MKL_INT ldc)
  {
    cblas_zgemm(Order, TransA, TransB, M, N,K, 
        static_cast<const void*>(&alpha), 
        static_cast<const void*>(A), lda, 
        static_cast<const void*>(B), ldb,
        static_cast<const void*>(&beta), 
        static_cast<void*>(C), ldc);
  }
  template <typename MATRIX_T>
    void cblas_gemm(const MATRIX_T& A, const MATRIX_T& B, MATRIX_T& C,
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
      cblas_gemm(order, TransA, TransB, M, N, K, alpha, A.data(), lda, B.data(), ldb, beta, C.data(), ldc);     
    }

}

#endif
