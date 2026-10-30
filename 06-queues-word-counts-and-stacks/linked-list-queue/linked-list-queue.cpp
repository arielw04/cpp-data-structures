#include <iostream>
using namespace std;

// Define QueueNode struct
struct QueueNode {
    int data;
    QueueNode* next;
};

// Define Queue struct
struct Queue {
    QueueNode* front;
    QueueNode* rear;

    // Constructor to initialize pointers
    Queue() : front(nullptr), rear(nullptr) {}
};

// Function to check if the queue is empty
bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

// Function to enqueue a value into the queue
void enqueue(Queue* q, int value) {
    QueueNode* newNode = new QueueNode();
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue a value from the queue
bool dequeue(Queue* q, int& value) {
    if (isEmpty(q)) {
        return false;
    }

    QueueNode* temp = q->front;
    value = temp->data;
    q->front = q->front->next;

    if (q->front == nullptr) {
        q->rear = nullptr;
    }

    delete temp;
    return true;
}

// Function to display the queue contents
void display(const Queue* q) {
    if (isEmpty(q)) {
        cout << "*** Current items in queue: (Empty)" << endl;
        return;
    }

    cout << "*** Current items in queue: ";
    QueueNode* current = q->front;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Function to free all memory allocated for the queue
void freeQueue(Queue* q) {
    int temp;
    while (dequeue(q, temp)) {
        // Dequeue all elements and free memory
    }
    cout << "Delete all elements from queue." << endl;
}

// Main function with interactive menu
int main() {
    Queue queue;
    char choice;
    int value;

    do {
        display(&queue);
        cout << "Options: (e)nqueue, (d)equeue, (f)ree, (t)erminate: ";
        cin >> choice;

        switch (choice) {
        case 'e': // Enqueue
            cout << "Enters the value: ";
            cin >> value;
            enqueue(&queue, value);
            break;

        case 'd': // Dequeue
            if (dequeue(&queue, value)) {
                cout << "(Removed " << value << " from queue)" << endl;
            }
            else {
                cout << "Cannot dequeue, the queue is empty!" << endl;
            }
            break;

        case 'f': // Free queue
            freeQueue(&queue);
            break;

        case 't': // Terminate
            cout << "Exit the program, and delete all elements." << endl;
            freeQueue(&queue);
            break;

        default: // Invalid option
            cout << "Invalid option, enter again!" << endl;
            break;
        }
    } while (choice != 't');

    return 0;
}
