#include <iostream>
#include <string>

#define AUFGABE1


// ----------------------------------------------------------------------
// ------------ Ausgabe 1 -----------------------------------------------
// Wie muss der Code umgeschrieben werden damit er funktioniert?
#ifdef AUFGABE1
class Shape {
protected:
    int width;
    int height;
public:
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
    int getWidth(){
        return width;
    }
};

class Rectangle : private Shape{
public:
    int getArea() {
        return (getWidth() * height);
    }
    using Shape::height;

};

int main(void) {
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);
    Rect.height;
    // Print the area of the object.
    std::cout << "Total area: " << Rect.getArea() << std::endl;

    return 0;
}
#endif;

// Was passiert wenn die Vererbung als private angegeben wird?
// Was wenn die member Variablen von Shape private sind?
// Wie sieht das Klassendiagram für diesen Code aus?



// ----------------------------------------------------------------------
// ------------ Ausgabe 2 -----------------------------------------------
// Wie muss der Code umgeschrieben werden damit er funktionniert?

#ifdef AUFGABE2

class Entity {
    float x =0 , y = 0;
public:

	void Move(float xa, float ya) {
		x += xa;
		y += ya;
	}
};

class Player : public Entity{
private:
    using Entity::y;
public :
	const char* name = nullptr;
	void Print() {
		std::cout << name << std::endl;
	}
    void setX(float x){
        this->x = x;
    }

};
int main()
{
	Player D;
	D.setX(5.5f);
	D.y = 4.4f;
	D.Move(1.1f,2.2f);
	D.name = "Caleb";
	D.Print();

	std::cout <<"Size of Entity was : " << sizeof(Entity) << std::endl;
	std::cout <<"Size of Player was : "<< sizeof(Player) << std::endl;

	std::cin.get();
}

// In cpp hat man member-variablen lieber beschützt - Wie müsste der Code umgeschrieben werden?
// Wie sieht das Klassendiagram für diesen Code aus?
#endif;

// ----------------------------------------------------------------------
// ------------ Ausgabe 3 -----------------------------------------------
// Wie muss der Code ergänzt werden damit er funktioniert
#ifdef AUFGABE3
class Employee
{
protected:
    int id;
    float salary;
public:

    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    Employee() {}
};

class Programmer : public Employee
{
protected:
    int languageCode;
public:

    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }
    void getData(){
        std::cout<<id<<std::endl;
    }
};





int main()
{
    Employee harry(1), rohan(2);
    std::cout << harry.salary << std::endl;
    std::cout << rohan.salary << std::endl;
    Programmer skillF(10);
    std::cout << skillF.salary;
    std::cout << skillF.languageCode<<std::endl;
    std::cout << skillF.id<<std::endl;
    skillF.getData();
    return 0;
}

// Wie muss der Code umgeschrieben werden damit die Member-Variablen der beiden Funktionnen beschüzt sind
// Wie sieht das Klassendiagram aus?
#endif

// ----------------------------------------------------------------------
// ------------ Ausgabe 4 -----------------------------------------------
// Wie muss der Code ergänzt werden damit er funktioniert?

#ifdef AUFGABE4

class Name {
public:
  char firstname[80];
  char surname[80];
};

class Date {
public:
  int day;
  int month;
  int year;
  Date(){
      year = 0;
      month = 0;
      day = 0;
  }
  void show(){
      std::cout << month << "/" << day << "/" << year << std::endl;
  }
};

class Phone {
public:
      int areacode;
      int number;
};

class Person {
public:
    Date birthdate;
    Name name;
    Phone number;


    int age(Date& date) {
        if(date.year <= birthdate.year)
            return 0;
        int years = date.year - birthdate.year;
        if((date.month>birthdate.month) || (date.month == birthdate.month && date.day>= birthdate.day))
            return years;
        else
            return --years;
    }
};


int main() {
  Person her = {{ "L", "G" },
                {1, 4, 1976 },
                {999,5551234}
               };

  Person actress;
  actress = her;
  Date today = { 4, 4, 2007 };

  std::cout << std::endl << "Today is ";
  today.show();
  std::cout << std::endl;
  std::cout << "Today " << actress.name.firstname << " is "
       << actress.age(today) << " years old."
       << std::endl;
  std::cout << "Phonenumber is" << actress.number.number << std::endl;
  return 0;
}

// Fügen sie einen Konstruktor für die Klassen hinzu & "beschützen" sie die member-variablen
// Wie sieht das Klassendiagram aus.

#endif
// ----------------------------------------------------------------------
// ------------ Ausgabe 5 -----------------------------------------------
// Wie würde das Klassendiagram für diese Funktion aussehen.

