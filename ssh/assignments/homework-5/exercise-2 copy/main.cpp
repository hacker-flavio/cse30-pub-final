#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open the test file for reading
    std::ifstream testFile("test.cpp");

    if (!testFile.is_open()) {
        std::cerr << "Failed to open the test file." << std::endl;
        return 1;
    }

    std::string line;
    bool insideAssertion = false;

    while (std::getline(testFile, line)) {
        // Check if we are inside an assertion
        if (line.find("Assert::That") != std::string::npos) {
            insideAssertion = true;

            // Split the assertion line by double quotes
            size_t pos = line.find("\"");
            if (pos != std::string::npos) {
                std::string assertionPart = line.substr(pos + 1); // Get the part after the first double quote

                // Split the assertion part by newline characters
                while ((pos = assertionPart.find("\\n")) != std::string::npos) {
                    std::cout << assertionPart.substr(0, pos) << std::endl;
                    assertionPart = assertionPart.substr(pos + 2); // Move to the next part after "\\n"
                }

                // Print the remaining part
                std::cout<< "Done..." << std::endl;
            }
        }

        // Check for the end of the assertion
        if (insideAssertion && line.find(");") != std::string::npos) {
            insideAssertion = false;
        }
    }

    // Close the test file
    testFile.close();

    return 0;
}
