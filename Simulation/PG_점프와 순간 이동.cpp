#include <iostream>
using namespace std;

long long calc(int n) {
	if(n == 1) return 1;
	if( n % 2 == 1) {
		return calc(n/2) + 1;
	} else return calc(n / 2);
}

long long solution(int n)
{
    return calc(n);
}
