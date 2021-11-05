#include <iostream>
#include "weekdays.h"

int main() {

    Weekday otherDay = Weekday(1);
    otherDay.decrement(14);
    otherDay.printDay();
    Weekday someDay = Weekday(4);
    someDay.decrement(2);
    someDay.printDay();

    return 0;
}
