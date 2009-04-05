#ifndef __CPPMKL_MATRIX_H__
#define __CPPMKL_MATRIX_H__
#include <assert.h>
#include <stddef.h>
#include <mkl.h>

namespace cppmkl
{
  template<typename T>  
  class matrix
  {
    T* d;
    size_t s1;
    size_t s2;
    matrix(const matrix<T>& rhs);
    matrix<T>& operator=(const matrix<T>& rhs);
    public:
    matrix(): d(0), s1(0), s2(0)
    {
    }
    matrix(size_t r, size_t c):s1(r), s2(c)
    {
      d = static_cast<T*>(MKL_malloc(r*c*sizeof(T), 128));
      if(d == 0)
      {
        throw std::bad_alloc();
      }
      for(size_t i=0;i<r*c;++i) d[i]=0.0;
    }
    matrix(const T* _d, size_t r, size_t c): s1(r), s2(c)
    {
      d = static_cast<T*>(MKL_malloc(r*c*sizeof(T), 128));
      if(d == 0)
      {
        throw std::bad_alloc();
      }
      for(size_t i=0;i<r*c;++i) d[i]=_d[i];
    }
    ~matrix() //non virtual, don't inherit from 
    {
      if(d)
      {
        MKL_free(d);
      }
    }
    // creates new matrix of specified size
    void resize(size_t r, size_t c)
    {
      if(d)
      {
        MKL_free(d);
      }
      d = static_cast<T*>(MKL_malloc(r*c*sizeof(T), 128));
      if(d == 0) 
      { 
        throw std::bad_alloc();
      }
      for(size_t i=0;i<r*c;++i) d[i]=0.0;
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
    T* data() { return d; }
    const T* data() const { return d; }
    size_t size1() const { return s1; }
    size_t size2() const { return s2; }
  
  };
}

#endif
