#include <iostream>
#include <fstream>
#include <iomanip>

double min(double a, double b){
	if (a < b)return a;
	else return b;
}

int main(){
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	int n;
	in >> n;
	double* nails = new double[n];
	for (int i = 0; i < n; i++) {
		in >> nails[i];
	}
	double r = nails[1] - nails[0];
	out << std::fixed;
	out << std::setprecision(2);
	double min_sum = 0;
	if (n == 2)
		min_sum = r;
	if (n == 3)
		min_sum= nails[2] - nails[0];
	if (n == 4)
		min_sum = r + nails[n - 1] - nails[n - 2];
	
	    double* dp = new double[n];
		dp[1] = nails[1] - nails[0];
		dp[2] = nails[2] - nails[0];
		for (int i = 3; i < n; i++)
			dp[i] = min(dp[i - 1], dp[i - 2]) + nails[i] - nails[i - 1];
		min_sum = dp[n - 1];

	out << min_sum;
	return 0;
}