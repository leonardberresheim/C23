#include "control_structures.h"
#include <stdexcept>

#define if                                                                     \
  static_assert(false, "if darf hier nicht verwendet werden");                 \
  if

/**
 * @brief Gibt den übergebenen Wochentag als std::string in englischer Sprache
 * zurück.
 *
 * @throw std::domain_error Wenn day ein unbekannter Tag ist.
 * @param day Wochentag
 * @return std::string
 */
string day_to_string_en(Days_t day) {
    // Benutzen Sie Switch-Case, die Exception soll für den Fehlerfall unverändert
    // übernommen werden.
    switch(day){
        case Monday:
            return "Monday";
        case Tuesday:
            return "Tuesday";
        case Wednesday:
            return "Wednesday";
        case Thursday:
            return "Thursday";
        case Friday:
            return "Friday";
        case Saturday:
            return "Saturday";
        case Sunday:
            return "Sunday";
        default:
            throw domain_error("Unknown day");
    }

}

#undef if

#define switch                                                                 \
  static_assert(false, "switch darf hier nicht verwendet werden");             \
  switch

/**
 * @brief Gibt den als std::string übergebenen Wochentag in englischer Sprache
 * als Days_t enum zurück.
 *
 * @throw std::domain_error Wenn day ein unbekannter Tag ist.
 * @param day Wochentag in gleicher Schreibweise wie die Werte des Days_t enum.
 * @return Days_t
 */
Days_t day_from_string_en(string day) {
    // Benutzen Sie If-Else, die Exception soll für den Fehlerfall unverändert
    // übernommen werden.
    if(day == "Monday"){
        return Monday;
    }else if(day == "Tuesday"){
        return Tuesday;
    }else if(day == "Wednesday"){
        return Wednesday;
    }else if(day == "Thursday"){
        return Thursday;
    }else if(day == "Friday"){
        return Friday;
    }else if(day == "Saturday"){
        return Saturday;
    }else if(day == "Sunday"){
        return Sunday;
    }else{
        throw domain_error("Unknown day");
    }
}

#undef switch

// Bei den folgenden Funktionen dürfen alle bekannten Kontrollstrukturen
// benutzen. Probieren Sie alle Funktionen einmal mit Allen zu lösen. Geht das?
// Falls ja - welche ist besonders Effektiv? Kann is_odd() und is_even()
// komplett ohne den Einsatz von if, switch oder ?: implementiert werden? Eine
// der beiden Funktionen kann auch als Negation der anderen dargestellt werden.

/**
 * @brief Prüft ob eine Zahl ungerade ist.
 *
 * @param num
 * @return true Zahl ist ungerade
 * @return false Zahl ist gerade
 */
bool is_odd(int64_t num) {
    return num % 2;
}

/**
 * @brief Prüft ob eine Zahl gerade ist.
 *
 * @param num
 * @return true Zahl ist gerade
 * @return false Zahl ist ungerade
 */
bool is_even(int64_t num) {
    return !is_odd(num);
}

/**
 * @brief Gibt die Größere der beiden übergebenen Zahlen zurück.
 * @return int64_t Die größere Zahl
 */
int64_t max(int64_t a, int64_t b) {
    if(a > b){
        return a;
    }else{
        return b;
    }
}

/**
 * @brief Gibt die Kleinere der beiden übergebenen Zahlen zurück.
 * @return int64_t Die kleinere Zahl
 */
int64_t min(int64_t a, int64_t b) {
    if(a < b){
        return a;
    }else{
        return b;
    }
}