/*
name: Brenna DeGan
date: 12/9/2016
description: practice with recursion, binary search trees and stacks. 
sources cited: book, office hours, http://cslibrary.stanford.edu/110/BinaryTrees.html
*/


// A Binary Search Tree
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stack>
using namespace std;

// Stack template
template <class T>
class BinarySearchTree
{
private:
   struct TreeNode
   {
      T value;           // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   
   // Private member functions
   void insertNode(TreeNode *); //do i need this?
   void destroySubTree(TreeNode *);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   bool searchNode(TreeNode *, T) const;
   
public:
   // Constructor
   BinarySearchTree()
   { root = NULL; }
      
   // Destructor
   ~BinarySearchTree()
      { destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(T);

   bool search(T item)
      { return searchNode(root, item); }
   
   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
};

//**********************************************************
// insertNode creates a new node to hold item as its value,*
// and puts it into its proper place within the BST.       *
//**********************************************************
template <class T>
void BinarySearchTree<T>::insertNode(T item) 
{
   TreeNode *parentPtr = root; 
   TreeNode *newNode = NULL; //Pointer to new node

   //create a new node and store item in it
   newNode = new TreeNode;
   newNode->value = item;
   newNode->left = newNode->right = NULL;

   // put new node in proper place

   if (root == NULL)
      root = newNode;

   else
   { 
      TreeNode *childPtr = root;
      while(childPtr != NULL)
      {
         if(newNode->value < childPtr->value)
         {
            parentPtr = childPtr;
            childPtr = parentPtr->left;
            
         }
         else if(newNode->value > childPtr->value)
         {
            parentPtr = childPtr;
            childPtr = parentPtr->right;
         }
         else if(newNode->value == childPtr->value)
         {
            cout << newNode->value << " already exists in the BST" << endl;
            return; 
         }
      }

      // insert newNode at this spot
      if(newNode->value < parentPtr->value)
         parentPtr->left = newNode;
      else
         parentPtr->right = newNode;
   }

   return;
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes nodePtr and all of its children.         *
//***************************************************
template <class T>
void BinarySearchTree<T>::destroySubTree(TreeNode *nodePtr)
{
   // input *nodePtr

   if(nodePtr == NULL)
      return;

   // declare a stack of TreeNode pointers
   stack <TreeNode *> s;  

   //declare curr pointer and initalize
   TreeNode *curr = root; 

   while(!s.empty() || curr != NULL)
   {
      if(curr != NULL)
      {
         s.push(curr);
         curr = curr->left;
      }
      else
      {
         TreeNode *n = s.top();
         s.pop();
         curr = n->right;
         delete n; 
      }
   return;
   }

}
   
//***************************************************
// searchNode determines if the item is present in  *
// the subttree rooted at nodePtr. If so, the       *
// function returns true. Otherwise, it returns     *
// false.                                           *
//***************************************************
template <class T>
bool BinarySearchTree<T>::searchNode(TreeNode *nodePtr, T item) const
{

   if(nodePtr == NULL)
   {
      return false;
   }
   
   else
   {
      if(nodePtr->value == item)
      {
      return true;
      }
      else
      {
         if (item < nodePtr->value)
         {
            return searchNode(nodePtr->left, item);
         }
         else
         {
            return searchNode(nodePtr->right, item);
         }
      }  
   }
 

}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree rotted at nodePtr, via inorder traversal.      *
//****************************************************************
template <class T>
void BinarySearchTree<T>::displayInOrder(TreeNode *nodePtr) const
{
  // input treenode pointer

   if(nodePtr == NULL)
      return;

   // declare a stack of TreeNode pointers
   stack <TreeNode *> s; 

   //declare curr pointer and initalize
   TreeNode *curr = root; 

   while(!s.empty() || curr != NULL)
   {
      if(curr != NULL)
      {
         s.push(curr);
         curr = curr->left;
      }
      else
      {
         TreeNode *n = s.top();
         s.pop();
         cout << n->value << endl;
         curr = n->right;
      }
   }
   return;
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree rotted at nodePtr, via preorder traversal.     *
//****************************************************************
template <class T>
void BinarySearchTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
   // input parameter *nodePtr

   if (nodePtr == NULL)
      return; 

   // declare stack of TreeNode Pointers
   stack <TreeNode *> s;  

   //declare TreeNode pointer called curr
   TreeNode *curr; 

   //push root onto the stack
   s.push(root);

   while(!s.empty())
   {
      curr = s.top();
      cout << curr->value << endl;
      s.pop();

      if(curr->right != NULL)
         s.push(curr->right);
      if(curr->left != NULL)
         s.push(curr->left);
   }
   return;
}
#endif