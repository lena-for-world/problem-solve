

bool solution(int x) {
    bool answer = true;
    string st = to_string(x);
    int sum = 0;
    for(int i = 0; i < st.size(); i++) {
        sum = sum + (st[i] - '0');
    }
    if(x % sum == 0) answer = true;
    else answer = false;
    return answer;
}

bool solution(int x) {
    bool answer = true;
    int nTemp = x;
    int nSum = 0;
    while (nTemp > 0)
    {
        nSum += nTemp % 10;
        nTemp /= 10;
    }

    return x % nSum == 0 ? true : false;
}
