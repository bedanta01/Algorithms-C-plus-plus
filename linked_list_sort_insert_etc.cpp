#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

/*void MergeSort(struct node**headref){
    struct node* a;
    struct node* b;
    struct node *head = *headref;

    split(head,&a,&b);

    MergeSort(&a);
    MergeSort(&b);

    *head = merge(&a,&b);
}

void split(struct node* head,struct node** a,struct node** b){
    struct node* slow;
    struct node* fast;

    if(head==NULL || head->next==NULL){
        *a = head;
        *b = NULL;
    }
    else{
        slow = head;
        fast = head->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast->next!=NULL){
                slow = slow->next;
            }
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }

}

void merge(struct node* a,struct node* b){
    s
}*/

void reverse(struct node** head){
    struct node** temp = head;

    struct node* prev = *head;
    struct ndoe* curr = (*head)->next;

    *head = curr;

    while()

}

void insertFront(struct node** head,int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void insertBack(struct node** head,int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    struct node* temp = *head;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;

}
void print(struct node* head){
    struct node* temp = head;
    do{
        cout<<temp->data<<"-->";
        temp=temp->next;
    }while(temp!=NULL);
    cout<<"NULL";
}

int main(){
    struct node* head = NULL;
    insertBack(&head,5);
    insertFront(&head,3);
    insertFront(&head,4);
    insertFront(&head,2);
    insertBack(&head,6);
    insertBack(&head,7);
    insertBack(&head,115);
    reverse(&head);
    //MergeSort(&head);
    print(head);
}
