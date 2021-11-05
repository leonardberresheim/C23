#include "weekdays.h"

weekday::weekday() noexcept {
    this->m_day = Monday;
}

weekday::weekday(const std::string &day){
    if(day == "Monday" || day == "monday"){
        this->m_day = Monday;
    }else if(day == "Tuesday" || day == "tuesday"){
        this->m_day = Tuesday;
    }else if(day == "Wednesday" || day == "wednesday"){
        this->m_day = Wednesday;
    }else if(day == "Thursday" || day == "thursday"){
        this->m_day = Thursday;
    }else if(day == "Friday" || day == "friday"){
        this->m_day = Friday;
    }else if(day == "Saturday" || day == "saturday"){
        this->m_day = Saturday;
    }else if(day == "Sunday" || day == "sunday"){
        this->m_day = Sunday;
    }else{
        throw std::invalid_argument("Parameter is not a valid weekday!");
    }
}

weekday::weekday(const std::int8_t day){
    switch(day){
        case 0:
            this->m_day = Monday;
            break;
        case 1:
            this->m_day = Tuesday;
            break;
        case 2:
            this->m_day = Wednesday;
            break;
        case 3:
            this->m_day = Thursday;
            break;
        case 4:
            this->m_day = Friday;
            break;
        case 5:
            this->m_day = Saturday;
            break;
        case 6:
            this->m_day = Sunday;
            break;
        default:
            throw std::invalid_argument("Parameter is not a valid weekday (0-6)!");
    }
}

void weekday::increment() noexcept {
    this->m_day = Days((this->m_day + 1) % 7);
}

void weekday::increment(std::int32_t days) noexcept {
    for(int i = 0; i < days; i++){
        increment();
    }
}

void weekday::decrement() noexcept {
    this->m_day = Days((7+(this->m_day - 1))%7);
}

void weekday::decrement(std::int32_t days) noexcept {
    for(int i = 0; i < days; i ++){
        this->decrement();
    }
}

int8_t weekday::current_day() const noexcept {
    return m_day;
}

void weekday::printDay(){
    std::cout << this->m_day << std::endl;
}