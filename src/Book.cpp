#include "Book.h"
#include <iostream>

Book::Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i, const Date& d) : 
    nome {n}, cognome {c}, titolo{t}, isbn{std::string(i)}, data{d}, disponibile{true} {}

void Book::setIsbn(std::string i){
    isbn = i;
}

void Book::setTitolo(std::string t){
    titolo = t;
}

void Book::setNome(std::string n){
    nome = n;
}

void Book::setCognome(std::string c){
    cognome = c;
}

void Book::setData(Date d){
    data = d;
}

void Book::setDisponibile(bool d){
    disponibile = d;
}

void Book::presta(){
    if(disponibile){
        disponibile = false;
    }
}
void Book::restituisci(){
    if(!disponibile){
        disponibile = true;
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
