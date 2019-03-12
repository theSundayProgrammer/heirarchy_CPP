#include "heirarchy.hpp"
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
raw_child readNextRow(std::string&  line)
{
    
    std::stringstream   lineStream(line);
    std::string         cell;

    raw_child child;
    if(std::getline(lineStream, cell, ','))
    {
        child.id = std::stoi(cell);
    }
    if(std::getline(lineStream, cell, ','))
    {
      boost::trim(cell);
      child.name = cell;
    }
    if(std::getline(lineStream, cell, ','))
    {
        child.parent = std::stoi(cell);
    }
    return child;
}
#ifdef MAIN_CPP_FILE
int main()
{
  std::ifstream ifs("heirarchy.dat");
  std::string line;
  while(std::getline(ifs, line))
  {
    auto child = readNextRow(line);
    std::cout << child.id << "," << child.name << "," << child.parent << std::endl;
  }
}
#endif