#pragma once

#include <string>
#include <iostream>

class Displayable {
public:
    virtual std::string to_string() const = 0;
};

