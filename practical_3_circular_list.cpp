#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
class Circular_List{
   private:
    Node* tail;

public:
    Circular_List() {
        tail = NULL;
    }
    ~Circular_List() {
        clear_list();
    }
    void insertNode(int element, int d) {
        if (tail == NULL) {
            Node* newNode = new Node(d);
            tail = newNode;
            newNode->next = newNode;
        }
        else {
            Node* curr = tail;

            while (curr->data != element) {
                curr = curr->next;
            }
            Node* temp = new Node(d);
            temp->next = curr->next;
            curr->next = temp;
        }
    }
    void print() {
        Node* temp = tail;
        if (tail == NULL) {
            cout << "List is Empty" << endl;
            return;
        }

        do {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != temp);

        cout << endl;
    }
    void deleteNode(int value) {
        if (tail == NULL) {
            cout << "List is empty, please check again" << endl;
            return;
        }
        else {
            Node* prev = tail;
            Node* curr = prev->next;

            while (curr->data != value) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;

            if (curr == prev) {
                tail = NULL;
            }
            else if (tail == curr) {
                tail = prev;
            }

            curr->next = NULL;
            delete curr;
        }
    }
    Node* searchNode(int value) {
        if (tail == NULL) {
            cout << "List is Empty" << endl;
            return NULL;
        }

        Node* temp = tail->next;

        do {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        } while (temp != tail->next);

        return NULL;
    }
    void clear_list() {
        if (tail != NULL) {
            delete tail;
            tail = NULL;
        }
    }
};
int main(){
    Circular_List list;
    Node* foundNode = nullptr;
    int choice;

    do {
        cout << "\nCircular Linked List Menu"<<endl;
        cout << "1. Insert Node"<<endl;
        cout << "2. Print List"<<endl;
        cout << "3. Delete Node"<<endl;
        cout << "4. Search Node"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int element, data;
                cout << "Enter the element after which you want to insert the node: ";
                cin >> element;
                cout << "Enter the data for the new node: ";
                cin >> data;
                list.insertNode(element, data);
                break;

            case 2:
                cout << "Current List: ";
                list.print();
                break;

            case 3:
                int deleteValue;
                cout << "Enter the value of the node you want to delete: ";
                cin >> deleteValue;
                list.deleteNode(deleteValue);
                break;

            case 4:
                int searchValue;
                cout << "Enter the value you want to search in the list: ";
                cin >> searchValue;
                foundNode = list.searchNode(searchValue);
                if (foundNode != NULL) {
                    cout << "Node with value " << searchValue << " found at address: " << foundNode << endl;
                } else {
                    cout << "Node with value " << searchValue << " not found in the list" << endl;
                }
                break;

            case 5:
                cout << "Exiting the program. Goodbye"<<endl;
                break;

            default:
                cout << "Invalid choice"<<endl;
        }
    } while (choice != 5);
   return 0;
}
