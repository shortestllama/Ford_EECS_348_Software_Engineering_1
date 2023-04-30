#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_dept_taken(int dept, int taken[]) {

	for (int i = 0; i < 4; i++) {
		if (dept == taken[i]) {
			return true;
		}
	}

	return false;
}

bool is_taken(int prog, int taken[]) {
	
	for (int i = 0; i < 4; i++) {
		if (prog == taken[i]) {
			return true;
		}
	}

	return false;
}

int* has_conflict(int prog, int dept, int Dept[][5], int taken[]) {
	static int conflicts[5];

	for (int i = 0; i < 5; i++) {
		conflicts[i] = 0;
	}

	conflicts[0] = dept;

	for (int i = dept; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!is_taken(Dept[i][j], taken)) {
				if (prog == Dept[i][j]) {
					for (int k = 0; k < 5; k++) {
						if (conflicts[k] == 0) {
							conflicts[k] = i + 1;
							break;
						}
					}
				}

				else {
					break;
				}
			}
		}
	}

	if (conflicts[1] != 0) {
		return conflicts;
	}

	conflicts[0] = 0;

	return conflicts;
}

void preference(int Prog[][5], int Dept[][5]) {
	int taken[4];
	int dept_taken[4];
	int* conflict;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!is_taken(Dept[i][j], taken)) {
				conflict = has_conflict(Dept[i][j], i + 1, Dept, taken);
				if (!conflict[0]) {
					if (i == 4) {
						cout << "Department #3 will get Programmer #" << Dept[i][j] << "\n";
					}

					else {
						cout << "Department #" << i + 1 << " will get Programmer #" << Dept[i][j] << "\n";
					}

					taken[i] = Dept[i][j];
					dept_taken[i - 1] = i + 1;
					break;
				}

				else {
					for (int k = 0; k < 5; k++) {
						if (!is_dept_taken(Prog[Dept[i][j] - 1][k], dept_taken)) {
							for (int l = 0; l < 5; l++) {

								if (Prog[Dept[i][j] - 1][k] == conflict[l]) {
									cout << "Department #" << Prog[Dept[i][j] - 1][k] << " will get Programmer #" << Dept[i][j] << "\n";
									taken[i] = Dept[i][j];
									dept_taken[i] = i + 1;
									k = 5;
									j = 5;
									break;
								}
							}
						}
					}
				}
			}

			else {
				continue;
			}
		}
	}
}

int main() {
	string file_name;
	string line;

	int Prog[5][5];
	int Dept[5][5];

	cout << "Please enter a file name: ";
	cin >> file_name;
	
	ifstream pref(file_name);

	if (pref.is_open()) {
		for (int i = 0; i < 10; i++) {
			getline(pref, line);

			for (int j = 0; j < 5; j++) {
				if (i < 5) {
					Dept[j][i] = atoi(&line[j * 2]);
				}

				else {
					Prog[j][i - 5] = atoi(&line[j * 2]);
				}
			}
		}
	}

	else {
		cout << "Unable to open file";
	}

	preference(Prog, Dept);

	return 0;
}
