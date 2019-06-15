#include<iostream> 
#include<fstream>
#include<Math.h>
using namespace std; 
  
// An AVL tree node  
typedef struct Node  
{  
    string fjala;  
    Node *left;  
    Node *right;  
    int lartesia;  
}Node;  
  
  
  
  
// A utility function to get maximum 
// of two integers  
  
  
// A utility function to get the  
// height of the tree  
int lartesia(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->lartesia;  
}  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
Node* krijoNyje(string fjala)  
{  
    Node* node = new Node();   
 	node->fjala=fjala;
    node->left = NULL;  
    node->right = NULL;  
    node->lartesia = 1; // new node is initially 
                      // added at leaf  
    return node;  
}  
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
Node *rrotulloDjathtas(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update lartesias  
    y->lartesia = max(lartesia(y->left), 
                    lartesia(y->right)) + 1;  
    x->lartesia = max(lartesia(x->left), 
                    lartesia(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node *rrotulloMajtas(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update lartesias  
    x->lartesia = max(lartesia(x->left),     
                    lartesia(x->right)) + 1;  
    y->lartesia = max(lartesia(y->left),  
                    lartesia(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return lartesia(N->left) - lartesia(N->right);  
}  
  
// Recursive function to add a key 
// in the subtree rooted with node and 
// returns the new root of the subtree.  
Node* add(Node* node, string fjala)  
{  
    /* 1. Perform the normal BST addion */
    if (node == NULL)  
        return(krijoNyje(fjala));  
  
    if (fjala.compare(node->fjala)<0)  
        node->left = add(node->left,fjala);  
    else if (fjala.compare(node->fjala)>0)  
        node->right = add(node->right,fjala);  
    else // Equal keys are not allowed in BST  
        return node;  
  
    /* 2. Update lartesia of this ancestor node */
    node->lartesia = 1 + max(lartesia(node->left),  
                        lartesia(node->right));  
  
    /* 3. Get the balance factor of this ancestor  
        node to check whether this node became  
        unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then  
    // there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && fjala.compare(node->left->fjala)<0)  
        return rrotulloDjathtas(node);  
  
    // Right Right Case  
    if (balance < -1 && fjala.compare(node->right->fjala)>0)  
        return rrotulloMajtas(node);  
  
    // Left Right Case  
    if (balance > 1 && fjala.compare(node->left->fjala)>0)  
    {  
        node->left = rrotulloMajtas(node->left);  
        return rrotulloDjathtas(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && fjala.compare(node->right->fjala)<0)  
    {  
        node->right = rrotulloDjathtas(node->right);  
        return rrotulloMajtas(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  
  
// A utility function to print afisho  
// traversal of the tree.  
// The function also prints lartesia  
// of every node  
void afisho(Node *root)  
{  
    if(root != NULL)  
    {  
          
        afisho(root->left); 
		cout << root->fjala << " "; 
        afisho(root->right);  
    }  
}  
  
// Driver Code 
int main()  
{  
    Node *root = NULL;  
       fstream in;
	in.open("skedar.txt",ios::in);
	string a;
	while(!in.eof()){
		in>>a;
		root=add(root,a);
	} 
    afisho(root);  
      
    return 0;  
}  
  
