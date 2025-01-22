#ifndef COMPARATOR
#define COMPARATOR

template <typename Key>
struct Comparator
{
    bool operator()(const Key& a, const Key& b) const { return a < b; }
};

#endif // COMPARATOR
