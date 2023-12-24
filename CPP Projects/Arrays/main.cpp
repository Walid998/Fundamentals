#include <iostream>

using namespace std;

class Array
{
private:
    int size;
    int length;
    int* items;

public:
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }

    void Fill()
    {
        int noOfItems;
        cout << "How many items you want to fill?\n";
        cin >> noOfItems;
        if(noOfItems > size)
        {
            cout << "You cannot exceed array size";
            return;
        }
        for (int i = 0; i < noOfItems; i++)
        {
            cout << "Enter item no " << i+1 << ": ";
            cin >> items[i];
            length++;
        }
    }

    void Display()
    {
        if(length == 0)
        {
            cout << "Array is empty!";
            return;
        }
        cout << "Array items: \n";
        for(int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }

    int indexOf(int item)
    {
        for(int i = 0; i < length; i++)
        {
            if(items[i] == item)
            {
                return i;
            }
        }
        return -1;
    }

    void Append(int newItem)
    {
        if(length >= size)
        {
            cout << "The array is full\n";
            return;
        }
        items[length] = newItem;
        length++;
    }

    void Insert(int index, int newItem)
    {
        if(length >= size)
        {
            cout << "The array is full" << endl;
            return;
        }
        if(index < 0 || index > size)
        {
            cout << "index out of range" << endl;
            return;
        }


        for (int i = length; i > index; i--)
        {
            items[i] = items[i-1];
        }
        items[index] = newItem;
        length++;
    }

    void Delete(int index)
    {
        if(index < 0 || index > size)
        {
            cout << "index out of range" << endl;
            return;
        }
        for(int i = index; i < length -1; i++)
        {
            items[i] = items[i+1];
        }
        length--;
    }

    void Extend(int newSize){
        if(newSize <= size){
            cout << "New size connot be less than or equal the old size";
            return;
        }
        else{
            size = newSize;
            int* oldItems = items;
            items = new int[size];
            for(int i = 0; i < length; i++){
                items[i] = oldItems[i];
            }
            delete[]oldItems;
        }
    }


    int getSize()
    {
        return size;
    }

    int getLength()
    {
        return length;
    }

};

int main()
{
    int arrsize;
    cout << "Enter Array Size:" << endl;
    cin >> arrsize;
    Array myArray(arrsize);

//    ********** FILL THE ARRAY
    myArray.Fill();
    myArray.Display();
//    ******************

//    ********** SEARCH
//    int searchItem;
//    cout << "Enter Search Item:";
//    cin >> searchItem;
//    int searchResult = myArray.indexOf(searchItem);
//    if(searchResult != -1){
//        cout << "Index of" << searchItem << " is: " << searchResult << endl;
//    }else{
//        cout << "Cannot find index of item: " << searchItem << endl;
//    }
//    ******************

//    ********** APPEND NEW ITEM
    myArray.Append(55);
    myArray.Display();
//    ******************

//    ********** INSERT NEW ITEM
//    cout << "Enter the index of inserted item: " << endl;
//    int insertedItemIndex;
//    cin >> insertedItemIndex;
//    cout << "Enter the item value: " << endl;
//    int insertedItemValue;
//    cin >> insertedItemValue;
//    myArray.Insert(insertedItemIndex, insertedItemValue);
//    myArray.Display();
//    ******************

//    ********** DELETE AN ITEM
//    cout << "Enter the index of deleted item: " << endl;
//    int deletedItemIndex;
//    cin >> deletedItemIndex;
//    myArray.Delete(deletedItemIndex);
//    myArray.Display();
//    ******************

//    ********** Extend Array Size
//    cout << "Enter new array size: " << endl;
//    int newSize;
//    cin >> newSize;
//    myArray.Extend(newSize);
//    cout << "Array size is: " << myArray.getSize() << endl;
//    myArray.Append(5);
//    myArray.Display();
//    ******************


    return 0;
}
