#ifndef FORWARDLIST
#define FORWARDLIST

template <typename T>
class ForwardList
{
public:
    /*ForwardList();
    ~ForwardList();

    void push_front(T value);
    void pop_front();
    void clear();*/

private:
    class Node
    {
        T data_;
        Node* next_;

        Node(T value);
    };

private:
    Node* head_;
    size_t size_;
};

#endif // FORWARDLIST
