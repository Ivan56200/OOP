/*Napišite klasu IntStack: stog cijelih brojeva koji elemente čuva u nizu na heapu.
◦ Članovi: pointer na niz, broj elemenata i veličina niza (kapacitet). 
  Konstruktor prima početni kapacitet (zadano 2) i zauzima niz s new[]; destruktor ga oslobađa.
◦ push(int x): ako je niz pun, zauzmite novi niz dvostruke veličine, prepišite elemente, oslobodite stari niz i tek onda dodajte x.
◦ pop(), top(), empty(), size() i capacity(). capacity() vraća veličinu niza
◦ Napišite copy konstruktor (deep copy).
Program za testiranje je u datoteci intstack_main.cpp.
Što bi se ispisalo bez vlastitog copy konstruktora?*/

// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.
#include <iostream>

// ovdje napisite klasu IntStack
class IntStack {
	int* niz;
	int brojElem;
	int kapacitet;

public:
	IntStack(int n = 2) : niz(new int[n]), brojElem(0), kapacitet(n) { }

	~IntStack() { delete[] niz; }

	IntStack(const IntStack& drugi) : niz(new int[drugi.kapacitet]), brojElem(drugi.brojElem), kapacitet(drugi.kapacitet) {
		for (int i = 0; i < brojElem; i++)
			niz[i] = drugi.niz[i];
	}

	void push(int n) {
		if (brojElem == kapacitet) {
			int* novi = new int[kapacitet * 2];

			for (int i = 0; i < brojElem; i++) {
				novi[i] = niz[i];
			}

			delete[] niz;

			niz = novi;
			kapacitet *= 2;
		}
		niz[brojElem] = n;
		brojElem++;
	}

	void pop() {
		if (!empty()) {
			brojElem--;
		}
	}

	int top() const {
		return niz[brojElem - 1];
	}

	bool empty() const {
		return brojElem == 0;
	}

	int size() const {
		return brojElem;
	}

	int capacity() const {
		return kapacitet;
	}
};

int main()
{
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
	std::cout << '\n';
	return 0;
}

/*Ocekivani ispis:
	5 8 50
	50 99
	50 40 30 20 10*/