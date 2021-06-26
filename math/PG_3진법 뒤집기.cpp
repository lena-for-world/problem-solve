
string temp;
int answer;

void func(int n) {
    if (n <= 0) return;
    func(n/3);
    temp += (char)((n%3) +'0');
}

void func2(string st) {
    int tr = 1;
    for(int i = 0; i < st.size(); i++) {
        answer += (int)(st[i]-'0') * tr;
        tr *= 3;
    }
}

int solution(int n) {
    answer = 0;
    temp = "";
    func(n);
    func2(temp);
    return answer;
}
