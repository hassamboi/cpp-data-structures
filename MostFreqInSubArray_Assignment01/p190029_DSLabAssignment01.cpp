#include <iostream>
using namespace std;

class List
{
private:
    int *arr;
    int *current;
    int *end;
    int size;

public:
    List(int s = 0)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            *(arr + i) = 0;
        }
        current = arr; //set to start
        end = arr + (size - 1);
    }

    ~List()
    {
        delete[] arr;
    }

    //CURRENT PTR MOVEMENT - USED FOR ADD METHOD
    /*void start()
    {
        current = arr;
    }

    void tail()
    {
        current = end;
    }

    void next()
    {
        if (current == end)
            cout << "Error: End of the list" << endl;

        else
            current++;
    }

    void back()
    {
        if (current == arr)
            cout << "Error: Beginning of the list" << endl;
        else
            current--;
    }*/

    //displaying list
    void display();

    void add(int num);
    void mostFrequentElementsInSubArray(int left, int right, int frequency);
};

//displaying the list
void List::display()
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";

    cout << endl;
}

void List::add(int num)
{
    int *temp = NULL;
    temp = end;

    while (temp != current)
    {
        *temp = *(temp - 1);
        temp--;
    }

    *current = num;
    if (current != end)
        current++;
}

void List::mostFrequentElementsInSubArray(int left, int right, int frequency)
{
    bool condition = (0 <= left && left <= right && right < size) && (2 * frequency >= right - (left + 1));

    if (!condition)
    {
        cout << "The condition wasn't met, returning." << endl;
        return;
    }

    int tempSize = (right - left) + 1; // e.g: 3-0 + 1 = 4
    int *tempArr = new int[tempSize];  // new int [4] -> [0 1 2 3]
    int temp;

    //COPYING ELEMENTS OF LIST TO A TEMP ARRAY
    for (int i = 0; i < tempSize; i++)
        *(tempArr + i) = *(arr + left + i);

    //ASCENDING SORTING OF TEMP ARRAY
    for (int i = 0; i < tempSize; i++)
    {
        for (int j = i + 1; j < tempSize; j++)
        {
            if (*(tempArr + i) > *(tempArr + j))
            {
                temp = *(tempArr + i);
                *(tempArr + i) = *(tempArr + j);
                *(tempArr + j) = temp;
            }
        }
    }

    int currCount = 1;
    int j = 0;

    cout << "The most frequent elements in sub array are: ";

    for (int i = 0; i < tempSize; i++)
    {
        j = i + 1;
        while ((*(tempArr + i) == *(tempArr + j)) && j < tempSize)
        {
            i++;
            j++;
            currCount++;
        }
        if (currCount >= frequency)
        {
            cout << *(tempArr + i) << " ";
            condition = false; //condition false in case of items
        }
        currCount = 1;
    }

    //condition true in case of no items
    if (condition)
        cout << "NO ITEM";

    cout << endl;
    delete[] tempArr;
}

int main()
{
    List *list = new List(8);

    list->add(2);
    list->add(3);
    list->add(2);
    list->add(3);
    list->add(3);
    list->add(4);
    list->add(5);
    list->add(6);

    list->mostFrequentElementsInSubArray(0, 3, 1);

    list->display();

    delete list;

    return 0;
}