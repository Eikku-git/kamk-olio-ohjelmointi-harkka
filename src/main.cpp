#include "collection.hpp"
#include "game.hpp"
#include "book.hpp"
#include <iostream>

int main() {
	Collection<Game> games("games");
	Collection<Book> books("books");
	bool running = true;
	while (running) {
		std::cout << "Select an option\n" 
			<< "(1) Go to games collection\n"
			<< "(2) Go to books collection\n"
			<< "(3) End program\n";
		int opt;
		std::cin >> opt;
		switch (opt) {
		case 1:
			games.ViewMenu();
			break;
		case 2:
			books.ViewMenu();
			break;
		case 3:
			running = false;
			break;
		default:
			break;
		}
	}
	return 0;
}
