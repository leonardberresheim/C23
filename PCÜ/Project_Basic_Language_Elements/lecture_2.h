#pragma once

#include <string>
#include <iostream>
#include <bits/stdc++.h>


/**
 * @brief Liest Vorname und Nachname und das Alter von der Konsole ein und
 * antwortet mit "Hello [Vorname] [Nachname] ([Alter])!" auf der Konsole (z. B.
 * "Hello Carsten Thomas (56)!")
 */
void greet_person();

/* Wer es etwas schwieriger haben möchte aktiviert dieses Define.
 *
 * Die greet_person Funktion muss dann eine std::invalid_argument exception
 * werfen wenn: Vorname oder Nachname aus anderen Zeichen als Buchstaben
 * bestehen. Das Alter aus anderen Zeichen als Ziffern besteht.
 */
// #define VALIDATE_INPUT_GREET_PERSON

/**
 * @brief Führt einfache mathematische Operationen aus, welche im Postfix-Format
 * angegeben sind. Als Parameter wird eine Zeichenfolge verwendet, wobei die
 * Zeichenfolge ein Operationszeichen gefolgt von zwei Zahlen (int und / oder
 * double) enthält ("* 3.14 2" oder "+ 100.8 1234"). Die Funktion gibt das
 * Ergebnis der Operation als double zurück. Die Funktion muss die folgenden
 * Operationen unterstützen: + - / *.
 *
 * @param operation Mathematische Operation im Postfix-Format
 * @return double Ergebnis der Berechnung
 */
double calculate(const std::string &operation);

/* Wer es etwas schwieriger haben möchte aktiviert dieses Define.
 * Die calculate Funktion muss dann eine std::invalid_argument exception werfen
 * wenn:
 * Nicht genau zwei Operanten übergeben werden.
 * Die Operanten keine Integer oder Double Zahlen sind.
 * Eine Division durch 0 probiert wird.
 * Eine Operation versucht wird die nicht + - / * ist.
 */
// #define VALIDATE_INPUT_CALCULATE

/**
 * @brief Erkennt wiederholte Wörter in einem Eingabetext (die zweite Instanz
 * des wiederholten Wortes folgt unmittelbar auf die erste). Die Funktion gibt
 * die Anzahl der gefundenen wiederholten Wörter zurück (zwei Instanzen zählen
 * als ein wiederholtes Wort).
 *
 * @param sentence Eingabetext der Analysiert wird.
 * @return int32_t Anzahl wiederholter Wörter.
 */
int32_t count_repeated_words(const std::string &sentence);

/**
 * @brief Übersetzt die übergebene Zeichenfolge in eine Zahlenfolge, die dem
 * ASCII-Wert der Zeichen in der Zeichenfolge entspricht. Die Zahlenfolge wird
 * als String dargestellt. Beispielsweise wird "Aa 3" als Eingabezeichenfolge
 * zu "65 97 32 51" als Ausgabezeichenfolge führen.
 *
 * @param ascii_string String von ASCII Zeichen
 * @return std::string String der ASCII Zeichen als Zahlenfolge
 */
std::string as_ascii_index(const std::string &ascii_string);


bool isNotAlphabet(char c);