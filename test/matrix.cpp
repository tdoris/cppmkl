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
