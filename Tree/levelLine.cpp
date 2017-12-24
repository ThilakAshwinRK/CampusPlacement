// refer this http://ideone.com/0Xfy8E our pgm

// C program for recursive level order traversal in spiral form
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <iostream>
#include <queue>
using namespace std; 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Function protoypes */
//void printGivenLevel(struct node* root);
//struct node* newNode(int data);
void printGivenLevel(struct node* root)
/*{
// Base Case
    if (root == NULL)  return;
 
    // Create an empty queue for level order tarversal
    queue<node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}*/

{   
if(root==NULL) return;
  
   queue<node *> q;
   q.push(root);
   while(1)
  {
      printf("\n");
   int  count=q.size();
    printf("count %d : ",count);
       if(count==0)
             break;
          while(count>0)
            {
                 node* node=q.front();
                cout<<node->data<<" ";
                q.pop();
                 
                if(node->left!=NULL)
                  q.push(node->left);
               if(node->right!=NULL)   
                  q.push(node->left);
            count--;
             }

  }
}
 
struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printGivenLevel(root);
 
    return 0;
}

