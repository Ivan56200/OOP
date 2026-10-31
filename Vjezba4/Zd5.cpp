/*Definirajte strukturu Student s članovima jmbag, surname i points. Neki su se studenti
na ispit prijavili dvaput (isti JMBAG):

std::vector<Student> registered{
	{"0302", "Kovac", 78}, {"0117", "Babic", 45},
	{"0255", "Maric", 91}, {"0117", "Babic", 45},
	{"0410", "Novak", 78}, {"0089", "Juric", 62},
	{"0255", "Maric", 91}, {"0520", "Maric", 55},
	{"0333", "Peric", 30}};

◦ Uklonite dvostruke prijave (sort, unique, erase) i ispišite broj prijavljenih studenata.
◦ Korisnik unosi prag bodova. Uklonite studente s manje bodova od praga.
◦ Ispišite rang-listu: po bodovima silazno, a kod jednakih bodova po prezimenu.

prijavljenih: 7
Prag: 50
1. Maric (0255) 91
2. Kovac (0302) 78
3. Novak (0410) 78
4. Juric (0089) 62
5. Maric (0520) 55*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
	std::string jmbag, surname;
	int points;
};

void ispis(const Student& s) {
	std::cout << s.jmbag << '\n';
	std::cout << s.surname << '\n';
	std::cout << s.points << "\n\n";
}

int main() {
	std::vector<Student> registered{
		{"0302", "Kovac", 78}, {"0117", "Babic", 45},
		{"0255", "Maric", 91}, {"0117", "Babic", 45},
		{"0410", "Novak", 78}, {"0089", "Juric", 62},
		{"0255", "Maric", 91}, {"0520", "Maric", 55},
		{"0333", "Peric", 30}
	};
	int prijavljenih = 0;

	std::sort(registered.begin(), registered.end(),
		[](const Student& a, const Student& b) { return a.jmbag < b.jmbag; });

	auto isti = std::unique(registered.begin(), registered.end(),
		[](const Student& a, const Student& b) { return a.jmbag == b.jmbag; });

	registered.erase(isti, registered.end());

	for (const auto& i : registered) {
		//ispis(i);
		prijavljenih++;
	}
	std::cout << "\nBroj prijavljenih: " << prijavljenih << '\n';



	int prag;
	do {
		std::cout << "Unesite bodove: ";
		std::cin >> prag;
	} while (prag < 0 || prag > 100);

	auto ispodPraga = std::erase_if(registered,
		[prag](const Student& s) { return s.points < prag;});

	//for (const auto& i : registered) { ispis(i); }



	
	std::sort(registered.begin(), registered.end(),
		[](const Student& a, const Student& b) {
			if (a.jmbag != b.jmbag) return a.points > b.points;
			return a.surname < b.surname; });

	for (const auto& i : registered) { ispis(i); }


	return 0;
}