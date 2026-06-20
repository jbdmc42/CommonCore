#include <iostream>
#include <string>
#include <fstream>
#include "SedIsBad.hpp"

void	createTestFile(const std::string& filename, const std::string& content) {
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << RED << "Error: could not create test file " << CYAN << filename << RED << "." << RESET << std::endl;
		return ;
	}
	file << content;
	file.close();
	std::cout << PURPLE << "[✓] Generated: " << CYAN << filename << RESET << std::endl;
}

int	main(void) {
	std::cout << CLEAR_SCREEN;
	std::cout << BROWNISH << "==================== GENERATING TEST SUITE ====================" << RESET << std::endl;
	
	// 1. Edge Case: Chaotic random text
	std::string chaoticText =
		"bgabgioagsgbfjkgbipgbiugbiegbieruagbrgba gbwhgbg ag jg hjg bawhgb ahwbipwbaf wag bgewhg ewh gWHJEG EWHG  gwEHG WG bfeWIUFBEJWF NG J N egjbewhjg awf wgfnwajg njF GJNWAJG    gjgbajgnajg\n"
        "abc fangkjbggagng ag agbgnpwagag abc angiuagpagna abcfiabgbgbabgabgabgajabcabgjajkgabgjlaajgbajkçgbkarabcgjakbçabgjbg gnajgbçgbgb a b c ghangangjnakfmefnddjnfa cbn abgewagnawfmoij1984u5br jwbfjnjwknjfn\n"
        "ngjknegklnewl 5u32iu23i gnangkl abckla 48914n1 rfaniofnfmklgan\n";
	createTestFile("chaotic.txt", chaoticText);

	// 2. Edge Case: Consecutive duplicate targets (e.g., replacing "aaa" with "X")
    createTestFile("consecutive.txt", "aaaaaaaaaaaaaaaa\n");

    // 3. Edge Case: Empty file
    createTestFile("empty.txt", "");

    // 4. Edge Case: Multiple consecutive newlines
    createTestFile("newlines.txt", "\n\n\nHello\n\nWorld\n\n\n");

	// 5. NEW: Missing Newline at EOF
    createTestFile("no_eof_newline.txt", "This file does not end with a newline character");

    // 6. NEW: Overlapping patterns (Try replacing "aba" with "XYZ")
    createTestFile("overlapping.txt", "abababa matches aba inside ababababa\n");

    // 7. NEW: Special and hidden characters
    createTestFile("special_chars.txt", "Text\twith\ttabs\nAccents: çóñãà\nSymbols: #$%^&*()_+\n");

    std::cout << BROWNISH << "===============================================================" << RESET << std::endl;
    std::cout << CYAN << ">>> Ready! Run your ./SedIsBad program against these files. <<<" << RESET << std::endl;
    return (0);
}