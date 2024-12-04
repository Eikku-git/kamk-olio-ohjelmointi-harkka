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
	const char* const c_ItemName;
	std::vector<Item> m_Items;
public:

	Collection(const char* colName, const char* itemName) : c_Name(colName), c_ItemName(itemName), m_Items() {
		std::ifstream filestream((std::string)c_name + ".col");
		if (filestream.is_open()) {
			if (!filestream.good()) {
				std::cout << "failed to open games file!\n";
			} 
			while (filestream.good() && filestream.peek() != EOF) {
				filestream >> m_Items.emplace_back();
				filestream.get();
			}
		}
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

	void ViewMenu() {
		std::cout << "Welcome to " << c_Name << " collection\n" << "Select an option\n"
			<< "(1) View items"
			<< "(2) Add item"
			<< "(3) Remove item";
		int opt;
		std::cin >> opt;
		switch (opt) {
		case 1:
			size_t count = m_Items.size();
			for (size_t i = 0; i < count; i++) {
				std::cout << i + 1 << '\n'
				m_Items[i].Print();
			}
			break;
		case 2:
			Item item{};
			if (Item::Create(item)) {
				m_Items.emplace_back(std::move(item));
			}
		case 3:
			std::cout << "Type an index";
			std::cin >> opt--;
			DeleteItem(opt);
			break;
		}
	}

	~Collection() {
		std::ofstream filestream((std::string)c_name + ".col", std::ofstream::out | std::ofstream::trunc);
		for (const Item& item : m_Items) {
			filestream << item;	
		}
	}
};
