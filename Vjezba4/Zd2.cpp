/*Definirajte strukturu Song s članovima title, artist, year i plays (broj slušanja) i
funkciju void print_song(const Song& s). Vektor pjesama inicijalizirajte s nekoliko pjesama.
◦ Sortirajte pjesme po godini; pjesme iz iste godine sortirajte po naslovu.
◦ Korisnik unosi ime izvođača. Ispišite koliko pjesama tog izvođača ima na popisu i
njegovu najstariju pjesmu; ako ih nema, ispišite poruku.
◦ Ispišite najslušaniju pjesmu.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Song {
	std::string title, artist;
	int year, plays;
};

void print_song(const Song& s) {
	std::cout << "Naslov: " << s.title << '\n';
	std::cout << "Producent: " << s.artist << '\n';
	std::cout << "Godina izdanja: " << s.year << '\n';
	std::cout << "Br slusanja: " << s.plays << '\n';
	std::cout << '\n' << '\n';
}

int main() {
	std::vector<Song> songs = {
		{"Pjesma1", "Izvodac1", 2018, 211314},
		{"Pjesma2", "Izvodac2", 2020, 500000},
		{"Pjesma3", "Izvodac1", 2015, 100000},
		{"Pjesma4", "Izvodac1", 2015, 100000}
	};

	std::sort(songs.begin(), songs.end(),
		[](const Song& a, const Song& b){
		if (a.year != b.year) { return a.year < b.year; }
		return a.title < b.title;
	});

	for (auto& i : songs) {	print_song(i);	}



	std::string autor;
	int brPjesaman{};
	Song najstarija{};
	bool postoji = false;

	std::cout << "Unesi autora: ";
	std::cin >> autor;

	for (auto& i : songs) { 
		if (autor == i.artist) {
			brPjesaman++;
			if (!postoji) { najstarija = i; }
			postoji = true;
		}
		if (postoji && najstarija.year > i.year) najstarija = i;
	}

	if (brPjesaman == 0) std::cout << "Nema pjesama";
	
	else {
		std::cout << "Br pjesama: " << brPjesaman << '\n';
		std::cout << "Najstarija pjesma: " << '\n';
		print_song(najstarija);
	}



	Song najslusanija = songs[0];
	for (auto& i : songs) {
		if (najslusanija.plays < i.plays) najslusanija = i;
	}
	std::cout << "\nNajslusanija:\n";
	print_song(najslusanija);

	return 0;
}