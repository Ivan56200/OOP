/*Napišite inline funkcije add, subtract, multiply i divide s prototipom
double(double, double).
◦ Spremite adrese funkcija u niz function pointera.
◦ Korisnik unosi dva broja i redni broj operacije (0–3), a program poziva odgovarajuću
funkciju iz niza.
◦ Za dijeljenje s nulom ispišite poruku umjesto rezultata.*/

#include <iostream>

inline double add(double a, double b) {
	return a + b;
}

inline double subtract(double a, double b) {
	return a - b;
}

inline double multiply(double a, double b) {
	return a * b;
}

inline double divide(double a, double b) {
	return a / b;
}

int main() {
	double broj1, broj2;
	int znak = -1;
	
	std::cout << "Unesite brojeve: " << std::endl;
	std::cin >> broj1 >> broj2;

	std::cout << "\0" << "0 = zbrajanje, 1 = oduzimanje, 2 = mnozenje, 3 = djeljenje " << std::endl;
	while (znak > 3 || znak < 0) { 
		std::cin >> znak; 
		std::cin.ignore();
	}

	
	double (*funkcije[])(double, double) = {
		add, subtract, multiply, divide
	};

	if (znak == 3 && (broj1 == 0 || broj2 == 0)) {
		std::cout << "Nemozemo djeliti s 0" << std::endl;
	}

	else {
		double rezultat = funkcije[znak](broj1, broj2);
		std::cout << rezultat << std::endl;
	}

	return 0;
}
