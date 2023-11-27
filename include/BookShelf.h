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
         * @brief Costruttore con capacità
         * @param capacity Capacità della BookShelf
        */
        BookShelf(int capacity) : buffer_(new Book[capacity]), size_(0), capacity_(capacity) {}

        /**
         * @brief Override operatore di assegnamento
        */
        BookShelf& operator=(const BookShelf& other);

        /**
         * @brief Accessor con controllo di bound
         * @param index Indice dell'elemento da accedere
         * @return Elemento all'indice index
        */
        Book& operator[](int index);

        /**
         * @brief Accessor con controllo di bound (const version)
         * @param index Indice dell'elemento da accedere
         * @return Elemento all'indice index
        */
        const Book& operator[](int index) const;

        /**
         * @brief Elemento ad indice
         * @param index Indice dell'elemento da accedere
         * @return Elemento all'indice index
        */
        Book& at(int index);

        /**
         * @brief Elemento ad indice (const version)
         * @param index Indice dell'elemento da accedere
         * @return Elemento all'indice index
        */
        const Book& at(int index) const;

        /**
         * @brief Aggiunge un elemento alla fine della BookShelf
         * @param value Elemento da aggiungere
        */
        void push_back(Book book);

        /**
         * @brief Rimuove l'ultimo elemento della BookShelf
        */
        void pop_back();

        /**
         * @brief Restituisce la dimensione della BookShelf
         * @return Dimensione della BookShelf
        */
        void reserve(int size);
        
        /**
         * @brief Restituisce il numero di libri
        */
        int getSize() const {return size_;}

        /**
         * @brief Restituisce la capacità della BookShelf
         * @return Capacità della BookShelf
        */
        int getCapacity() const {return capacity_;}

    private:
        Book* buffer_;
        int size_;
        int capacity_;
};

#endif // BOOKSHELF_H
