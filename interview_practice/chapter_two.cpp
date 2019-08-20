#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
  static int counter;
  int data;
  int id;
  struct Node *next;
  Node(int x) {
    data = x;
    id= counter;
    counter++;
    next = NULL;
  }
};

int Node::counter=0;

void print(Node *root) {
    Node *temp = root;
    while(temp!=NULL) {
        cout<<temp->id<<"->";
        temp=temp->next;
    }
}

// Function to remove duplicates from the linked list
// root: root of the linked list
Node *removeDuplicates(Node *root)
{
 // your code goes here
    if(root==NULL) return root;
    
    Node* ptr= root;
    while(ptr!=NULL) {
        Node* aux= ptr->next;
        Node* prev= ptr;
        while(aux!=NULL) {
            if(ptr->data == aux->data) {
                std::cout << "deletion of node "<< aux->id<<std::endl;
                Node* temp=aux;
                prev->next= aux->next;
                aux= prev->next;
                delete temp;
            } else {
                  aux=aux->next;
                  prev=prev->next;
            }
        }
        ptr=ptr->next;
    }

    return root;
}

void remove_duplicates() {
    // your code goes here
    int T;
    cin>>T;
    
    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;
 
        for(int i=0;i<K;i++){
            int data;
            cin>>data;
            if(head==NULL)
                head=temp=new Node(data);
            else {
                temp->next = new Node(data);
                temp=temp->next;
            }
        }

        Node *result  = removeDuplicates(head);
        print(result);
        //cout<<endl;
        
    }
}

Node* get_m_to_end(Node* root, long int m_to_end) {
    long int list_length=0;
    Node* aux=root;
    /// compute the length of the list
    while(aux!=NULL) {
        list_length++;
        aux= aux->next;
    }
    aux=root;

    long int node_position= list_length-m_to_end;
    if(node_position<0) return root;

    /// Move to get the last    
    for(size_t i=0; i<node_position-1; i++)
        aux=aux->next;

    return aux;
}


void get_m_to_last(){
    Node* root= NULL;
    int numbers[]= {1, 2,3 ,4 ,5 ,6 ,7 ,8 ,9, 10};

    root=new Node(numbers[0]);
    Node* aux=root;

    for(size_t i=1; i<10; i++){
        aux->next= new Node(numbers[i]);
        std::cout << aux->data << std::endl;
        aux=aux->next;
    }

    std::cout << root->data << std::endl;
    std::cout << get_m_to_end(root, 5)->data << std::endl;

}


void partition(Node* root, Node* pivot) {

    Node* aux= root;
    Node* left=NULL;
    Node* right=NULL;
    Node* left_aux= NULL;
    Node* right_aux= NULL;


    while(aux!=NULL) {
        if(aux==pivot){ aux=aux->next; continue;} /// not comparing itself
        // std::cout << "The value of the aux is: "<< aux->data <<std::endl;

        if(pivot->data > aux->data) {
            if(left==NULL) {
                left=aux;
                left_aux=aux;
            } else {
                left_aux->next=aux;
                left_aux=aux;
            }
        } else {
            if (right==NULL) {
                right=aux;
                right_aux=aux;
            } else {
                right_aux->next=aux;
                right_aux=aux;
            }
        print(right);
        std::cout<<std::endl;
        }
        aux= aux->next;
    }

    right_aux->next=NULL;
    left_aux->next=pivot;
    pivot->next= right;
    root= left;
}


int main() {
    Node *head=NULL, *temp=NULL;
    Node *part=NULL;

    for(int i=10;i>=0;i--){
        if(head==NULL)
            head=temp=new Node(i);
        else {
            temp->next = new Node(i);
            temp=temp->next;
        }
        if(i==5) part=temp;
    }

    print(head);
    std::cout << "\nPartition around: " <<part->data <<std::endl;
    partition(head, part);
    print(head);
    std::cout << std::endl;



    return 0;
}
