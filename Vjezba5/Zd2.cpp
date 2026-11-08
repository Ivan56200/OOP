/*Klasa Clip predstavlja isječak pjesme od sekunde start do sekunde end. Zadana je u datoteci clip.cpp, zajedno s main:
Ispravite klasu tako da program ispiše "Concrete (Shame): 180 s"
Za svaku grešku objasnite zašto nastaje.
Hint 1: Dvije greške javlja kompajler. Pogledajte na predavanju koji članovi moraju dobiti vrijednost pri nastanku i što znači this->.
Hint 2: Treća greška nije greška pri kompajliranju: program se prevede, ali ispiše krivo trajanje. g++ uz -Wall na nju upozori, a Visual Studio ne upozori ni na razini Level4
(/W4). Usporedite redoslijed članova u klasi s redoslijedom u inicijalizacijskoj listi.

Postavke kompajlera za warninge:
g++: g++ -Wall -Wextra clip.cpp -o clip
Visual Studio: Project → Properties (Configuration: All Configurations) → C/C++ → General → Warning Level → Level4 (/W4)
VS Code: u datoteci .vscode/tasks.json u popis "args" dodati "-Wall", "-Wextra"*/

// Vjezba 5: klasa Clip ne radi ispravno.
// Ispravite je tako da program ispise: Concrete (Shame): 180 s

#include <iostream>
#include <string>

class Clip {
    int start;
    int end;
    int length;
    std::string name;
    const int max_length;
public:
    Clip(const std::string& name, int s, int e)
        : start(s), end(e), max_length(600), length(end - start) {
        this->name = name;
    }
    
    void print() const {
        std::cout << name << ": " << length << " s\n";
    }
};

int main()
{
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}
