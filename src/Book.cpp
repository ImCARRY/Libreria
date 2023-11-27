/**
 * Implementation of Book class
 * @author Federico Borsati
 * @matricola 2046106
 * @gruppo JFK
*/

#include "Book.h"
#include <iostream>

Book::Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i, const Date& d) : 
    nome_ {n}, 
    cognome_ {c}, 
    titolo_{t}, 
    isbn_{std::string(i)}, 
    data_{d}, 
    disponibile_{true} 
    {
        if(i.length() != ISBN_LENGTH)
            throw Invalid{};
    }

void Book::setIsbn(std::string i){
    if(i.length() != ISBN_LENGTH)
        throw Invalid{};
    isbn_ = i;
}

void Book::setTitolo(std::string t){
    titolo_ = t;
}

void Book::setNome(std::string n){
    nome_ = n;
}

void Book::setCognome(std::string c){
    cognome_ = c;
}

void Book::setData(Date d){
    data_ = d;
}

void Book::setDisponibile(bool d){
    disponibile_ = d;
}

void Book::presta(){
    if(disponibile_){
        disponibile_ = false;
    }
}
void Book::restituisci(){
    if(!disponibile_){
        disponibile_ = true;
    }
}

/**
 * @brief Operatore di uguaglianza tra due libri(tramite ISBN)
 * @param book1 Primo libro
 * @param book2 Secondo libro
*/
bool operator==(const Book& book1, const Book& book2) { 
    return book1.getIsbn() == book2.getIsbn();
}
bool operator!=(const Book& book1, const Book& book2) {
    return !(book1.getIsbn() == book2.getIsbn());
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Titolo: " << book.getTitolo() << "\n"
    << "Autore: " << book.getNome() << " " << book.getCognome() << "\n"
    << "ISBN: " << book.getIsbn() << "\n"
    << "Copyright: ";
    
    if(book.getData().isDefault())
        os << "non disponibile";
    else
        os << book.getData();
    
    os << "\nDISPONIBILE: " << ((book.isDisponibile())?"SI":"NO");   
    
    return os;
}
