#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef chrono::microseconds MSEC;
typedef chrono::high_resolution_clock HRC;

class Node {
public:
    int value;       /*creating fields for a node*/
    Node* next;
};

class Stack {
private:
    Node* topNode;      /*creating a pointer for the top element*/
public:
    Stack() {
        topNode= NULL;
    }
    void push(int insertedValue) {      /*this will push the element into the linked list*/
        Node* newNode = new Node();
        newNode->value = insertedValue;
        newNode->next = topNode;
        topNode = newNode;
    }
    int pop() {
        if (isEmpty()) {      /*checking whether the linked list is empty*/
            cout << "Stack Underflow\n";
            return -1;
        } else {
            Node* poppedNode = topNode;
            int poppedElement = poppedNode->value;
            topNode = topNode->next;
            delete poppedNode;
            return poppedElement;
        }
    }
    bool isEmpty() {      /*this will return whether the linked list is empty or not*/
        if(topNode == NULL){
            return true;
        }
        else{
            return false;
        }

    }

    int stackTop() {     /*this method returns the top element of the stack*/
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            return topNode->value;
        }
    }
    void display() {     /*this method prints the elements in the linked list*/
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            cout << "Elements of the stack :- ";
            Node* currentNode = topNode;
            while (currentNode != NULL) {
                cout << currentNode->value << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main() {
    srand(time(NULL));
    auto start = HRC::now();

    Stack myStack;
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
