#pragma once

#include <vector>
#include <string>
#include <fstream>

struct Game {

	std::string m_name{};
	uint32_t m_releaseYear{};
	uint32_t m_releaseMonth{};
	uint32_t m_releaseDay{};
	std::vector<Game> m_dlc{};

	friend std::ifstream& operator>>(std::ifstream& fstream, Game& game) {
		fstream >> game.m_name >> game.m_releaseYear >> game.m_releaseMonth >> game.m_releaseDay;
		if (fstream.peek() == '{') {
			while (fstream.good() && fstream.peek() != '}') {
				fstream >> game.m_dlc.emplace_back();
			}
		}
		return fstream;
	}

	friend std::ofstream& operator<<(std::ofstream& ofstream, const Game& game) {
		ofstream << game.m_name << std::endl 
			<< game.m_releaseDay << ' ' << game.m_releaseMonth << ' ' << game.m_releaseYear << std::endl;
		if (game.m_dlc.size()) {
			ofstream << '{' << std::endl;
			for (const Game& dlc : game.m_dlc) {
				ofstream << dlc;
			}
			ofstream << '}' << std::endl;
		}
		return ofstream;
	}
};
