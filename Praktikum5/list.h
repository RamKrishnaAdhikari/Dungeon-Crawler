
#ifndef MYLIST_H
#define MYLIST_H
#include <cstddef> // for std::size_t

class Level;

class myList
{
    class iterator;
public:
    myList();
    ~myList();
    void push_back(Level* level);
    void push_front(Level* level);
    void pop_back();
    void pop_front();
    bool empty() const;
    std::size_t size() const;
    void remove(Level* level);
    iterator begin();
    iterator end();

private:
    struct Element
    {
        Level* data;
        Element* next;
        Element* prev;
        Element(Level* lvl) : data(lvl), next(nullptr), prev(nullptr) {}
    };

    Element* head;
    Element* tail;
    std::size_t m_size;

    class iterator
    {
    public:
        iterator(Element* elem) : current(elem) {}

        iterator& operator ++();
        iterator& operator --();
        Level*& operator *();
        bool operator ==(const iterator& other) const;
        bool operator !=(const iterator& other) const;
    private:
        Element* current;
    };
};

#endif // MYLIST_H
