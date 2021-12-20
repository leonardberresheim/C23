#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Object;
class World;

class Displayable{
    // 3 Pts
    virtual std::string to_string() const = 0;
};

// 2 Pts
class Object : Displayable{
public:
    // 2 Pts
    Object(int x, int y) : m_x(x), m_y(y), m_world(nullptr) {}
    // 2 Pts
    std::string to_string() const override;

    void spawn(World &w);

    // 2 Pts
    inline int getX() const {return m_x;}
    int getY() const {return m_y;}

// 2 Pts
protected:
    int m_x, m_y;
    World* m_world;

    // 4 Pts
    friend bool operator==(Object &rO1, Object &rO2);
};


class World : Displayable{
public:
    // 3 Pts
    World(int length, int height, std::string name) : m_length(length), m_height(height), m_name(name){
        m_objects.clear();
    }

    inline std::string getName() const {return m_name;}

    void insert(Object &obj);

    // 4 Pts
    bool isIn(const Object &rO) const{
        std::cout << rO.getX() << " | " << rO.getY() << " | " << m_length << " | " << m_height;
        if(rO.getX() >= 0 && rO.getX() <= m_length && rO.getY() >= 0 && rO.getY() <= m_height){
            return true;
        }else{
            return false;
        }
    }

    // 2 Pts
    std::string to_string() const final{
        std::string str = "";
        str += m_name + " : (" + std::to_string(m_length) + " x " + std::to_string(m_height) + ")\n";
        // 2 Pts
        for(auto c : m_objects){
            str += c->to_string();
        }
        return str;
    }
protected:
    std::string m_name;
private:
    const int m_length, m_height;
    std::vector<Object*> m_objects;
};

class Player : public Object{
public:
    Player(std::string name, int x, int y) : m_name(name), Object(x,y){}
    std::string to_string() const override{
        return m_name + " at " + this->Object::to_string();
    }

    void operator<(int i);
    void operator^(int i);
    inline std::string getName(){return m_name;}
private:
    std::string m_name;
};

// 4 Pts
class ObjectException{
public:
    ObjectException(const Object &rO, const World &rW, int mode) : m_mode(mode), m_objectName(rO.to_string()), m_worldName(rW.getName()){}
    std::string getError(){
        if(m_mode == 0)
            return "Object: \n" + m_objectName + "already spawned in: " + m_worldName + "\n";
        else if(m_mode == 1){
            return "An object already exists at this position for " + m_objectName;
        }else{
            return m_objectName + " reached the limits of " + m_worldName;
        }
    }
private:
    int m_mode;
    std::string m_objectName, m_worldName;
};


std::string Object::to_string() const {
    std::string str = "Position: (" + std::to_string(m_x) + " | " + std::to_string(m_y) + ")";
    if(m_world){
        str += " in " + m_world->getName();
    }
    str += "\n";
    return str;
}

void Object::spawn(World &w){
    if(m_world != &w){
        m_world = &w;
        // 2 Pts
        m_world->insert(*this);
    }else{
        // 2 Pts
        throw ObjectException(*this,w,0);
    }
}

// 2 Pts
bool operator==(Object &rO1, Object &rO2) {
    // 2 Pts
    auto it1 = dynamic_cast<Player*>(&rO1);
    auto it2 = dynamic_cast<Player*>(&rO2);
    // 2 Pts
    if(it1 != nullptr && it2 != nullptr){
        return it1->getName() == it2->getName();
    }else{
        return(rO1.m_x == rO2.m_x && rO1.m_y == rO2.m_y);
    }
}

void World::insert(Object &obj){
    // 3 Pts
    auto it = std::find_if(m_objects.begin(), m_objects.end(), [&obj](const Object* pO)->bool{return (obj.getX() == pO->getX() && obj.getY() == pO->getY());});
    // 1 Pts
    if(it == m_objects.end()){
        // 2 Pts
        m_objects.push_back(&obj);
    }else{
        // 2 Pts
        throw ObjectException(obj, *this, 1);
    }
}

// 2 Pts
void Player::operator<(int i){
    // 2 Pts
    if(m_world->isIn(Object(m_x-i,m_y))){
        m_x += i;
    }else{throw ObjectException(*this,*m_world,2);}
}
void Player::operator^(int i){
    if(m_world->isIn(Object(m_x,m_y+i))){
        m_y += i;
    }else{throw ObjectException(*this,*m_world,2);}
}

int main() {
    Object o1(5,5);
    Object o2(5,5);
    World w1(100,100,"HTW-G505");
    // 2 Pts
    try{
        o1.spawn(w1);
        o1.spawn(w1);
    }catch(ObjectException &e){
        std::cout << e.getError();
    }

    try{
        o2.spawn(w1);
    }catch(ObjectException &e){
        std::cout << e.getError();
    }

    Player p1("Uwe", 15,99);
    p1.spawn(w1);
    std::cout << p1.to_string();

    try{
        p1^3;
    }catch(ObjectException &e){
        std::cout << e.getError();
    }
    std::cout << p1.to_string();

    //std::cout << w1.to_string();
    return 0;
}
