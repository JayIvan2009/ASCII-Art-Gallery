#include <iostream>
#include "AsciiImage.h"

int GetUserChoice(bool options[], int maxSz);			// function prototype

int main() {
	std::vector<AsciiImage*> images;					// a vector of AsciiImage pointers
	std::ifstream file;									// ifstream variable for file
	std::string filename;								// string variable for file name
	bool options[5];									// bool variable array with 5 options
	char dump;											// char variable for looping through each char of file

	std::cout << "Enter Gallery File: ";
	std::cin >> filename;								// enter file name
	
	file.open(filename + ".txt");						// opens file
	while (file >> dump) {								// loops through each char in the file until there is none left
		AsciiImage *imgEntry = new AsciiImage;			// creates a temporary new AsciiImage pointer class
		if (imgEntry->LoadImage(file))					// use the LoadImage function in the temp class
			images.push_back(imgEntry);					// puts the AsciiImage instance  
	}
	file.close();										// closes file 

	std::cout << std::endl;
	std::cout << "Please enter your image choice and display options (0 or 1)." << std::endl;
	std::cout << "> ImageIndex ShowTitle ShowName ShowID ShowCategory ShowURL" << std::endl;
	std::cout << std::endl;
	std::cout << "ExampleUsage:" << std::endl;
	std::cout << "> 0 1 1 1 1 1		Shows image 0 with title, artist name, image id, category, url" << std::endl;
	std::cout << "> 0 1 1 0 0 0		Shows image 0 with title and artist name" << std::endl;
	std::cout << "Enter '-1' to close application" << std::endl;
	std::cout << std::endl << std::endl;

	while (true) {										// loops through user input until -1 is entered
		int choice = GetUserChoice(options, images.size());
		if (choice == -1)
			break;
		images[choice]->PrintImage(options[0], options[1], options[2], options[3], options[4]);
	}

	while (!images.empty()) {							// loops through the vector and deletes each element
		delete images.back();
		images.pop_back();
	}
	return 0;
}

int GetUserChoice(bool options[], int maxSz) {			// function for getting user choices
	int choice = -1;

	while (true) {										// loops through user input until invalid input or -1 is entered
		std::cout << "> ";
		std::cin >> choice;
		if (choice == -1) {
			return -1;
		}
		for (int i = 0; i < 5; i++) {
			std::cin >> options[i];
		}
		if (choice < maxSz)
			break;
		else {
			std::cout << "Please enter an image number between 0 and " << (maxSz - 1) << "." << std::endl;
		}
	}

	return choice;
}