#include <assert.h>
#include <iostream>
#include "cppmkl/matrix.h"

using namespace std;
using namespace cppmkl;

void matrix_construction()
{
  cout << __FUNCTION__ <<endl;  
  {
    matrix<double> m;
  }
  {    
    matrix<double> m(10,10);
  }
  {
    //should cause bad alloc
    bool bad_alloc_thrown = false;
    try
    {
      matrix<double> m(1024*1024*1024, 1024*1024*1024);
    } catch(bad_alloc& ba)
    {
      bad_alloc_thrown = true;
    }
    assert(bad_alloc_thrown);
  }
}
