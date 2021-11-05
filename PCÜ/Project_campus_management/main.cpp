#include <iostream>
#include "persons.h"
#include "university.h"
#include "traits.h"
using namespace std::chrono;
/**
 * Gibt ein beliebiges Objekt welches die abstrakte Displayable implementiert
 * auf der Standardausgabe aus, in dem es dessen to_string Methode nutzt. (2)
 *
 * @param displayable Das Objekt welches ausgegeben wird.
 */
void print_stdout(Displayable &displayable){
    std::cout << displayable.to_string() << std::endl;
}

std::chrono::system_clock::time_point strToTime(int year, int mon, int day){
    std::tm tm = {0,0,0,day,mon-1,year-1900};
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int main() {
    // 1. Legen Sie 3 Adressen an
    Address *address_1 = new Address("Berlinestr.", 12, "12044", "Berlin", "Germany");
    Address *address_2 = new Address("Hamburgerstr.", 13, "10392", "Hamburg", "Germany");
    Address address_3 = Address("Mexicostr.", 67, "11011", "Pekin", "China");
    // 2. Legen Sie zwei Personen an
    Person person_2 = Person("Jaqueline", "Shakira", std::chrono::system_clock::now(), address_3);
    Person *person_1 = new Person("Jamal", "Erikson", strToTime(1995, 5, 13), *address_1);
    // 3. Legen Sie 2 Lehrkräfte an, dabei soll eine Lehrkraft mit Hilfe eines der Personen Objekte erzeugt werden.
    Teacher *lehrer_1 = new Teacher(*person_1);
    Teacher *lehrer_2 = new Teacher("Leonard", "Berresheim", std::chrono::system_clock::time_point{1300000000s}, address_3);
    // 4. Legen Sie 3 Studierende an, dabei soll eine Studierende mit Hilfe des anderen Personen Objektes erzeugt werden.
    Student *student_1 = new Student(*person_1);
    Student *student_2 = new Student("Benjamin", "Alhari", std::chrono::system_clock::time_point{1389270934s}, *address_1);
    Student *student_3 = new Student("Ali", "Meier", std::chrono::system_clock::time_point{1389270934s}, *address_2);
    // 5. Legen Sie zwei Universitäten an, beide sollen an einer anderen Adresse liegen und einen anderen Namen haben.
    University *university_1 = new University("Humbold Universitaet", *address_1);
    University *university_2 = new University("Hochschule fuer technik", *address_2);
    // 6. Lassen Sie sich die Daten aller Objekte ausgeben.
    print_stdout(*address_1);
    print_stdout(*address_2);
    print_stdout(address_3);
    print_stdout(*person_1);
    print_stdout(person_2);
    print_stdout(*lehrer_1);
    print_stdout(*lehrer_2);
    print_stdout(*student_1);
    print_stdout(*student_2);
    print_stdout(*student_3);
    print_stdout(*university_1);
    print_stdout(*university_2);
    std::cout << "-----------------------------------------------------" << std::endl;
    // 7. Zwei Personen sollen danach an die gleiche Adresse ziehen.
    person_1->relocate(*address_2);
    person_2.relocate(*address_2);
    // 8. Lassen Sie sich die Daten der Personen und der Lehrkraft sowie der Studierenden ausgeben, welche aus den Personen erstellt wurden. Wohnen alle an der erwarteten Adresse? Können Sie sich das Verhalten erklären?
    print_stdout(*person_1);
    print_stdout(person_2);
    print_stdout(*lehrer_1);
    print_stdout(*student_1);
    /* Das passiert weil wir den Copy constructor benutzen, dieser verweißt nicht sondern kopiert ein object*/
    std::cout << "----------------------------------------------" << std::endl;
    // 9. Stellen Sie eine Lehrkraft an der ersten Universität an und eine an der zweiten Universität an. Beide sollen ein anderes Gehalt erhalten.
    university_1->hire(*lehrer_1, 5000);
    university_2->hire(*lehrer_2, 7500);
    // 10. Immatrikulieren Sie zwei Studierende an einer Universität und einen an der anderen.
    university_1->enroll(*student_1);
    university_1->enroll(*student_2);
    university_2->enroll(*student_3);
    // 11. Legen Sie zwei Kurse an dieser Universität an, die Kurse sollen jeweils einer Lehrkraft zugeordnet werden.
    university_1->offer_course("Angewandte Alchemie", *lehrer_1);
    university_1->offer_course("Forgeschrittene Inkonsistenz", *lehrer_2);
    // 12. Schreiben Sie die Studierenden in beide Kurse ein, dies soll über die Universität erfolgen.
    university_1->list_courses()[0]->enlist(*student_1);
    university_1->list_courses()[1]->enlist(*student_2);
    // 13. Prüfen Sie die Konsistenz der Verbindungen und Daten in dem Sie sich die Daten der Lehrkräfte, Studierenden und der Universitäten ausgeben lassen. Sehen Sie das gewünschte Ergebnis?
    print_stdout(*university_1);
    print_stdout(*university_2);
    print_stdout(*lehrer_1);
    print_stdout(*lehrer_2);
    print_stdout(*student_1);
    print_stdout(*student_2);
    // 14. Schreiben Sie eine Studentin an einer anderen Universität ein und Exmatrikulieren Sie einen Studenten.
    student_2->exmatriculate();
    student_1->enroll(*university_2);
    // 15. Lassen Sie eine Lehrkraft den Kurs der anderen Lehrkraft übernehmen.
    std::cout << "--------------------------------------------------" << std::endl;
    print_stdout(*lehrer_1);
    lehrer_1->assign_course(*university_1->list_courses()[1]);
    // 16. Prüfen Sie ein letztes Mal die Konsistenz der Verbindungen und Daten in dem Sie sich die Daten der Lehrkräfte, Studierenden und der Universitäten ausgeben lassen. Sehen Sie das gewünschte Ergebnis?
    std::cout << "--------------------------------------------------" << std::endl;
    print_stdout(*lehrer_1);
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    print_stdout(*university_1->list_courses()[0]);
}
