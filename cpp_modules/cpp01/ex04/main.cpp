#include "SedIsBad.hpp"

std::string	replaceOccurences(std::string content, const std::string& firstString, const std::string& secondString) {
	if (firstString.empty())
		return (content);
	
	std::string	result;
	size_t		currentPos = 0;
	size_t		foundPos;

	// 1. search for the firstString inside the content
	while ((foundPos = content.find(firstString, currentPos)) != std::string::npos) {
		// 2. copy everything up to the match
		result.append(content, currentPos, foundPos - currentPos);
		// 3. add the string to replace, secondString
		result += secondString;
		// 4. jump past the string we found
		currentPos = foundPos + firstString.length();
	}
	// 5. copy any leftover text at the end of the file
	result.append(content, currentPos, std::string::npos);
	return (result);
}

int main(int argc, char **argv) {
	std::cout << CLEAR_SCREEN;
	if (argc != 4 || argv[1][0] == '\0') {
		std::cerr << RED << "Error: invalid number of arguments." << RESET << std::endl;
		std::cerr << CYAN << ">>> Usage: ./sedIsBad <filename> <stringToFind> <stringToReplace> <<<" << std::endl;  
		return (1);
	}
	
	std::string	filename = argv[1];
	std::string firstString = argv[2];
	std::string secondString = argv[3];

	// 1. protect the program against empty filename string passed via command line
	if (filename.empty()) {
		std::cerr << RED << "Error: filename cannot be empty." << RESET << std::endl;
		return (1);
	}

	// 2. open the input file and check if it exists / can be read
	std::ifstream inFile(filename.c_str());		// .c_str is required for C++ 98 open()
	if (!inFile.is_open()) {
		std::cerr << RED << "Error: cannot open file " << CYAN << filename << RED << " or it doesn't exist." << RESET << std::endl;
		return (1);
	}

	// 3. copy the file content line by line into a single string
	std::string	line;
	std::string	fileContent;
	while (std::getline(inFile, line)) {
		fileContent += line;
		if (!inFile.eof())
			fileContent += "\n";
	}
	inFile.close();		// close the file immediately when done reading

	// 4. pass the full content string to the replacement function
	std::string result = replaceOccurences(fileContent, firstString, secondString);

	// 5. open/create the <filename>.replace file
	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr << RED << "Error: could not create output file " << CYAN << outFilename << RED << "." << RESET << std::endl;
		return (1);
	}

	// 6. write the resulting modified text block into the new file
	outFile << result;
	outFile.close();

	std::cout << PURPLE << "Success: replaced content written to " << CYAN << outFilename << PURPLE << "." << RESET << std::endl;
	std::cout << BROWNISH << "\n=============== TESTING ===============>" << RESET << std::endl;
	std::cout << PURPLE << filename << ": " << RESET << std::endl;
	std::cout << CYAN << fileContent << RESET << std::endl;
	std::cout << BROWNISH << "=======================================>" << RESET << std::endl;
	std::cout << PURPLE << outFilename << ": " << RESET << std::endl;
	std::cout << CYAN << result << RESET << std::endl;
	std::cout << BROWNISH << "============ TEST FINISHED ============>" << RESET << std::endl;
	return (0);
}