#include "NodeOfList.h"
template <typename T>
class List
{
private:
    int size;
    NodeOfList<T>* head;
    NodeOfList<T>* tail;

public:
    List() : head(nullptr), tail(nullptr), size(0) {};


    void clear() {
        while (head != nullptr) {
            NodeOfList<T>* temp = head;
            head = head->next;
            delete temp->date;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }


    void setHead(NodeOfList<T>* hd) {
        head = hd;
    }

    void setTail(NodeOfList<T>* tl) {
        tail = tl;
    }

    NodeOfList<T>* getHead() {
        return head;
    }

    NodeOfList<T>* getTail() {
        return tail;
    }

    int getSize() {
        return size;
    }

    void addNode(NodeOfList<T>* node) {
        if (node == nullptr) return;
        if (head == nullptr) {
            head = node;
            tail = node;
            size++;
        }
        else {
            tail->next = node;
            tail = node;
            size++;
        }
    }

    void removeNode(int i) {
        if (i >= size || i == -1)
        {
            throw 21;
        }
        NodeOfList<T>* temp = head;
        NodeOfList<T>* removeTemp;

        if (i == 0) {
            removeTemp = head;
            head = head->next;
        }
        else {
            for (int b = 0; b < i - 1; b++) {
                temp = temp->next;
            }
            removeTemp = temp->next;
            temp->next = temp->next->next;
        }

        if (removeTemp != nullptr) delete removeTemp;
        size--;
    }

    NodeOfList<T>* getNode(int i) {
        if (i >= size || i == -1) throw 21;
        NodeOfList<T>* temp = head;
        for (int b = 0; b < i; b++) {
            temp = temp->next;
        }

        return temp;
    }

};