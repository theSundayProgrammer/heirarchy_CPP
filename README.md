=== Comaprison of C++ and Pyton Solutions for Heirarchy Problem ===
“Rien n'est plus dangereux qu'une idée, quand on n'a qu'une idée.”
Émile-Auguste Chartier
Abstract
In considering how to print a multiway tree in heirarchical, this blog shows that there are many ways to represent a multiway tree in a data structure. The most obvious solution of a node with a pointer to a list of child nodes is not always the best.

Problem
Consider a table of the of following form:

<item\_id,parent\_id,content>

where item\_id is unique to every row and parent\_id matches with an item_id of some row except for a special row called the root which has a special  parent\_id, say zero,  that is not present as an item _id. It is required to print this table in an heirachical fashion as for example
Root
  Child1
    Subchild1
    Subchild2
    ...
    SubchildN
  Child2
    Subchild21
    Subchild22

The first solution is to convert the given linear data into a multiway tree and traverse the data in a pre-order fashion. This can be done by picking the root node and traversing the tree to pick all its immediate children and then recursively the children of the children. This can be done using breadth-first or depth-first algorithm. Another way to do it would be to use a map (known as intermediate map henceforth) from the parent\_id to an array of children. This can then be used to generate a multiway tree. Another way to represent the intermediate map is using a multi-map as in C++ multimap or Ocaml Hashtbl. (On a personal note I tried using Map in OCaml and had some issues because a Map in Ocaml is immutable. Hence I used a Hashtbl and then I realised I could use multimap in C++). 
Notice that since the sole purpose of the tree is print the data in a heirarchical fashion, it is possible to print the data using the same traversal as in generating a tree. Hence there is no need to generate the tree.

Taking a cue from Chartier as quoted above I considered other ways to address the main problem which is to print the array data in a heirachical fashion. The brute force solution would to be start with the root and then traverse the array to print all its children and all their children recursively. Notice tfrom the code below that the time complexity is O(n^2) in terms of comparisons because each non-leaf item takes n comparisons to print all its immediate children and each leaf node takes n comparisons to determine it is a leaf node. To reduce that we could sort the array based on parent\_id. This would reduce the number of comparisons to at most log(n). Hence including the sorting this would take O(n.log(n)).  In other words we have used a sorted tree to represent a multiway tree. 



















