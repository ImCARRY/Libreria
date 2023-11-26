#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include <iostream>

class Book 
{
    private:
        
        std::string nome;
        std::string cognome;
        std::string titolo;
        std::string isbn;
        Date data;
        bool disponibile = false;       
        
    public:

        /**
         * @brief Costruttore di default di Book
        */
        Book() : nome{""}, cognome{""}, titolo{""}, isbn{""}, data{Date()} {}

        
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

        std::string getIsbn() const {return isbn;}
        std::string getTitolo() const {return titolo;}
        std::string getNome() const {return nome;}
        std::string getCognome() const {return cognome;}
        Date getData() const {return data;}

        void setIsbn(std::string);
        void setTitolo(std::string);
        void setNome(std::string);
        void setCognome(std::string);
        void setData(Date);
        void setDisponibile(bool);
        
        bool isDisponibile() const {return disponibile;}
        void presta();
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
