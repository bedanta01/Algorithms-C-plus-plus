#include <iostream>
using namespace std;

int level=1;

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

int printatlevel(struct node* root,int curr_level){
    if(root==NULL){
        return 0;
    }
    if(curr_level==level){
        cout<<root->data;
        return 0;
    }
    curr_level++;
    printatlevel(root->left,curr_level);
    printatlevel(root->right,curr_level);
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
    
    printatlevel(root,0);
	return 0;
}