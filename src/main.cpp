#include <SFML/Graphics.hpp>
#include "Controller.h"

int main()
{
	try {
		srand(int(time(NULL)));
		Controller c;
		c.run();
		return EXIT_SUCCESS;
	}
	catch (const std::ios_base::failure & e) {
		std::cout << e.what() << "\n";
		exit(EXIT_FAILURE);
	}
	catch (const std::exception & e) {
		std::cout << e.what() << "\n";
	}
	catch (...) {
		std::cout << "Unknown exception";
	}
	
}
