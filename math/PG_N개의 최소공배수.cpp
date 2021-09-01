#include <string>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcd(int a, int b) {
	return ((a*b) / gcd(a,b));
}

int solution(vector<int> arr) {
	int answer = 0;
	if(arr.size() < 2) {
		answer = arr[0];
	} else {
		answer = lcd(arr[0], arr[1]);
        for(int i = 2; i < arr.size(); i++) {
            if(answer < arr[i]) {
                answer = lcd(arr[i], answer);
            } else answer = lcd(answer, arr[i]);
		}
	}
	return answer;
}
