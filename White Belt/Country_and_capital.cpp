#include <iostream>
#include <map>
#include <string>

void DUMP(const std::map <std::string, std::string>& country_and_capital) {
	if (country_and_capital.empty() == true) {

		std::cout << "There are no countries in the world";

	}
	else {

		for (auto item : country_and_capital) {

			std::cout << item.first << "/" << item.second << " ";

		}
	}

	std::cout << std::endl;
}

void ABOUT(const std::map <std::string, std::string>& country_and_capital, const std::string& country) {

	if (country_and_capital.find(country) == country_and_capital.end()) {

		std::cout << "Country " <<  country << " doesn't exist" << std::endl;

	}
	else {

		std::cout << "Country " << country << " has capital " << country_and_capital.find(country)->second << std::endl;

	}
}


void RENAME(std::map <std::string, std::string>& country_and_capital, const std::string& old_country_name, const std::string& new_country_name) {

	//std::cout << country_and_capital[old_country_name] <<" "<<old_country_name << " " << new_country_name << " " << country_and_capital.count(old_country_name) << " " << country_and_capital.count(new_country_name) << std::endl;

	if ((country_and_capital.count(old_country_name) == 0) || (country_and_capital.count(new_country_name) == 1) || (old_country_name == new_country_name)) {

		std::cout << "Incorrect rename, skip" << std::endl;
	
	}
	else {

		country_and_capital[new_country_name] = country_and_capital[old_country_name];
		country_and_capital.erase(old_country_name);
		
		std::cout << "Country " << old_country_name << " with capital " << country_and_capital[new_country_name] << " has been renamed to " << new_country_name << std::endl ;
	
	}
}


void CHANGE_CAPITAL(std::map<std::string, std::string>& country_and_capital, std::string country, std::string new_capital) {

	if (country_and_capital.find(country) == country_and_capital.end()) {
		
		country_and_capital[country] = new_capital;
		//std::cout << country_and_capital[country] << std::endl;
		std::cout << "Introduce new country " << country << " with capital " << new_capital << std::endl;

	}
	else {

		if (country_and_capital[country] == new_capital) {

			std::cout << "Country " << country << " hasn't changed its capital" << std::endl;

		}
		else {

			std::cout << "Country " << country << " has changed its capital from " << country_and_capital[country] << " to " << new_capital << std::endl;
			country_and_capital[country] = new_capital;

		}
	}
}



int main() {
	int n;
	std::cin >> n;
	std::map <std::string, std::string> country_and_capital;
	for (int i = 0; i < n; ++i) {
		std::string operation;
		std::cin >> operation;
		if (operation == "DUMP") {

			DUMP(country_and_capital);

		}
		else {

			if (operation == "ABOUT") {
				std::string country;
				std::cin >> country;

				ABOUT(country_and_capital, country);

			}
			else {

				if (operation == "RENAME") {
					std::string old_country_name, new_country_name;
					std::cin >> old_country_name >> new_country_name;

					RENAME(country_and_capital, old_country_name, new_country_name);

				}
				else {

					if (operation == "CHANGE_CAPITAL") {
						std::string country, new_capital;
						std::cin >> country >> new_capital;

						CHANGE_CAPITAL(country_and_capital, country, new_capital);

					}
				}
			}
		}
	}

	return 0;
}