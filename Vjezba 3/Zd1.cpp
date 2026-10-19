/*Napišite funkcije
◦ void input_vector(std::vector<int>& v) koja unosi cijele brojeve dok se ne unese
0 (nula se ne sprema),
◦ void print_vector(const std::vector<int>& v) koja ispisuje elemente vektora.
Unesite i ispišite vektor, a zatim ga ispišite obrnutim redoslijedom (rbegin(), rend()).
◦ U prazan vektor dodajte brojeve od 1 do 20 i nakon svakog push_back ispišite
size() i capacity().
◦ Ponovite s vektorom za koji je prije petlje pozvan reserve(100), a na kraju pozovite
shrink_to_fit() i ispišite kapacitet.*/

#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int>& v) {
	int broj = { -1 };
	v.reserve(100);
	while (broj != 0) {
		std::cin >> broj;
		v.push_back(broj);
		std::cout << v.size() << " " << v.capacity() << '\n';
	}
	v.shrink_to_fit();
	std::cout << v.capacity() << '\n' << std::endl;

	v.pop_back();
}

void print_vector(const std::vector<int>& v) {
	for (int broj : v) std::cout << broj << " ";
	std::cout << std::endl;

	for (auto it = v.rbegin(); it != v.rend(); it++){
		std::cout << *it << " ";
}

}

int main() {
	std::vector<int> brojevi{};

	input_vector(brojevi);
	print_vector(brojevi);

	return 0;
}