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

    // ~Node(){
    //     if(next!=NULL){
    //         delete next;
    //     }
    //     cout<<"deleting Node "<<getdata()<<endl;
    // }
    friend class list;
};

class List{
    Node * head;
    Node * tail;

    int helper(Node*start, int key){
    // base case
        if(start==NULL){
            return -1;
        }
    // value matches at start
        if(start->getdata() == key){
            return 0;
        }
    // recursive call
    int subIdx = helper(start->next, key);
        if(subIdx == -1) return -1;
        return subIdx+1;
    }

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

     void insert(int data, int pos){
        
        if(pos==0){
            push_front(data);
            return;
        } 
        
        // otherwise
        Node* temp = head;
        for(int jump=0; jump<pos-1; jump++){
            temp = temp->next;
        }

        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

   bool search(int key){  // Search the element

    Node*temp = head;
    while(temp!=NULL){
        if(temp->getdata() == key) return true;
        temp = temp->next;
    }
    return false;
}

    int searchIndex(int key){  // Search the index at which element is present.

    Node*temp = head;
    int idx=0;
    while(temp!=NULL){
        if(temp->getdata() == key){
            return idx;
        }
        idx++;
        temp = temp->next;
    }
    return -1;
}

    bool SearchRec(Node*head, int key){  // Search the element recursively

        // Node*temp = head;
        if(head == NULL) return false;

        // rec case
        if(head->getdata()==key) {
            return true;
        }
        else
        return SearchRec(head->next, key);
}


int SearchIndexRec(int key){  // Search the index at which element is present recursively.

        int idx = helper(head,key);
       return idx;
}

    void pop_front(){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void remove(int pos){
        Node*temp = head->next;
        Node*n = temp->next;
        for(int i=2; i<pos-1; i++){
            temp = temp->next;
            n=n->next;
        }
        temp->next = n->next;

        delete n;
    }

    void pop_back(){
        Node*temp = head->next;
            Node*n = temp->next;
        while(temp !=NULL){
            n=n->next;
        }
    delete n;

    }

// Deleting LL
    // ~List(){
    //     if(head!=NULL){
    //         delete head;
    //         head = NULL;
    //     }
    // }

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
