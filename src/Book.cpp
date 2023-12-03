/**
 * Implementation of Book class
 * @author JFK
*/

/**
 * MOVE NOT OK
 * COPY NOT OK
*/

#include "Book.h"
#include <iostream>
#include <utility>

Book::Book(std::string  n, std::string  c, std::string  t, const std::string& i, const Date& d) :
    nome_ {std::move(n)},
    cognome_ {std::move(c)},
    titolo_{std::move(t)},
    isbn_{std::string(i)}, 
    data_{d}, 
    disponibile_{true} 
    {
        if(i.length() != ISBN_LENGTH)
            throw Invalid{};
    }

Book::Book(const Book& other) :
    nome_{other.nome_},
    cognome_{other.cognome_},
    titolo_{other.titolo_},
    isbn_{other.isbn_},
    data_{other.data_},
    disponibile_{other.disponibile_}
{
}

Book::Book(Book&& other) noexcept :
    nome_{std::move(other.nome_)},
    cognome_{std::move(other.cognome_)},
    titolo_{std::move(other.titolo_)},
    isbn_{std::move(other.isbn_)},
    data_{std::move(other.data_)},
    disponibile_{std::move(other.disponibile_)}
{
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
