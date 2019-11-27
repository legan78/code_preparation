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
        cout<<temp->data<<"->";
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


Node* partition(Node* root, Node* pivot) {
    //// set pivot to the start of the list
    int daux= root->data;
    root->data= pivot->data;
    pivot->data= daux;

    Node* aux= root->next;
    Node* left=root->next;

    while(aux!=NULL) {
        if(aux->data< root->data) {
            std::cout << "Comparing: " << aux->data << "  with pivot "<< std::endl;
            //// swap node data
            int laux= left->data;
            left->data= aux->data;
            aux->data= laux;

            //// increase the node frontier
            left= left->next;
        }

        aux= aux->next;
    }

    std::cout << left->data<<std::endl;

    return root;
}


void do_partition() {
    Node *head=NULL, *temp=NULL;
    Node *part=NULL;

    for(int i=50;i>=0;i--){
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
    Node* parted= partition(head, part);
    print(parted);
    std::cout << std::endl;

}


int add_list(Node* n1, Node* n2) {
    size_t l1=0, l2=0;
    int cn=1, v1=0, v2=0;

    Node* aux=n1;
    while(aux!=NULL) {
        int n= aux->data;
        aux=aux->next; 
        v1+= (n*cn);
        cn*=10;
    }

    aux=n2;
    cn=1;


    while(aux!=NULL) {
        int n= aux->data;
        aux=aux->next; 
        v2+= (n*cn);
        cn*=10;
    }



    return v1+v2;
}


void add_list() {
    Node* n1= new Node(7);
    n1->next= new Node(1);
    n1->next->next= new Node(6);

    Node* n2= new Node(5);
    n2->next= new Node(9);
    n2->next->next= new Node(2);

    std::cout << add_list(n1, n2) << std::endl;
}

int main() {


    return 0;
}




