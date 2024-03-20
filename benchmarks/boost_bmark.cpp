#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

#include "mkl_lapack.h" //for dsecnd
#include "mkl_service.h" //for getcpuclocks
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include "cppmkl/cppmkl_boostw.h" // this must be included here

#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"

#include "matrix_utils.h"

using namespace std;

void test_boost_bmark()
{
  cout << __FUNCTION__ <<endl;
  {
    const size_t N=1000;
    boost::numeric::ublas::matrix<float> A(N,N);
    boost::numeric::ublas::matrix<float> B(N,N);
    boost::numeric::ublas::matrix<float> C(N,N);
    for(size_t r=0;r<A.size1();++r)
    {
      for(size_t c=0;c<A.size2();++c)
      {
        A(r,c) = 1.5+1.2*(r%7)+1.87*(c%11);
        B(r,c) = 1.2+1.7*(r%17)+1.87*(c%13);
      }
    }
    double boost_start, boost_end, cppmkl_start, cppmkl_end, cpufreq;
    cpufreq = mkl_get_cpu_frequency();
    boost_start = dsecnd(); 

    C = boost::numeric::ublas::prod(A,B);

    boost_end = dsecnd();

    cppmkl_start = dsecnd();

    cppmkl::cblas_gemm(A, B, C);

    cppmkl_end = dsecnd();

    cout << "boost start, end:"<<boost_start<<","<<boost_end<<endl;
    cout << "cppmkl start, end:"<<cppmkl_start<<","<<cppmkl_end<<endl;
    cout << "boost elapsed:"<< (boost_end - boost_start) / cpufreq <<endl;
    cout << "cppmkl elapsed:"<< (cppmkl_end - cppmkl_start) / cpufreq <<endl;
    cout << "cppmkl speedup:" <<(boost_end - boost_start) /  (cppmkl_end - cppmkl_start) << endl; 
  }
}
