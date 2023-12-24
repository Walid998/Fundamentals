#include <iostream>

using namespace std;

class Queue{
private:
    int size;
    int length;
    int* elements;
public:
    Queue(int queueSize){
        size = queueSize;
        length = 0;
        elements = new int[size];
    }

    void enqueue(int newElement){
        if(length >= size){
            cout << "The Queue is Full" << endl;
            return;
        }
        elements[length] = newElement;
        length++;
    }

    void dequeue(){
        if(length == 0){
            cout << "The Queue is Empty";
            return;
        }
        for(int i = 0; i < length-1; i++){
            elements[i] = elements[i+1];
        }
        length--;
    }

    void display(){
        cout << "Queue Elements: " << endl;
        for(int i = 0; i < length; i++){
            cout << elements[i] << "\t";
        }
        cout << endl;
    }
};

int main()
{
    int queueSize;
    cout << "Enter the queue size: " << endl;
    cin >> queueSize;
    Queue myQueue(queueSize);
    int newItem;
    for(int i = 0; i < queueSize; i++){
        cin >> newItem;
        myQueue.enqueue(newItem);
    }
    myQueue.display();

    cout << "Dequeue .. " << endl;
    myQueue.dequeue();
    myQueue.display();

    cout << "Dequeue .. " << endl;
    myQueue.dequeue();
    myQueue.display();

    return 0;
}
