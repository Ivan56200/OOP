/*Koristeći std::equal napišite funkcije
◦ bool starts_with(const std::string& s, const std::string& prefix),
◦ bool ends_with(const std::string& s, const std::string& suffix) koja stringove uspoređuje od kraja (rbegin()).
◦ Za vektor imena datoteka {"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt", 
  "vjezba03.cpp"} prebrojite datotekes nastavkom ".cpp".
◦ Uklonite iz vektora sve datoteke čije ime počinje s "vjezba" i ispišite vektor.

.cpp datoteka: 3
slajdovi.pdf main.cpp README.md notes.txt*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

bool starts_with(const std::string& s, const std::string& prefix) {
	return std::equal(s.begin(), s.begin() + prefix.size(), prefix.begin(), prefix.end());
}

bool ends_with(const std::string& s, const std::string& suffix) {
	return std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
	std::vector<std::string> datoteke = { "vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp" };
	std::string prefix = "vjezba";
	std::string sufix = ".cpp";

	int brojac = 0;
	for (auto i : datoteke) {
		if (ends_with(i, sufix) == true) {
			brojac++;
		}
	}
	std::cout << ".cpp datoteka: " << brojac << '\n';

	
	for (auto it = datoteke.begin(); it < datoteke.end(); ) {
		if (starts_with(*it, prefix) == true) it = datoteke.erase(it);
		else ++it;
	}

	for (auto i : datoteke) std::cout << i << " ";

	return 0;
}