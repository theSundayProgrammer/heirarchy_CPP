#include <vector>
#include <string>
#include <algorithm>
#include "heirarchy.hpp"

#include <iostream>

#include <fstream>
using namespace std;
std::vector<raw_child> raw_children;
void print_tree(
                raw_child const &root,
                int tab_count)
{
  int k;
  for (int i = 0; i < tab_count; ++i)
    std::cout << " ";
  std::cout << root.name  << std::endl;
  auto child = std::lower_bound(raw_children.begin(), raw_children.end(), root,
                            [&](raw_child const& r , raw_child const &root) { return r.parent<root.id; });
  while (child != raw_children.end() && child->parent==root.id)
  {
    print_tree(*child++, tab_count + 1);
  }
}
// main
int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage heirarchy <filename>" << std::endl;
    return 0;
  }

  {
    std::ifstream ifs(argv[1]);
    std::string line;
    while (std::getline(ifs, line))
    {
      auto child = readNextRow(line);
      raw_children.push_back(child);
      //std::cout << child.id << " " << child.name << " " << child.parent << std::endl;
    }
  }
  int k = 0;
  std::sort(raw_children.begin(), raw_children.end(),
                           [](raw_child const &x,raw_child const &y) { return x.parent <y.parent; });
  auto root = std::lower_bound( raw_children.begin(), raw_children.end(), 0,
                           []( raw_child const &x,int k) { return x.parent < k; });
  std::cout << "-----------------------" <<std::endl;
  std::cout << root->id << " " << root->name << " " << root->parent << std::endl;
  std::cin >> k;
  print_tree(*root, 0);
}
