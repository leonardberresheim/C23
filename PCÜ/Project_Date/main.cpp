#include "date.h"
#include <iostream>


int main() {
    Date date(18, 9, 2021);
    std::cout << date.weekday() << std::endl;
    std::cout << date.to_string();
}