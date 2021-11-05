#include <iomanip>
#include "date.h"

Date::Date() noexcept{
    m_time.tm_year = 1583;
    m_time.tm_mon = 1;
    m_time.tm_mday = 1;
}

Date::Date(const std::int8_t day, const std::int8_t month, const std::int32_t year) {
    if((year <= 1583) || (year > 9999) || (day < 1) || (day > 31) || (month < 1) || (month > 12)){
        throw std::invalid_argument("Parameter for day, month or year are incorrect!");
    }else if(month == 2){
        if(!((year % 400 == 0) || ((year % 100) != 0 && (year % 4) == 0)) && day > 28){
            throw std::invalid_argument("Achtung - It's not a Schaltyear - Day is wrong!!");
        }
    }else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            throw std::invalid_argument("Succeeded the numbers of days in month (30)");
        }
    }
    m_time.tm_year = year;
    m_time.tm_mon = month;
    m_time.tm_mday = day;
}

int8_t Date::day() const noexcept{
    return m_time.tm_mday;
}

int8_t Date::month() const noexcept {
    return m_time.tm_mon;
}

std::int32_t Date::year() const noexcept {
    return m_time.tm_year;
}

std::int8_t Date::weekday() const noexcept {
    std::tm time_in = {0,0,0,this->day(), this->month()-1, this->year()-1900};
    std::time_t time_tmp = std::mktime(&time_in);

    const std::tm *time_out = std::localtime(&time_tmp);
    if(time_out->tm_wday == 0){
        return 7;
    }else{
        return (time_out->tm_wday);
    }

}

std::string Date::to_string() const noexcept {
    std::string month, day;
    if(this->month() < 10){
        month = "0" + std::to_string(this->month());
    }else{
        month = std::to_string(this->month());
    }
    if(this->day() < 10){
        day = "0" + std::to_string(this->day());
    }else{
        day = std::to_string(this->day());
    }
    return std::to_string(year()) + "-" + month + "-" + day;
}