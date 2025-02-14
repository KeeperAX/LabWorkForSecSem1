#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr) {}
};

struct List
{
    Node* first;  //Node* second;
    List() : first(nullptr){};

    void push_buck(int value) {
        Node* newNode = new Node(value);
       if (!first) {
            first = newNode; 
            return;
        }
        Node* temp = first;
        while (temp->next) {
            temp = temp->next; 
        }
        temp->next = newNode; 
        //newNode->next = first; 
        //first = newNode; 
    }

    void print() {
        Node* temp = first;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

    }

    void pop() {
        if (!first) {
            return;
        }
        Node* temp = first; 
        first = first->next; 
        delete temp; 
    }


    
    void sort() {
        bool swap;
        do {
            swap = false;
            Node* current = first;
            Node* nextNode = first->next;

            while (nextNode) {
                if (current->val > nextNode->val) {
                    
                    swap(current->val, nextNode->val);
                    swap = true; 
                }
                current = nextNode;
                nextNode = nextNode->next;
            }
        } while (swap); 
    }

    void Reverse() {
        List positiveList; 
        Node* temp = first;

        while (temp) {
            if (temp->val > 0) { 
                positiveList.push_buck(temp->val); 
            }
            temp = temp->next;
        }

        positiveList.print(); 
    }
};

int main()
{
    List arr;
    short num = 1;
    while (true)
    {
        cin >> num;
        if (num != 0)
        {
            arr.push_buck(num);
        }
        else { break; }
    }
    cout << "Исходный список: ";
	arr.print();
    arr.sort();
    cout << "\nОтсортированные список: ";
    arr.Reverse();

   
    return 0;
}


