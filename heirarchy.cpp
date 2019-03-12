/**
 * A program that converts a linear array of parent child
 * relationships to a single m-ary tree.
 * Assumes the data is valid in that there is only one root
 **/
#include "heirarchy.hpp"
 using std::vector;
 std::map<int, vector<Data>> list_children;
 void generate_map(raw_child const& child)
  {
    list_children[child.parent].push_back({child.id,child.name});
  }
Data& get_root(int k)
{
  return list_children[k][0];
}
Child gen_tree(Data const & root)
{
  auto item = list_children.find(root.id);
  Child parent(root.name);
  if (item != list_children.end())
  {
      auto& subs = item->second;

      for (auto& ch : subs)
      {
        parent.children.push_back(gen_tree(ch));
      }
  }
  return parent;
}
void print_tree(Data const & root, int tab_count)
{
        for (int i = 0; i < tab_count; ++i)
            printf("  ");
        printf("%s\n", root.name.c_str());
  auto item = list_children.find(root.id);

  if (item != list_children.end())
  {
      auto& subs = item->second;

      for (auto& sub : subs)
        print_tree(sub, tab_count+1);
      
  }

}

void print_heirarch(Child const& parent, int tab_count)
    {
        for (int i = 0; i < tab_count; ++i)
            printf("  ");
        printf("%s\n", parent.name.c_str());
        for (auto& sub : parent.children)
            print_heirarch(sub, tab_count + 1);
        
    }
