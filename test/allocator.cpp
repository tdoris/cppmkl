#include <iostream>
#include <vector>
#include <assert.h>

#include "cppmkl/cppmkl_allocator.h"
using namespace std;

void test_basic_alloc()
{
  cout << __FUNCTION__ <<endl;
  const int n=10000;
  vector<int, cppmkl::cppmkl_allocator<int> > a(n);
  for(int i=0;i<n;++i)
  {
    a[i] = i*2;
  }
  for(int i=0;i<n;++i)
  {
    assert(a[i] == i*2);
  }
}



