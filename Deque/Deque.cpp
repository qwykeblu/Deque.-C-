// Deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node
{
    int mData;
    Node* pPrev, *pNext;
    Node()
    {
        this->mData = mData;
        pPrev = pNext = NULL;
    }
    Node(int value)
    {
        mData = value;
        pPrev = pNext = NULL;
    }
};

class Deque
{
private:
    Node *pFront, *pRear;
    int mSize;
public:
    Deque()
    {
        pFront = pRear = NULL;
        mSize = 0;
    }
    void pushFront(int data)
    {
        Node* newNode = new Node(data);
        if (newNode == NULL)
        {
            cout << "Error";
        }
        else
        {
            if (pFront == NULL)
            {
                pRear = pFront = newNode;
            }
            else
            {
                newNode->pNext = pFront;
                pFront->pPrev = newNode;
                pFront = newNode;
            }
            mSize++;
        }
    }
    void pushLast(int data)
    {
        Node* newNode = new Node(data);
        if (newNode == NULL)
        {
            cout << "Error";
        }
        else
        {
            if (pRear == NULL)
            {
                pFront = pRear = newNode;
            }
            else
            {
                newNode->pPrev = pRear;
                pRear->pNext = newNode;
                pRear = newNode;
            }
            mSize++;
        }
    }
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
        }
        else
        {
            Node* temp = pFront;
            pFront = pFront->pNext;

            if (pFront == NULL)
            {
                pRear = NULL;
            }
            else
            {
                pFront->pPrev = NULL;
            }
            free(temp);
            mSize--;
        }
    
    }
    void deleteLast()
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
        }
        else
        {
            Node* temp = pRear;
            pRear = pRear->pPrev;

            if (pRear == NULL)
            {
                pFront = NULL;
            }
            else
            {
                pRear->pNext = NULL;
            }
            free(temp);
            mSize--;
        }
    }
    int getFront() 
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
        }
        else
        {
        return pFront->mData;
        }

    }
    int getLast() 
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
        }
        else
        {
            return pRear->mData;
        }

    }
    void swap() 
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
        }
        else
        {
            Node* temp = pFront;
            while (temp->pNext != NULL) {
                temp = temp->pNext;
            }
            Node* tmp2 = new Node();
            tmp2->mData = temp->mData;
            temp->mData = pFront->mData;
            temp->pNext = NULL;
            pFront->mData = tmp2->mData;
        }

    }
    bool isEmpty()
    {
        return (mSize == 0);
    }
    int getSize()
    {
        return mSize;
    }
    void reverse()
    {
        Node* cur = pFront;
        Node* prev, * next = NULL;
        if (isEmpty())
        {
            cout << "Deque is empty";
        }
        else
        {
            Node* cur = pFront;
            while (cur != NULL)
            {

            }
        }
    
    }
    bool isBelong(int data) 
    {
        Node* temp = pFront;
        while (temp != NULL)
        {
            if (data == temp->mData)
            {
                return true;

            }
            temp = temp->pNext;
        }
        return false;
    }
    void clear()
    {
        pRear = NULL;
        while (pFront != NULL)
        {
            Node* temp = pFront;
            pFront = pFront->pNext;
            delete temp;
        }
        pFront = NULL;
        mSize = 0;
    }
    void show()
    {
        Node* node = pFront;
        while (node != NULL) 
        {
            cout << node->mData << " ";
            node = node->pNext;
        }
    }
};

int main()
{
    Deque deque; int num;

    while (true)
    {
        int choice;
        cout << "Greetings!" << endl;//(changed title)
        cout << "\n0.Exit.\n1.Insertion(head).\n2.Insertion(rear).\n3.Deletion(head).\n4.Deletion(rear).\n5.Get head.\n6.Get rear.\n7.Check emptyness.\n8.Check size.\n9.Clear deque.\n10.Swap front and rear.\n11.Check belonginess.\n";

        cin >> choice;
        switch (choice) 
        {
        case 0: return 0;
        case 1:
            cout << "Insertion to head - input value : "; cin >> num;
            deque.pushFront(num);
            deque.show();
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Insertion to rear - input value : "; cin >> num;
            deque.pushLast(num);
            deque.show();
            system("pause");
            system("cls");
            break;
        case 3:

            deque.deleteFront();
            deque.show();
            system("pause");
            system("cls");
            break;
        case 4:
            deque.deleteLast();
            deque.show();
            system("pause");
            system("cls");
            break;
        case 5:
            if (deque.isEmpty())
            {
                cout << "Deque is empty";
            }
            else
            {
            cout << "First element of deque : " << deque.getFront();
            }
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Last element of deque : " << deque.getLast();
            system("pause");
            system("cls");
            break;
        case 7:
            if (deque.isEmpty())
            {
                cout << "Deque is empty";
            }
            else
            {
                cout << "Deque is not empty: "; deque.show();
            }
            system("pause");
            system("cls");
            break;
        case 8:
            cout << "Size of deque : " << deque.getSize();
            system("pause");
            system("cls");
            break;
        case 9:
            deque.clear();
            system("pause");
            system("cls");
            break;
        case 10:
            cout << "Deque before swap: "; deque.show(); cout << endl;
            deque.swap();
            cout << "Deque after swap: "; deque.show(); cout << endl;
            
            system("pause");
            system("cls");
            break;
        case 11:
            cout << "Input number : "; int number; cin >> number;
            if (deque.isBelong(number))
            {
                cout << number << " belongs.\n";
            }
            else
            {
                cout << number << " does not belong.\n";
            }
            system("pause");
            system("cls");
            break;
        default:
            cout << "There is no " << choice << " choice!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}


