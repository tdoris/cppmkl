/* Auto-generated code*/
#ifndef __CPPMKL_VML_H__
#define __CPPMKL_VML_H__
#include <assert.h>
#include <mkl_vml.h>

namespace cppmkl
{
  inline void vadd(const MKL_INT n, const float* a, const float* b, float* r)
  {
    vsAdd(n, a, b, r);
  }
  inline void vadd(const MKL_INT n, const double* a, const double* b, double* r)
  {
    vdAdd(n, a, b, r);
  }
  inline void vadd(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b, MKL_Complex8* r)
  {
    vcAdd(n, a, b, r);
  }
  inline void vadd(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b, MKL_Complex16* r)
  {
    vzAdd(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vadd(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vadd(a.size(), a.data(), b.data(), r.data());  
  }
  inline void vsub(const MKL_INT n, const float* a, const float* b, float* r)
  {
    vsSub(n, a, b, r);
  }
  inline void vsub(const MKL_INT n, const double* a, const double* b, double* r)
  {
    vdSub(n, a, b, r);
  }
  inline void vsub(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b, MKL_Complex8* r)
  {
    vcSub(n, a, b, r);
  }
  inline void vsub(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b, MKL_Complex16* r)
  {
    vzSub(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vsub(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vsub(a.size(), a.data(), b.data(), r.data());  
  }
  inline void vsqr(const MKL_INT n, const float* a, float* r)
  {
    vsSqr(n, a, r);
  }
  inline void vsqr(const MKL_INT n, const double* a, double* r)
  {
    vdSqr(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vsqr(const VECTOR_T& a, VECTOR_T& r)
  {
    vsqr(a.size(), a.data(), r.data());  
  }
  inline void vmul(const MKL_INT n, const float* a, const float* b, float* r)
  {
    vsMul(n, a, b, r);
  }
  inline void vmul(const MKL_INT n, const double* a, const double* b, double* r)
  {
    vdMul(n, a, b, r);
  }
  inline void vmul(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b, MKL_Complex8* r)
  {
    vcMul(n, a, b, r);
  }
  inline void vmul(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b, MKL_Complex16* r)
  {
    vzMul(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vmul(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vmul(a.size(), a.data(), b.data(), r.data());  
  }
  inline void vmulbyconj(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b, MKL_Complex8* r)
  {
    vcMulByConj(n, a, b, r);
  }
  inline void vmulbyconj(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b, MKL_Complex16* r)
  {
    vzMulByConj(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vmulbyconj(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vmulbyconj(a.size(), a.data(), b.data(), r.data());  
  }
  inline void vconj(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcConj(n, a, r);
  }
  inline void vconj(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzConj(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vconj(const VECTOR_T& a, VECTOR_T& r)
  {
    vconj(a.size(), a.data(), r.data());  
  }
inline void vabs(const MKL_INT n, const float* a, float* r)
  {
    vsAbs(n, a, r);
  }
  inline void vabs(const MKL_INT n, const double* a, double* r)
  {
    vdAbs(n, a, r);
  }
  inline void vabs(const MKL_INT n, const MKL_Complex8* a, float* r)
  {
    vcAbs(n, a, r);
  }
  inline void vabs(const MKL_INT n, const MKL_Complex16* a, double* r)
  {
    vzAbs(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vabs(const VECTOR_T& a, VECTOR_T& r)
  {
    vabs(a.size(), a.data(), r.data());  
  }
  inline void vinv(const MKL_INT n, const float* a, float* r)
  {
    vsInv(n, a, r);
  }
  inline void vinv(const MKL_INT n, const double* a, double* r)
  {
    vdInv(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vinv(const VECTOR_T& a, VECTOR_T& r)
  {
    vinv(a.size(), a.data(), r.data());  
  }
  inline void vdiv(const MKL_INT n, const float* a, const float* b, float* r)
  {
    vsDiv(n, a, b, r);
  }
  inline void vdiv(const MKL_INT n, const double* a, const double* b, double* r)
  {
    vdDiv(n, a, b, r);
  }
  inline void vdiv(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b, MKL_Complex8* r)
  {
    vcDiv(n, a, b, r);
  }
  inline void vdiv(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b, MKL_Complex16* r)
  {
    vzDiv(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vdiv(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vdiv(a.size(), a.data(), b.data(), r.data());  
  }
  inline void vsqrt(const MKL_INT n, const float* a, float* r)
  {
    vsSqrt(n, a, r);
  }
  inline void vsqrt(const MKL_INT n, const double* a, double* r)
  {
    vdSqrt(n, a, r);
  }
  inline void vsqrt(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcSqrt(n, a, r);
  }
  inline void vsqrt(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzSqrt(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vsqrt(const VECTOR_T& a, VECTOR_T& r)
  {
    vsqrt(a.size(), a.data(), r.data());  
  }
  inline void vinvsqrt(const MKL_INT n, const float* a, float* r)
  {
    vsInvSqrt(n, a, r);
  }
  inline void vinvsqrt(const MKL_INT n, const double* a, double* r)
  {
    vdInvSqrt(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vinvsqrt(const VECTOR_T& a, VECTOR_T& r)
  {
    vinvsqrt(a.size(), a.data(), r.data());  
  }
  inline void vcbrt(const MKL_INT n, const float* a, float* r)
  {
    vsCbrt(n, a, r);
  }
  inline void vcbrt(const MKL_INT n, const double* a, double* r)
  {
    vdCbrt(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vcbrt(const VECTOR_T& a, VECTOR_T& r)
  {
    vcbrt(a.size(), a.data(), r.data());  
  }
  inline void vinvcbrt(const MKL_INT n, const float* a, float* r)
  {
    vsInvCbrt(n, a, r);
  }
  inline void vinvcbrt(const MKL_INT n, const double* a, double* r)
  {
    vdInvCbrt(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vinvcbrt(const VECTOR_T& a, VECTOR_T& r)
  {
    vinvcbrt(a.size(), a.data(), r.data());  
  }
  inline void vpow2o3(const MKL_INT n, const float* a, float* r)
  {
    vsPow2o3(n, a, r);
  }
  inline void vpow2o3(const MKL_INT n, const double* a, double* r)
  {
    vdPow2o3(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vpow2o3(const VECTOR_T& a, VECTOR_T& r)
  {
    vpow2o3(a.size(), a.data(), r.data());  
  }
  inline void vpow3o2(const MKL_INT n, const float* a, float* r)
  {
    vsPow3o2(n, a, r);
  }
  inline void vpow3o2(const MKL_INT n, const double* a, double* r)
  {
    vdPow3o2(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vpow3o2(const VECTOR_T& a, VECTOR_T& r)
  {
    vpow3o2(a.size(), a.data(), r.data());  
  }
  inline void vpow(const MKL_INT n, const float* a, const float* b, float* r)
  {
    vsPow(n, a, b, r);
  }
  inline void vpow(const MKL_INT n, const double* a, const double* b, double* r)
  {
    vdPow(n, a, b, r);
  }
  inline void vpow(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b, MKL_Complex8* r)
  {
    vcPow(n, a, b, r);
  }
  inline void vpow(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b, MKL_Complex16* r)
  {
    vzPow(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vpow(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vpow(a.size(), a.data(), b.data(), r.data());  
  }
inline void vpowx(const MKL_INT n, const float* a, const float b, float* r)
  {
    vsPowx(n, a, b, r);
  }
  inline void vpowx(const MKL_INT n, const double* a, const double b, double* r)
  {
    vdPowx(n, a, b, r);
  }
  inline void vpowx(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8& b, MKL_Complex8* r)
  {
    vcPowx(n, a, b, r);
  }
  inline void vpowx(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16& b, MKL_Complex16* r)
  {
    vzPowx(n, a, b, r);
  }
  template <typename SCALAR_T, typename VECTOR_T>
  inline void vpowx(const VECTOR_T& a, const SCALAR_T& b, VECTOR_T& r)
  {
    vpowx(a.size(), a.data(), b, r.data());  
  }
  inline void vhypot(const MKL_INT n, const float* a, const float* b, float* r)
  {
    vsHypot(n, a, b, r);
  }
  inline void vhypot(const MKL_INT n, const double* a, const double* b, double* r)
  {
    vdHypot(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vhypot(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vhypot(a.size(), a.data(), b.data(), r.data());  
  }
  inline void vexp(const MKL_INT n, const float* a, float* r)
  {
    vsExp(n, a, r);
  }
  inline void vexp(const MKL_INT n, const double* a, double* r)
  {
    vdExp(n, a, r);
  }
  inline void vexp(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcExp(n, a, r);
  }
  inline void vexp(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzExp(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vexp(const VECTOR_T& a, VECTOR_T& r)
  {
    vexp(a.size(), a.data(), r.data());  
  }
  inline void vexpm1(const MKL_INT n, const float* a, float* r)
  {
    vsExpm1(n, a, r);
  }
  inline void vexpm1(const MKL_INT n, const double* a, double* r)
  {
    vdExpm1(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vexpm1(const VECTOR_T& a, VECTOR_T& r)
  {
    vexpm1(a.size(), a.data(), r.data());  
  }
  inline void vln(const MKL_INT n, const float* a, float* r)
  {
    vsLn(n, a, r);
  }
  inline void vln(const MKL_INT n, const double* a, double* r)
  {
    vdLn(n, a, r);
  }
  inline void vln(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcLn(n, a, r);
  }
  inline void vln(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzLn(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vln(const VECTOR_T& a, VECTOR_T& r)
  {
    vln(a.size(), a.data(), r.data());  
  }
  inline void vlog10(const MKL_INT n, const float* a, float* r)
  {
    vsLog10(n, a, r);
  }
  inline void vlog10(const MKL_INT n, const double* a, double* r)
  {
    vdLog10(n, a, r);
  }
  inline void vlog10(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcLog10(n, a, r);
  }
  inline void vlog10(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzLog10(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vlog10(const VECTOR_T& a, VECTOR_T& r)
  {
    vlog10(a.size(), a.data(), r.data());  
  }
  inline void vlog1p(const MKL_INT n, const float* a, float* r)
  {
    vsLog1p(n, a, r);
  }
  inline void vlog1p(const MKL_INT n, const double* a, double* r)
  {
    vdLog1p(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vlog1p(const VECTOR_T& a, VECTOR_T& r)
  {
    vlog1p(a.size(), a.data(), r.data());  
  }
  inline void vcos(const MKL_INT n, const float* a, float* r)
  {
    vsCos(n, a, r);
  }
  inline void vcos(const MKL_INT n, const double* a, double* r)
  {
    vdCos(n, a, r);
  }
  inline void vcos(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcCos(n, a, r);
  }
  inline void vcos(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzCos(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vcos(const VECTOR_T& a, VECTOR_T& r)
  {
    vcos(a.size(), a.data(), r.data());  
  }
  inline void vsin(const MKL_INT n, const float* a, float* r)
  {
    vsSin(n, a, r);
  }
  inline void vsin(const MKL_INT n, const double* a, double* r)
  {
    vdSin(n, a, r);
  }
  inline void vsin(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcSin(n, a, r);
  }
  inline void vsin(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzSin(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vsin(const VECTOR_T& a, VECTOR_T& r)
  {
    vsin(a.size(), a.data(), r.data());  
  }
inline void vsincos(const MKL_INT n, const float* a, float* y, float* z)
  {
    vsSinCos(n, a, y, z);
  }
  inline void vsincos(const MKL_INT n, const double* a, double* y, double* z)
  {
    vdSinCos(n, a, y, z);
  }
  template <typename VECTOR_T>
  inline void vsincos(const VECTOR_T& a, VECTOR_T& y, VECTOR_T& z)
  {
    vsincos(a.size(), a.data(), y.data(), z.data());  
  }
  inline void vCIS(const MKL_INT n, const float* a, MKL_Complex8* r)
  {
    vcCIS(n, a, r);
  }
  inline void vCIS(const MKL_INT n, const double* a, MKL_Complex16* r)
  {
    vzCIS(n, a, r);
  }
  template <typename VECTOR_T_REAL, typename VECTOR_T_COMPLEX>
  inline void vCIS(const VECTOR_T_REAL& a, VECTOR_T_COMPLEX& r)
  {
    vCIS(a.size(), a.data(), r.data());  
  }
  inline void vtan(const MKL_INT n, const float* a, float* r)
  {
    vsTan(n, a, r);
  }
  inline void vtan(const MKL_INT n, const double* a, double* r)
  {
    vdTan(n, a, r);
  }
  inline void vtan(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcTan(n, a, r);
  }
  inline void vtan(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzTan(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vtan(const VECTOR_T& a, VECTOR_T& r)
  {
    vtan(a.size(), a.data(), r.data());  
  }
  inline void vacos(const MKL_INT n, const float* a, float* r)
  {
    vsAcos(n, a, r);
  }
  inline void vacos(const MKL_INT n, const double* a, double* r)
  {
    vdAcos(n, a, r);
  }
  inline void vacos(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcAcos(n, a, r);
  }
  inline void vacos(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzAcos(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vacos(const VECTOR_T& a, VECTOR_T& r)
  {
    vacos(a.size(), a.data(), r.data());  
  }
  inline void vasin(const MKL_INT n, const float* a, float* r)
  {
    vsAsin(n, a, r);
  }
  inline void vasin(const MKL_INT n, const double* a, double* r)
  {
    vdAsin(n, a, r);
  }
  inline void vasin(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcAsin(n, a, r);
  }
  inline void vasin(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzAsin(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vasin(const VECTOR_T& a, VECTOR_T& r)
  {
    vasin(a.size(), a.data(), r.data());  
  }
  inline void vatan(const MKL_INT n, const float* a, float* r)
  {
    vsAtan(n, a, r);
  }
  inline void vatan(const MKL_INT n, const double* a, double* r)
  {
    vdAtan(n, a, r);
  }
  inline void vatan(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcAtan(n, a, r);
  }
  inline void vatan(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzAtan(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vatan(const VECTOR_T& a, VECTOR_T& r)
  {
    vatan(a.size(), a.data(), r.data());  
  }
  inline void vatan2(const MKL_INT n, const float* a, const float* b, float* r)
  {
    vsAtan2(n, a, b, r);
  }
  inline void vatan2(const MKL_INT n, const double* a, const double* b, double* r)
  {
    vdAtan2(n, a, b, r);
  }
  template <typename VECTOR_T>
  inline void vatan2(const VECTOR_T& a, const VECTOR_T& b, VECTOR_T& r)
  {
    vatan2(a.size(), a.data(), b.data(), r.data());  
  }
  inline void vcosh(const MKL_INT n, const float* a, float* r)
  {
    vsCosh(n, a, r);
  }
  inline void vcosh(const MKL_INT n, const double* a, double* r)
  {
    vdCosh(n, a, r);
  }
  inline void vcosh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcCosh(n, a, r);
  }
  inline void vcosh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzCosh(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vcosh(const VECTOR_T& a, VECTOR_T& r)
  {
    vcosh(a.size(), a.data(), r.data());  
  }
  inline void vsinh(const MKL_INT n, const float* a, float* r)
  {
    vsSinh(n, a, r);
  }
  inline void vsinh(const MKL_INT n, const double* a, double* r)
  {
    vdSinh(n, a, r);
  }
  inline void vsinh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcSinh(n, a, r);
  }
  inline void vsinh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzSinh(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vsinh(const VECTOR_T& a, VECTOR_T& r)
  {
    vsinh(a.size(), a.data(), r.data());  
  }
  inline void vtanh(const MKL_INT n, const float* a, float* r)
  {
    vsTanh(n, a, r);
  }
  inline void vtanh(const MKL_INT n, const double* a, double* r)
  {
    vdTanh(n, a, r);
  }
  inline void vtanh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcTanh(n, a, r);
  }
  inline void vtanh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzTanh(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vtanh(const VECTOR_T& a, VECTOR_T& r)
  {
    vtanh(a.size(), a.data(), r.data());  
  }
  inline void vacosh(const MKL_INT n, const float* a, float* r)
  {
    vsAcosh(n, a, r);
  }
  inline void vacosh(const MKL_INT n, const double* a, double* r)
  {
    vdAcosh(n, a, r);
  }
  inline void vacosh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcAcosh(n, a, r);
  }
  inline void vacosh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzAcosh(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vacosh(const VECTOR_T& a, VECTOR_T& r)
  {
    vacosh(a.size(), a.data(), r.data());  
  }
  inline void vasinh(const MKL_INT n, const float* a, float* r)
  {
    vsAsinh(n, a, r);
  }
  inline void vasinh(const MKL_INT n, const double* a, double* r)
  {
    vdAsinh(n, a, r);
  }
  inline void vasinh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcAsinh(n, a, r);
  }
  inline void vasinh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzAsinh(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vasinh(const VECTOR_T& a, VECTOR_T& r)
  {
    vasinh(a.size(), a.data(), r.data());  
  }
  inline void vatanh(const MKL_INT n, const float* a, float* r)
  {
    vsAtanh(n, a, r);
  }
  inline void vatanh(const MKL_INT n, const double* a, double* r)
  {
    vdAtanh(n, a, r);
  }
  inline void vatanh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* r)
  {
    vcAtanh(n, a, r);
  }
  inline void vatanh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* r)
  {
    vzAtanh(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vatanh(const VECTOR_T& a, VECTOR_T& r)
  {
    vatanh(a.size(), a.data(), r.data());  
  }
  inline void verf(const MKL_INT n, const float* a, float* r)
  {
    vsErf(n, a, r);
  }
  inline void verf(const MKL_INT n, const double* a, double* r)
  {
    vdErf(n, a, r);
  }
  template <typename VECTOR_T>
  inline void verf(const VECTOR_T& a, VECTOR_T& r)
  {
    verf(a.size(), a.data(), r.data());  
  }
  inline void verfc(const MKL_INT n, const float* a, float* r)
  {
    vsErfc(n, a, r);
  }
  inline void verfc(const MKL_INT n, const double* a, double* r)
  {
    vdErfc(n, a, r);
  }
  template <typename VECTOR_T>
  inline void verfc(const VECTOR_T& a, VECTOR_T& r)
  {
    verfc(a.size(), a.data(), r.data());  
  }
  inline void vcdfnorm(const MKL_INT n, const float* a, float* r)
  {
    vsCdfNorm(n, a, r);
  }
  inline void vcdfnorm(const MKL_INT n, const double* a, double* r)
  {
    vdCdfNorm(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vcdfnorm(const VECTOR_T& a, VECTOR_T& r)
  {
    vcdfnorm(a.size(), a.data(), r.data());  
  }
  inline void verfinv(const MKL_INT n, const float* a, float* r)
  {
    vsErfInv(n, a, r);
  }
  inline void verfinv(const MKL_INT n, const double* a, double* r)
  {
    vdErfInv(n, a, r);
  }
  template <typename VECTOR_T>
  inline void verfinv(const VECTOR_T& a, VECTOR_T& r)
  {
    verfinv(a.size(), a.data(), r.data());  
  }
  inline void verfcinv(const MKL_INT n, const float* a, float* r)
  {
    vsErfcInv(n, a, r);
  }
  inline void verfcinv(const MKL_INT n, const double* a, double* r)
  {
    vdErfcInv(n, a, r);
  }
  template <typename VECTOR_T>
  inline void verfcinv(const VECTOR_T& a, VECTOR_T& r)
  {
    verfcinv(a.size(), a.data(), r.data());  
  }
  inline void vcdfnorminv(const MKL_INT n, const float* a, float* r)
  {
    vsCdfNormInv(n, a, r);
  }
  inline void vcdfnorminv(const MKL_INT n, const double* a, double* r)
  {
    vdCdfNormInv(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vcdfnorminv(const VECTOR_T& a, VECTOR_T& r)
  {
    vcdfnorminv(a.size(), a.data(), r.data());  
  }
  inline void vfloor(const MKL_INT n, const float* a, float* r)
  {
    vsFloor(n, a, r);
  }
  inline void vfloor(const MKL_INT n, const double* a, double* r)
  {
    vdFloor(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vfloor(const VECTOR_T& a, VECTOR_T& r)
  {
    vfloor(a.size(), a.data(), r.data());  
  }
  inline void vceil(const MKL_INT n, const float* a, float* r)
  {
    vsCeil(n, a, r);
  }
  inline void vceil(const MKL_INT n, const double* a, double* r)
  {
    vdCeil(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vceil(const VECTOR_T& a, VECTOR_T& r)
  {
    vceil(a.size(), a.data(), r.data());  
  }
  inline void vtrunc(const MKL_INT n, const float* a, float* r)
  {
    vsTrunc(n, a, r);
  }
  inline void vtrunc(const MKL_INT n, const double* a, double* r)
  {
    vdTrunc(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vtrunc(const VECTOR_T& a, VECTOR_T& r)
  {
    vtrunc(a.size(), a.data(), r.data());  
  }
  inline void vround(const MKL_INT n, const float* a, float* r)
  {
    vsRound(n, a, r);
  }
  inline void vround(const MKL_INT n, const double* a, double* r)
  {
    vdRound(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vround(const VECTOR_T& a, VECTOR_T& r)
  {
    vround(a.size(), a.data(), r.data());  
  }
  inline void vnearbyint(const MKL_INT n, const float* a, float* r)
  {
    vsNearbyInt(n, a, r);
  }
  inline void vnearbyint(const MKL_INT n, const double* a, double* r)
  {
    vdNearbyInt(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vnearbyint(const VECTOR_T& a, VECTOR_T& r)
  {
    vnearbyint(a.size(), a.data(), r.data());  
  }
  inline void vrint(const MKL_INT n, const float* a, float* r)
  {
    vsRint(n, a, r);
  }
  inline void vrint(const MKL_INT n, const double* a, double* r)
  {
    vdRint(n, a, r);
  }
  template <typename VECTOR_T>
  inline void vrint(const VECTOR_T& a, VECTOR_T& r)
  {
    vrint(a.size(), a.data(), r.data());  
  }
inline void vmodf(const MKL_INT n, const float* a, float* y, float* z)
  {
    vsModf(n, a, y, z);
  }
  inline void vmodf(const MKL_INT n, const double* a, double* y, double* z)
  {
    vdModf(n, a, y, z);
  }
  template <typename VECTOR_T>
  inline void vmodf(const VECTOR_T& a, VECTOR_T& y, VECTOR_T& z)
  {
    vmodf(a.size(), a.data(), y.data(), z.data());  
  }
}

#endif
