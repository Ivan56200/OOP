#include <iostream>
#include <string>
#include <algorithm>

bool split_email(const std::string& email, std::string& user, std::string& domain) {
	auto znak = std::find(email.begin(), email.end(), '@');
	if (znak == email.end() || 
		std::find(znak + 1, email.end(), '@' ) != email.end() ||
		znak == email.begin() ||
		znak + 1 == email.end()) {
		return false; 
	}
	
	int brojac = 0;
	for (char i : email) {
		if (i == '@') { 
			brojac++;
			continue; 
		}

		if (brojac == 0) {
			user += i;
		}

		else {
			domain += i;
		}
	}

	auto znakDomena = std::find(domain.begin(), domain.end(), '.');
	if (znakDomena == domain.end()) { return false; }
		
	return true;
}

int main() {
	std::string email;
	std::string user;
	std::string domain;

	std::getline(std::cin, email);

	if (split_email(email, user, domain) == 0) {
		std::cout << "Greska";
	}
	else {
		std::cout << "User: " << user << " " << "Domena: " << domain << std::endl;
	}
	return 0;
}