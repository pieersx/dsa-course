// Crea una cola e inserta un elemento.

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *front;
    Node *rear;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
};

bool empty(Node *front)
{
    return front == nullptr;
}

void enqueue(Queue &q, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (q.rear == nullptr) {
        q.front = newNode;
        q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

void dequeue(Queue &q)
{
    if (empty(q.front)) {
        cout << "La cola está vacía." << endl;
        return;
    }

    Node *temp = q.front;
    q.front = q.front->next;

    if (empty(q.front)) {
        q.rear = nullptr;
    }

    delete temp;
}

void display(Queue &q)
{
    if (empty(q.front)) {
        cout << "La cola está vacía." << endl;
        return;
    }

    Node *current = q.front;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "Null" << endl;
}

int main()
{
    Queue queue;
    int choice;

    do {
        int value;
        cout << "\n1. Insertar elemento (enqueue)";
        cout << "\n2. Eliminar elemento (dequeue)";
        cout << "\n3. Mostrar cola";
        cout << "\n4. Salir";
        cout << "\n\n-> Elige una opción: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Introduce el valor a insertar: ";
            cin >> value;
            enqueue(queue, value);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida. Intenta de nuevo." << endl;
        }

    } while (choice != 4);

    return 0;
}
