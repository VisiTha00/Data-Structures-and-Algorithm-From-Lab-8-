#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef chrono::microseconds MSEC;
typedef chrono::high_resolution_clock HRC;

class Stack {
private:
    int* arr;   /* Creating a pointer for the array*/
    int arrSize;  /* maximum number of elements that can be in the array*/
    int topElement;    /*index number of the top element*/
public:
    Stack(int sizeOfTheArr) {
        arrSize = sizeOfTheArr;
        arr = new int[sizeOfTheArr];
        topElement = -1;
    }

    void push(int value) {
        if (isFull()) {    /*checking whether the array is full*/
            cout << "Stack Overflow\n";
        }
        else {
            topElement = topElement + 1;
            arr[topElement] = value;    /*pushing the element to the array*/
        }
    }
    int pop() {
        if (isEmpty()) {     /*checking whether the array is empty*/
            cout << "Stack Underflow\n";
            return -1;
        } else {
            int poppedElement = arr[topElement];
            topElement = topElement - 1;
            return poppedElement;    /* returning the popping element*/
        }
    }

    bool isEmpty() {     /*this will return whether the array is empty or not*/
        if(topElement != -1){
            return false;
        }
        else{
            return true;
        }
    }

    bool isFull() {       /*this will return whether the array is full or not*/
        if(topElement == arrSize - 1){
            return true;
        }
        else{
            return false;
        }
    }

    int stackTop() {    /* this will return the top element in the stack*/
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            return arr[topElement];
        }
    }

    void display() {     /*this method prints the elements in the array*/
        if (isEmpty()) {
            cout << "Stack is empty\n";
        }
        else {
            cout << "Elements of the stack are :- ";
            for (int i = topElement; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    srand(time(NULL));
    auto start = HRC::now();

    Stack myStack(10);
    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);
    myStack.push(23);
    myStack.push(6);
    myStack.push(18);
    myStack.push(20);
    myStack.push(17);
    myStack.display();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.display();
    myStack.push(4);
    myStack.push(30);
    myStack.push(3);
    myStack.push(1);
    myStack.display();

    auto end = HRC::now();
    auto exec_time = chrono::duration_cast<MSEC>(end-start);
    cout << "Execution time = "<<exec_time.count()<<" microseconds"<<endl;

    return 0;
}
