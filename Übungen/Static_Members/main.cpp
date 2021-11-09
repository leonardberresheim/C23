#include <iostream>


#define AUFGABE3


#ifdef AUFGABE1
// Gegeben Sei folgende Klasse. Diese soll erweitert werden um einen Zähler
// - der hochgezählt wird wenn ein Object dieser Klasse instanziert wird


class Object{
public:
    Object(const std::string &shape, const int &surface) : {}

private:
    std::string m_shape;
    int m_surface;

};



int main() {
    Object p1{"Circle", 50};
    Object p2 = Object("Cube", 32);
    Object p3("Pyramid", 100);
    return 0;
}

// Es soll eine weitere statische Variable hinzugefügt werden,
// die angibt ob wir uns im 2d oder 3d Raum befinden

#endif

#ifdef AUFGABE2
// Gegeben Sei die Klasse zahl. Diese Zahl soll erweitert werden um eine statische Variable, die die Summe
// aller Zahlen der Klasse speichert.
class Zahl{
    const int m_zahl;
};


int main(){

    return 0;
}

//

#endif


#ifdef AUFGABE3

#include <iostream>
using namespace std;

enum VehicleType {
    VT_TwoWheeler,    VT_ThreeWheeler,    VT_FourWheeler
};

// Library classes
class Vehicle {
public:
    virtual void printVehicle() = 0;
    static Vehicle* Create(VehicleType type);
};
class TwoWheeler : public Vehicle {
public:
    void printVehicle() {
        cout << "I am two wheeler" << endl;
    }
};
class ThreeWheeler : public Vehicle {
public:
    void printVehicle() {
        cout << "I am three wheeler" << endl;
    }
};
class FourWheeler : public Vehicle {
public:
    void printVehicle() {
        cout << "I am four wheeler" << endl;
    }
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
Vehicle* Vehicle::Create(VehicleType type) {
    if (type == VT_TwoWheeler)
        return new TwoWheeler();
    else if (type == VT_ThreeWheeler)
        return new ThreeWheeler();
    else if (type == VT_FourWheeler)
        return new FourWheeler();
    else return NULL;
}

// Client class
class Client {
public:

    // Client doesn't explicitly create objects
    // but passes type to factory method "Create()"
    Client()
    {
        VehicleType type = VT_ThreeWheeler;
        pVehicle = Vehicle::Create(type);
    }
    ~Client() {
        if (pVehicle) {
            delete[] pVehicle;
            pVehicle = NULL;
        }
    }
    Vehicle* getVehicle()  {
        return pVehicle;
    }

private:
    Vehicle *pVehicle;
};

// Driver program
int main() {
    Client *pClient = new Client();
    Vehicle * pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
    return 0;
}



#endif
