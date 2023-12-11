#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class doublylist
{
private:
    Node *head;
    Node *tail;

public:
    doublylist()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void insert_head(int val)
    {
        Node *temp = new Node(val);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void insert_tail(int val)
    {
        Node *temp = new Node(val);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void remove_first_element()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;

            if (head->next == nullptr)
            {
                delete temp;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
        }
    }
    void remove_last_element()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = tail;

            if (tail->prev == nullptr)
            {
                // If there is only one element in the list.
                delete temp;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                // If there are more than one element in the list.
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
        }
    }
    void print()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};
int main(){
    doublylist list;

    int choice, value;

    do {
        cout << "1. Insert at Head"<<endl;
        cout << "2. Insert at Tail"<<endl;
        cout << "3. Remove First Element"<<endl;
        cout << "4. Remove Last Element"<<endl;
        cout << "5. Print List"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                list.insert_head(value);
                break;

            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                list.insert_tail(value);
                break;

            case 3:
                list.remove_first_element();
                break;

            case 4:
                list.remove_last_element();
                break;

            case 5:
                cout << "Doubly Linked List: ";
                list.print();
                break;

            case 0:
                cout << "Exiting program"<<endl;
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 0);
    return 0;
}