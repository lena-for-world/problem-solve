#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int five = N / 5;
	int c = N % 5;
	int two;
	if(N < 5) {
		if(N % 2 == 1) cout << -1;
		else cout << N/ 2;
	}
	else if(N %5 == 0) cout << five;
	else
		while(c!=0) {
			if(c % 2 == 1) {
				five -= 1;
				c += 5;
			}
			else {
				two = c / 2;
				c = c % 2;
				cout << five + two;
				break;
			}
		}
	return 0;
}
