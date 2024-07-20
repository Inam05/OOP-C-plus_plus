/*
Implement a class template for a generic LinkedList. Include methods to add, remove, and search for elements. Ensure proper
handling of edge cases.
*/

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        Node *current = head;
        Node *next;
        while (current)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void add(T val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void remove(T val)
    {
        if (!head)
            return;
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        Node *prev = nullptr;
        while (current && current->data != val)
        {
            prev = current;
            current = current->next;
        }
        if (current)
        {
            prev->next = current->next;
            delete current;
        }
    }

    bool search(T val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();

    list.remove(2);
    list.print();

    cout << "Search 3: " << (list.search(3) ? "Found" : "Not Found") << endl;
    cout << "Search 2: " << (list.search(2) ? "Found" : "Not Found") << endl;

    return 0;
}
