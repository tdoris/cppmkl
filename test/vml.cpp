#include <assert.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "cppmkl/cppmkl_vml.h"
#include "cppmkl/matrix.h"
using namespace std;

bool eq(double a, double b)
{
  const double maxAbsoluteError = 1e-7;
  const double maxRelativeError = 1e-5;

  if(fabs(a - b) < maxAbsoluteError) return true;

  if(fabs(a/b) > (1.0-maxRelativeError) && fabs(a/b) < (1.0+maxRelativeError)) return true;

  return false;
}

void test_vml()
{
  cout << __FUNCTION__ <<endl;
  {
    const int N = 10000;
    cppmkl::matrix<double> a(N, 1);
    cppmkl::matrix<double> b(N, 1);
    cppmkl::matrix<double> lt_three(N, 1);
    cppmkl::matrix<double> lt_ten(N, 1);
    cppmkl::matrix<double> negten_to_posten(N, 1);
    cppmkl::matrix<double> sin_of_a(N, 1);
    cppmkl::matrix<double> cos_of_a(N, 1);
    cppmkl::matrix<double> tan_of_a(N, 1);
    cppmkl::matrix<double> sinh_of_a(N, 1);
    cppmkl::matrix<double> cosh_of_a(N, 1);
    cppmkl::matrix<double> tanh_of_a(N, 1);
    cppmkl::matrix<double> r(N, 1);
    for(size_t i=0;i<a.size();++i)
    {
      a(i,0) = 2.3234*i;
      b(i,0) = i;
      lt_three(i,0) = i*3.0 / N;
      lt_ten(i,0) = i * 10/N;
      negten_to_posten(i,0) =-10.0+ 20*i/N;
    }
    cppmkl::vadd(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), a(i,0)+b(i,0)) );
    }
    cppmkl::vsub(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (a(i,0)-b(i,0))) );
    }
    cppmkl::vsqr(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), a(i,0)*a(i,0)));
    }
    cppmkl::vmul(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), a(i,0)*b(i,0)) );
    }
    cppmkl::vinv(a,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r(i,0), (1/a(i,0))));
    }
    cppmkl::vdiv(a,b,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r(i,0), a(i,0)/b(i,0)) );
    }
    cppmkl::vsqrt(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (sqrt(a(i,0)))) );
    }
    cppmkl::vinvsqrt(a,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r(i,0), (1.0/sqrt(a(i,0)))) );
    }
    cppmkl::vcbrt(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (pow(a(i,0),0.3333333333333333333))) );
    }
    cppmkl::vinvcbrt(a,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r(i,0), (1.0/pow(a(i,0),0.3333333333333333333))) );
    }
    cppmkl::vpow2o3(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (pow(a(i,0),0.6666666666666666666))) );
    }
    cppmkl::vpow3o2(a,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (pow(a(i,0),1.5))) );
    }
    cppmkl::vpow(a, lt_three, r);
    for(size_t i=0;i<a.size();++i)
    {
      if(!( eq(r(i,0), pow(a(i,0), lt_three(i,0)))))
      {
        cout << setprecision(20);
        cout << "i:"<<i<<" a(i,0):"<<a(i,0)<<" lt_three(i,0):"<<lt_three(i,0)<< " r(i,0):"<<r(i,0)<<" pow():"<< pow(a(i,0), lt_three(i,0))<<endl;
      }
      assert( eq(r(i,0), pow(a(i,0), lt_three(i,0))));
    }
    cppmkl::vpowx(a, 1.2, r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (pow(a(i,0),1.2))) );
    }
    cppmkl::vhypot(a,b,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (sqrt(a(i,0)*a(i,0) + b(i,0)*b(i,0)))) );
    }
    cppmkl::vexp(lt_ten ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (exp(lt_ten(i,0)))) );
    }
    cppmkl::vexpm1(lt_ten ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (exp(lt_ten(i,0))-1.0)) );
    }
    cppmkl::vln(a ,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r(i,0), (log(a(i,0)))) );
    }
    cppmkl::vlog10(a ,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r(i,0), (log10(a(i,0)))) );
    }
    cppmkl::vlog1p(a ,r);
    for(size_t i=1;i<a.size();++i)
    {
      assert( eq(r(i,0), (log(a(i,0)+1.0))) );
    }
    cppmkl::vcos(a ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (cos(a(i,0)))) );
    }
    cos_of_a = r;

    cppmkl::vsin(a ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (sin(a(i,0)))) );
    }
    sin_of_a = r;

    cppmkl::vtan(a ,r);
    for(size_t i=0;i<a.size();++i)
    {
      assert( eq(r(i,0), (tan(a(i,0)))) );
    }
    tan_of_a=r;

    cppmkl::vacos(cos_of_a ,r);
    for(size_t i=0;i<cos_of_a.size();++i)
    {
      assert( eq(r(i,0), (acos(cos_of_a(i,0)))) );
    }
    cppmkl::vasin(sin_of_a ,r);
    for(size_t i=0;i<sin_of_a.size();++i)
    {
      assert( eq(r(i,0), (asin(sin_of_a(i,0)))) );
    }

    cppmkl::vatan(tan_of_a ,r);
    for(size_t i=0;i<tan_of_a.size();++i)
    {
      assert( eq(r(i,0), (atan(tan_of_a(i,0)))) );
    }

    cppmkl::vcosh(negten_to_posten ,r);
    for(size_t i=0;i<negten_to_posten.size();++i)
    {
      assert( eq(r(i,0), (cosh(negten_to_posten(i,0)))) );
    }
    cosh_of_a = r;

    cppmkl::vsinh(negten_to_posten ,r);
    for(size_t i=0;i<negten_to_posten.size();++i)
    {
      assert( eq(r(i,0), (sinh(negten_to_posten(i,0)))) );
    }
    sinh_of_a = r;

    cppmkl::vtanh(negten_to_posten ,r);
    for(size_t i=0;i<negten_to_posten.size();++i)
    {
      assert( eq(r(i,0), (tanh(negten_to_posten(i,0)))) );
    }
    tanh_of_a = r;

    cppmkl::vacosh(cosh_of_a ,r);
    for(size_t i=0;i<cosh_of_a.size();++i)
    {
      assert( eq(r(i,0), (acosh(cosh_of_a(i,0)))) );
    }
    cppmkl::vasinh(sinh_of_a ,r);
    for(size_t i=0;i<sinh_of_a.size();++i)
    {
      assert( eq(r(i,0), (asinh(sinh_of_a(i,0)))) );
    }
    cppmkl::vatanh(tanh_of_a ,r);
    for(size_t i=0;i<tanh_of_a.size();++i)
    {
      assert( eq(r(i,0), (atanh(tanh_of_a(i,0)))) );
    }
  }
}
