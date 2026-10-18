/*Napišite funkciju void my_transform(int arr[], int n, int (*f)(int)) koja svaki
element niza zamijeni s f(element).
◦ Napišite funkciju twice koja broj udvostruči i predajte je funkciji my_transform.
◦ Pozovite my_transform s lambdom bez konteksta koja parne brojeve prepolovi, a
neparne udvostruči.
◦ U funkciji main (ne koristeći my_transform) lambdom s kontekstom [&] izračunajte
sumu i produkt članova niza, a lambdom s kontekstom [prag, &s] sumu članova
većih od zadanog praga.
Može li se lambda s kontekstom predati funkciji my_transform? Zašto?*/

#include <iostream>

void my_transform(int arr[], int n, int (*f)(int)) {
	for (int i = 0; i < n; i++) {
		arr[i] = f(arr[i]);
	}
}

int twice(int a) {
	return a * a;
}

int main() {
	int niz[] = { 1, 2, 3, 4, 5};
	int duljina = sizeof(niz) / sizeof(niz[0]);

	my_transform(niz, duljina, twice);
	for (int i = 0; i < duljina; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;

	//////////////////////////////////////////////////
	
	my_transform(niz, duljina, [](int a) {
		if (a % 2 == 0) { return a / 2; }
		return a * 2;
		});

	for (int i = 0; i < duljina; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;

	//////////////////////////////////////////////////

	int suma = 0, produkt = 1;

	auto sumaProdukt = [&]() {
		for (int i = 0; i < duljina; i++) {
			suma += niz[i];
			produkt *= niz[i];
		}
		};
	sumaProdukt();
	std::cout << suma << " " << produkt << std::endl;

	//////////////////////////////////////////////////

	int prag = 2;
	int s = 0;

	auto sumaVecih = [prag, &s, &niz, duljina]() {
		for (int i = 0; i < duljina; ++i) {
			if (niz[i] > prag) {
				s += niz[i];
			}
		}
		};

	sumaVecih();
	std::cout << s << std::endl;


	return 0;
}