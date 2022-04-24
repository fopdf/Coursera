#include <iostream>
#include <map>


std::map<char, int> BuildCharCounters(const std::string& a) {

	std::map<char, int> counter;
	for (const char& letter : a) {

		++counter[letter];

	}

	return counter;
}



int main() {

	std::map<char, std::string> one, two;
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {

		std::string a, b;
		std::cin >> a >> b;
		if (BuildCharCounters(a) == BuildCharCounters(b)) {

			std::cout << "YES" << std::endl;
		
		}
		else {

			std::cout << "NO" << std::endl;

		}
	}
	return 0;
}