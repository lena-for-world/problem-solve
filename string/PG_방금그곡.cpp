#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

// 맵핑 없이 하려고 했는데 자꾸 2-3개 틀려서 다른 사람 코드 참고 해서 했다

// 시간 계산
int calcTime(string start, string end) {
    int startHour = (start[0] - 48) * 10 + (start[1] - 48);
    int startMinute = (start[3] - 48) * 10 + (start[4] - 48);
    int endHour = (end[0] - 48) * 10 + (end[1] - 48);
    int endMinute = (end[3] - 48) * 10 + (end[4] - 48);
    return (endHour-startHour)*60+(endMinute-startMinute);
}

// '#' 붙은 경우 맵핑시킴
string chg(string in, map<string, char> s)
{
    string out = "";
    for(int i = 0; i < in.size(); i++)
    {
        if(in[i + 1] == '#')
        {
            if(in[i] != 'B' && in[i] != 'E') out += s[in.substr(i, 2)];
            i++;
        }
         else
            out += in[i];
    }
    return out;
}

string solution(string m, vector<string> musicinfos) {
    int mxrunning = 0;
    string answer = "";
    istringstream iss;
    vector<string> start, end, name, music;
   
    map<string, char> s;
    s["C#"] = 'Q';
    s["D#"] = 'W';
    s["F#"] = 'R';
    s["G#"] = 'T';
    s["A#"] = 'Y';
    
    m = chg(m, s);
    
    for(int a = 0; a < musicinfos.size(); a++) {
        string musicinfo = musicinfos[a];
        istringstream iss(musicinfo);
        string temp = "";
        int i = 0;
        while(getline(iss, temp, ',')) {
            if(i==0) start.push_back(temp);
            if(i==1) end.push_back(temp);
            if(i==2) name.push_back(temp);
            if(i==3) music.push_back(temp);
            i++;
        }
    }
    
    for(int i =0; i < musicinfos.size(); i++) {
        string musik = chg(music[i], s);
        int playTime = musik.length();
        int running = calcTime(start[i], end[i]);
        string st = "";
        for(int j = 0; j < running/playTime; j++) {
            st += musik;
        }
        st += musik.substr(0, running%playTime);
        cout << st << endl;
        if(st.find(m) != string::npos) {
            if(running > mxrunning) {
                answer = name[i];
                mxrunning = max(running, mxrunning);
            }
        }
    }
    if(answer == "") answer = "(None)";
    return answer;
}
