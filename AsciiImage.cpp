#include "AsciiImage.h"

bool AsciiImage::LoadImage(std::ifstream &file) {
	std::string s, temp;						// string variables to use for extracting strings in file

	file.unget();								// used to retrieve back the first char that's taken from the main file's "while (file >> dump)" loop
	for (int i = 0; i < 6; i++) {				// for loop to loop through 6 entries inside the info vector
		if (i == 2) {							// element "2" of info is the ascii art
			while (s != "=====") {				// while loop that loops through the strings until "=====" is encountered
				std::getline(file, s);			// gets each line of the ascii art
				temp += s + '\n';				// and adds it all into the 'temp' string
			}
			info.push_back(check(temp));		// pushes back 'temp' into the info vector while also checking if empty or not using the 'check' function
		}
		else {									// else loop through this
			std::getline(file, s);				// gets each line
			info.push_back(check(s));			// and pushes back string into the info vector while using 'check' function again
			switch (i) {						// switch statement for each element
			case 0:
				info[i] = "Title: " + info[i];	// first element '0' of info is "Title: " + string
				break;
			case 1:
				info[i] = "ID: " + info[i];		// second element '1' of info is "ID: " + string
				break;
			case 3:
				info[i] = "URL: " + info[i];	// fourth element '3' of info is "URL: " + string
				break;
			case 4:
				info[i] = "Category: " + info[i];	// fifth element '4' of info is "Category: " + string
				break;
			case 5:
				info[i] = "Author: " + info[i];	// sixth element '5' of info is "Author: " + string
				break;
			}
		}
	}
	return true;
}

void AsciiImage::PrintImage(bool showTitle, bool showName, bool showID, bool showCateg, bool showURL) {
	std::map<int, bool> showSet = { {0, showTitle}, {1, showID}, {3, showURL}, {4, showCateg}, {5, showName} };		// map used in order to be able to use a loop to avoid repitition
	std::istringstream s(info[2]), temp(info[2]);		// istringstream variables to get each line of the ascii art
	std::string line;
	max = 0;											// resets the max private variable

	while (std::getline(temp, line)) {					// Gets the max length of each line of ascii art in a set
		getMax(line);
	}
	for (int i = 0; i < 6; i++) {						// Gets the max length of info in a set
		if (showSet[i])									// if statement to only get max IF the info is shown
			getMax(info[i]);
	}

	PrintHorizontalBorders();							// calls the function to print the horizontal borders
	while (std::getline(s, line)) {						// while loop to get each line of the ascii art
		PrintVerticalBorders(line);						// calls the function to print the vertical borders along with the string
	}
	for (int i = 0; i < 6; i++) {						// for loop to loop through the showSet map
		if (showSet[i])									// if statement to only print the vertical borders and string IF the info is shown
			PrintVerticalBorders(info[i]);
	}
	PrintHorizontalBorders();							// calls the function to print the horizontal borders
}

void AsciiImage::PrintHorizontalBorders() {				// horizonontal borders function
	for (int i = 0; i < max + 6; i++) {					// for loop to loop through 0 to 'max' + 6 (the added spaces before and after each string)
		std::cout << "=";								// prints out "=" for the horizontal borders
	}
	std::cout << std::endl;
}

void AsciiImage::PrintVerticalBorders(std::string s) {	// vertical borders function
	int count = (s.length() + 4) - (max + 6);			// int variable to calculate the spaces needed after the string is printed
	std::cout << "|  " << s;							// prints left horizontal border and then the string
	for (int i = 0; i < abs(count); i++) {				// for loop from 0 to the absolute value of 'count'
		std::cout << " ";								// to print out 'count' amount of whitespaces
	}
	std::cout << "|" << std::endl;						// prints right horizontal border
}