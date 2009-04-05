#ifndef __MATRIX_UTILS_H__
#define __MATRIX_UTILS_H__

#include <iostream>
#include <sstream>
#include <string>
void initm(cppmkl::matrix<double>& m, const char* s)
{
  std::vector<double> data;
  size_t rows=0;
  size_t max_col_size = 0;
  size_t current_col=0;

  std::stringstream ss(s);
  std::string row;

  while(std::getline(ss,row,';'))
  {
    std::stringstream rowStream(row);
    double val;
    current_col=0;
    while(rowStream >> val)
    {
      data.push_back(val);
      current_col++;
    }
    if(max_col_size == 0)
    {
      max_col_size = current_col;
    }
    else if(current_col !=max_col_size)
    {
      throw "number of columns must match";
    }
    rows++;
  }
  m.resize(rows, current_col);
  size_t i=0;
  for(size_t r=0;r<rows; ++r)
  {
    for(size_t c=0;c<current_col;++c)
    {
      m(r,c) = data[i++];
    }
  }
}


void print_matrix(const cppmkl::matrix<double>& m)
{
  for(size_t r=0;r<m.size1();++r)
  {
    for(size_t c=0;c<m.size2();++c)
    {
      std::cout <<m(r,c) << " ";
    }
    std::cout << "\n";
  }
}


#endif
