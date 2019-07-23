#include <iostream>

using namespace std;

class Node {

public:
    Node(){
        next = nullptr;
    }

    ~Node(){
    }

    int getValue(){ return this->value; }
    void setValue(int value){ this->value = value; }
    Node* getNext(){ return next; }
    void setNext(Node * next){ this->next = next; }

private:
    int value;
    Node * next;
};

class LinkList {

public:
    LinkList(){
        head = new Node();
    }

    ~LinkList(){
        Node * current;
        Node * next = head->getNext();

        // TODO: Properly de-allocate memory from the heap
    }

    void add(int value){
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

    void display(){
        Node * temp = head->getNext();
        while(temp != nullptr){
            cout << temp->getValue() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    
	}

    void remove(int index){
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

private:
    Node * head;
};

int main(){

    /*
    0 1 2 3 4 5
    1 2 3 4 5
    1 3 4 5
    1 3 4
    ERROR: index for removal is beyond the end of the list
    1 3 4
    */

    LinkList list;

    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    list.display(); // 0 1 2 3 4 5

    list.remove(0); // removes first index

    list.display(); // 1 2 3 4 5

    list.remove(1); // removes second index

    list.display(); // 1 3 4 5

    list.remove(3); // removes fourth index

    list.display(); // 1 3 4

    list.remove(9); // error

    list.display(); // 1 3 4

    return 0;
}
