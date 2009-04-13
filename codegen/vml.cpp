#include <assert.h>
#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#include <sstream>


using namespace std;
struct func
{
  string wrapper_name;
  string mkl_name;
  string sdcz;
  bool hasB;
  func(const string& _wrapper_name, const string& _mkl_name, const string& _sdcz, bool _hasB)
    : wrapper_name(_wrapper_name), mkl_name(_mkl_name), sdcz(_sdcz), hasB(_hasB)
  {
  } 
  void print()
  {
    if(sdcz.find("s") != string::npos)
    {
      s_function(wrapper_name, mkl_name);
    }
    if(sdcz.find("d") != string::npos)
    {
      d_function(wrapper_name, mkl_name);
    }
    if(sdcz.find("c") != string::npos)
    {
      c_function(wrapper_name, mkl_name);
    }
    if(sdcz.find("z") != string::npos)
    {
      z_function(wrapper_name, mkl_name);
    }
    template_function(wrapper_name, mkl_name);
  }

private:
  string mklfcall()
  {
    stringstream ss;
    if(hasB)
    {
      ss << mkl_name<<"(n, a, b, r);";
    }
    else
    {
      ss << mkl_name<<"(n, a, r);";
    }
    return ss.str();
  }
  void s_function(const string& wrapper_name, const string& mkl_name)
  {
    cout <<"  inline void "<<wrapper_name<<"(const MKL_INT n, const float* a, ";
    if(hasB)
    {
      cout << "const float* b, ";
    }
    cout << "float* r)"<<endl;
    cout <<"  {"<<endl;
    cout <<"    vs"<<mklfcall()<<endl;
    cout <<"  }"<<endl;
  }

  void d_function(const string& wrapper_name, const string& mkl_name)
  {
    cout <<"  inline void "<<wrapper_name<<"(const MKL_INT n, const double* a, ";
    if(hasB)
    {
      cout <<"const double* b, ";
    }
    cout <<"double* r)"<<endl;
    cout <<"  {"<<endl;
    cout <<"    vd"<<mklfcall()<<endl;
    cout <<"  }"<<endl;
  }
  void c_function(const string& wrapper_name, const string& mkl_name)
  {
    cout <<"  inline void "<<wrapper_name<<"(const MKL_INT n, const MKL_Complex8* a, ";
    if(hasB)
    {
      cout << "const MKL_Complex8* b, ";
    }
    cout << "MKL_Complex8* r)"<<endl;
    cout <<"  {"<<endl;
    cout <<"    vc"<<mklfcall()<<endl;
    cout <<"  }"<<endl;
  }
  void z_function(const string& wrapper_name, const string& mkl_name)
  {
    cout <<"  inline void "<<wrapper_name<<"(const MKL_INT n, const MKL_Complex16* a, ";
    if(hasB)
    {
      cout <<"const MKL_Complex16* b, ";
    }
    cout <<"MKL_Complex16* r)"<<endl;
    cout <<"  {"<<endl;
    cout <<"    vz"<<mklfcall()<<endl;
    cout <<"  }"<<endl;
  }
  void template_function(const string& wrapper_name, const string& mkl_name)
  {
    cout <<"  template <typename VECTOR_T>"<<endl;
    cout <<"  inline void "<<wrapper_name<<"(const VECTOR_T& a, ";
    if(hasB)
    {
      cout << "const VECTOR_T& b, ";
    }
    cout << "VECTOR_T& r)"<<endl;
    cout <<"  {"<<endl;
    if(hasB)
    {
      cout <<"    "<<wrapper_name<<"(a.size(), a.data(), b.data(), r.data());  "<<endl;
    }
    else
    {
      cout <<"    "<<wrapper_name<<"(a.size(), a.data(), r.data());  "<<endl;
    }
    cout <<"  }"<<endl;
  }

};

void header()
{
  cout <<"/* Auto-generated code*/"<<endl;
  cout <<"#ifndef __CPPMKL_VML_H__"<<endl;
  cout <<"#define __CPPMKL_VML_H__"<<endl;
  cout <<"#include <assert.h>"<<endl;
  cout <<"#include <mkl_vml.h>"<<endl;
  cout <<""<<endl;
  cout <<"namespace cppmkl"<<endl;
  cout <<"{"<<endl;
}
void trailer()
{
  cout <<"}"<<endl;
  cout <<""<<endl;
  cout <<"#endif"<<endl;
}

// special case, result is real for complex inputs; 
void vabs()
{
  cout <<"inline void vabs(const MKL_INT n, const float* a, float* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vsAbs(n, a, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vabs(const MKL_INT n, const double* a, double* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vdAbs(n, a, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vabs(const MKL_INT n, const MKL_Complex8* a, float* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vcAbs(n, a, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vabs(const MKL_INT n, const MKL_Complex16* a, double* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vzAbs(n, a, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  template <typename VECTOR_T>"<<endl;
  cout <<"  inline void vabs(const VECTOR_T& a, VECTOR_T& r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vabs(a.size(), a.data(), r.data());  "<<endl;
  cout <<"  }"<<endl;
}

//special case, b is a single value 
void vpowx()
{
  cout <<"inline void vpowx(const MKL_INT n, const float* a, const float b, float* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vsPowx(n, a, b, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vpowx(const MKL_INT n, const double* a, const double b, double* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vdPowx(n, a, b, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vpowx(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8& b, MKL_Complex8* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vcPowx(n, a, b, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vpowx(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16& b, MKL_Complex16* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vzPowx(n, a, b, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  template <typename SCALAR_T, typename VECTOR_T>"<<endl;
  cout <<"  inline void vpowx(const VECTOR_T& a, const SCALAR_T& b, VECTOR_T& r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vpowx(a.size(), a.data(), b, r.data());  "<<endl;
  cout <<"  }"<<endl;
}

