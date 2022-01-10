#include<iostream>
#include "list.h"
using namespace std;
 
int main()
{
    List l;
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_front(0);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);
   

    Node *head=l.begin();
   
     while(head!=NULL){
        cout<<head->getdata()<<"->";

        head=head->next;
    }
    cout<<endl;

    l.reverse(head);
    
    while(head!=NULL){
        cout<<head->getdata()<<"->";

        head=head->next;
    }

 return 0;
}


