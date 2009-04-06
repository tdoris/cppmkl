#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
#include "cppmkl/matrix.h"
using namespace std;

void test_asum()
{
  cppmkl::matrix<double> A(10,1);
  for(size_t i=0;i<10;++i)
  {
    A(i,0) = i*1.0;
  }
  double sum = cppmkl::cblas_asum(A);
  assert(sum == 45);
}

