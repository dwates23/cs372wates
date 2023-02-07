#include <iostream>
#include <list>
using namespace std;

struct Node 
{
    int recpt;
    string item;
    Node *next;
};

class ReceiptBag 
{
  public:
    ReceiptBag() 
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void put(string item) 
    {
        Node* newode = new Node;
        newode->recpt = size;
        newode->item = item;
        newode->next = NULL;
        if (head == NULL) 
        {
            head = newode;
            tail = newode;
        } 
        else 
        {
            tail->next = newode;
            tail = tail->next;
        }
        size++;
    }

    string remove(int recpt) 
    {
        if (head == NULL) return "";
        Node* temp = head;
        if (head->recpt == recpt) 
        {
            head = head->next;
            string item = temp->item;
            delete temp;
            size--;
            return item;
        }
        while (temp->next != NULL) 
        {
            if (temp->next->recpt == recpt) 
            {
                Node* removedNode = temp->next;
                temp->next = removedNode->next;
                string item = removedNode->item;
                delete removedNode;
                size--;
                return item;
            }
            temp = temp->next;
        }
        return "";
    }

  private:
    Node* head;
    Node* tail;
    int size;
};

int main() 
{
    return 0;
}
