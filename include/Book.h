/**
 * Implementation of Book class
 * @author JFK
*/
#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include <iostream>

constexpr int ISBN_LENGTH = 13;

class Book 
{
    private:

    std::string nome_;
        std::string cognome_;
        std::string titolo_;
        std::string isbn_;
        Date data_;
        //Disponibile al prestito
        bool disponibile_ = false;       
        
    public:

        /**
         * @brief Costruttore di default di Book
        */
        Book() : nome_{""}, cognome_{""}, titolo_{""}, isbn_{""}, data_{Date()} {}

        
        /**
         * @brief Costruttore di Book
         * @param n Nome dell'autore
         * @param c Cognome dell'autore
         * @param t Titolo del libro
         * @param i ISBN del libro
         * @param d Data di pubblicazione del libro
        */
        Book(std::string  n, std::string  c, std::string  t, const std::string& i, const Date& d = Date());

        /**
         * @brief Costruttore di copia di Book
         * @param other Book da copiare
        */
        Book(const Book& other);

        /**
         * @brief Costruttore di spostamento di Book
         * @param other Book da spostare
        */
        Book(Book&& other) noexcept;

        /**
         * Member functions
        */

        std::string getIsbn() const {return isbn_;}
        std::string getTitolo() const {return titolo_;}
        std::string getNome() const {return nome_;}
        std::string getCognome() const {return cognome_;}
        Date getData() const {return data_;}

        /**
         * @brief Deve essere lungo 13 caratteri
        */
        void setIsbn(std::string);
        void setTitolo(std::string);
        void setNome(std::string);
        void setCognome(std::string);
        void setData(Date);
        void setDisponibile(bool);
        static int getISBN_LENGTH();
        
        /**
         *  @brief Disponibilita' libro in magazzino
        */
        bool isDisponibile() const {return disponibile_;}

        /**
         * @brief Rende il libro non piu' disponibile
        */
        void presta();

        /**
         * @brief Rende il libro di nuovo disponibile
        */
        void restituisci();
        
        /* Classe definita per la gestione delle eccezioni */
        class Invalid{};

    Book(volatile const std::string& nome, volatile std::string cognome, volatile std::string titolo,
         volatile std::string isbn);
};

/**
 * Basic operator overloading
*/

/**
 * @brief Operatore di uguaglianza tra due libri(tramite ISBN)
 * @param book1 Primo libro
 * @param book2 Secondo libro
*/
bool operator==(const Book& book1, const Book& book2);

/**
 * @brief Operatore di disuguaglianza tra due libri(tramite ISBN)
 * @param book1 Primo libro
 * @param book2 Secondo libro
*/
bool operator!=(const Book& book1, const Book& book2);

/* Output to stream */
std::ostream& operator<<(std::ostream& os, const Book& book);

#endif
