#include<iostream>
#include <random>

using namespace std;

const int SIZE = 5;
/*
Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot,
while all elements with values greater than the pivot come after it (equal values can go either way).
*/

int Partition(int vector1[], int start, int end) { //In this line: function take a vector input and integers start and end.
    int swap = rand()%2;
    int pivot;
    if(swap == 1){
         pivot = vector1[start];
    }else{
         pivot = vector1[end];
    }
    int startb = start, index = 0;//In this line: declare the variables, startb at the first cycle is 0 ..
    // ... pivot is the first of the vector element and index is initialized at value 0;

    //time complexity O(n-1)
    for (index = start + 1; index <=end; index++) {//In this line: the index is initialized at the starting position + one element and increase ...
        //...of one until it does not reach the value of end.
        if (pivot > vector1[index]) { //In this line: the if statement check if he pivot is bigger than the array index.
            vector1[startb] = vector1[index];//In this line: copy the position at index.
            vector1[index] = vector1[startb + 1];//this line: copy the next element of startb.
            vector1[startb + 1] = pivot;//this line: the position of startb + 1 take the initial value of the pivot.
            startb = startb + 1;//this line: increments the startb of one.
        }
    }
    return startb;//this line:return the start be that will be used for the next value of end.
}

//print function
void print(int vector1[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "[" << vector1[i] << "]";
    }
}

//sorting function it is recursive
//time complexity O(n)
void QuickSort(int vector1[], int start, int end) { //In this line: take an array and two integers.
    if (start < end) { //In this line: boolean comparator, check if start is smaller than end.
        int p = Partition(vector1, start,
                          end); //In this line: the integer declared p take the value of startb (+1 at every turn).
        QuickSort(vector1, start, p - 1); //In this line: the input value of end change according to p -> startb.
        QuickSort(vector1, p + 1, end); //In this line:the input value of start change according to p -> startb.
    }
}

int main() {
    int vector1[] = {55, 44, 2, 1, 65};
    int start = 0, end = 4;
    QuickSort(vector1, start, end);
    print(vector1, end);
    return 0;
}
