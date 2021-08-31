#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> id_map; 
    vector<string> uid_log;
    vector<string> log;
    for(int i =0;i<record.size();i++){
        vector<string> tmp;
        string uid = "";
        string nick = "";
        size_t start = 0;
        size_t index = record[i].find(' ');
        while(index != string::npos){
            tmp.push_back(record[i].substr(start,index-start));
            start = index + 1;
            index = record[i].find(' ',start);
        }
        tmp.push_back(record[i].substr(start,index-start));
        if(tmp[0] == "Enter") {
            //id_map.insert({tmp[1],tmp[2]});
            id_map[tmp[1]] = tmp[2];
            log.push_back("Enter");
            uid_log.push_back(tmp[1]);
        } else if(tmp[0] == "Leave"){
            log.push_back("Leave");
            uid_log.push_back(tmp[1]);
        } else if(tmp[0] == "Change"){
            //id_map.erase(tmp[1]);
            //id_map.insert({tmp[1],tmp[2]});
            id_map[tmp[1]] = tmp[2];
            log.push_back("Change");
            uid_log.push_back(tmp[1]);
        }
    }
    for(int i =0;i<log.size();i++){
        string uid_temp = uid_log[i];
        string nick_temp = id_map[uid_temp];
        if(log[i] == "Enter"){
            answer.push_back(nick_temp + "님이 들어왔습니다.");
        } else if(log[i] == "Leave"){
            answer.push_back(nick_temp + "님이 나갔습니다.");
        }
    }
    return answer;
}
