/*
 * Heap.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: Kevin Jin
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;
void up_heap(int* & heap, int pos);
void pop_off(int* & heap, int iterator);
void down_heap(int* & heap, int pos, int iterator);
int main () {
	bool valid = false;
	while (!valid) {
		int* heap = new int[101];
		int iterator = 0;
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
					cout << "File contents:" << endl;
					cout << nums;
					int temp = 0;
					for (int i = 0; i < strlen(nums); i++) {
						if (isdigit(nums[i])) {
							temp *= 10;
							temp += nums[i] - '0';
						}
						else {
							heap[iterator] = temp;
							up_heap(heap, iterator);
							//cout << endl << temp;
							temp = 0;
							iterator++;
						}
					}
					heap[iterator] = temp;
					up_heap(heap, iterator);
					//cout << endl << temp;
					temp = 0;
					//cout << endl << temp;
					cout << endl << "After sort:" << endl;
//					for (int i = 0; i < 100; i++) {
//						cout << " " << heap[i];
//					}
					pop_off(heap, iterator);

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

void up_heap(int* & heap, int pos) {
	if (pos != 0) {
		int parent = (pos - 2 + pos % 2) / 2;
		if (heap[parent] < heap[pos]) {
			int temp = heap[parent];
			heap[parent] = heap[pos];
			heap[pos] = temp;
			up_heap(heap, parent);
		}
	}
}

void pop_off(int* & heap, int iterator) {
	if (iterator > 0) {
		cout << heap[0] << " ";
		heap[0] = heap[iterator];
		iterator--;
		down_heap(heap, 0, iterator);
		pop_off(heap, iterator);
	}
	else
		cout << heap[0] << " ";
}

void down_heap(int* & heap, int pos, int iterator) {
	if ((int)log2(pos + 1) < (int)log2(iterator + 1)) {
		if (heap[pos] < heap[pos * 2 + 1]) {
			if (heap[pos] < heap[pos * 2 + 2]) {
				if (heap[pos * 2 + 1] > heap[pos * 2 + 2]) {
					int temp = heap[pos];
					heap[pos] = heap[pos * 2 + 1];
					heap[pos * 2 + 1] = temp;
					down_heap(heap, pos * 2 + 1, iterator);
				}
				else {
					int temp = heap[pos];
					heap[pos] = heap[pos * 2 + 2];
					heap[pos * 2 + 2] = temp;
					down_heap(heap, pos * 2 + 2, iterator);
				}
			}
			else {
				int temp = heap[pos];
				heap[pos] = heap[pos * 2 + 1];
				heap[pos * 2 + 1] = temp;
				down_heap(heap, pos * 2 + 1, iterator);
			}
		}
		else if (heap[pos] < heap[pos * 2 + 2]) {
			int temp = heap[pos];
			heap[pos] = heap[pos * 2 + 2];
			heap[pos * 2 + 2] = temp;
			down_heap(heap, pos * 2 + 2, iterator);
		}
	}
}
