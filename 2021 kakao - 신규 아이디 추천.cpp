#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    //answer = new_id;
    //level1
    //transform(answer.begin(),answer.end(),answer.begin(),::tolower);
    for(int i = 0;i<new_id.size();i++){
        new_id[i] = tolower(new_id[i]);
    }
    //level2
    for(int i =0;i<new_id.size();i++){
        /*if(!isalpha(answer[i])){
            if(!isdigit(answer[i])){
                if(answer[i] != '-'){
                    if(answer[i] != '_'){
                        if(answer[i] != '.'){
                            answer[i] = ' ';
                        }
                    }
                }
            }
        }*/
        if(isalpha(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '.' || new_id[i] == '_'){
            answer.push_back(new_id[i]);
        }
    }
    //level3
    string tmp = answer;
    answer.clear();
    for(int i = 0;i<tmp.size();i++){
        if(tmp[i] == '.'){
            if(tmp[i+1] == '.'){
                continue;
            } else{
                answer.push_back(tmp[i]);
            }
        } else{
            answer.push_back(tmp[i]);
        }
    }    
    //level4
    for(int i = 0;i<answer.size();i++){
        if(answer[i] == '.'){
            if(i == 0 || i == answer.size()-1){
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
    if(answer.size() > 15){
        answer = answer.substr(0,15);
    }
    if(answer.back() == '.'){
        answer.back() = ' ';
    }
    answer.erase(remove(answer.begin(),answer.end(),' '),answer.end());
    //level7
    if(answer.size() <=2){
        while(answer.size() < 3){
            answer  = answer + answer.back();
        }
    }
    return answer;
}
