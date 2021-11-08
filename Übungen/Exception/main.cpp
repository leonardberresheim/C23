#include <iostream>

template <class X, std::size_t Y>
constexpr std::size_t length(const X (&array)[Y]) noexcept
{
    return Y;
}

#define AUFGABE1

#ifdef AUFGABE1

// ----------------------------------------------------------------------
// ------------ Ausgabe 1 -----------------------------------------------
// Bei einer Falschen Eingabe soll das Programm abgebrochen werden.

int main() {
    char ziffer;
    std::cout << "Bitte geben Sie eine Ziffer ein: ";
    std::cin >> ziffer;

    if(!std::isdigit(ziffer)){
        std::cout << "Eingabe ist keine Ziffer" << std::endl;
    }else{
        std::cout << "Gut gemacht!" << std::endl;
    }
    return 0;
}

// Schreibe den Code so um, dass bei einer falschen Eingabe der Nutzer erneut nach einer Eingabe gefragt wird.
// Bei erneuter falschen Eingabe bricht das Programm ab
#endif

// ----------------------------------------------------------------------
// ------------ Ausgabe 2 -----------------------------------------------
// Der Nutzer gibt 2 Zahlen ein. Die eine wird durch die andere geteilt. Die Division durch 0 soll abgefangen werden.
#ifdef AUFGABE2
int main(){
    double numberA, numberB;

    std::cout << "Enter two numbers - Number A will be divided by Number B" << std::endl;
    std::cout << "NumberA : ";
    std::cin >> numberA;
    std::cout << "NumberB : ";
    std::cin >> numberB;

    double result = numberA  / numberB;
    std::cout << numberA << "/" << numberB << " = " << result << std::endl;

    return 0;
}

#endif

#ifdef AUFGABE2b
// Es soll ein Array erstellt wernde, der Nutzer gibt die Länge des Arrays for.
// Was passiert wenn der Nutzer eine Fasche eingabe tätigt.
int main(){

    int len;
    std::cout << "Please enter the length of array: ";
    std::cin >> len;

    int *numbers = new int[len];

    return 0;
}

#endif

// ----------------------------------------------------------------------
// ------------ Ausgabe 3 -----------------------------------------------
// Folgendes Program umschreiben um Exceptions zu benutzten.
#ifdef AUFGABE3
bool printLineSuccess(std::string text) {
    for(int i = 0; i < text.length(); i++){
        if(!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122) || (text[i] == ' '))){
            return false;
        }
    }
    std::cout << text << std::endl;

    return true;
}

int main(){
    std::string text;
    std::cout << "Enter a text with only letters: ";
    getline(std::cin, text, '\n');
    if(!printLineSuccess(text)){
        std::cout << "Only letters are allowed!";
    }
    return 1;
}

#endif

// ----------------------------------------------------------------------
// ------------ Ausgabe 4 -----------------------------------------------
// Der Nutzer soll Ziffer für Ziffer einen String eingeben, der String kann aber nur 5 Zeichen lang sein.
// Wenn der String "überläuft" soll eine Exception ausgegeben werden. Außerdem soll ein Fehler ausgegeben werden,
// wenn der Nutzer ein Leerzeichen eingibt


#ifdef AUFGABE4
char getChar(){
    std::string c;
    std::cout << "Character: ";
    getline(std::cin, c, '\n');
    if(c[0] == ' '){
        return NULL;
    }else{
        return c[0];
    }
}

int main(){
    std::cout << "Type in a word - enter $ to stop" << std::endl;
    std::string word = "";


    while(1){
        char c = getChar();
        if(c == NULL){
            std::cout << "Not a char!" << std::endl;
        }else if(c == '$'){
            std::cout << "Your word ist: " << word << std::endl;
            break;
        }
        else{
            if(word.length() < 5) {
                word += c;
            }else{
                std::cout << "Word is to long" << std::endl;
                break;
            }
        }
    }

    return 0;
}

// Was wenn der Nutzer 2 Zeichen eingibt.

#endif

#ifdef AUFGABE5
// Für Aufgabe 1 soll eine eigene Exception class implementiert werden die folgendes ausgibt:
// <eingabe> is not a digit!

int main() {
    try {
        char ziffer;
        std::cout << "Bitte geben Sie eine Ziffer ein: ";
        std::cin >> ziffer;

        if(!std::isdigit(ziffer)){
            throw std::domain_error("Is not a digit");
        }else{
            std::cout << "Gut gemacht!" << std::endl;
        }
    }
    catch (std::domain_error e) {
        std::cout << e.what();

    }
    return 0;
}
#endif