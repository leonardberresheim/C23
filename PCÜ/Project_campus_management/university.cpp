#include "university.h"
#include "persons.h"

//------------------------------------------------------------------------
// -------------------- University ---------------------------------------

University::University(const std::string &name, Address &address) : m_address(address) {
    if(name.length() < 10){
        throw std::invalid_argument("Name of University is to short!");
    }else{
        this->m_name = name;
    }
}

University::~University() {
    for(int i = 0; i < m_teachers.size(); i++){
        this->lay_off(*m_teachers[i]);
    }
    for(int i = 0; i < m_students.size(); i++){
        this->exmatriculate(*m_students[i]);
    }
}

void University::enroll(Student &student) {
    this->m_exmat_flag = true;
    bool isAlreadyHired = false;
    for(int i = 0; i < m_students.size(); i++){
        if(m_students[i] == &student){
            isAlreadyHired = true;
            break;
        }
    }
    if(isAlreadyHired == false){
        this->m_students.push_back(&student);
        if(student.exmat_flag() == false){
            student.enroll(*this);
        }
    }
    this->m_exmat_flag = false;
}

void University::exmatriculate(Student &student) {
    this->m_exmat_flag = true;
    for(int i = 0; i < m_students.size(); i++){
        if(m_students[i] == &student){
            if(m_students[i]->exmat_flag() == false){
                student.exmatriculate();
            }
            m_students.erase(m_students.begin() + i);
            break;
        }
    }
    this->m_exmat_flag = false;
}

void University::hire(Teacher &teacher, std::int32_t loan) {
    bool isAlreadyHired = false;
    for(int i = 0; i < m_teachers.size(); i++){
        if(m_teachers[i] == &teacher){
            isAlreadyHired = true;
            break;
        }
    }
    if(isAlreadyHired == false){
        this->m_teachers.push_back(&teacher);
        teacher.hire(*this, loan);
    }
}

void University::lay_off(Teacher &teacher) {
    for(int i = 0; i < m_teachers.size(); i++){
        if(m_teachers[i] == &teacher){
            teacher.lay_off();
            m_teachers.erase(m_teachers.begin() + i);
            break;
        }
    }
}

Course & University::offer_course(const std::string &name, Teacher &teacher) {
    bool courseAlreadyExists = false;
    for(int i = 0; i < m_courses.size(); i++){
        if(m_courses[i]->name() == name){
            courseAlreadyExists = true;
        }
    }
    if(courseAlreadyExists == false){
        Course *newCourse = new Course(name);
        m_courses.push_back(newCourse);
        newCourse->assign_teacher(teacher);
    }
}

std::string University::name() const {
    return m_name;
}

std::vector<Teacher *> & University::list_teachers() {
    return list_teachers();
}

std::vector<Student *> & University::list_students() {
    return list_students();
}

std::vector<Course *> & University::list_courses() {
    return m_courses;
}

std::string University::to_string() const {
    std::string str;
    str = "University: "+ this->m_name + "\n\n" + this->m_address.to_string() + "\n\nAnzahl Studierender: " + std::to_string(m_students.size()) + "\n";
    for(int i = 0; i < m_students.size(); i++){
        str += m_students[i]->first_name() + " " + m_students[i]->last_name() + "\n";
    }
    str += "\nAnzahl Lehrkräfte: " + std::to_string(m_students.size()) + "\n";
    for(int i = 0; i < m_teachers.size(); i++){
        str += m_teachers[i]->first_name() + " " + m_teachers[i]->last_name() + "\n";
    }
    str += "\nAnzahl Seminare: " + std::to_string(m_courses.size()) + "\n";
    for(int i = 0; i < m_courses.size(); i++){
        str += m_courses[i]->name() + "\n";
    }
    str += "\n";
    return str;
}

bool University::exmat_flag() {
    return m_exmat_flag;
}

//------------------------------------------------------------------------
// -------------------- Course -------------------------------------------

Course::Course(const std::string &name) {
    if(name.length() < 10){
        throw std::domain_error("Name of course is to short!");
    }else{
        this->m_name = name;
    }
}

Course::~Course() {
    this->resign_teacher();
    for(int i = 0; i < m_students.size(); i++){
        this->leave(*m_students[i]);
    }
}

void Course::enlist(Student &student) {
    bool isAlreadyEnlisted = false;
    for(int i = 0; i < m_students.size(); i++){
         if(m_students[i] == &student){
             isAlreadyEnlisted = true;
         }
    }
    if(isAlreadyEnlisted == false){
        m_students.push_back(&student);
        student.enlist(*this);
    }
}

void Course::leave(Student &student) {
    for(int i = 0; i < m_students.size(); i++){
        if(m_students[i] == &student){
            student.leave(*this);
            m_students.erase(m_students.begin() + i);
            break;
        }
    }
}

void Course::assign_teacher(Teacher &teacher) {
    m_assigning_flag = true;
    if(m_teacher == NULL){
        m_teacher = &teacher;
        if(teacher.assign_flag() == false){
            teacher.assign_course(*this);
        }
    }else{
        this->resign_teacher();
    }
    m_assigning_flag = false;
}

void Course::resign_teacher() {
    m_assigning_flag = true;
    if(m_teacher->assign_flag() == false){
        m_teacher->resign_course(*this);
    }
    m_teacher = NULL;
    m_assigning_flag = false;
}

std::vector<Student *> & Course::list_students() {
    return m_students;
}

Teacher * Course::teacher() {
    return m_teacher;
}

std::string Course::name() const {
    return m_name;
}

bool Course::assign_flag(){
    return m_assigning_flag;
}

std::string Course::to_string() const {
    std::string str;
    str = "Seminar: " + this->m_name + "\n\nLehrkraft: " + m_teacher->first_name() + " " + m_teacher->last_name() + "\n\nAnzahl Studierende: " + std::to_string(m_students.size()) + "\n";
    for(int i = 0; i < m_students.size(); i++){
        str += m_students[i]->first_name() + " " + m_students[i]->last_name() + "\n";
    }
    str += "\n";
    return str;
}

//------------------------------------------------------------------------
// -------------------- Address ------------------------------------------

Address::Address(const std::string &street, const std::int32_t streetNo, const std::string zipcode, const std::string city, const std::string country){
    if(street.length() < 10 || streetNo <= 0 || city.length() < 3 || country.length() < 3 || !isOnlyNumber(zipcode) || zipcode.length() != 5){
        throw std::domain_error("Konstruktor arguments are incorrect!");
    }else{
        this->m_street = street;
        this->m_street_no = streetNo;
        this->m_zipcode = zipcode;
        this->m_city = city;
        this->m_country = country;
    }
}

std::string Address::to_string() const {
    return this->m_street + " " + std::to_string(this->m_street_no) + "\n" + this->m_zipcode + " " + this->m_city + "\n" + this->m_country + "\n";;
}

const bool Address::isOnlyNumber(std::string str) {
    for(int i = 0; i <= str.length(); i++){
        if(str[i] < 48 || str[i] > 57){
            return false;
        }else{
            return true;
        }
    }
    return true;
}