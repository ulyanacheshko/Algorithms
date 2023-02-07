#include <iostream>
#include <fstream>
std::ifstream in("input.txt");
std::ofstream out("output.txt");

void pow (long long n) {
	long long c = 0;
	while (n > 0) {
		if (n % 2 == 0){
			n /= 2;
			c++;
		}
		else {
			out << c << std::endl;
			n /= 2;
			c++;
		}
		
	}
}

int main(){
    long long n;
	in >> n;
	pow(n);
	return 0;
}