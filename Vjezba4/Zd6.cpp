/*Provjera pravopisa: rječnik je zadan kao vektor riječi (malim slovima, bez dijakritika),
npr. {"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije", "jednostavan", "za", "pocetnike"}.
◦ Rječnik jednom sortirajte.
◦ Korisnik unosi rečenicu. Podijelite je na riječi (funkcija split_words iz prošle vježbe), iz svake riječi
  uklonite zareze i točke (remove_if), pretvorite je u mala slova i provjerite nalazi li se u rječniku (binary_search).
◦ Ispišite broj nepoznatih riječi i same riječi.

Recenica: C++ star i nemocan, ali nije jednostavan
nepoznatih rijeci: 2 star nemocan*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<std::string> split_words(const std::string& text) {
    std::vector<std::string> rijeci;
    std::string trenutna;

    for (char c : text) {
        if (c == ' ') {
            if (!trenutna.empty()) {

                trenutna.erase(
                    std::remove_if(trenutna.begin(), trenutna.end(),
                        [](char znak) {
                            return znak == ',' || znak == '.';
                        }),
                    trenutna.end()
                );

                std::transform( trenutna.begin(), trenutna.end(), trenutna.begin(),
                    [](unsigned char znak) {
                        return std::tolower(znak);
                    }
                );

                rijeci.push_back(trenutna);
                trenutna.clear();
            }
        }
        else {
            trenutna += c;
        }
    }

    if (!trenutna.empty()) {
        trenutna.erase(std::remove_if(trenutna.begin(), trenutna.end(),
                [](char znak) {
                    return znak == ',' || znak == '.';
                }),
            trenutna.end()
        );

        std::transform( trenutna.begin(), trenutna.end(), trenutna.begin(),
            [](unsigned char znak) {
                return std::tolower(znak);
            }
        );

        rijeci.push_back(trenutna);
    }

    return rijeci;
}

int main() {
	std::vector<std::string> rjecnik = { "programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije", "jednostavan", "za", "pocetnike" };
	std::sort(rjecnik.begin(), rjecnik.end(),
		[](const std::string a, const std::string b) { return a < b; });
	
	for (const auto& i : rjecnik) {
		std::cout << i << " ";
	}
    std::cout << '\n';

	std::string recenica;
	std::getline(std::cin, recenica);

    std::vector<std::string> rijeci = split_words(recenica);

    std::vector<std::string> nepoznate;

    for (const auto& rijec : rijeci) {
        if (!std::binary_search(rjecnik.begin(), rjecnik.end(), rijec)) {
            nepoznate.push_back(rijec);
        }
    }

    std::cout << "Recenica: " << recenica << '\n';

    std::cout << "Nepoznatih rijeci: " << nepoznate.size();

    for (const auto& rijec : nepoznate) {
        std::cout << " " << rijec;
    }
	return 0;
}