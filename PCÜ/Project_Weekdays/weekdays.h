#pragma once

#include <string>
#include <iostream>

class weekday {
public:
    /**
     * @brief Instanziert einen neuen Wochentag, als Default-Wert wird dieser auf
     * Montag gesetzt.
     *
     */
    weekday() noexcept;

    /**
     * @brief Instanziert einen neuen Wochentag aus der übergebenen Zeichenkette.
     * Es wird die englische Schreibweise der Wochentage (Monday..Sunday)
     * erwartet. Groß- und Kleinschreibung ist nicht relevant. Im Falle das ein
     * ungültiger Tag angegeben wird, wirft der Konstruktor eine
     * std::invalid_argument exception.
     *
     * @param day Der Wochentag in englischer Sprache.
     */
    weekday(const std::string &day);

    /**
     * @brief Instanziert einen Wochentag explizit aus der Angabe eines Wochentags
     * in numerischer Form. Montag ist dabei 0 und Sonntag die 6. Im Falle das ein
     * ungültiger Tag angegeben wird, wirft der Konstruktor eine
     * std::invalid_argument exception.
     *
     * @param day Der Wochentag als Zahl.
     */
    explicit weekday(const std::int8_t day);

    /**
     * @brief Setzt den Wochentag auf den nächsten Tag.
     *
     */
    void increment() noexcept;

    /**
     * @brief Zählt den Wochentag um die angegebene Anzahl von Tagen weiter.
     *
     * @param days Anzahl der Tage welche weitergezählt werden.
     */
    void increment(std::int32_t days) noexcept;

    /**
     * @brief Setzt den Wochentag auf den vorherigen Tag.
     *
     */
    void decrement() noexcept;

    /**
     * @brief Zählt den Wochentag um die angegebene Anzahl von Tagen zurück.
     *
     * @param days Anzahl der Tage welche zurückgezählt werden.
     */
    void decrement(std::int32_t days) noexcept;

    /**
     * @brief Gibt den aktuellen Tag in numerischer Form zurück. Montag wird als 0
     * repräsentiert.
     *
     * @return int8_t Der aktuelle Wochentag
     */
    int8_t current_day() const noexcept;

    void printDay();

private:
    /* Hier kommen alle Methoden und Attribute hin die Sie für die Implementierung
     * benötigen */
    enum Days {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    Days m_day;
};