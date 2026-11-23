/*U igri postoji više vrsta neprijatelja, a svaka vrsta na svoj način prima udarac. Napišite baznu klasu Enemy koja ima ime i zdravlje. 
Njezina virtualna metoda take_damage(d) smanji zdravlje za d, a virtualni destruktor ispiše da neprijatelj nestaje. Iz klase Enemy izvedite tri klase:
◦ Goblin (zdravlje 20) prima udarac isto kao Enemy;
◦ Bat (zdravlje 15) izbjegne svaki drugi udarac i tada ne gubi zdravlje;
◦ Ghost (zdravlje 30) prima samo pola štete.
Klasa Level čuva neprijatelje u std::vector<Enemy*> i vlasnik je svih neprijatelja u levelu: 
neprijatelji se stvaraju s new, a Level ih briše u svom destruktoru. Kopiranje levela zabranite. Kad u levelu eksplodira bomba, metoda explode(d)
svakom neprijatelju zada udarac d, a svaki ga neprijatelj primi na svoj način. Mrtvi neprijatelji se zatim brišu i uklanjaju iz levela. 
Ostale metode klase Level vide se iz programa level_main.cpp.*/

// Vjezba 8, zadatak 2: napisite klase Enemy, Goblin, Bat, Ghost i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase
class Enemy {
private:
	std::string ime;
	int health;

public:
	Enemy(std::string n, int h) : ime(n), health(h) {}
	
	virtual ~Enemy() {
		std::cout << ime << " nestaje\n";
	}
		
	virtual void take_damage(int d) {
		health -= d;
		if (health <= 0) health = 0;
	}

	bool is_dead() const {
		return health == 0;
	}

	void print() const {
		std::cout << ime << " " << health << '\n';
	}
};

class Goblin : public Enemy {
public:
	Goblin() : Enemy("Goblin", 20) {}
};

class Bat : public Enemy {
	int udarci = 0;

public:
	Bat() : Enemy("Bat", 15) {}

	void take_damage(int d) override{
		udarci++;
		
		if (udarci == 2) {
			std::cout << "Bat izbjegne udarac" << '\n';
			udarci = 0;
			return;
		}
		Enemy::take_damage(d);
	}
};

class Ghost : public Enemy {
public:
	Ghost() : Enemy("Ghost", 30) {}

	void take_damage(int d) override {
		Enemy::take_damage(d / 2);
	}
};



class Level {
private:
	std::vector<Enemy*> enemies;

public:
	Level() {}

	Level(const Level&) = delete;
	Level& operator=(const Level&) = delete;

	~Level() {
		for (Enemy* e : enemies)
			delete e;
	}

	void add(Enemy* e) {
		enemies.push_back(e);
	}

	int size() const {
		return enemies.size();
	}

	void explode(int d) {
		for (Enemy* e : enemies)
			e->take_damage(d);
	}

	void print() const {
		for (Enemy* e : enemies)
			e->print();
	}

	void remove_dead() {
		for (auto it = enemies.begin(); it != enemies.end();) {
			if ((*it)->is_dead()) {
				delete* it;
				it = enemies.erase(it);
			}
			else {
				++it;
			}
		}
	}

};



int main()
{
	Level cave;
	cave.add(new Goblin);            // od sada je cave vlasnik neprijatelja
	cave.add(new Bat);
	cave.add(new Ghost);
	cave.add(new Goblin);
	std::cout << cave.size() << '\n';

	cave.explode(10);                // bomba pogodi sve neprijatelje
	cave.print();
	std::cout << "---\n";
	cave.explode(10);
	cave.print();
	std::cout << "---\n";
	cave.remove_dead();
	std::cout << cave.size() << '\n';
	std::cout << "--- kraj ---\n";
	return 0;                        // destruktor klase Level brise preostale neprijatelje
}

/*
Ocekivani ispis:

	4
	Goblin 10
	Bat 5
	Ghost 25
	Goblin 10
	---
	Bat izbjegne udarac
	Goblin 0
	Bat 5
	Ghost 20
	Goblin 0
	---
	Goblin nestaje
	Goblin nestaje
	2
	--- kraj ---
	Bat nestaje
	Ghost nestaje
*/



