/*#include <iostream>

class Baterija{
private:
	int postotak;
	int aktivne;
	static int next_aktivne;

	static int limit(int p) {
		if (p < 0) return 0;
		if (p > 100) return 100;
		return p;
	}

public:
	//konstruktor
	Baterija(int p = 100) : postotak(p), aktivne(next_aktivne++){}

	//destruk
	~Baterija() {;
		next_aktivne--;
	}

	//copy konstruktor
	Baterija(const Baterija& b) {
		postotak = b.postotak;
		aktivne = next_aktivne++;
	}

	void napuni(int energija) {
		postotak = limit(postotak + energija);
	}

	void potrosi(int energija) {
		postotak = limit(postotak - energija);
	}
	
	int posto() const { return postotak; }

	static int broj_akt() { return next_aktivne; }


};
int Baterija::next_aktivne = 0;

int main() {
	Baterija b1;
	std::cout << "Postotak: " << b1.posto() 
		<< " Aktivne: " << b1.broj_akt() << '\n';

	b1.napuni(-40);
	std::cout << "Postotak: " << b1.posto()
		<< " Aktivne: " << b1.broj_akt() << '\n';

	b1.napuni(-80);
	std::cout << "Postotak: " << b1.posto()
		<< " Aktivne: " << b1.broj_akt() << '\n';

	b1.napuni(+120);
	std::cout << "Postotak: " << b1.posto()
		<< " Aktivne: " << b1.broj_akt() << '\n';
	  
	Baterija b2;	
	std::cout << "\nAktivne: " << b1.broj_akt() << '\n';


	Baterija copy (b1);
	std::cout << "\nPostotak - kopija: " << b1.posto()
		<< " Aktivne: " << copy.broj_akt() << '\n';
	return 0;
}*/