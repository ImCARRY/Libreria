#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "Book.h"

class BookShelf {
    public:
        /**
         * @brief Costruttore di default
        */
        BookShelf();
        ~BookShelf();

        /**
         * @brief Costruttore di copia
         * @param other BookShelf da copiare
        */
        BookShelf(const BookShelf& other);

        /**
         * @brief Operatore di assegnamento
         * @param other BookShelf da copiare
        */
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
