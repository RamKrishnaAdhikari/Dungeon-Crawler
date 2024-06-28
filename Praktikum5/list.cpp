
#include "list.h"
#include <iostream>
#include <exception>

myList::myList() : head(nullptr), tail(nullptr), m_size(0)
{
}

myList::~myList()
{
    while (!empty())
    {
        pop_back();
    }
}

void myList::push_back(Level* level)
{
    Element* newElement = new Element(level);
    if (tail)
    {
        tail->next = newElement;
        newElement->prev = tail;
        tail = newElement;
    }
    else
    {
        head = tail = newElement;
    }
    m_size++;
}

void myList::push_front(Level* level)
{
    Element* newElement = new Element(level);
    if (head)
    {
        head->prev = newElement;
        newElement->next = head;
        head = newElement;
    }
    else
    {
        head = tail = newElement;
    }
    m_size++;
}

void myList::pop_back()
{
    if (empty())
    {
        throw std::out_of_range("List is empty");
    }
    Element* oldtail = tail;
    if (tail->prev)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
    {
        head = tail = nullptr;
    }
    delete oldtail;
    m_size--;
}

void myList::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("List is empty");
    }
    Element* oldhead = head;
    if (head->next)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else
    {
        head = tail = nullptr;
    }
    delete oldhead;
    m_size--;
}

bool myList::empty() const
{
    return m_size == 0;
    // Alternatively: return head == nullptr;
}

std::size_t myList::size() const
{
    return m_size;
}

void myList::remove(Level* level)
{
    Element* current = head;
    while (current)
    {
        if (current->data == level)
        {
            Element* toDelete = current;
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                tail = current->prev;
            }
            current = current->next;
            delete toDelete;
            m_size--;
        }
        else
        {
            current = current->next;
        }
    }
}

myList::iterator myList::begin()
{
    if (empty())
    {
        return iterator(nullptr);
    }
    return iterator(head);
}

myList::iterator myList::end ()
{
    return iterator(nullptr);
}

myList::iterator& myList::iterator::operator ++()
{
    if (!current)
    {
        throw std::logic_error("nullptr cannot be decremented");
    }
    if (!current->prev)
    {
        throw std::out_of_range("Decrementing begin iterator");
    }
    current = current->prev;

    return *this;
}

myList::iterator& myList::iterator::operator --()
{
    if (!current)
    {
        throw std::logic_error("null ptr cannot be decremented");
    }
    if (!current->prev)
    {
        throw std::out_of_range("Decrementing begin iterator");

    }
    current = current->prev;

    return *this;
}

Level*& myList::iterator::operator *()
{
    if (current)
    {
        return current->data;
    }
    throw std::out_of_range("Dereferencing end operator");
}

bool myList::iterator::operator ==(const iterator& other) const
{
    return current == other.current;
}

bool myList::iterator::operator !=(const iterator& other) const
{
    return current != other.current;
}




