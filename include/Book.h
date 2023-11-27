#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include <iostream>

class Book 
{
    private:
        
        std::string nome_;
        std::string cognome_;
        std::string titolo_;
        std::string isbn_;
        Date data_;
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
        Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i, const Date& d = Date());

        /**
         * Member functions
        */

        std::string getIsbn() const {return isbn_;}
        std::string getTitolo() const {return titolo_;}
        std::string getNome() const {return nome_;}
        std::string getCognome() const {return cognome_;}
        Date getData() const {return data_;}

        void setIsbn(std::string);
        void setTitolo(std::string);
        void setNome(std::string);
        void setCognome(std::string);
        void setData(Date);
        void setDisponibile(bool);
        
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
};

/**
 * Basic operator overloading
*/

bool operator==(const Book& book1, const Book& book2);
bool operator!=(const Book& book1, const Book& book2);

/* Output to stream */
std::ostream& operator<<(std::ostream& os, const Book& book);

#endif
