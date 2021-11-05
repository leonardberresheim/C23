#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <time.h>
#include <sstream>

class Date {
public:
    /**
     * @brief Instanziert ein neues Datum. Als Default-Wert wird das Jahr nach dem
     * Beginn des Gregorianischen Kalenders genommen. Also der 1. Januar 1583.
     */
    Date() noexcept;

    /**
     * @brief Instanziert ein neues Datum aus den übergebenen Angaben für Tag,
     * Monat und Jahr. Die Werte werden auf Gültigkeit überprüft. Das Umfasst die
     * Anzahl der Tage eines Monats, den Monat und das Jahr. Überprüfen Sie auch
     * ob das Jahr ein Schaltjahr ist! Als frühestes gültiges Datum wird der 1.1.
     * Januar 1583 angenommen. Falls ein unmögliches Datum angegeben wird eine
     * std::invalid_argument exception geworfen.
     *
     * @param day Der Tag des Monats, also abhängig vom Monat maximal 1 - 31
     * @param month Der Monat des Jahres 1 - 12
     * @param year Das Jahr 1583 - 9999
     */
    Date(const std::int8_t day, const std::int8_t month, const std::int32_t year);

    /**
     * @brief Gibt den Tag des Datums zurück.
     *
     */
    int8_t day() const noexcept;

    /**
     * @brief Gibt den Monat des Datums zurück.
     *
     */
    int8_t month() const noexcept;

    /**
     * @brief Gibt das Jahr des Datums zurück.
     */
    std::int32_t year() const noexcept;

    /**
     * @brief Gibt den Wochentag des Datums zurück als Zahl zurück. Die Zählung
     * beginnt dabei bei 1 für Montag und endet bei 7 für Sonntag.
     */
    std::int8_t weekday() const noexcept;

    /**
     * @brief Das Datum in Menschenlesbarer Form nach ISO 8601. Im Format:
     * YYYY-MM-DD z.B.: "2020-12-31"
     */
    std::string to_string() const noexcept;

private:
    /* Hier kommen alle Methoden und Attribute hin die Sie für die Implementierung
     * benötigen */
    std::tm m_time;
};