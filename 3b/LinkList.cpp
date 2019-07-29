#include <iostream>
#include "LinkList.h"

using namespace std;

LinkList::LinkList(){
    head = new Node();
}

LinkList::~LinkList(){
    Node * current;
    Node * next = head->getNext();

    delete current;
}

void LinkList::add(int value){
    Node * current = head;

    // iterate until we get to the end of the list
    while(current->getNext() != nullptr){
        current = current->getNext();
    }

    // now create a new Node
    Node * newNode = new Node();
    newNode->setValue(value);
    current->setNext(newNode);
}

void LinkList::display(){
    Node * temp = head->getNext();
    while(temp != nullptr){
        cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    cout << endl;

}

void LinkList::remove(int index){
    Node * current = head->getNext();
    Node * previous = head;
    // first set the pointer to the appropriate index
    for(int i = 0; i < index; i++){
        if(current->getNext() == nullptr){
            cout << "ERROR: index for removal is beyond the end of the list" << endl;
            return;
        }
        else{
            previous = current;
            current = current->getNext();
        }
    }

    // now that we are pointing at the appropriate index, we remove the element
    Node * next = current->getNext();
    previous->setNext(next);
    delete current;
}