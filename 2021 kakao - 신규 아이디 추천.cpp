#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    answer = new_id;
    //level1
    transform(answer.begin(),answer.end(),answer.begin(),::tolower);
    //level2
    for(int i =0;i<sizeof(answer);i++){
        if(!isalpha(answer[i])){
            if(!isdigit(answer[i])){
                if(!(answer[i] == '-')){
                    if(!(answer[i] == '_')){
                        if(!(answer[i] == '.')){
                            answer[i] = ' ';
                        }
                    }
                }
            }
        }
    }
    answer.erase(remove(answer.begin(),answer.end(),' '),answer.end());
    //level3
    for(int i = 0;i<sizeof(answer);i++){
        if(answer[i] == '.'){
            if(answer[i+1] == '.'){
                answer[i] = ' ';
            } 
        }
    }    
    answer.erase(remove(answer.begin(),answer.end(),' '),answer.end());
    //level4
    for(int i = 0;i<sizeof(answer);i++){
        if(answer[i] == '.'){
            if(i == 0 || i == sizeof(answer)-1){
                answer[i] = ' ';
            } 
        }
    }
    answer.erase(remove(answer.begin(),answer.end(),' '),answer.end());
    //level5
    if(answer.empty()){
        answer.append("a");
    }
    //level6
    if(answer.size() >= 16){
        answer = answer.substr(0,15);
    }
    if(answer[answer.size()-1] == '.'){
        answer[answer.size()-1] = ' ';
    }
    answer.erase(remove(answer.begin(),answer.end(),' '),answer.end());
    //level7
    if(answer.size() <=2){
        string tmp;
        tmp.assign(answer,answer.size()-1,1);
        for(int i =answer.size();i<3;i++){
            answer.append(tmp);
        }
    }
    return answer;
}
