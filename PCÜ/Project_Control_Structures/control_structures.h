#pragma once

#include <string>

using namespace std;

enum Days_t { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

string day_to_string_en(Days_t day);
Days_t day_from_string_en(string day);
bool is_odd(int64_t num);
bool is_even(int64_t num);
int64_t max(int64_t a, int64_t b);
int64_t min(int64_t a, int64_t b);