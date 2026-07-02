#include "Harl.hpp"

int main(void) {
    Harl        harl;
    std::string level;

    std::cout << CLEAR_SCREEN;
    while (true) {
        std::cout << BROWNISH << "Enter complain level (DEBUG, INFO, WARNING, ERROR) or 'EXIT': " << RESET;
        if (!std::getline(std::cin, level)) // Handles Ctrl+D gracefully
            break;

        if (level == "EXIT") {
            std::cout << CYAN << "Harl has finally gone quiet." << RESET << std::endl;
            break;
        }

        if (!level.empty()) {
            harl.complain(level);
            std::cout << "\n-------------------------------------\n" << std::endl;
        }
    }
    return (0);
}