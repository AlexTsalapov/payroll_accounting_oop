#include "Queer.h"


template <typename T> Queue<T>::Queue()
{
    begin = NULL;
    end = NULL;
}

template <typename T> Queue<T>::Queue(const Queue& obj)
{
    Block<T>* value = obj.begin;
    while (value)
    {
        addItemBegin(value->info);
        value = value->next;
    }
}

template <typename T> Queue<T>::~Queue()
{
    Block<T>* value = begin;
    while (value != NULL)
    {
        value = begin->next;

        delete begin;

        begin = value;
    }
}

template <typename T> void Queue<T>::addItemBegin(T item)
{
    Block<T>* value = new Block<T>;
    value->prev = NULL;
    value->info = item;

    if (begin != NULL)
    {
        value->next = begin;
        begin->prev = value;
        begin = value;
    }
    else
    {
        begin = value;
        end = value;
        value->next = NULL;
    }
}

template <typename T> void Queue<T>::addItemEnd(T item)
{
    Block<T>* value = new Block<T>;
    value->info = item;
    value->next = NULL;

    if (begin != NULL)
    {
        value->prev = end;
        end->next = value;
        end = value;
    }
    else
    {
        begin = value;
        end = value;
        value->prev = NULL;
    }
}

template <typename T> T Queue<T>::getItem(int k)
{
    Block<T>* value = begin;
    int i = 0;
    while (value != NULL)
    {


        if (i == k)
        {
            return value->info;

        }

        value = value->next;
        i++;
    }
}
template <typename T> int Queue<T>::getSizeQueue()
{
    Block<T>* value = begin;
    int x = -1;
    while (value != NULL)
    {
        x++;
        value = value->next;

    }

    return x;
}
template <typename T> void Queue<T>::editItem(int n)
{
    Block<T>* value = begin;
    int i = 0;
    while (value != NULL)
    {
        if (i == n)
        {
            value->info.editPerson();
        }
        value = value->next; 
        i++;
    }
}

template <typename T> void Queue<T>::deleteItemBeggin(int x)
{
    x--;
    int i = 0;
    Block<T>* value = begin;
    swap2Item(x, i);
    for (int k = x; k > 1; k--)
    {
        swapItem(k);
    }

    if (begin == end)
    {
        begin->next = NULL;
        begin = NULL;
        end = NULL;

        delete begin;
        return;
    }
    if (begin->next)
    {
        Block<T>* value = begin;

        begin = begin->next;
        begin->prev = NULL;

        delete value;

        return;
    }
}


template <typename T> void Queue<T>::deleteItemEnd(int z)
{
    int k = getSizeQueue();
    int x = k - z;
   
    int i = 0;
    Block<T>* value = begin;
    swap2Item(x, i);
    for (int k = x; k > 1; k--)
    {
        swapItem(k);
    }

    if (begin == end)
    {
        begin->next = NULL;
        begin = NULL;
        end = NULL;

        delete begin;
        return;
    }
    if (begin->next)
    {
        Block<T>* value = begin;

        begin = begin->next;
        begin->prev = NULL;

        delete value;

        return;
    }
}

template <typename T> void Queue<T>::swapItem(int n)
{
    Block<T>* value = begin;
    int i = 0;

    while (value != NULL)
    {
        i++;

        if (i == n)
        {
            std::swap(value->info, value->next->info);
            return;
        }

        value = value->next;
    }
}
template <typename T> void Queue<T>::swap2Item(int n, int k)
{
    Block<T>* value = begin;
    Block<T>* value2 = begin;
    int i = 0;
    int j = 0;
    while (value != NULL)
    {
        if (i == n)
        {
            while (value2 != NULL)
            {

                if (j == k)
                {
                    std::swap(value->info, value2->info);
                    return;
                }
                j++;
                value2 = value2->next;
            }
        }
        i++;
        value = value->next;
    }
}








template <typename T> Queue<T>& Queue<T>::operator=(const Queue& obj)
{
    if (this != &obj)
    {
        Block<T>* value = begin;

        while (value)
        {
            begin = begin->next;
            delete value;
            value = begin;
        }

        value = obj.begin;

        while (value)
        {
            addItemBegin(value->info);
            value = value->next;
        }
    }

    return *this;
}
template <typename T> void Queue<T>::show()
{
    int counter = 1;
    if (((begin == NULL) && (end == NULL)))
    {
        std::cout << "  Очередь пуста." << std::endl << std::endl;
    }
    else
    {
        Block<T>* value = begin;

        while (value != NULL)
        {
            std::cout << counter << std::setw(2)<<"|" << value->info;
            value = value->next;
            counter++;
        }
        std::cout << std::endl << std::endl;
    }
}

template <typename T> void Queue<T>::showItem(int n)
{
    Block<T>* value = begin;
    int i = 0;

    while (value != NULL)
    {
        

        if (i == n)
        {
            std::cout << i+1 << std::setw(2) << "|" << value->info ;
            return;
        }
        i++;

        value = value->next;
    }
}






