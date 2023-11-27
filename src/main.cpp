/**
 * Entry point
 * @author Federico Borsati
 * @matricola 2046106
 * @gruppo JFK
*/
#include <iostream>
#include "Book.h"
#include "BookShelf.h"

int main(){

    Book l1 = Book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4", Date(1, Date::Month::jan, 2000));
    Book l2 = Book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    BookShelf bs = BookShelf();
    bs.push_back(l1);
    bs.push_back(l2);

    std::cout << l1 << std::endl;

    l1.presta();
    std::cout << l1 << std::endl;

    /**
     * Test case #1
    */
    try
    {
        BookShelf shelf(10);
        shelf.push_back(l1);
        shelf.pop_back();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Test case #1 fallito" << std::endl;
        std::cerr << e.what() << std::endl;
    }


    return 0;
}