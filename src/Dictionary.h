#include <utility>

#include "Comparator.h"
#include "ForwardList.h"
#ifndef DICTIONARY
#define DICTIONARY

template <typename Key, typename Value, typename Compare = Comparator<Key>>
class Dictionary
{
public:
    Dictionary();
    ~Dictionary();

    void push(Key k, Value v);
    Value get(Key k);
    Value drop(Key k);
    void print();

private:
    ForwardList<std::pair<Key, Value>> list_;
    Compare comp_;
};

template <typename Key, typename Value, typename Compare>
Dictionary<Key, Value, Compare>::Dictionary()
{
}

template <typename Key, typename Value, typename Compare>
Dictionary<Key, Value, Compare>::~Dictionary()
{
}

template <typename Key, typename Value, typename Compare>
void Dictionary<Key, Value, Compare>::push(Key k, Value v)
{
    for (auto it = list_.begin(); it != list_.end(); ++it)
    {
        if (k == it->first)
        {
            return;
        }
    }

    list_.push_front(std::make_pair(k, v));
}

template <typename Key, typename Value, typename Compare>
Value Dictionary<Key, Value, Compare>::get(Key k)
{
    for (auto it = list_.begin(); it != list_.end(); ++it)
    {
        if (k == it->first)
        {
            return it->second;
        }
    }
}

template <typename Key, typename Value, typename Compare>
Value Dictionary<Key, Value, Compare>::drop(Key k)
{
    auto prevValueIt = list_.begin();

    if (k == prevValueIt->first)
    {
        Value tempValue = prevValueIt->second;
        list_.pop_front();
        return tempValue;
    }

    for (auto it = list_.begin(); it != list_.end(); ++it)
    {
        if (k == it->first)
        {
            Value tempValue = it->second;
            list_.erase_after(prevValueIt);
            return tempValue;
        }
        prevValueIt = it;
    }
}

#endif // DICTIONARY
