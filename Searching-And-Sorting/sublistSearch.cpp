/**
 * C++ program to find a list in a second list
 * -> Search a linked list in another linked list
 */
#include <bits/stdc++.h>
using namespace std;

// A linked list node
struct _node {
    int data;
    _node* next;
};

// function to print nodes in a given linked list
void printList(_node* node) {
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

// function to add new node to a linked list
_node *newNode(int key) {
    _node *temp = new _node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

bool findList(_node *a, _node *b) {
    _node *tempA, *tempB;
    tempA = a;
    tempB = b;

    if(a == NULL || b == NULL)
        return false;

    while(tempA != NULL && tempB != NULL) {
        if(tempA->data == tempB->data) {
            tempA = tempA->next;
            tempB = tempB->next;
        } else {
            tempA = a;
            tempB = b = b->next;
        }
    }

    if(tempA == NULL)
        return true;

    return false;
}

// driver code
int main() {
    // creating two linked lists to test above functions
    _node *a = newNode(1);
    a->next = newNode(2);
    a->next->next = newNode(3);

    _node *b = newNode(1);
    b->next = newNode(1);
    b->next->next = newNode(2);
    b->next->next->next = newNode(3);
    b->next->next->next->next = newNode(3);

    // a is the list to identified in list b
    findList(a, b) ? printf("list A is found in list B") : printf("list A is not found in B");
}