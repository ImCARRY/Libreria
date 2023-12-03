/**
 * Implementation of Date class
 * @author JFK
*/
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
        Date() : day_{1}, month_{jan}, year_{MIN_YEAR}, defaultDate{true} {}

        /**
         * @brief Costruttore di Date
         * @param d Giorno
         * @param m Mese
         * @param y Anno
        */
        Date(int, Month, int);

        /**
         * @brief Costruttore di copia di Date
         * @param other Date da copiare
        */
        Date(const Date& other);

        /**
         * @brief Costruttore di spostamento di Date
         * @param other Date da spostare
        */
        Date(Date&& other) noexcept;

        int getDay() const {return day_;}
        Month getMonth() const {return month_;}
        int getYear() const {return year_;}
        void setDay(int d);
        void setMonth(Month m);
        void setYear(int y);

        bool isDefault();

        class Invalid{};
        
    private:
        int day_;
        Month month_;
        int year_;
        /* Flag per distinguere una data 01/01/1 impostata di default da una impostata manualmente */
        bool defaultDate;
        // Anno minimo di partenza
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
