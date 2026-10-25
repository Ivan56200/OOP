/*Napišite funkcije
 o std::string with_separators(std::string digits) koja broju zapisanom kao string umeće točku ispred svake skupine
   od tri znamenke, gledano s desna (insert); broj može biti negativan,
 o std::string without_separators (std::string text) koja uklanja sve točke (find erase).
 "1234567" -> "1.234.567"	"-1234567" -> "-1.234.567"
 "100000" -> "100.000"		"1.234.567" -> "-1234567"*/

#include <iostream>
#include <string>
#include <cctype>

std::string with_separators(std::string &digits) {
	int brojac = 0;
	
	for (int i = digits.length() - 1; i != 0; i--) {
		if (isdigit(digits[i])) { brojac++; }

		if (brojac == 3) {
			brojac = 0;
			digits.insert(i, ".");
		}
	}

	return digits;
}

std::string without_separators(std::string &text) {
	auto znamenka = std::find(text.begin(), text.end(), '.');
	while (znamenka != text.end()) {
		znamenka = text.erase(znamenka);
		znamenka = std::find(text.begin(), text.end(), '.');
	}
	return text;
}

int main() {
	std::string x = "1234567";
	std::string y = "100000";

	std::cout << with_separators(x) << std::endl;
	std::cout << without_separators(x) << std::endl;
	std::cout << '\n';
	std::cout << with_separators(y) << std::endl;
	std::cout << without_separators(y) << std::endl;

	return 0;
}