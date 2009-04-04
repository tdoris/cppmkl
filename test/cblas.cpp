#include <assert.h>
#include <iostream>
#include "cppmkl/cppmkl_cblas.h"
using namespace std;
void print_matrix(const cppmkl::matrix& m)
{
  for(size_t r=0;r<m.size1();++r)
  {
    for(size_t c=0;c<m.size2();++c)
    {
      cout <<m(r,c) << " ";
    }
    cout << "\n";
  }
}
void test_cblas_dgemm()
{
  cout << __FUNCTION__ <<endl;
  {
    cout <<"test 1"<<endl;
    cppmkl::matrix A(3,3);
    cppmkl::matrix B(3,3);
    cppmkl::matrix C(3,3);
    A(0,0) = 1.0;
    A(1,1) = 1.0;
    A(2,2) = 1.0;
    B(0,0) = 1.0;
    B(0,1) = 1.1;
    B(0,2) = 1.2;
    B(1,0) = 2.0;
    B(1,1) = 2.1;
    B(1,2) = 2.2;
    B(2,0) = 3.0;
    B(2,1) = 3.1;
    B(2,2) = 3.2;
    cppmkl::cblas_dgemm(A, B, C);
    assert(C(0,0) == 1.0);
    assert(C(0,1) == 1.1);
    assert(C(0,2) == 1.2);
    assert(C(1,0) == 2.0);
    assert(C(1,1) == 2.1);
    assert(C(1,2) == 2.2);
    assert(C(2,0) == 3.0);
    assert(C(2,1) == 3.1);
    assert(C(2,2) == 3.2);
  }
  {
    cout <<"test 2"<<endl;
    cppmkl::matrix A(2,3);
    cppmkl::matrix B(3,2);
    cppmkl::matrix C(2,2);
    A(0,0) = 1.0;
    A(0,1) = 0.0;
    A(0,2) = 2.0;
    A(1,0) = -1.0;
    A(1,1) = 3.0;
    A(1,2) = 1.0;
    B(0,0) = 3.0;
    B(0,1) = 1.0;
    B(1,0) = 2.0;
    B(1,1) = 1.0;
    B(2,0) = 1.0;
    B(2,1) = 0.0;
    cppmkl::cblas_dgemm(A, B, C);
    assert(C(0,0) == 5.0);
    assert(C(0,1) == 1.0);
    assert(C(1,0) == 4.0);
    assert(C(1,1) == 2.0);
  }
}
