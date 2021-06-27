string solution(int a, int b) {
    string answer = "";
    int start = 5, sum = 0;
    int month[12] ={31,29,31,30,31,30,31,31,30,31,30,31};
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    for(int i = 0; i < a-1; i++) sum += month[i];
    sum += b;
    sum %= 7;
    answer = day[(start+sum-1)%7];
    return answer;
}
