#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Fahrzeug{
public:
    //
    Fahrzeug(int verfuegbar, int preis, std::string name) : m_verfuegbar(verfuegbar), m_preis(preis), m_name(name) {
        anzahlFahrzeuge += 1;
        m_id = name[0] + (name[1] + std::to_string(anzahlFahrzeuge));
    }

    //
    static int anzahlFahrzeuge;

    //
    inline bool getVerfuegbarkeit() const {return m_verfuegbar;}

    std::string getId() const {return m_id;}

    //
    virtual std::string toString() const = 0;

protected:
    bool m_verfuegbar;
    int m_preis;
    std::string m_id;
    std::string m_name;

    //
    friend void prepareVehicle(Fahrzeug* pF);
};

//
int Fahrzeug::anzahlFahrzeuge = 0;

//
class Fahrrad : public Fahrzeug{
public:
    Fahrrad(int verfuegbar, int preis, std::string name, bool isElectric) : m_isElectric(isElectric),
                                                                                            Fahrzeug(verfuegbar,preis,name) {}
    //
    std::string toString () const override{
        return "The " + m_name + (m_isElectric ? "electric" : "non-electric") + " bike (" + m_id + ") is " +
               (m_verfuegbar ? "available" : "unavailable") + " for " + std::to_string(m_preis) + "€" + "\n";
    }
private:
    bool m_isElectric;
};

class MotorisiertesFahrzeug : public Fahrzeug{
public:
    // FEHLER
    MotorisiertesFahrzeug(int verfuegbar, int preis, std::string name, int tankStand, int maxTankCapacity) :
                            Fahrzeug(verfuegbar,preis,name){
        m_tankStand = tankStand;
        m_maxTankCapacity = maxTankCapacity;
    }

    void refuel(int fuelVolume){
        if(m_tankStand + fuelVolume > m_maxTankCapacity)
            m_tankStand = m_maxTankCapacity;
        else
            m_tankStand += fuelVolume;
        std::cout << "Fuel level now: " << m_tankStand << "L" << std::endl;
    }
protected:
    int m_tankStand;
    const int m_maxTankCapacity;
};

class PKW : public MotorisiertesFahrzeug{
public:
    PKW(int verfuegbar, int preis, std::string name, int tankStand, int maxTankCapacity, int anzahlSitze) : m_anzahlSitze(anzahlSitze),
           MotorisiertesFahrzeug(verfuegbar, preis,name,tankStand,maxTankCapacity){}
    //
    std::string toString () const final{
        return "The " + m_name + " car (" + m_id + ") is " +
               (m_verfuegbar ? "available" : "unavailable") + " for " + std::to_string(m_preis) + "€\nSpecification:\nNumber of seats: " + std::to_string(m_anzahlSitze)
               + "\nTankstand: " + std::to_string(m_tankStand) + "\nMax speed: " + std::to_string(m_maxTankCapacity) + "\n";
    }
private:
    int m_anzahlSitze;
};

class LKW : public MotorisiertesFahrzeug{
    LKW(int verfuegbar, int preis, std::string name, int tankStand, int maxTankCapacity, int last) : m_last(last), MotorisiertesFahrzeug(verfuegbar, preis,name,tankStand,maxTankCapacity){}
private:
    std::string toString () const override{
        return "The " + m_name + " car (" + m_id + ") is " +
               (m_verfuegbar ? "available" : "unavailable") + " for " + std::to_string(m_preis) + "€\nSpecification:\nLoad: " + std::to_string(m_last)
               + "\nTankstand: " + std::to_string(m_tankStand) + "\nMax speed: " + std::to_string(m_maxTankCapacity) + "\n";
    }
    int m_last;
};

//
std::ostream& operator<<(std::ostream &os, const Fahrzeug& rF){
    os << rF.toString();
    return os;
}

class Inventory{
public:
    Inventory(){
        //
        warehouseInventory.clear();
        onlineInventory.clear();
    };

    void addToInventory(Fahrzeug &rF, bool online){
        //
        std::vector<Fahrzeug*>* pInventory;
        //
        if(online){
            pInventory = &onlineInventory;
        }else{
            pInventory = &warehouseInventory;
        }
        //
        auto inventoryIt = std::find_if(pInventory->begin(), pInventory->end(), [&rF](const Fahrzeug *v)->bool{return v->getId() == rF.getId();});
        //
        if(inventoryIt == pInventory->end()){
            //
            pInventory->push_back(&rF);
        }
    }

    void printInventory(){
        std::cout << "List of vehicles in Warehouse-Inventory: " << std::endl;
        //
        for(auto c : onlineInventory){
            //
            std::cout << *c << std::endl;
        }

        for(auto c : warehouseInventory){
            //
            std::cout << c->toString() << std::endl;
        }
    }

private:
    //
    std::vector<Fahrzeug*> warehouseInventory, onlineInventory;
};



void prepareVehicle(Fahrzeug *pV) {
    //
    auto *pM = dynamic_cast<MotorisiertesFahrzeug *>(pV);
    //
    if (pM != nullptr)
        pM->refuel(100);

    //
    std::cout << "Vehicle " << pV->m_id << " is ready" << std::endl;
}



int main() {
    // FEHLER
    MotorisiertesFahrzeug m1 = MotorisiertesFahrzeug(true, 200, "Audi A2", 50, 150);

    // FEHLER
    const Inventory v1;
    v1.printInventory()
    return 0;
}

