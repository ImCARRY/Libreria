
#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"

class Bookshelf {
    public:
        Bookshelf();
        ~Bookshelf();
        Bookshelf(const Bookshelf& other);
        Bookshelf& operator=(const Bookshelf& other);
        Book& operator[](int index);
        const Book& operator[](int index) const;
        Book& at(int index);
        const Book& at(int index) const;
        void push_back(Book book);
        void pop_back();
        void reserve(int size);
        
        int getSize() const {return size;}
        int getCapacity() const {return capacity;}

    private:
        Book* buffer;
        int size;
        int capacity;
};

#endif // BOOKSHELF_H
