
#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"

class BookShelf {
    public:
        BookShelf();
        ~BookShelf();
        BookShelf(const BookShelf& other);
        BookShelf(int capacity) : buffer(new Book[capacity]), size(0), capacity(capacity) {}
        BookShelf& operator=(const BookShelf& other);
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
