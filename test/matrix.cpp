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
}

void matrix_access()
{
  cout << __FUNCTION__ <<endl;  
  {    
    matrix<double> m(10,10);
    m(0,0) = 1.1;
    m(9,9) = 9.9;
    assert(m(0,0) == 1.1);
    assert(m(9,9) == 9.9);
    const double *d = m.data();
    for(size_t i=1;i<99;++i)
    {
      assert(d[i] == 0.0);
    }
  }
}

