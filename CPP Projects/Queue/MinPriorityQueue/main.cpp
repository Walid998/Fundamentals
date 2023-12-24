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

    int findMin(){
        int index;
        int minElement = elements[0];
        for(int i = 0; i < length; i++){
            if(minElement > elements[i]){
                minElement = elements[i];
                index = i;
            }
        }
        return index;
    }

    void dequeue(){
        int minIndex = findMin();
        for(int i = minIndex; i < length-1; i++){
            elements[i] = elements[i+1];
        }
        length--;
    }

    void display(){
        if(length == 0){
            cout << "Queue is Empty!!" << endl;
        }
        for(int i = 0; i < length; i++)
            cout << elements[i] << "\t";

        cout << endl;
    }
}
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

    cout << "Dequeue .. " << endl;
    myQueue.dequeue();
    myQueue.display();

    cout << "Dequeue .. " << endl;
    myQueue.dequeue();
    myQueue.display();

    cout << "Dequeue .. " << endl;
    myQueue.dequeue();
    myQueue.display();


    return 0;
}
