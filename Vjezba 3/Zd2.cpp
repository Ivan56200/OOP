/*Korisnik unosi broj dana n, a zatim n izmjerenih temperatura.
◦ Vektor temperatura stvorite konstruktorom s n elemenata i popunite ga preko indeksa.
◦ Napravite novi vektor promjena temperature između susjednih dana (drugi minus prvi, treći minus drugi, …).
  Kroz vektor temperatura prođite iteratorima. Za novi vektor unaprijed rezervirajte mjesto.
◦ Za izvještaj je potrebno točno 7 dana. Jednim pozivom resize skratite vektor na 7 dana ako je uneseno više,
  odnosno dopunite ga do 7 dana temperaturom zadnjeg izmjerenog dana ako je uneseno manje.

Broj dana: 4
12.5 14 13 9.5
Promjene: 1.5 -1 -3.5
Izvjestaj: 12.5 14 13 9.5 9.5 9.5 9.5
Koliko elemenata imaju std::vector<int> a(5); i std::vector<int> b{5};? Provjerite ispisom.*/

#include <iostream>
#include <vector>

int main() {
	int nDana{};
	double nTemperatura{};

	std::cin >> nDana;

	std::vector<double> temperatura(nDana);

	for (int i = 0; i < nDana; i++) {
		std::cin >> nTemperatura;
		temperatura[i] = nTemperatura;
	}

	std::cout << "\nBroj dana: " << nDana << std::endl;
	for (double i : temperatura) { std::cout << i << " "; }

	std::vector<double> promjenaTemperature;
	promjenaTemperature.reserve(temperatura.size() - 1);

	for (auto it = temperatura.begin() + 1; it != temperatura.end(); ++it) {
		promjenaTemperature.push_back(*it - *(it - 1));
	}

	std::cout << "\nPromjene: ";
	for (auto i : promjenaTemperature) { std::cout << i << " "; }

	temperatura.resize(7, temperatura.back());

	std::cout << "\nIzvjestaj: ";
	for (auto i : temperatura) {
		std::cout << i << " ";
	}
		
	return 0;
}