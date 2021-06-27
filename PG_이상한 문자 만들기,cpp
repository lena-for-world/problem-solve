string solution(string s) {
    string answer = "";
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){ 
        if(s[i] == ' ') {
            cnt = 0;
            answer += ' ';
        }
        else {
            if(cnt % 2 == 0) {
                if(s[i] >= 97) answer += (char)(s[i] - 32);
                else answer += s[i];
            }
            else {
                if(s[i] < 97) answer += (char)(s[i] + 32);
                else answer += s[i];
            }
            cnt++;
        }
    }
    return answer;
}


// toupper, tolower, 비트연산자 활용한 코드

string solution(string s) {
  string answer = "";
  for(int i = 0, cnt = 1; i < s.size(); i++, cnt++) {
    if(s[i] == ' ') {
      cnt = 0;
      answer += ' ';
    }
    else {
      cnt & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }
  }
  return answer;
}
