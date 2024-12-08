#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class Game {

	std::string m_Name{};
	std::string m_Studio{};
	uint32_t m_ReleaseYear{};
	uint32_t m_ReleaseMonth{};
	uint32_t m_ReleaseDay{};

public:

	void Print() const {
		std::cout << "Name: " << m_Name << std::endl 
			<< "Studio: " << m_Studio << std::endl
			<< "Release date: " << m_ReleaseDay << '/' << m_ReleaseMonth << '/' << m_ReleaseYear << std::endl;
	}

	void Edit() {
		while (true) {
			std::cout << "Choose which info to edit: " << std::endl
				<< "(1) Edit name" << std::endl
				<< "(2) Edit studio" << std::endl
				<< "(3) Edit release date" << std::endl
				<< "(4) Return" << std::endl;
			int opt;
			std::cin >> opt;
			switch (opt) {
				case 1:
					std::cout << "Enter name:" << std::endl;
					std::cin >> m_Name;
					break;
				case 2:
					std::cout << "Enter studio:" << std::endl;
					std::cin >> m_Studio;
					break;
				case 3:
					std::cout << "Enter release year" << std::endl;
					std::cin >> m_ReleaseYear;
					std::cout << "Enter release month" << std::endl;
					std::cin >> m_ReleaseMonth;
					std::cout << "Enter release day" << std::endl;
					std::cin >> m_ReleaseDay;
					break;
				case 4:
					return;
				default:
					std::cout << "Invalid option!" << std::endl;
			}
		}
	}

	bool FillInfo() {
		std::cout << "Enter game name" << std::endl;
		std::cin >> m_Name;
		std::cout << "Enter game studio" << std::endl;
		std::cin >> m_Studio;
		std::cout << "Enter game release year" << std::endl;
		std::cin >> m_ReleaseYear;
		std::cout << "Enter game release month" << std::endl;
		std::cin >> m_ReleaseMonth;
		std::cout << "Enter game release day" << std::endl;
		std::cin >> m_ReleaseDay;
		while (true) {
			std::cout << "Here's the filled info: " << std::endl;
			Print();
			std::cout << "Type 'y' to confirm, 'e' to edit or 'c' to cancel";
			char input;
			std::cin >> input;
			switch (input) {
				case 'y':
					return true;
				case 'e':
					Edit();
					break;
				case 'c':
					return false;
				default:
					std::cout << "Invalid input!" << std::endl;
			}
		}	
		return true;
	}


	friend std::ifstream& operator>>(std::ifstream& fstream, Game& game) {
		fstream >> game.m_Name >> game.m_Studio >> game.m_ReleaseYear >> game.m_ReleaseMonth >> game.m_ReleaseDay;
		return fstream;
	}

	friend std::ofstream& operator<<(std::ofstream& ofstream, const Game& game) {
		ofstream << game.m_Name << std::endl 
			<< game.m_Studio << std::endl
			<< game.m_ReleaseDay << ' ' << game.m_ReleaseMonth << ' ' << game.m_ReleaseYear << std::endl;
		return ofstream;
	}
};
