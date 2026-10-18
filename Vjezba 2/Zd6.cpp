/*Definirajte strukturu Student koja sadrži ime, JMBAG, godinu studija, broj položenih
ECTS bodova u godini i prosjek ocjena. Napišite funkciju
void filter_students(Student s[], int n,
void (*action)(Student&),
bool (*cond)(const Student&));
koja akciju izvrši nad svakim studentom koji zadovoljava uvjet. Akcije napišite kao
funkcije, a uvjete kao lambda izraze. Pozivom funkcije filter_students:
◦ ispišite sve studente prve godine koji su položili barem jedan ispit,
◦ ispišite sve studente s prosjekom većim od 3.5,
◦ povećajte godinu studija svim studentima koji su položili barem 45 ECTS bodova.*/

#include <iostream>
#include <string>

struct Student
{
    std::string ime;
    std::string JMBAG;
    int godStudija, ECTS;
    double prosjek;
};

void print_student(Student& s){
    std::cout << "Ime: " << s.ime << std::endl;
    std::cout << "JMBAG: " << s.JMBAG << std::endl;
    std::cout << "Godina studija: " << s.godStudija << std::endl;
    std::cout << "ECTS: " << s.ECTS << std::endl;
    std::cout << "Prosjek: " << s.prosjek << std::endl;
    std::cout << std::endl;
}

void visaGod(Student& s){
    s.godStudija++;
}

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&)){
    for (int i = 0; i < n; i++) {
        if (cond(s[i])){
            action(s[i]);
        }
    }
}

int main(){
    Student studenti[] = {
        {"Ivan", "1234567890", 3, 30, 4.2},
        {"Marko", "0987654321", 2, 45, 3.7},
        {"Filip", "1357924680", 1, 0, 2.9},
        {"Joisp", "0864297531", 3, 60, 3.2}
    };

    int n = sizeof(studenti) / sizeof(studenti[0]);

    
    filter_students(studenti, n, print_student, [](const Student& s){
            return s.godStudija == 1 && s.ECTS > 0;
        }
    );

    filter_students(studenti, n, print_student, [](const Student& s){
            return s.prosjek > 3.5;
        }
    );

    filter_students(studenti, n, visaGod, [](const Student& s){
            return s.ECTS >= 45;
        }
    );

    return 0;
}