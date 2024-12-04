#pragma once

#include <fstream>
#include <string>

struct Book {

	std::string m_name{};
	uint32_t m_releaseYear{};
	uint32_t m_releaseMonth{};
	uint32_t m_releaseDay{};

	friend std::ifstream& operator>>(std::ifstream& fstream, Book& book) {
		fstream >> book.m_name >> book.m_releaseYear >> book.m_releaseMonth >> book.m_releaseDay;
		return fstream;
	}

	friend std::ofstream& operator<<(std::ofstream& ofstream, const Book& book) {
		ofstream << book.m_name << std::endl 
			<< book.m_releaseDay << ' ' << book.m_releaseMonth << ' ' << book.m_releaseYear << std::endl;
		return ofstream;
	}
};