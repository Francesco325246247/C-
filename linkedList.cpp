#include <iostream>

typedef void vd;
using namespace std;


struct container { //base struct with two parameters
    int pkg; //integer declaration
    container* nextContainer; //pointer declaration to the nextContainer address position
};

// only for the first container
vd initFirstContainer(struct container *top,int n){ //here initialize the first container
    top->pkg = n; //point gets the member called pkg from the struct that top point to
    top->nextContainer = nullptr;//point gets the member called nextContainer from the struct that top point to
}

// appending
vd addcontainer(struct container *top, int n) { // this function take a pointer and an integer n
    auto *newcontainer = new container; //create a new container
    newcontainer->pkg = n;  //point gets the member called pkg from the struct that newcontainer point to
    newcontainer->nextContainer = nullptr; //point gets the member called nextContainer from the struct that top point to

    container *ptr = top;     //initialize a struct pointer to top variable
    while(ptr != nullptr) {  //while there is other top to point at in O(n)
        if(ptr->nextContainer == nullptr) { //if point gets the member called nextContainer from the struct that ptr point to in O(1)
            ptr->nextContainer = newcontainer; //point gets the member called nextContainer from the struct that ptr point to
            return;
        }
        ptr = ptr->nextContainer; //ptr assigned to the point that gets the member called nextContainer from the struct that top point to
    }
}

struct container *srccontainer(struct container *top, int n) { //search for a container take two parameters  pointer and value
    container *ptr = top; //initialize ptr pointer to top
    while(ptr != nullptr) {   // O(n)
        if(ptr->pkg == n) return ptr; //if point gets the member called nextContainer from the struct that ptr point to in O(1)
        ptr = ptr->nextContainer; //ptr assigned to the point that gets the member called nextContainer from the struct that top point to
    }

}

bool delcontainer(struct container **top, container *ptrDel) { //in O(1) pointer-to-pointer
    container *ptr = *top; //point gets the member called nextContainer from the struct that ptr point to
    if(ptrDel == *top) {
        *top = ptr->nextContainer;
        delete ptrDel; //delete ptrDel
        return true;
    }

    while(ptr != nullptr) {// in O(n)
        if(ptr->nextContainer == ptrDel) {
            ptr->nextContainer = ptrDel->nextContainer;
            delete ptrDel;
            return true;
        }
        ptr = ptr->nextContainer;
    }
    return false;
}

vd delLinkedList(struct container **container) //pointer-to-pointer
{
    struct container *tmpcontainer; //create a pointer tmpcontainer
    while(*container != nullptr) { //and while the pointer is not point to nullptr
        tmpcontainer = *container; //copy the container into a temporary container
        *container = tmpcontainer->nextContainer; //the container pointer assigned the value to the instance pointer of tmpcontainer inside struct to the next container
        delete tmpcontainer; //deallocate memory from the free-store
    }
}

vd show(struct container *top) {
    container *list = top;
    while(list != nullptr) {
        cout << list->pkg << " ";
        list = list->nextContainer;
    }
}

int main()
{
    struct container *newtop;
    auto *top = new container;
    initFirstContainer(top,5);

}
