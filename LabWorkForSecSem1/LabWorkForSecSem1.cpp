#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr) {}
};

struct Stack {
    Node* top;  
    Stack() : top(nullptr) {}

    void push_buck(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;  
        top = newNode;       
    }

    void print() {
        printHelper(top);
    }

    void printHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        printHelper(node->next);
        
        if (node->val > 0) {
            cout << node->val << " ";
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
        stack.push_buck(num);  
    }

    cout << "Положительные числа в обратном порядке: ";
    stack.print();  
    cout << endl;

    return 0;
}
