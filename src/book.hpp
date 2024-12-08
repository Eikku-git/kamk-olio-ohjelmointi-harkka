#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>

class Book {

	std::string m_Name{};
	std::string m_Author{};
	uint32_t m_ReleaseYear{};

public:

	void Print() const {
		std::cout << "Name: " << m_Name << std::endl 
			<< "Author: " << m_Author << std::endl
			<< "Release year: " << m_ReleaseYear << std::endl;
	}

	void Edit() {
		while (true) {
			std::cout << "Choose which info to edit:" << std::endl
				<< "(1) Edit name" << std::endl
				<< "(2) Edit author" << std::endl
				<< "(3) Edit release year" << std::endl
				<< "(4) Cancel" << std::endl;
			int opt;
			std::cin >> opt;
			switch (opt) {
				case 1:
					std::cout << "Enter name:" << std::endl;
					std::cin >> m_Name;
					break;
				case 2:
					std::cout << "Enter author:" << std::endl;
					std::cin >> m_Author;
					break;
				case 3:
					std::cout << "Enter release year:" << std::endl;
					std::cin >> m_ReleaseYear;
					break;
				case 4:
					return;
				default:
					std::cout << "Invalid option!" << std::endl;
			}
		}
	}

	bool FillInfo() {
		std::cout << "Enter book name" << std::endl;
		std::cin >> m_Name;
		std::cout << "Enter book author" << std::endl;
		std::cin >> m_Author;
		std::cout << "Enter book release year" << std::endl;
		std::cin >> m_ReleaseYear;
		std::cout << "Here's the filled info: " << std::endl;
		Print();
		while (true) {
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

	friend std::ifstream& operator>>(std::ifstream& fstream, Book& book) {
		fstream >> book.m_Name >> book.m_Author >> book.m_ReleaseYear;
		return fstream;
	}

	friend std::ofstream& operator<<(std::ofstream& ofstream, const Book& book) {
		ofstream << book.m_Name << std::endl 
			<< book.m_Author << std::endl
			<< book.m_ReleaseYear << std::endl;
		return ofstream;
	}
};
