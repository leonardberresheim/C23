#pragma once

#include <cstdint>
#include <iostream>

/**
 * @brief Liest eine positive Ganze Zahl von der Standardeingabe.
 *
 * @throw std::domain_error Wenn übergebene Zahl nicht eine positive Ganze Zahl
 * ist.
 * @return std::int32_t
 */
std::int32_t positive_int_from_stdin();

/**
 * @brief Spielt das Spiel Fizz Buzz, bis zur übergebenen Grenze.
 *
 * @param limit Positive Grenze zu der gezählt wird.
 *
 */
void fizz_buzz(std::int32_t limit);

/**
 * @brief Testet auf Restlose Teilbarkeit zweier Zahlen.
 *
 * @param lhs Dividend
 * @param rhs Divisor
 * @return true Der Dividend ist restlos durch den Divisor teilbar.
 * @return false Der Dividend ist nicht restlos durch den Divisor teilbar.
 */
bool is_divisible_by(std::int32_t lhs, std::int32_t rhs);