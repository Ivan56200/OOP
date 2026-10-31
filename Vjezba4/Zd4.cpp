/*Definirajte strukturu PasswordInfo s članovima length, digits, uppercase i special
(broj posebnih znakova, npr. !, #, ?).
◦ Napišite funkciju PasswordInfo analyze(const std::string& password) koja vraća strukturu
  popunjenu podacima o lozinci (count_if; std::isdigit, std::isupper, std::ispunct).
◦ Napišite funkciju bool is_strong(const PasswordInfo& info): lozinka je jaka ako ima
  barem 10 znakova i barem jednu znamenku, jedno veliko slovo i jedan poseban znak.

lozinka123: duljina 10, znamenke 3, velika 0, posebni 0 -> slaba
Lozinka123!: duljina 11, znamenke 3, velika 1, posebni 1 -> jaka*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

struct PasswordInfo {
	int length, digits, uppercase, special;
};

PasswordInfo analyze(const std::string& password) {
	
	int duljina = password.length();

	int brojevi = std::count_if(password.begin(), password.end(),
		[](unsigned char i) { return std::isdigit(i);});

	int veliko = std::count_if(password.begin(), password.end(),
		[](unsigned char i) {return std::isupper(i);});

	int znak = std::count_if(password.begin(), password.end(),
		[](unsigned char i) {return std::ispunct(i);});

	/*std::cout << duljina << '\n';
	std::cout << brojevi << '\n';
	std::cout << veliko << '\n';
	std::cout << znak << '\n';*/

	return { duljina, brojevi, veliko, znak };
}

bool is_strong(const PasswordInfo& info) {
	if (info.length < 10 || info.digits < 1 || info.uppercase < 1 || info.special < 1) return false;
	return true;
}

int main() {
	std::string lozinka = "lozinka123!";
	
	if (is_strong(analyze(lozinka))) std::cout << "Jaka";
	else std::cout << "slaba";

	return 0;
}

//Drugi nacin
/* PasswordInfo analyze(const std::string& password) {
   PasswordInfo lozinka1{0, 0, 0, 0};
   lozinka1.length = password.length();
   ...
   return lozinka1;
   -----------------------------------------------------
   int main(){
   PasswordInfo lozinka1 = analyze(lozinka);
   if (is_strong(lozinka1)) std::cout << "Jaka";
   else std::cout << "slaba";
*/