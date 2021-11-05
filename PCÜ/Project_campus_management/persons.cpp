#include "persons.h"
#include "university.h"

//------------------------------------------------------------------------
// -------------------- Person -------------------------------------------

Person::Person(const std::string &first_name, const std::string &last_name, const std::chrono::system_clock::time_point &birthday, const Address &address){
    if(first_name.length() < 2 || !isOnlyAlphabet(first_name) || last_name.length() < 2 || !isOnlyAlphabet(last_name) || birthday > std::chrono::system_clock::now()){
       throw std::domain_error("Constructor arguments are invalid!");
    }else{
        this->m_first_name = first_name;
        this->m_last_name = last_name;
        this->m_birthday = birthday;
        m_place_of_residence = new Address(address);
    }
}

void Person::relocate(Address &place_of_residence) {
    this->m_place_of_residence = &place_of_residence;
}

const std::string & Person::last_name() {
    return this->m_last_name;
}

const std::string & Person::first_name() {
    return this->m_first_name;
}

const Address & Person::place_of_residence() {
    return *m_place_of_residence;
}

const std::chrono::system_clock::time_point Person::birthday() {
    return this->m_birthday;
}

std::string Person::to_string() const {
    std::time_t t = std::chrono::system_clock::to_time_t(m_birthday);
    return this->m_first_name + " " + this->m_last_name + "\n" + std::ctime(&t) + "\n\n" + m_place_of_residence->to_string() + "\n";
}

//------------------------------------------------------------------------
// -------------------- Student ------------------------------------------

std::int32_t Student::s_student_counter = 0;

Student::Student(const std::string &first_name, const std::string &last_name,
                 const std::chrono::system_clock::time_point &birthday, const Address &address) : Person(first_name, last_name, birthday, address), m_student_number(s_student_counter++){
}

Student::Student(Person &person) : Person(person), m_student_number(this->s_student_counter++){}

Student::~Student() {
    for(int i = 0; i < m_courses.size(); i++){
        this->leave(*m_courses[i]);
    }
    if(m_university != NULL){
        this->exmatriculate();
    }
}

void Student::enlist(Course &course) {
    bool isAlreadyEnlisted = false;
    for(int i = 0; i < m_courses.size(); i++){
        if(m_courses[i] == &course) {
            isAlreadyEnlisted = true;
            break;
        }
    }
    if(isAlreadyEnlisted == false){
        m_courses.push_back(&course);
        course.enlist(*this);
    }
}

void Student::leave(Course &course) {
    for(int i = 0; i < m_courses.size(); i++){
        if(m_courses[i] == &course){
            course.leave(*this);
            m_courses.erase(m_courses.begin() + i);
            break;
        }
    }
}

void Student::enroll(University &university) {
    this->m_exmat_flag = true;
    if(m_university != NULL){
        this->exmatriculate();
    }
    m_university = &university;
    if(university.exmat_flag() == false){
        university.enroll(*this);
    }
    this->m_exmat_flag = false;
}

void Student::exmatriculate() {
    this->m_exmat_flag = true;
    if(m_university != NULL){
        if(m_university->exmat_flag() == false){
            m_university->exmatriculate(*this);
        }
        m_university = NULL;
    }
    this->m_exmat_flag = false;
}

std::vector<Course *> & Student::list_courses(){
    return m_courses;
}

University * Student::university() {
    return m_university;
}

std::string Student::to_string() const {
    std::string str;
    str = Person::to_string();
    if(m_university != NULL){
        str += "\n\nUniversität: " + m_university->name() + "\nMatrikelnummer: " + std::to_string(this->m_student_number);
    }
    str += "\n\nAnzahl Seminare: " + std::to_string(m_courses.size()) + "\n";
    for(int i = 0; i < m_courses.size(); i++){
        str += m_courses[i]->name() + "\n";
    }
    return str;
}

bool Student::exmat_flag() {
    return m_exmat_flag;
}

//------------------------------------------------------------------------
// -------------------- Teacher ------------------------------------------

Teacher::Teacher(const std::string &first_name, const std::string &last_name,
                 const std::chrono::system_clock::time_point &birthday, const Address &address) : Person(first_name, last_name, birthday, address), m_loan(0){}

Teacher::Teacher(Person &person) : Person(person), m_loan(0){}

Teacher::~Teacher() {
    for(int i = 0; i < m_courses.size(); i++){
        this->resign_course(*m_courses[i]);
    }
    if(m_university != NULL){
        this->lay_off();
    }
}

void Teacher::assign_course(Course &course) {
    m_assigning_flag = true;
    bool isAlreadyAssigned = false;
    for(int i = 0; i < m_courses.size(); i++){
        if(m_courses[i] == &course){
            isAlreadyAssigned = true;
            m_assigning_flag = false;
            break;
        }
    }
    if(isAlreadyAssigned == false){
        m_courses.push_back(&course);
        if(course.assign_flag() == false){
            course.assign_teacher(*this);
        }
    }
    m_assigning_flag = false;
}

void Teacher::resign_course(Course &course) {
    this->m_assigning_flag = true;
    for(int i = 0; i < m_courses.size(); i++){
        if(m_courses[i] == &course){
            if(m_courses[i]->assign_flag() == false) {
                m_courses[i]->resign_teacher();
            }
            m_courses.erase(m_courses.begin() + i);
            this->m_assigning_flag = false;
            break;
        }
    }
    this->m_assigning_flag = false;
}

void Teacher::hire(University &university, std::int32_t loan) {
    if(this->m_university != NULL){
        this->lay_off();
    }
    this->m_university = &university;
    university.hire(*this, loan);
    if(loan < 1000){
        throw std::domain_error("The loan is unacceptable!");
    }else{
        this->m_loan = loan;
    }
}

void Teacher::lay_off() {
    if(this->m_university != NULL){
        m_university->lay_off(*this);
        m_university = NULL;
    }
}

std::vector<Course *> & Teacher::list_courses() {
    return m_courses;
}

University * Teacher::university() {
    return m_university;
}

std::string Teacher::to_string() const {
    std::string str;
    str = Person::to_string();
    if(m_university != NULL){
        str +=+ "\n\nUniversität: " + m_university->name() + "\nGehalt: " + std::to_string(this->m_loan);
    }
    str += "\n\nAnzahl Seminare: " + std::to_string(m_courses.size()) + "\n";

    for(int i = 0; i < m_courses.size(); i++){
        str += m_courses[i]->name() + "\n";
    }
    return str;
}

bool Teacher::assign_flag() {
    return m_assigning_flag;
}

const bool Person::isOnlyAlphabet(std::string str) {
    for(int i = 0; i < str.length(); i++){
        if((str[i] >= 65 && str[i] < 90) || (str[i] >= 97 && str[i] <= 122)){
            return true;
        }else{
            return false;
        }
    }
    return true;
}