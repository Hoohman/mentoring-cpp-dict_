#include <cstddef>
#ifndef FORWARDLIST
#define FORWARDLIST


template <typename T>
class ForwardList
{
public:
    ForwardList();
    ~ForwardList();

    void push_front(const T value);
    void pop_front();
    void clear();
    bool empty();
    size_t size();

public:
    class Iterator;

    Iterator begin();
    Iterator end();

private:
    class Node;

private:
    Node* head_;
    size_t size_;
};


// Реализация итератора
template <typename T>
class ForwardList<T>::Iterator
{
public:
    Iterator(Node* node) : currentNode_(node) { }

    bool operator!=(Iterator other) { return currentNode_ != other.currentNode_; }

    bool operator==(Iterator other) { return currentNode_ == other.currentNode_; }

    T& operator*() { return currentNode_->data_; }

    void operator++() { currentNode_ = currentNode_->next_; }

    Iterator operator++(int)
    {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

private:
    Node* currentNode_;
};

template <typename T>
typename ForwardList<T>::Iterator ForwardList<T>::begin()
{
    return Iterator(head_);
}

template <typename T>
typename ForwardList<T>::Iterator ForwardList<T>::end()
{
    return Iterator(nullptr);
}

// Реализация ноды
template <typename T>
class ForwardList<T>::Node
{
public:
    Node(T value) : data_(value), next_(nullptr) { }

    T data_;
    Node* next_;
};

// Методы ForwardList`а
template <typename T>
ForwardList<T>::ForwardList() : size_(0), head_(nullptr)
{
}

template <typename T>
ForwardList<T>::~ForwardList()
{
    clear();
}

template <typename T>
void ForwardList<T>::push_front(const T value)
{
    Node* newNode = new Node(value);
    newNode->next_ = head_;
    head_ = newNode;
    size_++;
}

template <typename T>
void ForwardList<T>::pop_front()
{
    if (head_)
    {
        Node* tempNode = head_;
        head_ = head_->next_;
        delete tempNode;
        size_--;
    }
}

template <typename T>
void ForwardList<T>::clear()
{
    while (head_)
    {
        Node* tempNode = head_;
        head_ = head_->next_;
        delete tempNode;
        size_--;
    }
}

template <typename T>
bool ForwardList<T>::empty()
{
    if (size_ == 0)
    {
        return true;
    }
    return false;
}

template <typename T>
size_t ForwardList<T>::size()
{
    return size_;
}

#endif // FORWARDLIST
