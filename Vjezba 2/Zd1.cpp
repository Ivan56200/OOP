/*Zadana je pretprocesorska direktiva (makro) #define MAX(a, b) a > b ? a : b. Prije
pokretanja predvidite vrijednosti varijabli
int a = MAX(3, 5);
int b = 2 * MAX(3, 5);
int c = MAX(3, 5) + 1;
a zatim provjerite.
◦ Popravite makro zagradama i ponovno provjerite.
◦ Napišite inline funkciju my_max.
Za int i = 3; usporedite rezultat poziva
MAX(++i, 2) i my_max(++i, 2) i vrijednost i nakon poziva.
◦ Funkciju my_max napišite kao function template i pozovite je za int, double, char i
std::string.*/

#include <iostream>
#include <string>
#define MAX(a, b) (a > b ? a : b)

inline int my_max(int a, int b) {
	return (a > b) ? a : b;
}

template <typename T>
T my_maks(T& a, T& b) {
	return a > b ? a: b;
}

int main() {
	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;

	int i = 3;
	std::cout << MAX(++i, 2) << std::endl;
	std::cout << my_max(++i, 2) << std::endl;
	std::cout << std::endl;

	int e = 1, f = 2;
	double g = 1.2, h = 2.5;
	char x = 'A', y = 'B';
	std::string q = "abac", z = "efg";

	std::cout << my_maks(e, f) << std::endl;
	std::cout << my_maks(g, h) << std::endl;
	std::cout << my_maks(x, y) << std::endl;
	std::cout << my_maks(q, z) << std::endl;

	return 0;
}