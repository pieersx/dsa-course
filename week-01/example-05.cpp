// Crea una cola e inserta un elemento.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

bool empty(Node *front)
{
    return front == nullptr;
}

void enqueue(Node *&front, Node *&rear, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (empty(front)) {
        front = newNode;
    } else {
        rear->next = newNode;
    }

    rear = newNode;
}

void display(Node *front)
{
    Node *current = front;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "Null" << endl;
}

int main()
{
    Node *front = nullptr;
    Node *rear = nullptr;
    int value;

    cout << "Introzca un valor: ";
    cin >> value;
    enqueue(front, rear, value);

    cout << "Introduzca otro valor: ";
    cin >> value;
    enqueue(front, rear, value);

    cout << "Introduzca otro valor: ";
    cin >> value;
    enqueue(front, rear, value);

    display(front);

    return 0;
}
