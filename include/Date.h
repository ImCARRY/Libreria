#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
    public:
        
        enum Month{
            jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
        };

        /**
         * @brief Costruttore di default di Date
        */
        Date() : day{1}, month{jan}, year{MIN_YEAR}, defaultDate{true} {}

        /**
         * @brief Costruttore di Date
         * @param d Giorno
         * @param m Mese
         * @param y Anno
        */
        Date(int, Month, int);

        int getDay() const {return day;}
        Month getMonth() const {return month;}
        int getYear() const {return year;}
        void setDay(int d);
        void setMonth(Month m);
        void setYear(int y);

        bool isDefault();

        class Invalid{};
        
    private:
        int day;
        Month month;
        int year;
        /* Flag per distinguere una data 01/01/1600 impostata di default da una impostata manualmente */
        bool defaultDate;
        /* Valore minimo accettato per l'anno */
        static constexpr int MIN_YEAR = 1;
        
        /**
         * @brief Funzione per verificare la validità di una data
        */
        bool validate(int, Month, int);

        /**
         * @brief Funzione per verificare se un anno è bisestile
        */
        bool isLeapYear(int);
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif
