// This program tests the BinarySearchTree class template.
// Feel free to modify it since you will not submit it.
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
   // Creates an empty binary search tree that stores ints.
   BinarySearchTree<int> tree;

   // Testing insert function
   cout << "Testing the insertNode function:" << endl;
   cout << "Inserting 50" << endl;
   tree.insertNode(50);
   // The binary search tree should now look like this:
   //             50
   cout << "Inserting 25" << endl;
   tree.insertNode(25);
   // The binary search tree should now look like this:
   //            50
   //          /    
   //        25
   cout << "Inserting 65" << endl;
   tree.insertNode(65);
   // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   cout << "Inserting 10" << endl;
   tree.insertNode(10);
      // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   //       /
   //     10
   cout << "Inserting 35" << endl;
   tree.insertNode(35);
      // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   //       /  \    
   //     10   35
   cout << "Inserting 60" << endl;
   tree.insertNode(60);
      // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   //       /  \    /  \
   //     10   35  60
   cout << "Inserting 80" << endl;
   tree.insertNode(80);
      // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   //       /  \    /  \
   //     10   35  60  80
   cout << "Inserting 55" << endl;
   tree.insertNode(55);
      // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   //       /  \    /  \
   //     10   35  60  80
   //             /  
   //            55
   cout << "Inserting 70" << endl;
   tree.insertNode(70);
      // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   //       /  \    /  \
   //     10   35  60  80
   //             /    /
   //            55   70
   cout << "Inserting 58" << endl;
   tree.insertNode(58);
   // The binary search tree should now look like this:
   //            50
   //          /    \
   //        25      65
   //       /  \    /  \
   //     10   35  60  80
   //             /    /
   //            55   70
   //              \
   //              58

   cout << endl;
   cout << "Testing the displayInOrder function:" << endl;
   tree.displayInOrder();
   cout << endl;

   // Testing the displayPreOrder function
   cout << "Testing the displayPreOrder function:" << endl;
   tree.displayPreOrder();
   cout << endl;

   // Testing the search function
   // Searches that return TRUE
   cout << "Testing the search function" << endl;
   cout << "Searching for 50...Result: " << tree.search(50) << endl;
   cout << "Searching for 25...Result: " << tree.search(25) << endl;
   cout << "Searching for 65...Result: " << tree.search(65) << endl;
   cout << "Searching for 10...Result: " << tree.search(10) << endl;
   cout << "Searching for 35...Result: " << tree.search(35) << endl;
   cout << "Searching for 60...Result: " << tree.search(60) << endl;
   cout << "Searching for 80...Result: " << tree.search(80) << endl;
   cout << "Searching for 55...Result: " << tree.search(55) << endl;
   cout << "Searching for 70...Result: " << tree.search(70) << endl;
   cout << "Searching for 58...Result: " << tree.search(58) << endl;

   // Searches that return FALSE
   cout << "Searching for 62...Result: " << tree.search(62) << endl;
   cout << "Searching for 12...Result: " << tree.search(12) << endl;
   cout << "Searching for 1 ...Result: " << tree.search(1) << endl;
   cout << "Searching for 27...Result: " << tree.search(27) << endl;
   cout << endl;

   cout << "Deconstructing the tree...calling destroySubTree(root)." << endl;
   return 0;
}