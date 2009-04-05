#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


#include "cppmkl/cppmkl_cblas.h"

using namespace std;
char* progname;
int main(int argv, char** argc)
{
  void print_matrix(const cppmkl::matrix& m);
  void usage();
  bool load(const string& filename, vector<double>& d, size_t& rows, size_t& cols);
  void parsearguments(int argv, char* argc[], string& file1, string& file2, CBLAS_TRANSPOSE& transa, CBLAS_TRANSPOSE& transb, double& alhpa, double& beta);
 
  progname=argc[0];
  if(argv < 3)
  {
    usage();
    return 0;
  }
  string file1, file2;
  CBLAS_TRANSPOSE transa=CblasNoTrans, transb=CblasNoTrans;
  double alpha=1.0, beta=0.0;
  
  parsearguments(argv, argc, file1, file2, transa, transb, alpha, beta);

  {
    
    vector<double> data1, data2;
    size_t r, c;
    if(!load(file1, data1, r,c)) return 1;
    cppmkl::matrix A(&data1[0],r,c);

    if(!load(file2, data2, r,c)) return 1;
    cppmkl::matrix B(&data2[0],r,c);

    cppmkl::matrix C(A.size1(),B.size2());

    cppmkl::cblas_dgemm(A, B, C, (CBLAS_TRANSPOSE) transa,(CBLAS_TRANSPOSE ) transb, alpha, beta);
  
    cout << "C:\n";
    print_matrix(C);    
  } 
    
  return 0; 
}

CBLAS_TRANSPOSE char2transpose(char c)
{
  if(c=='T') return CblasTrans;
  if(c=='C') return CblasConjTrans;
  return CblasNoTrans;
}

void parsearguments(int argv, char** argc, string& file1, string& file2, CBLAS_TRANSPOSE& transa, CBLAS_TRANSPOSE& transb, double& alpha, double& beta)
{
  stringstream f1, f2; 
  f1 << argc[1];
  f2 << argc[2];
  file1 = f1.str();
  file2 = f2.str();
  if(argv>3)
  {
    transa = char2transpose(argc[3][0]);
  } 
  if(argv>4)
  {
    transb = char2transpose(argc[4][0]); 
  }
  if(argv>5)
  {
    stringstream ss; ss << argc[5];
    ss >> alpha;
  }
  if(argv>6)
  { 
    stringstream ss; ss << argc[6];
    ss >> beta;
  }
}

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
void usage()
{
  cout << "Usage:" << progname << " <file1> <file2> [transA] [transB] [alpha] [beta]\n";
  cout << "\t\tfile1: csv file containing matrix A\n";
  cout << "\t\tfile2: csv file containing matrix B\n";
  cout << "\t\ttransA,transB: [N|T|C] No transpose, Transpose, Conjugate transpose (default:No transpose)\n";
  cout << "\t\talpha,beta: C=alpha*op(A)*op(B)+beta*C (default 1.0, 0.0)\n";
  cout <<endl;
}
//todo: there must be a simpler way of loading a csv...
bool load(const string& filename, vector<double>& d, size_t& rows, size_t& cols)
{
  rows=0;
  std::ifstream  data(filename.c_str());
  if(!data)
  {
    cout << "failed to open "<<filename<<" for reading"<<endl;
    return false;
  }  
  std::string line;
  while(std::getline(data,line))
  {
    std::stringstream  lineStream(line);
    std::string        cell;
    while(std::getline(lineStream,cell,','))
    {
      stringstream cellStream(cell);
      double val;
      cellStream >> val;
      d.push_back(val);
    }
    rows++;
  }
  if(d.size() % rows != 0)
  {
    cout <<"in csv:"<<filename<<"not all rows are the same length"<<endl;
    return false;
  }
  cols = d.size() / rows;
  return true;
}

