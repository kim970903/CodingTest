#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
int dir[12][2] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,2}};
int get_distance(int num,int cur){
    int dist = -1;
    dist = abs(dir[num][0] - dir[cur][0]) + abs(dir[num][1] - dir[cur][1]);
    return dist;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int cur_right = 11;
    int cur_left = 10;
    
    for(int i=0;i<numbers.size();i++){
        int num = numbers[i];
        if(num == 1 || num == 4 || num == 7){
            answer.append("L");
            cur_left = num;
        } else if(num == 3 || num == 6 || num == 9){
            answer.append("R");
            cur_right = num;
        } else{
            if(get_distance(num,cur_left) > get_distance(num,cur_right)){
                answer.append("R");
                cur_right = num;
            } else if(get_distance(num,cur_left) < get_distance(num,cur_right)){
                answer.append("L");
                cur_left = num;
            } else {
                if(hand == "left"){
                    answer.append("L");
                    cur_left = num;
                } else {
                    answer.append("R");
                    cur_right = num;
                }
            }
        }
    }
    return answer;
}