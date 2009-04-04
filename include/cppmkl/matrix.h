#ifndef __CPPMKL_MATRIX_H__
#define __CPPMKL_MATRIX_H__
#include <assert.h>
#include <mkl.h>

namespace cppmkl
{
  class matrix
  {
    double* data;
    unsigned int row_count;
    unsigned int col_count;
    public:
    matrix()
    {
    }
    matrix(unsigned int r, unsigned int c):row_count(r), col_count(c)
    {
      data = static_cast<double*>(MKL_malloc(r*c*sizeof(double), 128));
      if(data == 0)
      {
        throw std::bad_alloc();
      }
    }
    ~matrix() //non virtual, don't inherit from matrix
    {
      MKL_free(data);
    }
    double& operator()(unsigned int row, unsigned int col)
    {
      assert(row<row_count);
      assert(col<col_count);
      return data[row*col_count+col];
    }
  };
}

#endif
