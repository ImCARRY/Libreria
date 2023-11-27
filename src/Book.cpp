#include "Book.h"
#include <iostream>

Book::Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i, const Date& d) : 
    nome_ {n}, cognome_ {c}, titolo_{t}, isbn_{std::string(i)}, data_{d}, disponibile_{true} {}

void Book::setIsbn(std::string i){
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

/* Confronto tra due libri secondo l'ISBN */
bool operator==(const Book& book1, const Book& book2) { 
    return book1.getIsbn() == book2.getIsbn();
}
bool operator!=(const Book& book1, const Book& book2) {
    return !(book1.getIsbn() == book2.getIsbn());
}

/* Nell'output to stream utilizziamo una visualizzazione del tipo
 *
 * TITOLO: <Titolo libro>
 * AUTORE: <Nome autore><Cognome autore>
 * ISBN: <ISBN libro> 
 * DATA DI COPYRIGHT: <Data di copyright del libro>
 * DISPONIBILE: <Disponibilità>
 *
 *Dopo diverse prove sembra essere l'indentazione più compatta e leggibile
 */
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "TITOLO: " << book.getTitolo() << "\n"
    << "AUTORE: " << book.getNome() << " " << book.getCognome() << "\n"
    << "ISBN: " << book.getIsbn() << "\n"
    << "DATA DI COPYRIGHT: ";
    
    /* NOTA: nella classe Date abbiamo definito un anno minimo che verrebbe
     *       visualizzato in output se la data di un libro viene inizializzata 
     *       tramite costruttore di default. Per evitarlo, visto che risulterebbe
     *       poco conforme dare una data a un libro senza titolo e autore,
     *       utilizziamo questo if per visualizzare "non disponibile" nel
     *       caso appena descritto
     */
    if(book.getData().isDefault())
        os << "non disponibile";
    else
        os << book.getData();
    
    /* NOTA: per evitare di visualizzare uno 0 o un 1 in output 
     *       alla voce "disponibile", utilizziamo l'operatore ternario
     *       per mantenere il codice compatto e visualizzare "SI" o "NO"
     */
    os << "\nDISPONIBILE: " << ((book.isDisponibile())?"SI":"NO");   
    
    return os;
}
