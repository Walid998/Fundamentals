#include <iostream>

using namespace std;

class Node{
public:
    int item;
    Node* next;
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    bool isEmpty(){
        return (head == NULL);
    }

    void appendFirst(int newItem){
        Node* newNode = new Node();
        newNode->item = newItem;
        if(head == NULL){
            newNode->next = NULL;
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void appendLast(int newItem){
        if(isEmpty()){
            appendFirst(newItem);
        }
        else{
            // create temp node
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            Node* newNode = new Node();
            newNode->item = newItem;
            newNode->next = NULL;
            temp->next = newNode;
        }
    }

    void display(){
        cout << "Linkedlist Items: " << endl;
        Node* temp = head;

        while(temp != NULL){
            cout << temp->item << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    int count(){
        int counter = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    bool isfound(int item){
        Node* temp = head;
        while(temp != NULL){
            if(temp->item == item){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    LinkedList lst;
    cout << "list contains " << lst.count() << " elements" << endl;

    int item;
    cout << "append item to the list: " << endl;
    cin >> item;
    lst.appendFirst(item);
    lst.display();

    cout << "append item to the list: " << endl;
    cin >> item;
    lst.appendFirst(item);
    lst.display();

    cout << "append item to the list: " << endl;
    cin >> item;
    lst.appendFirst(item);
    lst.display();

    cout << "Total items in the list is: " << lst.count() << endl;

    cout << "append item as last item: " << endl;
    cin >> item;
    lst.appendLast(item);
    lst.display();

    cout << "append item as last item: " << endl;
    cin >> item;
    lst.appendLast(item);
    lst.display();

    cout << "Total items in the list is: " << lst.count() << endl;


    return 0;
}
