string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') answer += ' ';
        else if(s[i] <= 122 && s[i] >= 97) {
            if(s[i] + n > 122) answer += (char)(int)((s[i]+n)%122+97-1);
            else answer += (char)(int)(s[i]+n);
        }
        else {
            if(s[i] + n > 90) answer += (char)(int)((s[i]+n)%90+65-1);
            else answer += (char)(int)(s[i]+n);
        }
    }
    return answer;
}
