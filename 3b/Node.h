#ifndef NODE_H
#define NODE_H

class Node {

public:
    Node();
    ~Node();

    int getValue();
    void setValue(int value);
    Node* getNext();
    void setNext(Node * next);

private:
    int value;
    Node * next;
};

#endif 