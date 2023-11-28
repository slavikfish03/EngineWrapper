#pragma once

#include <iostream>
#include <string>

class Subject {
private:

public:
	int f3i(int a, int b) {
		return a + b;
	}

	double f3d(double a, double b) {
		return a + b;
	}

	std::string f3s(std::string a, std::string b) {
		return a + " " + b;
	}

};