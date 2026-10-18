/*Funkciju my_sort iz prethodnog zadatka napišite kao function template.
◦ Pokušajte sortirati niz tipa double pomoću funkcije ascending iz prethodnog zadatka.
◦ Napišite ascending i descending kao function template i testirajte sortiranje za
  nizove tipa int, double i char.
Zašto se poziv s ascending iz prethodnog zadatka ne prevodi?*/

#include <iostream>

template <typename T>

void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (cmp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <typename T>
bool ascending(T i, T j) {
	return i > j;
}

template <typename T>
bool descending(T i, T j) {
	return i < j;
}

int main() {
	int niz1[] = { 5, 4, 1, 3, 2 };
	int duljina1 = sizeof(niz1) / sizeof(niz1[0]);

	double niz2[] = { 5.0, 4.3, 1.2, 3.1, 2.2 };
	int duljina2 = sizeof(niz2) / sizeof(niz2[0]);

	char niz3[] = { '5', '4', '1', '3', '2' };
	int duljina3 = sizeof(niz3) / sizeof(niz3[0]);


	//INT
	my_sort(niz1, duljina1, ascending);
	for (int i = 0; i < duljina1; i++) {
		std::cout << niz1[i] << " ";
	}
	std::cout << std::endl;

	my_sort(niz1, duljina1, descending);
	for (int i = 0; i < duljina1; i++) {
		std::cout << niz1[i] << " ";
	}
	std::cout << '\n' << std::endl;


	//DOUBLE
	my_sort(niz2, duljina2, ascending);
	for (int i = 0; i < duljina2; i++) {
		std::cout << niz2[i] << " ";
	}
	std::cout << std::endl;

	my_sort(niz2, duljina2, descending);
	for (int i = 0; i < duljina2; i++) {
		std::cout << niz2[i] << " ";
	}
	std::cout << '\n' << std::endl;


	//CHAR
	my_sort(niz3, duljina3, ascending);
	for (int i = 0; i < duljina3; i++) {
		std::cout << niz3[i] << " ";
	}
	std::cout << std::endl;

	my_sort(niz3, duljina3, descending);
	for (int i = 0; i < duljina3; i++) {
		std::cout << niz3[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}