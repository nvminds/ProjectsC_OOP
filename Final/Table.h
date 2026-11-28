#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Table {
	vector<int> widths;
	void line(int left, int mid, int right);
public:
	Table(vector<int> w):widths(w) {}
	void top();
	void middle();
	void bottom();
	void row(const vector<string>& cells);
};
