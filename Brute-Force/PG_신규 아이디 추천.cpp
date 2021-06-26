#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string id = "";
    int j = 0;
    int temp = new_id.size();
    for(int i = 0; i < temp; i++) {
        if(new_id[i] >= 65 && new_id[i] <= 90) new_id[i] = (char) (new_id[i] + 32);
    }
    while(j < temp) {
       if((new_id[j]-'0' >= 0 && new_id[j]-'0'<= 9) || (new_id[j] >= 97 && new_id[j] <= 122) || new_id[j] == '-' || new_id[j] == '_') {
            id += new_id[j];
            j++;
        }
        else if(new_id[j] == '.') {
        	if(id[id.size()-1] == '.') {
        		j++;
        		continue;
        	}
        	id += new_id[j];
        	j++;
        }
        else j++;
    }
    if(id[0] == '.') id.erase(0,1);
    if(id[id.size()-1] == '.') id.erase(id.size()-1, id.size());
    if(id == "") id += 'a';
    if(id.size() >= 16) id.erase(15, id.size());
    if(id[id.size()-1] == '.') id.erase(id.size()-1, id.size());
    if(id.size() <= 2) for(int i = id.size(); i < 3; i++) id += id[id.size()-1];
    answer = id;
    return answer;
}
