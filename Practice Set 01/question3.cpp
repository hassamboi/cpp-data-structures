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

    //YOUR QUESTION GOES HERE
    void shiftElementsToRightBy(int n)
    {
        if (head == NULL)
            return;

        for (int i = 0; i < n; i++)
        {
            node *tail = getTail();
            tail->next = head;
            node *newTail = getPreviousNode(tail->data);
            head = tail;
            newTail->next = NULL;
        }
    }
};

int main()
{
    SinglyLinkedList list;

    list.addNodeAtTail(6);
    list.addNodeAtTail(7);
    list.addNodeAtTail(8);
    list.addNodeAtTail(9);
    list.addNodeAtTail(10);
    list.addNodeAtTail(11);

    list.display();

    list.shiftElementsToRightBy(3);
    list.display();

    return 0;
}