#include <assert.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "cppmkl/cppmkl_vml.h"
#include "cppmkl/matrix.h"
using namespace std;

inline bool eq(double a, double b)
{
  const double maxAbsoluteError = 1e-7;
  const double maxRelativeError = 1e-5;

  if(fabs(a - b) < maxAbsoluteError) return true;

  if(fabs(a/b) > (1.0-maxRelativeError) && fabs(a/b) < (1.0+maxRelativeError)) return true;

  return false;
}

void test_std_vector_vml()
{
  cout << __FUNCTION__ <<endl;
  {
    const int N = 10000;
    vector<double> a(N);
    vector<double> b(N);
    vector<double> lt_three(N);
    vector<double> lt_ten(N);
    vector<double> negten_to_posten(N);
    vector<double> sin_of_a(N);
    vector<double> cos_of_a(N);
    vector<double> tan_of_a(N);
    vector<double> sinh_of_a(N);
    vector<double> cosh_of_a(N);
    vector<double> tanh_of_a(N);
    vector<double> r(N);
    for(size_t i=0;i<a.size();++i)
    {
      a[i] = 2.3234*i;
      b[i] = i;
      lt_three[i] = i*3.0 / N;
      lt_ten[i] = i * 10/N;
      negten_to_posten[i] =-10.0+ 20*i/N;
    }
    cppmkl::vadd(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], a[i]+b[i]) );
    }
    cppmkl::vsub(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (a[i]-b[i])) );
    }
    cppmkl::vsqr(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], a[i]*a[i]));
    }
    cppmkl::vmul(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], a[i]*b[i]) );
    }
    cppmkl::vinv(a,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r[i], (1/a[i])));
    }
    cppmkl::vdiv(a,b,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r[i], a[i]/b[i]) );
    }
    cppmkl::vsqrt(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (sqrt(a[i]))) );
    }
    cppmkl::vinvsqrt(a,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r[i], (1.0/sqrt(a[i]))) );
    }
    cppmkl::vcbrt(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (pow(a[i],0.3333333333333333333))) );
    }
    cppmkl::vinvcbrt(a,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r[i], (1.0/pow(a[i],0.3333333333333333333))) );
    }
    cppmkl::vpow2o3(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (pow(a[i],0.6666666666666666666))) );
    }
    cppmkl::vpow3o2(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (pow(a[i],1.5))) );
    }
    cppmkl::vpow(a, lt_three, r);
    for(size_t i=0;i<a.size();++i)
    {
      if(!( eq(r[i], pow(a[i], lt_three[i]))))
      {
        cout << setprecision(20);
        cout << "i:"<<i<<" a[i]:"<<a[i]<<" lt_three[i]:"<<lt_three[i]<< " r[i]:"<<r[i]<<" pow():"<< pow(a[i], lt_three[i])<<endl;
      }
      assert( eq(r[i], pow(a[i], lt_three[i])));
    }
    cppmkl::vpowx(a, 1.2, r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (pow(a[i],1.2))) );
    }
    cppmkl::vhypot(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (sqrt(a[i]*a[i] + b[i]*b[i]))) );
    }
    cppmkl::vexp(lt_ten ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (exp(lt_ten[i]))) );
    }
    cppmkl::vexpm1(lt_ten ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (exp(lt_ten[i])-1.0)) );
    }
    cppmkl::vln(a ,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r[i], (log(a[i]))) );
    }
    cppmkl::vlog10(a ,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r[i], (log10(a[i]))) );
    }
    cppmkl::vlog1p(a ,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r[i], (log(a[i]+1.0))) );
    }
    cppmkl::vcos(a ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (cos(a[i]))) );
    }
    cos_of_a = r;

    cppmkl::vsin(a ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (sin(a[i]))) );
    }
    sin_of_a = r;

    cppmkl::vtan(a ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r[i], (tan(a[i]))) );
    }
    tan_of_a=r;

    cppmkl::vacos(cos_of_a ,r);
    for(size_t i=0;i<cos_of_a.size();++i)
    {
      assert( eq(r[i], (acos(cos_of_a[i]))) );
    }
    cppmkl::vasin(sin_of_a ,r);
    for(size_t i=0;i<sin_of_a.size();++i)
    {
      assert( eq(r[i], (asin(sin_of_a[i]))) );
    }

    cppmkl::vatan(tan_of_a ,r);
    for(size_t i=0;i<tan_of_a.size();++i)
    {
      assert( eq(r[i], (atan(tan_of_a[i]))) );
    }

    cppmkl::vcosh(negten_to_posten ,r);
    for(size_t i=0;i<negten_to_posten.size();++i)
    {
      assert( eq(r[i], (cosh(negten_to_posten[i]))) );
    }
    cosh_of_a = r;

    cppmkl::vsinh(negten_to_posten ,r);
    for(size_t i=0;i<negten_to_posten.size();++i)
    {
      assert( eq(r[i], (sinh(negten_to_posten[i]))) );
    }
    sinh_of_a = r;

    cppmkl::vtanh(negten_to_posten ,r);
    for(size_t i=0;i<negten_to_posten.size();++i)
    {
      assert( eq(r[i], (tanh(negten_to_posten[i]))) );
    }
    tanh_of_a = r;

    cppmkl::vacosh(cosh_of_a ,r);
    for(size_t i=0;i<cosh_of_a.size();++i)
    {
      assert( eq(r[i], (acosh(cosh_of_a[i]))) );
    }
    cppmkl::vasinh(sinh_of_a ,r);
    for(size_t i=0;i<sinh_of_a.size();++i)
    {
      assert( eq(r[i], (asinh(sinh_of_a[i]))) );
    }
    cppmkl::vatanh(tanh_of_a ,r);
    for(size_t i=0;i<tanh_of_a.size();++i)
    {
      assert( eq(r[i], (atanh(tanh_of_a[i]))) );
    }
  }
}
