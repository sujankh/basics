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

 int GetSize(Node* node)
  {
    if(node == NULL)
      return 0;
    else
      return 1 + GetSize(node->left) + GetSize(node->right);
  }

 int MaxDepth(Node *node)
  {
    if(node == NULL)
      return 0;
    else 
      return max(1 + MaxDepth(node->left), 1 + MaxDepth(node->right));
  }

 void PrintPostOrder(Node* node)
 {
   if(node == NULL)
     return;
   else
     {
       PrintPostOrder(node->left);
       PrintPostOrder(node->right);
       cout << node->data << "\t";
     }
 }

 bool HasPathSum(Node* node, int sum)
 {

   cout << "HasPathSum( Node: ";

  if (node == NULL)    
    cout << "NULL";
  else
    cout << node->data;

  cout << ", sum =  " << sum << ")" << endl;

   if(node == NULL)
     {
       if(sum == 0)
	 return true;
       else
	 return false;
     }

   return HasPathSum(node->left, sum - node->data) || HasPathSum(node->right, sum - node->data);     
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

  int GetSize()
  {
    return GetSize(root);
  }

   int MaxDepth()
  {
    return MaxDepth(root);
  }
  
   int MinValue()
   {
     Node* currentNode = root;
     int minVal;
     
     while(currentNode != NULL)
       {
	 minVal = currentNode->data;
	 currentNode = currentNode->left;
       }

     return minVal;
   }

   void PrintPostOrder()
   {
     PrintPostOrder(root);
   }

   bool HasPathSum(int sum)
   {
     return HasPathSum(root, sum);
   }

};

#endif
