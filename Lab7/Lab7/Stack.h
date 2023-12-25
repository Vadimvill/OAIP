#include <iostream>
#include <vector>
#include <array>
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& item) : data(item), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() : topNode(nullptr) {}

    // Добавление элемента в стек
    void push(const T& element) {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Удаление элемента из стека
    void pop() {
        if (!empty()) {
            Node<T>* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        else {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    // Получение верхнего элемента стека
    T& top() {
        if (!empty()) {
            return topNode->data;
        }
        else {
            throw std::out_of_range("Stack is empty. Cannot get top element.");
        }
    }

    // Проверка на пустоту стека
    bool empty() const {
        return topNode == nullptr;
    }

    // Получение размера стека
    size_t size() const {
        size_t count = 0;
        Node<T>* current = topNode;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }
    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) : current(node) {}

       
        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }
        Iterator& operator+(int ind) {
            for (int i = 0;i < ind;i++) {
                if (current->next == nullptr) {
                    break;
                }
                current = current->next;
            }
            return *this;
        }
       
        T& operator*() const {
            if (current) {
                return current->data;
            }
            else {
                throw std::out_of_range("Iterator is out of bounds.");
            }
        }

   
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    
    Iterator begin() const {
        return Iterator(topNode);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};
template <typename T>
class StackManipulator {
private:
    Stack<T>& stack;

public:
    StackManipulator(Stack<T>& s) : stack(s) {}

    
    void sortElements(typename Stack<T>::Iterator start, typename Stack<T>::Iterator end) {
        
        std::vector<T> tempVector;
        for (auto it = start; it != end; ++it) {
            tempVector.push_back(*it);
        }

       
        for (size_t i = 0; i < tempVector.size() - 1; ++i) {
            for (size_t j = 0; j < tempVector.size() - i - 1; ++j) {
                if (tempVector[j] > tempVector[j + 1]) {
                    std::swap(tempVector[j], tempVector[j + 1]);
                }
            }
        }

       
        auto itStack = start;
        for (const auto& element : tempVector) {
            *itStack = element;
            ++itStack;
        }
    }

    
    bool findElement(const T& value,typename Stack<T>::Iterator start, typename Stack<T>::Iterator end) const {
        for (auto it = start; it != end; ++it) {
            if (*it == value) {
                return true;
   
            }
        }   
        return false;
    }
};


