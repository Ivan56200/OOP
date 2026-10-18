/*Napišite funkciju za sortiranje niza s prototipom
void my_sort(int arr[], int n, bool (*cmp)(int, int));
Napišite inline funkcije ascending i descending koje primaju dva int-a i vraćaju bool.
U main funkciji inicijalizirajte niz i sortirajte ga prvo uzlazno, a zatim silazno.*/

#include <iostream>

void my_sort(int arr[], int n, bool (*cmp)(int, int)){
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (cmp(arr[j], arr[j + 1])){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

inline bool ascending(int i, int j) {
	return i > j;
}

inline bool descending(int i, int j) {
	return i < j;
}

int main() {
	int niz[] = {5, 4, 1, 3, 2};
	int duljina = sizeof(niz) / sizeof(niz[0]);

	my_sort(niz, duljina, ascending);
	for (int i = 0; i < duljina; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;

	my_sort(niz, duljina, descending);
	for (int i = 0; i < duljina; i++) {
		std::cout << niz[i] << " ";
	}

	return 0;
}