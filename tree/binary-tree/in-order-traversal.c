//pre-order: root-> left subtree -> right subtree
//post-order : left subtree -> right subtree -> root
//in-order : left subtree -> root -> right subtree

//in-order
//left subtree  -> root -> right subtree

/*
                4
              /   \
             1     6
            /  \     
           5    2  

        [ [5 1 2] 4 6 ]  
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 //creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in heap
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n; // return node
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        //left subtree -> root -> right subtree
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);

    return 0;
}
