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

int main() {
    
    return 0;
}
