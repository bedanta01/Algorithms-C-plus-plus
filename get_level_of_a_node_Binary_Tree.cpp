#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}

int printLevel(struct node* root,int num){
    if(root == NULL){
        return 0;
    }
    if(root->data == num){
        return 1;
    }
    int l = printLevel(root->left,num);
    int r = printLevel(root->right,num);
    if(l>0){
        return l+1;
    }
    else if(r>0){
        return r+1;
    }
    return 0;
}

int main() {
	struct node *root = new struct node;
    int x;
 
    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    
    cout<<printLevel(root,1)-1;
	return 0;
}