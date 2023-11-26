#include <iostream>
#include "Book.h"
#include "BookShelf.h"

int main(){

    Book l1 = Book("Mario", "Grossi", "Il libro", "1234567890", Date(1, Date::Month::jan, 2000));
    Book l2 = Book("Mario", "Rossi", "Il libro", "1234567890");
    BookShelf bs = BookShelf();
    bs.push_back(l1);
    bs.push_back(l2);

    std::cout << l1 << std::endl;

    l1.presta();
    std::cout << l1 << std::endl;

    return 0;
}