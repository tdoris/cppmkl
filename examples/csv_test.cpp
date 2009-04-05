#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
  std::ifstream  data("A.csv");

  std::string line;
  while(std::getline(data,line))
  {
    std::stringstream  lineStream(line);
    std::string        cell;
    while(std::getline(lineStream,cell,','))
    {
      // You have a cell!!!!
      cout << "cell:["<<cell<<"]"<<endl;
    }
    cout << "newline"<<endl;
  }
}


