#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class SinglyLinkedList
{
private:
    node *head;

public:
    SinglyLinkedList() : head(NULL) {}
    ~SinglyLinkedList()
    {
        node *iter = head;
        head = NULL;
        node *iterNext = NULL;

        while (iter != NULL)
        {
            iterNext = iter->next;
            delete iter;
            iter = iterNext;
        }
    }

private:
    node *createNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

    node *getTail()
    {
        node *iter = head;

        while (iter->next != NULL)
            iter = iter->next;

        return iter;
    }

    node *searchKeyNode(int key)
    {
        node *iter = head;

        while (iter != NULL)
        {
            if (iter->data == key)
                return iter;

            iter = iter->next;
        }

        return NULL;
    }

    node *getPreviousNode(int key)
    {
        node *iter = head;

        while (iter->next != NULL)
        {
            if (iter->next->data == key)
                return iter;

            iter = iter->next;
        }

        return NULL;
    }

public:
    void addNodeAtTail(int value)
    {
        if (head == NULL)
        {
            head = createNode(value);
            return;
        }

        node *tail = getTail();
        node *append = createNode(value);
        tail->next = append;
    }

    void push(int value)
    {
        if (head == NULL)
        {
            head = createNode(value);
            return;
        }

        node *prepend = createNode(value);
        prepend->next = head;
        head = prepend;
    }

    void insertAtValue(int key, int value)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        node *keyNode = searchKeyNode(key);
        if (keyNode == NULL)
        {
            cout << "The key was not found" << endl;
            return;
        }
        node *append = createNode(value);
        append->next = keyNode->next;
        keyNode->next = append;
    }

    void deleteNode(int key)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        node *keyNode = searchKeyNode(key);

        if (keyNode == NULL)
        {
            cout << "The key was not found" << endl;
            return;
        }

        if (keyNode == head)
        {
            head = head->next;
            delete keyNode;
            keyNode = NULL;
        }

        else
        {
            node *prevNode = getPreviousNode(key);
            prevNode->next = keyNode->next;
            delete keyNode;
            keyNode = NULL;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }

        node *iter = head;
        while (iter != NULL)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    int getListLength()
    {
        node *iter = head;
        int lengthCount = 0;

        while (iter != NULL)
        {
            lengthCount++;
            iter = iter->next;
        }

        return lengthCount;
    }

    //THE QUESTION GOES HERE
    string checkListSortOrder()
    {
        if (head == NULL)
            return "list is empty";

        int ascendingCount = 1;
        int descendingCount = 1;

        node *prevNode = head;
        node *currentNode = head->next;

        while (currentNode != NULL)
        {
            if (prevNode->data <= currentNode->data)
                ascendingCount++;

            if (prevNode->data >= currentNode->data)
                descendingCount++;

            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        int listLength = getListLength();

        if ((ascendingCount == descendingCount))
            return "Equal / Unsorted";

        else if (ascendingCount >= listLength)
            return "Ascending";

        else if (descendingCount >= listLength)
            return "Descending";

        else
            return "Unsorted";
    }
};

int main()
{
    SinglyLinkedList list;

    list.addNodeAtTail(3);
    list.addNodeAtTail(3);
    list.addNodeAtTail(3);
    list.addNodeAtTail(3);
    list.addNodeAtTail(6);
    // list.addNodeAtTail(1);
    // list.addNodeAtTail(6);

    list.display();

    cout << list.checkListSortOrder() << endl;

    return 0;
}
