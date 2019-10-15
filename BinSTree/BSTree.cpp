/*
 * Binary Search Tree class
 * Do not alter the display() function, this will break the Repl.it
 * tests
 */

#include <iostream>
#include <cstdlib>
#include "BSTree.h"

using namespace std;



/*
 * Find Element in the Tree
 * find a node by item_key and provide an updated parent node
 *   pointer and location node pointer
 */



void BST::find(int item_key, node **prnt, node **loc)
{
    node *ptr, *ptrsave;
    if (root == nullptr)
    {
        *loc = nullptr;
        *prnt = nullptr;
        return;
    }
    if (item_key == root->key_value)
    {
        *loc = root;
        *prnt = nullptr;
        return;
    }
    if (item_key < root->key_value)
        ptr = root->p_left;
    else
        ptr = root->p_right;
    ptrsave = root;
    while (ptr != nullptr)
    {
        if (item_key == ptr->key_value)
        {
            *loc = ptr;
            *prnt = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item_key < ptr->key_value)
            ptr = ptr->p_left;
        else
            ptr = ptr->p_right;
    }
    *loc = nullptr;
    *prnt = ptrsave;
}

node* BST:: GetNewNode(int data) {
    node* newNode = new node();
    newNode->key_value = data;
    newNode->p_left = nullptr;
    newNode->p_right = nullptr;

    return newNode;
}



/*
 * Inserting Element into the Tree
 */
node* BST::insert(node **tree, node *newnode) {

    if (*tree == nullptr) {
        *tree = GetNewNode(newnode->key_value);
        return *tree;
    }
    //recursively calls to insert left node
    else if (newnode->key_value <= (*tree)->key_value) {
        (*tree)->p_left = insert(&((*tree)->p_left), newnode);
    }

    //recursively calls to insert right node
    else {
        (*tree)->p_right = insert(&((*tree)->p_right), newnode);
    }

    return *tree;
}


node* BST:: FindMin(node* tree) {

    node* current = tree;

    /* loop down to find the leftmost leaf */
    while (current->p_left != nullptr) {
        current = current->p_left;
    }

    return current;

}

node* BST::LowestLeft( node* place)
{
    struct node* thisOne = place;

    while (thisOne->p_left != nullptr)
        thisOne = thisOne->p_left;

    return thisOne;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
node* BST::remove(node* tree, int num)
{

    if (tree == nullptr){
        return tree;
    }

    if (num < tree->key_value) {

        if (tree->p_left == nullptr) {
            cout << "Item not present in tree" << endl;
        }
        else {
            tree->p_left = remove(tree->p_left, num);
        }

    }

    else if (num > tree->key_value) {

        if (tree->p_right == nullptr) {
            cout << "Item not present in tree" << endl;
        }
        else {
            tree->p_right = remove(tree->p_right, num);
        }

    }

    else {

        if (tree->p_left == nullptr) {
            node *temp = tree->p_right;
            free(tree);
            return temp;
        }
        else if (tree->p_right == nullptr)
        {
            struct node *temp = root->p_left;
            free(tree);
            return temp;
        }

        struct node* temp = LowestLeft(tree->p_right);
        tree->key_value = temp->key_value;
        tree->p_right = remove(tree->p_right, temp->key_value);
    }
    return tree;
}

/*
 * Case 0
 * the node is simply removed no other updates necessary.
 */
void BST::case_0(node *prnt, node *loc )
{
    /*
    //if (we are at the root)
    {
        //update the root
    }
    else
    {
        // otherwise simply remove node
    }
     */
}

/*
 * Case 1
 * We have only one child so promote the child and replace the target
 * node
 */
void BST::case_1(node *prnt, node *loc)
{
    /*
    node *child;
    //if (the child is on the left?)
    //point left
    // else  // must be the right side has child
    // point right
    //if (we are at the root handle specialy)
    {
        // update the root
    }
    else
    {
        //if (the node is left child of parent)
        //promote the left
        //else // the node is right of parent
        //    promote right
    }
     */
}

/*
 * Case case_2
 * We have to find and promote a successor or predecessor
 */
void BST::case_2(node *prnt, node *loc)
{
    /*
    // temporary pointers for node we are manipulating

    // Find successor: Step to the right child
    // Find the min of the subtree on parent's right

    //if (found node has no children)
    // Replace the target node with the successor node
    else
    // Temporarily remove the successor node by replacing it with
    // its right child, we will replace the node we are removing
    // with the successor we just removed.

    //if (we are at root)
    {
        //then update root
    }
    else
    {
        // Insert the successor node where the target node we
        //   are removing is located
    }
    // then update the successor child pointers to reflect the old
    //     target's child pointers.
     */
}


/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != nullptr)
    {
        display(ptr->p_right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->key_value;
        display(ptr->p_left, level+1);
    }
}

