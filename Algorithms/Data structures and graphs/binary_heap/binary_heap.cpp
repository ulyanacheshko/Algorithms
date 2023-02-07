#include<iostream>
#include<fstream>
int main() {
	std::ifstream in("input.txt");
	int n;
	in >> n;
	int* arr = new int[n+1];
	for (int i = 1; i < n+1; i++) {
		in >> arr[i];
	}
	std::ofstream out("output.txt");
	bool l = true;
	for (int i = 1; i <= (n / 2); i++) {
		if (2 * i + 1 <= n) {
			if (arr[i] > arr[2 * i] || arr[i] > arr[2 * i + 1]) 
				l = false;
		}
		else if (i == (n / 2)) {
			if (arr[i] > arr[2 * i])
				l = false;
		}
		else
			l = true;
	}
	if (l == false) out << "No";
	else out << "Yes";
	return 0;
}