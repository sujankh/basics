#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int data, Node* left, Node* right):data(data),
					  left(left),
					  right(right)
  {
  }
  
  Node()
  {
  }
  
};

class Tree
{
private:
  Node* root;

  void PrintTree(Node* node)
  {
    if(node == NULL)
      return;
    else
      {
	PrintTree(node->left);

	if(node != NULL)
	  {
	    cout << node->data << "\t";
      
	    PrintTree(node->right);	
	  }
      }
  }

public:
  Tree()
	{
	  root = NULL;
	}

   Node* AddNode(int data)
  {
	   AddNode(root, data);
  }
  
  void AddNode(Node*& target, int data)
  {
    if(target == NULL)
    {
      target = new Node(data, NULL, NULL);
    }
    else
    {
      if(data < target->data)
    	  AddNode(target->left, data);
      else
    	  AddNode(target->right, data);
    }
      
  }

  bool HasItem(int item)
  {
    return HasItem(root, item);
  }
  
  bool HasItem(Node* node, int item)
  {
	  if(node == NULL)
	  {
		  return false;
	  }
	  else
	  {
		  if(item == node->data)
		  {
			  return true;
		  }
		  else if(item < node->data)
		  {
			  return HasItem(node->left, item);
		  }
		  else
		  {
			  return HasItem(node->right, item);
		  }
	  }
  }
  
  void PrintTree()
  {
    PrintTree(root);
  }
};

#endif
