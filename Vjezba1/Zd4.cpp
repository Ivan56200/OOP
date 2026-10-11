/*4. U prostoru imena (namespace) geo definirajte konstantu PI. Napišite preopte-
rećene funkcije:
◦ double area(double r) — površina kruga,
◦ double area(double a, double b) — površina pravokutnika,
◦ int area(int a) — površina kvadrata.
Napišite i funkciju void print_line(char c = '-', int length = 30) koja ispisuje liniju
znakova. Koristite je za odvajanje ispisa.
Prije pokretanja predvidite koja se funkcija poziva za area(5), area(5.0), area(2,
3) i area('A'), a zatim provjerite.*/

#include <iostream>

namespace geo {
	const double PI{3.14};
}

double area(double r) {
	return geo::PI * (r * r);
}

double area(double a, double b) {
	return a*b;
}

int area(int a) {
	return a * a;
}

void print_line(char c = '-', int length = 30) {
	for (int i = 0; i < length; i++) {
		std::cout << c;
	}
	std::cout << '\n';
}

int main() {
	
	std::cout << area(5) << std::endl;
	print_line();

	std::cout << area(5.0) << std::endl;
	print_line();

	std::cout << area(2, 3) << std::endl;
	print_line();

	std::cout << area('A') << std::endl;

	return 0;
}