//special case, two output vectors func("vsincos", "SinCos", "sd",false).print(); 
void vsincos()
{
  cout <<"inline void vsincos(const MKL_INT n, const float* a, float* y, float* z)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vsSinCos(n, a, y, z);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vsincos(const MKL_INT n, const double* a, double* y, double* z)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vdSinCos(n, a, y, z);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  template <typename VECTOR_T>"<<endl;
  cout <<"  inline void vsincos(const VECTOR_T& a, VECTOR_T& y, VECTOR_T& z)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vsincos(a.size(), a.data(), y.data(), z.data());  "<<endl;
  cout <<"  }"<<endl;
}

  //special case, input vector is real, output complex
void vCIS()
{
  cout <<"  inline void vCIS(const MKL_INT n, const float* a, MKL_Complex8* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vcCIS(n, a, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vCIS(const MKL_INT n, const double* a, MKL_Complex16* r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vzCIS(n, a, r);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  template <typename VECTOR_T_REAL, typename VECTOR_T_COMPLEX>"<<endl;
  cout <<"  inline void vCIS(const VECTOR_T_REAL& a, VECTOR_T_COMPLEX& r)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vCIS(a.size(), a.data(), r.data());  "<<endl;
  cout <<"  }"<<endl;
  
}
//special case, two output vectors:func("vmodf", "Modf", "sd",false).print(); 
void vmodf()
{
  cout <<"inline void vmodf(const MKL_INT n, const float* a, float* y, float* z)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vsModf(n, a, y, z);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  inline void vmodf(const MKL_INT n, const double* a, double* y, double* z)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vdModf(n, a, y, z);"<<endl;
  cout <<"  }"<<endl;
  cout <<"  template <typename VECTOR_T>"<<endl;
  cout <<"  inline void vmodf(const VECTOR_T& a, VECTOR_T& y, VECTOR_T& z)"<<endl;
  cout <<"  {"<<endl;
  cout <<"    vmodf(a.size(), a.data(), y.data(), z.data());  "<<endl;
  cout <<"  }"<<endl;
}
vector<func> function;

void body()
{
  //arithmetic
  func("vadd", "Add", "sdcz",true).print(); 
  func("vsub", "Sub", "sdcz",true).print(); 
  func("vsqr", "Sqr", "sd",false).print(); 
  func("vmul", "Mul", "sdcz",true).print(); 
  func("vmulbyconj", "MulByConj", "cz",true).print(); 
  func("vconj", "Conj", "cz",false).print(); 
  vabs();
  //power and root 
  func("vinv", "Inv", "sd",false).print(); 
  func("vdiv", "Div", "sdcz",true).print(); 
  func("vsqrt", "Sqrt", "sdcz",false).print(); 
  func("vinvsqrt", "InvSqrt", "sd",false).print(); 
  func("vcbrt", "Cbrt", "sd",false).print(); 
  func("vinvcbrt", "InvCbrt", "sd",false).print(); 
  func("vpow2o3", "Pow2o3", "sd",false).print(); 
  func("vpow3o2", "Pow3o2", "sd", false).print(); 
  func("vpow", "Pow", "sdcz",true).print(); 
  vpowx();
  func("vhypot", "Hypot", "sd",true).print(); 
  //exp and log
  func("vexp", "Exp", "sdcz",false).print(); 
  func("vexpm1", "Expm1", "sd",false).print(); 
  func("vln", "Ln", "sdcz",false).print(); 
  func("vlog10", "Log10", "sdcz",false).print(); 
  func("vlog1p", "Log1p", "sd",false).print(); 
  //trig
  func("vcos", "Cos", "sdcz",false).print(); 
  func("vsin", "Sin", "sdcz",false).print(); 
  vsincos();
  vCIS();
  func("vtan", "Tan", "sdcz",false).print(); 
  func("vacos", "Acos", "sdcz",false).print(); 
  func("vasin", "Asin", "sdcz",false).print(); 
  func("vatan", "Atan", "sdcz",false).print(); 
  func("vatan2", "Atan2", "sd",true).print(); 
  //hyperbolic functions
  func("vcosh", "Cosh", "sdcz",false).print(); 
  func("vsinh", "Sinh", "sdcz",false).print(); 
  func("vtanh", "Tanh", "sdcz",false).print(); 
  func("vacosh", "Acosh", "sdcz",false).print(); 
  func("vasinh", "Asinh", "sdcz",false).print(); 
  func("vatanh", "Atanh", "sdcz",false).print(); 
  //special
  func("verf", "Erf", "sd",false).print(); 
  func("verfc", "Erfc", "sd",false).print(); 
  func("vcdfnorm", "CdfNorm", "sd",false).print(); 
  func("verfinv", "ErfInv", "sd",false).print(); 
  func("verfcinv", "ErfcInv", "sd",false).print(); 
  func("vcdfnorminv", "CdfNormInv", "sd",false).print(); 
  //rounding
  func("vfloor", "Floor", "sd",false).print(); 
  func("vceil", "Ceil", "sd",false).print(); 
  func("vtrunc", "Trunc", "sd",false).print(); 
  func("vround", "Round", "sd",false).print(); 
  func("vnearbyint", "NearbyInt", "sd",false).print(); 
  func("vrint", "Rint", "sd",false).print(); 
  vmodf();
}
int main()
{
  header();
  body();
  trailer();
  return 0;
}


