#include<iostream>
#include "Hashing.h"
using namespace std;


int main()
{
    Hashtable<int> h;
    h.insert("Mango", 120);
    h.insert("Orange", 60);
    h.insert("Apple", 200);
    h.insert("Grapes", 140);
    // h.insert("Bhindi", 40);
    // h.insert("Karela", 20);
    h.erase("Grapes");
    h.print();

    // string fruit;
	// cin>>fruit;

	// int *price = h.search(fruit);
	// if(price!=0){
	// 	cout<< "Price of fruit is "<< *price <<endl;
	// }
	// else{
	// 	cout<<"Fruit is not present";
	// }

	// //Supercool functionality!
	// h["newFruit"] = 200;
	// cout<<"New fruit cost : "<<h["newFruit"]<<endl;
	// h["newFruit"] += 20;

	// cout<<"New fruit updated cost : "<<h["newFruit"]<<endl;

    return 0;
}