#include <iostream>
#include "fizz_buzz.h"

int main() {
    std::int32_t limit = positive_int_from_stdin();
    std::cout << limit << std::endl;
    fizz_buzz(limit);
    return 0;
}
