#include <iostream>\\HelloWorld
using namespace std;
char m[3][3] = {
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }, };
void Get_Place() {
	system("cls");
	int i;
	cout << "\t\t\t\t\t\t\t" << m[0][0] << '|' << m[0][1] << '|' << m[0][2] << endl;
	cout << "\t\t\t\t\t\t\t" << "-----" << endl;
	cout << "\t\t\t\t\t\t\t" << m[1][0] << '|' << m[1][1] << '|' << m[1][2] << endl;
	cout << "\t\t\t\t\t\t\t" << "-----" << endl;
	cout << "\t\t\t\t\t\t\t" << m[2][0] << '|' << m[2][1] << '|' << m[2][2] << endl;
}

bool Check_Win() {
	for (int t = 0; t < 3; t++) {
		if ((m[t][0] != ' ') && (m[t][0] == m[t][1]) && (m[t][1] == m[t][2])) return true;
		if ((m[0][t] != ' ') && (m[0][t] == m[1][t]) && (m[1][t] == m[2][t])) return true;
	}
	if ((m[1][1] != ' ')) {
		if ((m[0][0] == m[1][1]) && (m[1][1] == m[2][2])) return true;
		else if ((m[0][2] == m[1][1]) && (m[1][1] == m[2][0])) return true;
		else return false;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int x, y;
	Get_Place();
	for (int k = 0; k < 9; k++) {
		if (k % 2 == 0) {
			do {
				cout << "\nВведите куда будем ставить X[1-3][1-3]:";
				cin >> x >> y;
				x--; y--;
				if (m[x][y] == 'X' or m[x][y] == 'O') cout << "Там уже стоит фигура!";
				else if (x > 3 or y > 3) cout << "Нет такого места!";
				else break;
			} while (true);
			m[x][y] = 'X';
			Get_Place();
			if (Check_Win()) {
				cout << "Победил Крестик!";
				return 0;
			};
		}
		else {
			do {
				cout << "\nВведите куда будем ставить O[1-3][1-3]:";
				cin >> x >> y;
				x--; y--;
				if (m[x][y] == 'X' or m[x][y] == 'O') cout << "Там уже стоит фигура!";
				else if (x > 3 or y > 3) cout << "Нет такого места!";
				else break;
			} while (true);
			m[x][y] = 'O';
			Get_Place();
			if (Check_Win()) {
				cout << "Победил Нолик!";
				return 0;
			};
		}
	}
	cout << "Ничья!";
	return 0;
}