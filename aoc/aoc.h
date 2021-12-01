#pragma once

#include <iostream>

namespace aoc
{
    const unsigned int margin_size = 4;

    template <typename T>
    struct list_item
    {
        T value;
        list_item<T>* next = nullptr;
        list_item<T>* prev = nullptr;
    };

    template <typename T>
    struct linked_list
    {
        list_item<T>* anchor = nullptr;
        unsigned int size = 0;
    };

    template <typename T>
    bool is_empty(linked_list<T>* list)
    {
        return list->size == 0;
    }

    template <typename T> 
    T& value_at(linked_list<T>* list, int index)
    {
        if (index >= 0 && index < list->size)
        {
            list_item<T>* current = list->anchor;

            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }

            return current->value;
        }
    }

    template <typename T>
    void push_back(linked_list<T>*& list, T value)
    {
        list_item<T>* item = new list_item<T>;
        item->value = value;

        if (is_empty(list))
        {
            list->anchor = item;
            list->size++;
        }
        else
        {
            list_item<T>* current = list->anchor;

            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = item;
            item->prev = current;
            list->size++;
        }
    }

    inline void print_blank();
    void print(std::string text, int margin = 0);
    void printm(std::string text);

    void print_logo();

    inline void print_blank()
    {
        std::cout << "\n";
    }

    void print_logo()
    {
        print_blank();
        printm("  ^~^  ,                           \n");
        printm(" ('Y') )                           \n");
        printm(" /   \/  Advent of Code 2021  __QQ \n");
        printm("(\|||/)                      (_)_\">\n");
        printm("                            /      \n");
        print_blank();
    }

    void print(std::string text, int margin)
    {
        for (int i = 0; i < margin; i++)
        {
            std::cout << " ";
        }

        std::cout << text;
    }

    void printm(std::string text)
    {
        print(text, margin_size);
    }
}
