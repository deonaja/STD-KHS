#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Create a JSON object
    json j;

    // Try to open the existing JSON file
    std::ifstream inFile("input.json");
    if (inFile) {
        // If the file exists, read the contents
        inFile >> j;
        inFile.close();
    } else {
        // If the file doesn't exist, initialize it
        j["names"] = json::array(); // Initialize as an array
    }

    // Get user input
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Add the new input to the JSON array
    j["names"].push_back(name);

    // Open the file to save the JSON data
    std::ofstream outFile("input.json");
    if (!outFile) {
        std::cerr << "Error creating file!" << std::endl;
        return 1;
    }

    // Write the JSON object to the file
    outFile << j.dump(4); // Pretty print with 4 spaces indentation
    outFile.close(); // Close the file

    std::cout << "Your input has been saved to input.json" << std::endl;
    return 0;
}
