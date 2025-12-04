#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next;
};


QueueNode* Front = nullptr;
QueueNode* Rear  = nullptr;

void EnQueue(int value) {
    QueueNode* node = new QueueNode;
    node->data = value;
    node->next = nullptr;

    if (Front == nullptr) {
        Front = Rear = node;
    } else {
        Rear->next = node;
        Rear = node;
    }
}

int DeQueue() {
    if (Front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    QueueNode* temp = Front;
    int value = temp->data;

    Front = Front->next;
    delete temp;

    if (Front == nullptr) Rear = nullptr;

    return value;
}

void Queue_Display() {
    if (Front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }

    QueueNode* cur = Front;

    cout << "Queue Elements: ";
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next) cout << " <- ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n----------- Queue Menu -----------\n";
        cout << "1 : EnQueue (Add)\n";
        cout << "2 : DeQueue (Remove)\n";
        cout << "3 : Queue Display\n";
        cout << "4 : Exit\n";
        cout << "----------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                EnQueue(value);
                break;

            case 2:
                value = DeQueue();
                if (value != -1)
                    cout << "Removed element: " << value << endl;
                break;

            case 3:
                Queue_Display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice, try again.\n";
        }

    } while (choice != 4);

    return 0;
}

