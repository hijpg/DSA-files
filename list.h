#include<iostream>
using namespace std;

class List;

class Node{
    int data;

public:
    Node* next;
    Node(int d) : data(d), next(NULL){}
    int getdata(){
        return data;
}

    friend class list;
};

class List{
    Node * head;
    Node * tail;

public:
    Node * begin(){
        return head;
    }

   List() : head(NULL), tail(NULL){}

    void push_front(int data){
        if(head==NULL){
            Node * n = new Node(data);
            head = tail = n;
        }
        else{
            Node * n = new Node(data);
            n->next = head;
            head = n;
        }
    }   

    void push_back(int data){

        if(head==NULL){
            Node * n = new Node(data);
            head = tail = n;
        }
        else{
            Node * n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }
    
    void reverse(Node*head){
        Node*Curr = head;
        Node*Prev = NULL;
        Node*Next;

        while(Curr!=NULL){
        // save the next node
            Next = Curr->next;
        // Make the current node point to prev.
            Curr->next = Prev;
        // Update P and C, take them 1 step forward.
            Prev = Curr;
            Curr = Next;
        }
        head = Prev;
    }
};
