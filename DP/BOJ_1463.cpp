// 1로 만들기

int func(int n) {
	if(n == 1) return 0;
    if(cache[n] != -1) return cache[n];
    cache[n] = func(n-1) +1;
    if(n % 2 == 0) {
    	cache[n] = min(cache[n], func(n/2) + 1);
    }
    if(n % 3 == 0) {
    	cache[n] = min(cache[n], func(n/3) + 1);
    }
    return cache[n];
}
