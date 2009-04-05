#ifndef __CPPMKL_MATRIX_H__
#define __CPPMKL_MATRIX_H__
#include <assert.h>
#include <stddef.h>
#include <vector>
#include <mkl.h>

namespace cppmkl
{
  /**
 * example of a matrix type that can be used with cppmkl wrapper functions
 * for simplicity this just uses a std::vector for underlying storage, a
 * performance/accuracy conscious implementation would manually manage the 
 * underlying storage using MKL_malloc and MKL_free and properly align the storage
 */
  template<typename T>  
  class matrix
  {
    std::vector<T> d;
    size_t s1;
    size_t s2;
    public:
    matrix(): s1(0), s2(0)
    {
    }
    matrix(size_t r, size_t c):s1(r), s2(c)
    {
      d.resize(r*c);
    }
    matrix(const std::vector<T> _d, size_t r, size_t c):d(_d), s1(r), s2(c)
    {
    }
    // creates new matrix of specified size
    void resize(size_t r, size_t c)
    {
      d.resize(r*c);
      s1 = r;
      s2 = c;
    }
    T& operator()(size_t row, size_t col)
    {
      assert(row<s1);
      assert(col<s2);
      return d[row*s2+col];
    }
    const T& operator()(size_t row, size_t col) const
    {
      assert(row<s1);
      assert(col<s2);
      return d[row*s2+col];
    }
    T* data() { return &d[0]; }
    const T* data() const { return &d[0]; }
    size_t size1() const { return s1; }
    size_t size2() const { return s2; }
  
  };
}

#endif