#ifdef AUFGABE5
class Author {
private:
   std::string name;
   std::string email;
   char gender;   // 'm', 'f', or 'u' for unknown

public:
   Author(std::string name, std::string email, char gender);
   std::string getName() const;
   std::string getEmail() const;
   void setEmail(std::string email);
   char getGender() const;
   void print() const;
};
class Book {
private:
    std::string name;
    Author author; // data member author is an instance of class Author
    double price;
    int qtyInStock;

public:
    Book(std::string name, Author author, double price, int qtyInStock = 0);
    std::string getName() const;
    Author getAuthor() const;  // Returns an instance of the class Author
    double getPrice() const;
    void setPrice(double price);
    int getQtyInStock() const;
    void setQtyInStock(int qtyInStock);
    void print() const;
    std::string getAuthorName() const;
};

int main() {
    // Declare and construct an instance of Author
    Author peter("Peter Jones", "peter@somewhere.com", 'm');
    peter.print();  // Peter Jones (m) at peter@somewhere.com

    // Declare and construct an instance of Book
    Book cppDummy("C++ for Dummies", peter, 19.99);
    cppDummy.setQtyInStock(88);
    cppDummy.print();
    // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

    std::cout << cppDummy.getQtyInStock() << std::endl;  // 88
    std::cout << cppDummy.getPrice() << std::endl;       // 19.99
    std::cout << cppDummy.getAuthor().getName() << std::endl;  // "Peter Jones"
    std::cout << cppDummy.getAuthor().getEmail() << std::endl; // "peter@somewhere.com"
    std::cout << cppDummy.getAuthorName() << std::endl;        // "Peter Jones"

    Book moreCpp("More C++ for Dummies", peter, -19.99);
    // price should be positive! Set to 0
    std::cout << moreCpp.getPrice() << std::endl;   // 0
}
#endif

// ----------------------------------------------------------------------
// ------------ Ausgabe 6 -----------------------------------------------
// Ergänze den folgenden Code um die Klasse Bus und Zug

#ifdef AUFGABE6
class Motor
{
public:
    Motor(int ps) : m_ps(ps) { } // kein Standardkonstruktor
    int getPS() {return m_ps;}
private:
    int m_ps;
};

class Fahrzeug
{
public:
    Fahrzeug(int radAnzahl) : m_radAnzahl(radAnzahl) { }
    int getRadanzahl() { return m_radAnzahl; }
private:
    int m_radAnzahl;
};
class Auto: public Fahrzeug
{
public:
    Auto(int radAnzahl, int ps)
            : Fahrzeug(radAnzahl), m_motor(ps) {}
    Auto() : Fahrzeug(4), m_motor(98) { }
    int getPS() { return m_motor.getPS(); }
private:
    Motor m_motor;
};

class Bus : public Auto{
    std::string linie;
    int sitzplaetze;
};

class Zug : public {

};

int main()
{
    Auto erstwagen(6, 400);
    Auto zweitwagen;
    std::cout << "Erstwagen: " << std::endl
         << "PS: " << erstwagen.getPS() <<std::endl
         << "Anzahl der Raeder: " << erstwagen.getRadanzahl() <<std::endl;

}

// Wie würde das Klassendiagram aussehen.
#endif

#ifdef AUFGABE7
class Motor {
public:
    Motor(int ps) : m_ps(ps) {} // kein Standardkonstruktor
    int getPS() { return m_ps; }

private:
    int m_ps;
};
class Fahrzeug {
public:
    Fahrzeug(int radAnzahl) : m_radAnzahl(radAnzahl) {}

    int getRadanzahl() { return m_radAnzahl; }

private:
    int m_radAnzahl;
};
class Auto: public Fahrzeug{
public:
    // Constructor for 'Auto' must
    // explicitly initialize the member
    // 'm_motor' which does not have a default constructor
    Auto(int radAnzahl, int ps) : Fahrzeug(radAnzahl), m_motor(ps){

    }
    Auto(){ }
    int getPS() { return m_motor.getPS(); }
private:
    Motor m_motor;
};

int main() {
    Auto erstwagen(6, 400);
    Auto zweitwagen;
    std::cout << "Erstwagen: " << std::endl
         << "PS: " << erstwagen.getPS() << std::endl
         << "Anzahl der Raeder: " << erstwagen.getRadanzahl() << std::endl;
    std::cout << "\nZweitwagen: " << std::endl
         << "PS: " << zweitwagen.getPS() << std::endl
         << "Anzahl der Raeder: " << zweitwagen.getRadanzahl() << std::endl;
    return 0;
};
#endif