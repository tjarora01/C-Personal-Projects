/*
 * C++ Program To Implement BST
 */
#ifndef BSTREE_H
#define BSTREE_H


/*
 * Node Declaration
 */
struct node
{
    int key_value;
    struct node *p_left;
    struct node *p_right;
};

/*
 * Class Declaration
 */
class BST
{
public:
    node* root;
    void find(int, node **, node **);
    node* GetNewNode(int data);
    node* FindMin( node* node);
    node* insert(node **, node *);
    //node* remove(node** root, int data);
    void case_0(node *,node *);
    void case_1(node *,node *);
    void case_2(node *,node *);
    void display(node *, int);

    node* LowestLeft( node* node);
    node* remove(struct node* root, int key);

    BST()
    {
        root = nullptr;
    }
};


#endif	//BSTREE_H

