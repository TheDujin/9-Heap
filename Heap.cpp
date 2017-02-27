/*
 * Heap.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: Kevin Jin
 */

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main () {
	bool valid = false;
	while (!valid) {
		char choose;
		cout << "Do you want to enter the numbers through the console or through a file?" << endl << "Choose: ";
		cin >> choose;
		cin.ignore(256, '\n');
		if (choose == 'f') {
			valid = true;
			char fileIn[81];
			cout << "Input the path to the input file." << endl << "Path: ";
			cin >> fileIn;
			ifstream input (fileIn);
			if (input.is_open()) {
				char* nums = new char[501];
				if (!input.eof()) {
					input.getline(nums, 500);
					cout << nums;
					int temp = 0;
					for (int i = 0; i < strlen(nums); i++) {
						if (isdigit(nums[i])) {
							temp *= 10;
							temp += nums[i] - '0';
						}
						else {
							cout << endl << temp;
							temp = 0;
						}
					}
					cout << endl << temp;


				}

				input.close();
			}
			else cout << "Unable to open file";
		}
		else if (choose == 'c') {
			valid = true;
			char* nums = new char[501];
			cout << "Input the numbers, each separated by a space." << endl << "Numbers: ";
			cin.getline(nums, 500);
			cout << nums;
		}
		else
			cout << "That input is invalid." << endl;
	}
	return 0;
}


