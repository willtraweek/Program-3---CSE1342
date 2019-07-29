#include "Node.h"

#ifndef LINKLIST_H
#define LINKLIST_H



class LinkList {

public:
    LinkList();
    ~LinkList();

    void add(int value);
    void display();
    void remove(int index);

private:
    Node * head;
};

#endif 