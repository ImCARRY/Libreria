/**
 * Implementation of book_test.cpp
 * @author JFK
*/
#include "Book.h"
#include "Date.h"

#include <vector>

int main() {
    try{
        Book l1 = Book("Mario", "Grossi", "Il libro", "123-4-567-890", Date(1, Date::Month::jan, 2000));
        Book l2 = Book();
        Date d1 = Date();
        Date d = Date(30, Date::Month::jan, 2000);
        return 0;
    }
    catch(std::invalid_argument& e){
        return 1;
    }
    
}