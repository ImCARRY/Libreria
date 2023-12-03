/**
 * Implementation of Date class
 * @author JFK
*/
#include "Date.h"
#include <iostream>


Date::Date(int d, Month m, int y){
    if(validate(d, m, y))
        day_ = d, month_ = m, year_ = y, defaultDate = false;
    else throw Invalid{};
}

Date::Date(const Date& other) :
    day_{other.day_},
    month_{other.month_},
    year_{other.year_},
    defaultDate{other.defaultDate}
{
}

Date::Date(Date&& other) noexcept :
    day_{std::move(other.day_)},
    month_{std::move(other.month_)},
    year_{std::move(other.year_)},
    defaultDate{std::move(other.defaultDate)}
{
}

void Date::setDay(int d){
    if(validate(d, month_, year_)){
        day_ = d;
        if(defaultDate)
            defaultDate = false;
    }
    else throw Invalid{};
}
void Date::setMonth(Month m){
    if(validate(day_, m, year_)){
        month_ = m;
        if(defaultDate)
            defaultDate = false;
    }
    else throw Invalid{};
}
void Date::setYear(int y){
    if(validate(day_, month_, y)) {
        year_ = y;
        if(defaultDate)
            defaultDate = false;
    }
    else throw Invalid{};
}

bool Date::validate(int d, Month m, int y){
    if(y<MIN_YEAR || d<1 || m<1 || m>12)
        return false;
        
    switch (m){
        case Month::feb:
            if(isLeapYear(y)){
                if(d>29) return false;
            }    
            else {
                if(d>28) return false;
            }
        case Month::apr:
        case Month::jun:
        case Month::sep:
        case Month::nov:
            if(d>30) return false;
            break;
        default:
            if(d>31)
                return false;
            break;
    }
    return true;
}

bool Date::isLeapYear(int y){
    if(y%4 != 0)
        return false;
    if(y%100==0 && y%400!=0)
        return false;
    return true;
}

/* Funzione per verificare se una data è di default o meno */
bool Date::isDefault(){
    return defaultDate;
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        defaultDate = other.defaultDate;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& date){
    //se il giorno e/o il mese hanno una sola cifra aggiungo uno 0 davanti per questioni estetiche
    return os<<((date.getDay()<10)?"0":"")<<date.getDay()
        <<"/"<<((date.getMonth()<10)?"0":"")<<date.getMonth()
        <<"/"<<date.getYear();
}
