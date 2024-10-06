#include <iostream>
#include <string>
void triangle(long long n) {
	for (int i = 1; i < n*2; i++) {
		if (i <= n) {
			std::cout << std::string (i, '*') << std::endl;
		}
		else {
			
			std::cout << std::string (n*2-i,'*') << std::endl;
		}
	}
	
}
int main() {
	long long n;
	std::cin >> n;
	triangle(n);
	return 0;
}