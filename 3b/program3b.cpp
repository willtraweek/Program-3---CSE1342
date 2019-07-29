#include <iostream>
#include "LinkList.h"

using namespace std;

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
