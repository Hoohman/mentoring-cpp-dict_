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

private:
    class Node
    {
    public:
        T data_;
        Node* next_;

        Node(T value);
    };

private:
    Node* head_;
    size_t size_;
};

template <typename T>
ForwardList<T>::Node::Node(T value) : data_(value), next_(nullptr)
{
}

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
