#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int result[1000] ={1000,};
    string temp = "";
    // i for letter length
    for(int i = 1;i <= s.size();i++){
        int count = 1;
        int j = 0;
        string str = "";
        str = s.substr(j,i);
        // j for iterate string
        for(j=i;j<=s.size();){
            if((s.compare(j,i,str))==0){
                count++;
                j += i;
            } else {
                if(count > 1){
                    temp.append(to_string(count));
                    temp.append(str);
                } else{
                    temp.append(str);
                }
                count = 1;
                str = s.substr(j,i);
                if(j+i > s.size()){
                    //string temp_str = str.substr(j, s.size()-j);
                    temp.append(str);
                }
                j += i;
            }
        }
        //cout << temp << endl;
        result[i-1] = temp.size();
        temp.clear();
    }
    /*for(int k =1; k<s.length();k++){
       printf("%d ",result[k]);
    }*/
    int small = 1000;
    for(int k =0; k<s.length();k++){
        if(small>result[k]){
            small = result[k];
        }
    }
    answer = small;
    return answer;
}
