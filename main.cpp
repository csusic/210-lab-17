// COMSC-210 | Lab 17 | Christine Susic

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addFrontNode(); //adding a node to the front
void addTailNode(); //adding a node to the tail
void deleteNode(); //deleting a node
void insertNode(); //inserting a node
void deleteList(); //deleting the entire linked list

int main() {
    Node *head = nullptr;
    int count = 0;

    addFrontNode(); //adding a node to the front
    addTailNode(); //adding a node to the tail
    deleteNode(); //deleting a node
    insertNode(); //inserting a node
    deleteList(); //deleting the entire linked list

    return 0;
}

//adding a node to the front
void addFrontNode() {
/*ADD NODE TO HEAD START*/
    Node *head = nullptr;
    int count = 0;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);
};

//adding a node to the tail
void addTailNode() {
/*ADD NODE TO TAIL START*/
    Node *head = nullptr;
    int count = 0;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        
        Node *newVal = new Node;
        Node *ptr = nullptr;
        newVal->value = tmp_val;
        newVal->next = nullptr;
        
        // adds node at tail
        if (!head) { // if this is the first node, it's the new tail
            head = newVal;
        }
        else { // its a second or subsequent node; place at the tail
            
        }
    }
    output(head);
}; 

//deleting a node
void deleteNode() {
/*DELETE NODE START*/
    Node *head = nullptr;
    int count = 0;
    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}; 

//inserting a node
void insertNode() {
/*INSERT NODE START*/
    Node *head = nullptr;
    int count = 0;
    Node * current = head;
    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node * prev = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}; 

//deleting the entire linked list
void deleteList() {
/*DELETE LINKED LIST START*/
    Node *head = nullptr;
    int count = 0;
    Node * current = head;
    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}; 

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}