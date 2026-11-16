/*Napišite klasu Money za iznos u eurima. Iznos se čuva kao cijeli broj centi (int), da se izbjegnu greške zaokruživanja s double. 
  Konstruktor Money(int euros = 0, int cents = 0).
◦ += i +; < za uspoređivanje iznosa.
◦ << ispisuje iznos u obliku 12.50 EUR; centi se uvijek ispisuju s dvije znamenke (1.05, ne 1.5).
◦ >> čita iznos u obliku 12.50: cijeli broj, znak, cijeli broj. Ako znak nije točka, operator sam postavlja failbit: in.setstate(std::ios::failbit).
Datoteka racun.txt u svakom retku ima naziv stavke i cijenu. Program za testiranje u datoteci money_main.cpp čita stavke dok čitanje uspijeva i ispisuje broj stavki,
ukupni iznos i najskuplju stavku (očekivani ispis je na dnu datoteke). Jedan redak u datoteci je neispravan.*/

#include <iostream>

class Money {
private:
	int euros;
	int centi;
	   
public:
	//Konstruktor
	Money() : euros(0), centi(0) {}

	//Money& operator+=() {}

	Money& operator<<(const Money& other) {
		if (centi < 10) std::cout << other.euros << ".0" << other.centi << " EUR" << '\n';
		else std::cout << other.euros << "." << other.centi << " EUR" << '\n';
	}

	Money&  operator>>(const Money& other) {
		std::cout << other.euros << "." << other.centi << '\n';
	}




};


int main() {


	return 0;
}