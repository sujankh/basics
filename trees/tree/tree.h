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
public:
   Node* AddNode(int data)
  {
    Node* newNode = new Node(data, NULL, NULL);
    AddNode(root, newNode);
  }
  
  void AddNode(Node* target, Node* newNode)
  {
    if(target == NULL)
    {
      target = newNode;
      return;
    }
    else
    {
      if(newNode->data < target->data)
	AddNode(target->left, newNode);
      else
	AddNode(target->right, newNode);
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
	if(item < node->data)
	  {
	    return HasItem(node->left, item);
	  }
	else
	  {
	    return HasItem(node->right, item);
	  }
      }
  }
  
};

#endif
