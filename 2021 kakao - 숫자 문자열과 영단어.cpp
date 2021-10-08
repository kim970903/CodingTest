#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> num_tmp;
    for(int i=0;i<s.size();){
        if(isdigit(s[i])){
            char tmp = s[i];
            answer = answer*10 + atoi(&tmp);
            i++;
        } else{
            switch(s[i]){
                case 'z': 
                    answer = answer*10;
                    i+=4;break;
                    
                case 'o': 
                    answer = answer*10 + 1;
                    i+=3;break;
                    
                case 't': if(s[i+1] == 'w'){
                    answer = answer*10 + 2;
                    i+=3;break;
                } else {
                    answer = answer*10 + 3;
                    i+=5;break;
                }
                case 'f': if(s[i+1] == 'o'){
                    answer = answer*10 + 4;
                    i+=4;break;
                } else {
                    answer = answer*10 + 5;
                    i+=4;break;
                }
                case 's': if(s[i+1] == 'i'){
                    answer = answer*10 + 6;
                    i+=3;break;
                } else {
                    answer = answer*10 + 7;
                    i+=5;break;
                }
                case 'e': 
                    answer = answer*10 + 8;
                    i+=5;break;
                    
                case 'n': 
                    answer = answer*10 + 9;
                    i+=4;break;
                default: ;
            }
             
        }
    }
    return answer;
}
