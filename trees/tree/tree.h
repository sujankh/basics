#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

#include <vector>

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

 
 vector<vector<int> > getAllPaths(Node* node)
   {
     vector<vector<int> >  pathsFromNode;

     if(node->left == NULL && node->right == NULL)
       {
	 vector<int> currentPath;
	 currentPath.push_back(node->data);

	 pathsFromNode.push_back(currentPath);
       }
     else
       {
     
	 if(node->left != NULL)
	   {
	     vector<vector<int> > childPaths = getAllPaths(node->left);
	     for(int i = 0; i < childPaths.size(); ++i)
	       {
		 vector<int> currentPath = childPaths[i];

		 currentPath.insert(currentPath.begin(), node->data);

		 pathsFromNode.push_back(currentPath);
	       }
	   }

	 if(node->right != NULL)
	   {
	     vector<vector<int> > childPaths = getAllPaths(node->right);

	     for(int i = 0; i < childPaths.size(); ++i)
	       {
		 vector<int> currentPath = childPaths[i];

		 currentPath.insert(currentPath.begin(), node->data);

		 pathsFromNode.push_back(currentPath);
	       }
	   }

       }

     return pathsFromNode;
     
   }

 void mirror(Node* node)
 {
   if(node->left == NULL && node->right == NULL)
     return;

   mirror(node->left);
   mirror(node->right);

   Node* tmp = node->left;
   node->left = node->right;
   node->right = tmp;
 }

 bool sameTree(Node *t1, Node *t2)
 {
   if(t1 == NULL || t2 == NULL)
     return t1 == t2;
   else if(t1->data != t2->data)
     return false;

   return sameTree(t1->left, t2->left) && sameTree(t1->right, t2->right);   
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

   void mirror()
   {
     mirror(root);
   }

   bool sameTree(Tree t2)
   {
     return sameTree(root, t2.root);
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

  vector<vector<int> > getAllPaths()
    {
      return getAllPaths(root);
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
