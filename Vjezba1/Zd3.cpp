/*Zadan je niz int numbers[] = {4, -7, 12, 0, 9, -3};
◦ Koristeći range-based for ispišite niz, a zatim svaki negativni element za-
mijenite njegovom apsolutnom vrijednošću.
◦ Napišite funkciju int& find_max(int arr[], int n) koja vraća referencu na naj-
veći element niza. Koristeći povratnu vrijednost kao lvalue, postavite naj-
veći element na 0 i ispišite niz.*/

#include <iostream>

int& find_max(int arr[], int n) {
	int lvalue = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[lvalue]) { lvalue = i; }
	}
	return arr[lvalue];
}

int main() {
	int numbers[] = { 4, -7, 12, 0, 9, -3 };
	int duljina = sizeof(numbers) / sizeof(numbers[0]);

	for (int& i : numbers) {
		std::cout << i << " ";
		if (i < 0) { i *= -1; }
	}
	std::cout << std::endl;

	find_max(numbers, duljina) = 0;

	for (int& i : numbers) {
		std::cout << i << " ";
	}

	return 0;
}