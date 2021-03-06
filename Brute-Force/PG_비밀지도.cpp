// 내 코드

string st;

void func(int n) {
    if(n <= 0) return;
    func(n / 2);
    st += (char)(n%2) + '0';
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> temp1;
    for(int i = 0; i < arr1.size(); i++) {
        st = "";
        func(arr1[i]);
        if(st.size() < arr1.size()) {
            string st2 = "";
            for(int q = 0; q < arr1.size()-st.size(); q++) {
                st2 += '0';
            }
            st2 += st;
            st = st2;
        }
        temp1.push_back(st);
    }
    for(int i = 0; i < arr2.size(); i++) {
        st = "";
        string anstemp = "";
        func(arr2[i]);
        if(st.size() < arr2.size()) {
            string st2 = "";
            for(int q = 0; q < arr2.size()-st.size(); q++) {
                st2 += '0';
            }
            st2 += st;
            st = st2;
        }
        for(int w = 0; w < st.size(); w++) {
            if(st[w] == '1' || temp1[i][w] == '1') anstemp += '#';
            else anstemp += ' ';
        }
        answer.push_back(anstemp);
    }
    return answer;
}


// 이건 엄청 간단한 비트 연산 코드

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n; i++){
        arr1[i] = arr1[i]|arr2[i];
        string ans = "";
        for(int j = 0; j<n; j++){
            if(arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}
