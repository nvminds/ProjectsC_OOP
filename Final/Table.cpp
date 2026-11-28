#include "Table.h"

void Table::line(int left, int mid, int right) {
	cout << (char)left;
	for (int i = 0; i < widths.size(); i++)
	{
		for (int j = 0; j < widths[i]; j++)
		{
			cout << char(205);
		}
		if (i < widths.size() - 1) {
			cout << (char)mid;
		}
	}
	cout << (char)right;
	cout << endl;
}

void Table::top() {
	line(201, 203, 187);
}

void Table::middle() {
	line(204, 206, 185);
}

void Table::bottom() {
	line(200, 202, 188);
}

void Table::row(const vector<string>& cells) {
	for (int i = 0; i < cells.size(); i++)
	{
		string cell = " " + cells[i];
		cout << char(186);
		cout << left << setw(widths[i]) << cell;
	}
	cout << char(186);
	cout << endl;
}
