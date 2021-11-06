#include <iostream>
#include <cmath>
using namespace std;

double x, y, c;

double calc(double n) {
	double t1 = sqrt(y*y - n*n);
	double t2 = sqrt(x*x - n*n);
	return t1*t2 / (t1+t2); // c에 대한 식
}

int main() {
	double answer;
	cin >> x >> y >> c;
	double low = 0, high = min(x, y), mid;
	while(high - low > 0.000001) {
		mid = (low + high) / 2.0;
		if(calc(mid) >= c) {
			low = mid;
			answer = mid;
		} else {
			high = mid;
		}
	}
	cout << fixed;
	cout.precision(3);
	cout << answer;
	return 0;
}
