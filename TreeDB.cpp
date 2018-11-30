
#include <iostream>
#include <string>
#include "TreeDB.h"
#include "DBentry.h"
#include "TreeNode.h"
#include <string>

using namespace std;

    TreeDB::TreeDB(){
        root = NULL;
        
    }
    
    void TreeDB::delete_tree(TreeNode* myroot){
        if(myroot == NULL) return;
        
        delete_tree(myroot->getLeft());
        
        delete_tree(myroot->getRight());
        
        delete myroot;
    }
    
    DBentry* TreeDB::findHelper(TreeNode* my_root, string name){
        probesCount++;
        if(my_root != NULL){
            if(my_root->getEntry()->getName() == name)
                return my_root->getEntry();
            else if(name > my_root->getEntry()->getName()){
                
                findHelper(my_root->getLeft(),name);
            }
            else if(name < my_root->getEntry()->getName()){
                findHelper(my_root->getRight(),name);
            }
            else if(my_root->getLeft() == NULL && my_root->getRight() == NULL)
                return nullptr;
        }
        else{
            return nullptr;
        }
    }
    
    TreeNode * findHelperRemove(TreeNode *my_root,TreeNode * &delNodeLeft,TreeNode * &delNodeRight,string name){ //use this function to get the preceding node
        if(my_root != NULL){
            if(my_root->getLeft()->getEntry()->getName() == name){
                delNodeLeft = my_root->getLeft();
                return my_root;
            }
            else if(my_root->getRight()->getEntry()->getName() == name){
                delNodeRight = my_root->getRight();
                return my_root;
            }
            else if(name > my_root->getEntry()->getName()){
                
                findHelperRemove(my_root->getLeft(),delNodeLeft,delNodeRight,name);
            }
            else if(name < my_root->getEntry()->getName()){
                findHelperRemove(my_root->getRight(),delNodeLeft,delNodeRight,name);
            }
            else if(my_root->getLeft() == NULL && my_root->getRight() == NULL)
                return nullptr;
        }
        else{
            return nullptr;
        }
    }
    
 void TreeDB::insertHelper(TreeNode* p) {
 if (p == NULL) return; // Nothing to insert
 if (root == NULL) { // basis
root = p; root->setLeft (NULL); root->setRight(NULL);
return;
 }
 // Helper function to facilitate the recursion
 insert_bst(p, root);
}
 
 void TreeDB::insert_bst(TreeNode* p, TreeNode* r) {
 if (p->getEntry() == r->getEntry()) return;
 if (p->getEntry() < r->getEntry()) {
 if (r->getLeft() == NULL) {
 r->setLeft(p);
 return;
 }
 else insert_bst(p, r->getLeft());
 }
 if (p->getEntry() > r->getEntry()) {
 if (r->getRight() == NULL) {
 r->setRight(p);
 return;
 }
 else insert_bst(p, r->getRight());
 }
}

 

   // the destructor, deletes all the entries in the database.
   TreeDB::~TreeDB(){
       if(root == NULL)
           return;
       
       
       delete_tree(root);
       
       
       
       
       
       
   }

   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB::insert(DBentry* newEntry){
       TreeNode l(newEntry);
       
       TreeNode * k = &l;
       
       //first search through the whole tree
       //if any node has the name don't include
       //else insert the node probably in any of the nodes.
       //how to pull of search algorithm without helper function?
       if((find(newEntry->getName())) == nullptr)
           return false;
       else{
           insertHelper(k);
           return true;
           
   
       }
       
       
       
 
 
} 
       
       
       
    

   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* TreeDB::find(string name){
       
       //if();
       //should I just use a for loop?
       //no, use recursion for this function
       //so base case is if right and left are null
       //through each iteration find the name? 
       //use or for the final results 
       return findHelper(root,name);
       
       //search through the whole array
       
   }
   
   

   // deletes the entry with the specified name (key)  from the database.
   // If the entry was indeed in the database, it returns true.
   // Returns false otherwise.
   // See section 6 of the lab handout for the *required* removal method.
   // If you do not use that removal method (replace deleted node by
   // maximum node in the left subtree when the deleted node has two children)
   // you will not match exercise's output.
   bool TreeDB::remove(string name){
     
       //how does the remove function work
       
       
       
       
       
       
       
       
       
       
   }
   
   bool TreeDB::removeHelper(TreeNode* my_root, string name){
       TreeNode *ptr0; // points to the parent node 
       TreeNode *ptrleft = nullptr; // points to the node to be deleted if left
       TreeNode *ptrright = nullptr; //points to the node to be deleted if right
       
       ptr0 = findHelperRemove(my_root,ptrleft,ptrright,name);
       
       
       
       //now do the four cases
       //case where deleting a leaf
       
       
       //case where deleted node is right child and only one child
       if(ptrleft == nullptr){
           if(ptrright->getLeft() == nullptr)//in this case the right child exist left is null
               ptr0->setRight(ptrright->getRight());
           else if(ptrright->getRight() == nullptr )
               ptr0->setRight(ptrright->getLeft()); //set any child of the right node to be the right child
       }
       //case where the deleted node is the left and only child
       if(ptrright == nullptr){
           if(ptrleft->getLeft() == nullptr)
               ptr0->setLeft(ptrleft->getRight());
           else if(ptrleft->getRight() == nullptr)
               ptr0->setLeft(ptrleft->getLeft()); 
       }
       
       //
               
           
           
       }
           
     
      
           
           
       
       
       
       
       
       
       
   
   
   
	
   // deletes all the entries in the database.
   void TreeDB::clear(){
       
       delete_tree(root);
       //similar to destructor
       
       
       
   }
    
   // prints the number of probes stored in probesCount
   void TreeDB::printProbes() const{
       cout<<probesCount<<endl;
       
       
       
       
   }
   
   void TreeDB::countActiveHelper(TreeNode* myroot, int& count) const{
      //int countActive = 0;
      
      if(myroot == NULL)
          return;
      countActiveHelper(myroot->getLeft(),count);
      
      if(myroot->getEntry()->getActive() == true)
      count++;
      
      countActiveHelper(myroot->getRight(),count);
      
   }
   
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   void TreeDB::countActive () const{
       
       int count = 0; 
       countActiveHelper(root,count);
       cout<<count<<endl;
               
       
       
       
   }

   // Prints the entire tree, in ascending order of key/name
 //  friend ostream& operator<< (ostream& out, const TreeDB& rhs);
