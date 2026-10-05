/*2. Učitajte godinu rođenja (std::cin >>), a zatim ime i prezime u jedan std::string
koristeći std::getline. Ispišite:
◦ inicijale (npr. Ana Horvat → A.H.),
◦ broj znakova imena i prezimena bez razmaka (koristite range-based for),
◦ koliko godina osoba navršava ove godine.*/

#include <iostream>
#include <string>

int main()
{
    int godRodenja{};
    std::cin >> godRodenja;

    std::string imePrezime;
    std::cin.ignore();
    std::getline(std::cin, imePrezime);

    //a
    std::cout << "Inicijali: ";
    for (int i = 0; i < imePrezime.length(); i++)
    {
        if (i == 0 && imePrezime[i] != ' '){
            std::cout << (char)std::toupper(imePrezime[i]) << '.';
        }
        else if (imePrezime[i] == ' ' && imePrezime[i+1] != ' ' && i+1 < imePrezime.length()){
            std::cout << (char)std::toupper(imePrezime[i + 1]) << '.';
        }
    }
    std::cout << std::endl;

    //b
    int brojac = 0;
    for (char znak : imePrezime){
        if (znak != ' ') { brojac++; }
    }

    std::cout << "Broj znamenki: " << brojac << std::endl;

    //c
    int trenutnaGodina = 2026;
    std::cout << "Navrsava: " << trenutnaGodina - godRodenja << std::endl;

    return 0;
}