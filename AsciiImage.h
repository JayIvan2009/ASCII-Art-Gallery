#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>

class AsciiImage
{
public:
	bool LoadImage(std::ifstream &file);			// load image prototype passing an ifstream reference
	void PrintImage(bool showTitle, bool showName, bool showID, bool showCateg, bool showURL);			// print image prototype
	void getMax(std::string &s) { if (s.length() > max) max = s.length(); };			// takes in a string and sets the value 'max' to the longest string
	std::string check(std::string &s) { return (s.empty() ? s = "Unknown" : s); };		// takes in a string and sets the string to "Unknown" if it's empty

private:
	std::vector<std::string> info;			// a vector of strings for each entry info
	int max = 0;							// max length of a string in an entry

	void PrintHorizontalBorders();			// horizontal borders prototype
	void PrintVerticalBorders(std::string s);			// vertical border prototype
};
