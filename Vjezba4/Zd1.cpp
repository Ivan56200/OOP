#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void input_vector(std::vector<int>& v) {
	v.reserve(100);

	int broj;
	std::cout << "Unesite brojeve (0 za kraj): ";
	while (std::cin >> broj && broj != 0) {
		v.push_back(broj);
	}
	v.shrink_to_fit();
}

int main(void) {
	std::vector<int> broj{};
	int k;

	input_vector(broj);

	if (broj.empty()) {
		std::cout << "Prazan vektor" << std::endl;
		return 0;
	}

	do {
		std::cout << "k: ";
		std::cin >> k;
	} while (k <= 0);

	int negativni = std::count_if(broj.begin(), broj.end(),
		[](int x) { return x < 0; });

	std::cout << "Negativnih: " << negativni << std::endl;

	auto prvi = std::find_if(broj.begin(), broj.end(),
		[k](int x) { return x % k == 0; });
	
	if (prvi != broj.end()) {
		std::cout << "Prvi visekratnik od " << k << *prvi
			<< " pozicija: " << std::distance(broj.begin(), prvi);
	}
	else {
		std::cout << "Nema visekratnika broja "	<< k << std::endl;
	}

	auto min = std::min_element(broj.begin(), broj.end());
	auto max = std::max_element(broj.begin(), broj.end());

	std::cout << "Min " << *min << " (pozicija " << std::distance(broj.begin(), min)
		<< "), max " << *max << " (pozicija " << std::distance(broj.begin(), max) << ")" << std::endl;

	broj.erase(
		std::remove_if(broj.begin(), broj.end(),
			[k](int x) { return x % k == 0; }),
		broj.end()
	);

	std::cout << "Bez visekratnika: ";

	for (int i : broj) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	
	return 0;
}
