#include <iostream>
using namespace std;

#include "tree.h"

int main()
{
  Tree tree;
  
  tree.AddNode(5);
  tree.AddNode(2);
  tree.AddNode(3);
  tree.AddNode(1);
  tree.AddNode(9);
  tree.AddNode(11);
  tree.AddNode(6);

  //  tree.AddNode(0);

  tree.PrintTree();

  cout << endl << tree.HasItem(5) << endl;
  cout << tree.HasItem(32) << endl;

  cout << "Tree Size: " <<  tree.GetSize() << endl;
  cout << "Depth: " << tree.MaxDepth() << endl;
  cout << "MinVal: " << tree.MinValue() << endl;
  
  cout << "Post order: \n";
  tree.PrintPostOrder();

}
