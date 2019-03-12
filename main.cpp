
/**
 * A program that converts a linear array of parent child
 * relationships to a single m-ary tree.
 * Assumes the data is valid in that there is only one root
 **/
#include "heirarchy.hpp"
 
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <fstream>
using namespace std;
void print_tree(Data const & root, int tab_count);
// main function to measure elapsed time of a C++ program 
// using chrono library
int main(int argc, char* argv[])
{
  if (argc <2)
  {
    std::cout << "Usage heirarchy <filename>" << std::endl;
    return 0;
  }
  auto big_bang = chrono::steady_clock::now();
  std::vector<raw_child> raw_children;
  {
    std::ifstream ifs(argv[1]);
    std::string line;
    while(std::getline(ifs, line))
    {
      auto child = readNextRow(line);
      raw_children.push_back(child);
    }
  }
	auto start = chrono::steady_clock::now();
  for(auto& child : raw_children)
    generate_map(child);


  //auto root = gen_tree(get_root(0));
  print_tree(get_root(0),0);
	auto end = chrono::steady_clock::now();
  //print_heirarch(root, 0);
	cout << "Time for reading data : " 
		<< chrono::duration_cast<chrono::microseconds>(start - big_bang).count()
		<< " µs" << endl;

cout << "Time to compute : " 
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;


	return 0;
}
