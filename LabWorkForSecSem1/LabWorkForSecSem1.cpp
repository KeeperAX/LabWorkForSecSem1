#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr) {}
};

struct Stack {
    Node* head;
    Stack() : head(nullptr) {}

    void push_back(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        printHelper(head);
    }

    void printHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        printHelper(node->next);

        if (node->val > 0) {
            cout << node->val << "->";
        }
    }

    ~Stack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Stack stack;
    int num;

    cout << "Введите числа (0 для завершения ввода):" << endl;
    while (true) {
        cin >> num; 
        if (num == 0) {
            break;
        }
        stack.push_back(num);
    }

    cout << "Положительные числа в обратном порядке: ";
    stack.print();
    cout << endl;

    return 0;
}
