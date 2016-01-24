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
  tree.AddNode(10);
  tree.AddNode(12);

  //  tree.AddNode(0);

  tree.PrintTree();

  Tree tree1;
  
  tree1.AddNode(5);
  tree1.AddNode(2);
  tree1.AddNode(3);
  tree1.AddNode(1);
  tree1.AddNode(9);
  tree1.AddNode(11);
  tree1.AddNode(6);
  tree1.AddNode(10);


  std::cout << "Equals: " << tree.sameTree(tree1) << std::endl;
  
  cout << endl << tree.HasItem(5) << endl;
  cout << tree.HasItem(32) << endl;

  cout << "Tree Size: " <<  tree.GetSize() << endl;
  cout << "Depth: " << tree.MaxDepth() << endl;
  cout << "MinVal: " << tree.MinValue() << endl;
  
  cout << "Post order: \n";
  tree.PrintPostOrder();
  
  cout << endl;
  cout << "Has Sum 25: " << tree.HasPathSum(25) << endl;
  /*  cout << "Has Sum 20: " << tree.HasPathSum(20) << endl;
  cout << "Has Sum 11: " << tree.HasPathSum(11) << endl;
  */cout << "Has Sum 7: " << tree.HasPathSum(7) << endl;
  /* cout << "Has Sum 8: " << tree.HasPathSum(8) << endl;
  cout << "Has Sum 0: " << tree.HasPathSum(0) << endl;
  */

  tree.mirror();
  
  vector<vector<int> > allPaths = tree.getAllPaths();
  
  for(int i = 0; i < allPaths.size(); ++i)
    {
      vector<int> currentPath = allPaths[i];

      for(int j = 0; j < currentPath.size(); ++j)
	{
	  cout << currentPath[j]  << "\t";
	}

      cout << endl;
    }
}
