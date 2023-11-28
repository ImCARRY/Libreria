/**
 * Implementation of library_prof_test.cpp
 * @author JFK
*/
#include "BookShelf.h"
#include "Book.h"
#include "Date.h"

#include <vector>

int main() {
    try{
        BookShelf shelf(10);
        Book mybook = Book("Federico", "Borsati", "Come NON passare l'esame", "123-4-567-890");
        shelf.push_back(mybook);

        if(shelf.getCapacity() != 10)
            return 1;
        if(shelf.getSize() != 1)
            return 1;

        shelf.pop_back();

        if(shelf.getCapacity() != 10)
            return 1;
        if(shelf.getSize() != 0)
            return 1;

        return 0;
    }
    catch(std::invalid_argument& e){
        return 1;
    }
    
}