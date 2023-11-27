/**
 * Implementation of book_test.cpp
 * @author Federico Borsati
 * @matricola 2046106
 * @gruppo JFK
*/
#include "Book.h"
#include "Date.h"

#include <vector>

int main() {
    try{
        Book l1 = Book("Mario", "Grossi", "Il libro", "123-4-567-890", Date(1, Date::Month::jan, 2000));
        return 0;
    }
    catch(std::invalid_argument& e){
        return 1;
    }
    
}