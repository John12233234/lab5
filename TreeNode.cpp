// A useful constructor

#include "TreeNode.h"
#include "DBentry.h"
#include <string>





    TreeNode::TreeNode(DBentry* _entryPtr){
        
        entryPtr = _entryPtr;
        left = NULL;
        right = NULL;
        
        
        
        
    }

    // the destructor
    TreeNode::~TreeNode(){
        
        delete entryPtr;
        //do i delete right and left?
        entryPtr = NULL;
     
                }

    // sets the left child of the TreeNode.
    void TreeNode::setLeft(TreeNode* newLeft){
        
        left = newLeft;
        
    }

    // sets the right child of the TreeNode
    void TreeNode::setRight(TreeNode* newRight){
        
        right = newRight;
        
    }

    // gets the left child of the TreeNode.
    TreeNode* TreeNode::getLeft() const{
        return left;
        
    }

    // gets the right child of the TreeNode
    TreeNode* TreeNode::getRight() const{
        return right;
        
    }

    // returns a pointer to the DBentry the TreeNode contains. 
    DBentry* TreeNode::getEntry() const{
        return entryPtr;
        
    }
