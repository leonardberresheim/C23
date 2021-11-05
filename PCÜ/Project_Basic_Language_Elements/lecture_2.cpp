#include "lecture_2.h"


void greet_person() {
    std::string vorname, nachname;
    int alter;
    std::cout << "Gebe deinen Vornamen ein : ";
    std::cin >> vorname;
    std::cout << "Deinen Nachnamen : ";
    std::cin >> nachname;
    std::cout << "Und dein Alter : ";
    std::cin >> alter;
    std::cout << "Hello " << vorname << " " << nachname << " (" << alter << ")!" << std::endl;
}

double calculate(const std::string &operation) {
    char op = operation[0];
    double result;
    bool nextNumber = false;
    bool number1IsInt = true, number2IsInt = true;
    std::string s_number1 = "", s_number2 = "";

    // Gehe jedes Zeichen in operation nacheinander durch ab [2] also der ersten Zahl
    for(int i = 2; i < operation.length(); i++){
        // Wenn ein Leerzeichen gefunden wird:
        if(operation[i] == ' '){
            // Ist die erste Zahl vorbei und wir beginnen mit der nächsten
            nextNumber = true;
        }else{
            // Wenn noch die erste Zahl betrachtet wird dann wird das aktuelle Zeichen in operation zum String s_number1 hinzugefügt
            if(nextNumber == false){
                s_number1 += operation[i];
            }else {
                // Ansonsten wird das aktuelkle Zeichen zu s_number2 hinzugefügt.
                s_number2 += operation[i];
            }
        }
    }

    // Beide Zahlen werden nach double konvertiert.
    double number1, number2;
    number1 = stod(s_number1);
    number2 = stod(s_number2);

    switch (op) {
        case '*':
            result = number1 * number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '+':
            result = number1 + number2;
            break;
        case '/':
            result = number1 / number2;
            break;

    }
    return result;
}

int32_t count_repeated_words(const std::string &input) {

    int numRepeatedWords = 0;
    std::istringstream ss(input);
    std::string word;
    std::vector<std::string> v_words;
    while(ss >> word){
        word.erase(std::remove_if(word.begin(), word.end(), &isNotAlphabet), word.end());
        if(!word.empty()){
            v_words.push_back(word);
        }

    }
    for(int i = 0; i < v_words.size()-1; i++){
        if(v_words[i] == v_words[i+1]){
            numRepeatedWords++;
        }
    }

    return numRepeatedWords;
}

std::string as_ascii_index(const std::string &ascii_string) {
    std::string ascii_numbers = "";
    char c;
    for(int i = 0; i < ascii_string.length(); i++){
        c = ascii_string[i];
        ascii_numbers += std::to_string((int)c);
        if(i != ascii_string.length()-1){
            ascii_numbers += " ";
        }
    }
    return ascii_numbers;
}

bool isNotAlphabet(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
        return false;
    }else{
        return true;
    }
}