#include "fizz_buzz.h"	

std::int32_t positive_int_from_stdin(){

        std::string input;
        std::cout << "Gebe eine positive ganze Zahl ein : ";

        getline(std::cin, input, '\r');

        if(input.empty()){
            throw std::domain_error("Geben Sie bitte eine positive ganze Zahl ein!");
        }
        for(int i = 0; i < input.length(); i++){
            if(std::isdigit(input[i]) == false){
                throw std::domain_error("Geben Sie bitte eine positive ganze Zahl ein!");
            }
        }
        return std::stoi(input);


    /*catch(std::domain_error &e){
        std::cerr << e.what();
    }*/

}

void fizz_buzz(std::int32_t limit){
    for(int i = 1; i <= limit; i++){
        if(is_divisible_by(i,3) && is_divisible_by(i,5)){
            std::cout << "Fizz Buzz" << std::endl;
        }else if(is_divisible_by(i,3)){
            std::cout << "Fizz" << std::endl;
        }else if(is_divisible_by(i,5)){
            std::cout << "Buzz" << std::endl;
        }else{
            std::cout << i << std::endl;
        }
    }
}

bool is_divisible_by(std::int32_t lhs, std::int32_t rhs){
    if(rhs == 0){
        return false;
    }
    if((lhs % rhs) == 0){
        return true;
    }else{
        return false;
    }
}
