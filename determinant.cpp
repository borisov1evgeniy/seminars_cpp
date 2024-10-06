#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<double> preobr(vector<double> v, long long n) {
	double k;
	for (int s1 = 0; s1 < n; s1++) {
		for (int del1 = s1 + 1; del1 < n; del1++) {

			if (v[s1 * n + s1] != 0) {
				k = v[del1 * n + s1] / v[s1 * n + s1];

				for (int vic = s1; vic < n; vic++) {
					v[del1 * n + vic] -= k * v[s1 * n + vic];
				}
			}
		}    
	}
	return v;
}

double deter(vector<double> v, long long n) {
	double det = 1;
	for (int i = 0; i < n; i++) {
		det *= v[i * n + i];
	}
	return det;
}
int main() {
	long long N;
	cin >> N;
	vector<double> V(N * N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> V[i * N + j];
		} 
	}
	V = preobr(V, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << V[i * N + j] << ' ';
		}
		cout << endl;
	}
	cout << deter(V,N);
	return 0;
}