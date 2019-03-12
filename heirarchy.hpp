#pragma once
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
typedef std::string content;

struct Data 
{
    int id;
    content name;
};

struct Child
{
    Child(content const& name_): name(name_){
    }
    content name;
    std::vector<Child> children;
};

struct raw_child
{
    int id;
    content name;
    int parent;
};
raw_child readNextRow(std::string&  line);

void generate_map(raw_child const& child);
Child gen_tree(Data const & root);
void print_heirarch(Child const& parent, int tab_count);
Data& get_root(int k);
