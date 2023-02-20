#include <iostream>
//#include <malloc.h>
//#include <locale.h>
using namespace std;

struct Node {  // узел
    char data;
    Node *nextPtr;
};

struct Queue {  // очередь
    int size;
    Node *first;
    Node *last;
};

int maximum, k = 0;

void createQ(Queue *Q);
int getSize(Queue *Q);
bool isEmpty(Queue *Q);
void printQ(Queue *Q);
void addNode(Queue *Q, int info);
void menuQ();


int main() {
    char etalon, value;
    cout << "Etalon element: "; cin >> etalon;
    cout << "Size of queue: "; cin >> maximum;

    Queue Q;
    Queue QPtr = Q;
    createQ(&QPtr);
    int choice;

    menuQ();
    cin >> choice;
    while (choice != 4) {
        switch(choice) {
            case 1:
                cout << "Insert symbol: "; cin >> value;
                if (value == etalon) {
                    cout << "Etalon inserted!\n\n";
                    printQ(&Q);
                    break;
                } else {
                    addNode(&QPtr, value);
                    break;
                }
            case 2:
                printQ(&Q);
                break;
            case 3:
                cout << getSize(&Q) << endl << endl;
                break;
            default:
                cout << "Incorrect choice, try again\n";
                menuQ();
                break;
        }
        menuQ();
        cout << "Choice:"; cin >> choice;
    }
    return 0;
}

void menuQ() {
    cout << "1 - Add element\n2 - Print queue\n3 - size of queue\n4 - exit\n\n";
}

void printQ(Queue *Q) {   // выводим все содержимое
    if (!isEmpty(Q)) {
        Node *temp;
        temp = Q->first->nextPtr;
        cout << "Queue\n";
        for (int i = 0; i < getSize(Q); i++) {
            cout << " | " << temp->data << " | ";
            temp = temp->nextPtr;
        }
        cout << " |\n\n";
    } else {
        cout << "Queue is empty\n\n";
    }
}

void addNode(Queue *Q, int info) {  // вставляем новый символ в стек
    if (k < maximum) {  // проверяем, чтобы в стеке еще было место
        Q->last->nextPtr = new Node;
        Q->last = Q->last->nextPtr;
        Q->last->data = info;
        Q->last->nextPtr = NULL;
        Q->size++;
        k++;
    } else {
        cout << info << " access denied\n";
    }
}

void createQ(Queue *qPtr) {  // создает ПУСТУЮ очередь
    qPtr->first = new Node;  // создаем новый узел
    qPtr->first->nextPtr = NULL;  // ссылка на следующий - NULL
    qPtr->last = qPtr->first;  // "границы" очереди
    qPtr->size = 0;  // размер 0 (потому что пустая)
}

bool isEmpty(Queue *Q) {
    return Q->first == Q->last;
}

int getSize(Queue *Q) {
    return Q->size;
}
