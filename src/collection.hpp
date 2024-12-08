#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

template<typename T>
class Collection {
public:

	typedef T Item;

private:
	const char* const c_Name;
	std::vector<Item> m_Items;
public:

	bool Save() {
		std::ofstream filestream((std::string)c_Name + ".col", std::ofstream::out | std::ofstream::trunc);
		if (!filestream.is_open() || !filestream.good()) {
			return false;
		}
		for (const Item& item : m_Items) {
			filestream << item;	
		}
		return true;
	}

	bool Load() {
		std::ifstream filestream((std::string)c_Name + ".col");
		if (filestream.is_open()) {
			if (!filestream.good()) {
				std::cout << "failed to open games file!\n";
				return false;
			} 
			while (filestream.good() && filestream.peek() != EOF) {
				filestream >> m_Items.emplace_back();
				filestream.get();
			}
		}
		return true;
	}

	const std::vector<Item>& GetItems() {
		return m_Items;
	}

	Item& NewItem() {
		return m_Items.emplace_back();
	}

	bool DeleteItem(size_t index) {
		if (index >= m_Items.size()) {
			std::cout << "Invalid index!";
			return false;
		}
		m_Items.erase(m_Items.begin() + index);
		return true;
	}

	bool EditItem(size_t index) {
		if (index >= m_Items.size()) {
			std::cout << "Invalid index!";
			return false;
		}
		m_Items[index].Edit();
	}

	void ViewMenu() {
		std::cout << "Welcome to " << c_Name << " collection" << std::endl;
		while (true) {
			std::cout << "Select an option" << std::endl
				<< "(1) View items" << std::endl
				<< "(2) Add item" << std::endl
				<< "(3) Edit item" << std::endl
				<< "(4) Remove item" << std::endl
				<< "(5) Return to main menu" << std::endl;
			int opt;
			std::cin >> opt;
			switch (opt) {
				case 1: {
					size_t count = m_Items.size();
					for (size_t i = 0; i < count; i++) {
						std::cout << i + 1 << '\n';
						m_Items[i].Print();
					}
					break;
				}
				case 2: {
					Item& item = m_Items.emplace_back();
					if (!item.FillInfo()) {
						m_Items.pop_back();
					}
					break;
				}
				case 3: {
					std::cout << "Type an index or -1 to cancel" << std::endl;
					std::cin >> opt;
					if (opt == -1) {
						break;
					}
					--opt;
					EditItem(opt);
					break;
				}
				case 4: {
					std::cout << "Type an index or -1 to cancel" << std::endl;
					std::cin >> opt;
					if (opt == -1) {
						break;
					}
					if (!DeleteItem(opt - 1)) {
						std::cout << "Couldn't delete item!" << std::endl;
					}
					break;
				}
				case 5:
					return;
				default:
					std::cout << "Invalid option!" << std::endl;
			}
		}
	}

	Collection(const char* colName) : c_Name(colName), m_Items() {
		if (!Load()) {
			std::cout << "failed to load" << c_Name << " collection" << std::endl;
		}
	}

	~Collection() {
		if (!Save()) {
			std::cout << "failed to save " << c_Name << " collection" << std::endl;
		}
	}
};
