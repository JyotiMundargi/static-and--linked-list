#include <iostream>
using namespace std;
  //for static list
class StaticList 
{
private:
    static const int MAX_SIZE = 50;
    int array[MAX_SIZE];
    int size;

public:
    StaticList() 
    {
        size = 0;
    }

    void insert(int value) 
    {
        if (size < MAX_SIZE)
         {
            array[size++] = value;
        } else 
        {
            cout << "List is full, cannot insert more elements." << endl;
        }
    }

    void display()
     {
        cout << "Static List: ";
        for (int i = 0; i < size; ++i) 
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// Linked List 
class Node 
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
 {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) 
    {

    }

    void insert(int value)
     {
        Node* newNode = new Node(value);
        if (!head)
         {
            head = newNode;
        } else
         {
            Node* temp = head;
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
     {
        cout << "Linked List: ";
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList()
     {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr)
         {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

int main() 
{
    // for Static List
    StaticList staticList;
    staticList.insert(1);
    staticList.insert(2);
    staticList.insert(3);
    staticList.display();

    // for Linked List
    LinkedList linkedList;
    linkedList.insert(10);
    linkedList.insert(20);
    linkedList.insert(30);
    linkedList.display();

    return 0;
}