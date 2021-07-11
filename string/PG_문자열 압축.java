// 스터디에서 java로 다시 푼 코드

import java.util.ArrayList;

class Solution {
    public int solution(String s) {
        int answer = 987654321;
        if(s.length()==1) {
            answer = 1;
        }
        for(int i = 1; i <= s.length()/2; i++) {
            String temp = s;
            String ans = "";
            int cnt = 1; int flag = 1;
            ArrayList<String> list = new ArrayList<String>();
            int a;
            for(a = 0; a < s.length()-i; a+=i) {
                if(a+i < s.length()) list.add(temp.substring(a, a+i));
            }
            list.add(temp.substring(a, s.length()));
            for(int j = 0; j < list.size()-1; j++) {
                String t1 = list.get(j);
                String t2 = list.get(j+1);
                if(t1.equals(t2)) {
                    cnt++;
                }
                else {
                    if(j == 0) {
                        ans += list.get(0);
                        continue;
                    }
                    if(cnt != 1) ans += Integer.toString(cnt);
                    ans += list.get(j);
                    cnt = 1;
                }
            }
            if(cnt != 1) ans += Integer.toString(cnt);
            ans += list.get(list.size()-1);
            answer = Math.min(answer, ans.length());
        }
        return answer;
    }
}
