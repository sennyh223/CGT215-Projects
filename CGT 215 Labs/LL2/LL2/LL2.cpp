// LL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

int main()
{
    Node* headPtr(NULL);
    Node* currentPtr(NULL);
    int in = 1;
    cout << "Enter positive numbers one per line, negative to stop " << endl;
    while (in > 0) {
        cout << "? ";
        cin >> in;
        if (in > 0) {
        Node* newNode = new Node();
        newNode->value = in;
        newNode->next = NULL;
        if (headPtr == NULL) {
            headPtr = newNode;
            }
        else {
            currentPtr->next = newNode;
        }
            currentPtr = newNode;
        }
    }
    currentPtr = headPtr;
    while (currentPtr = NULL) {
        cout << currentPtr->value<< endl;
        currentPtr = currentPtr->next;
    }

}


