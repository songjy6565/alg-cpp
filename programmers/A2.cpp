#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> a1 = {1,2,3,4,5};
    vector<int> a2 = {2,1,2,3,2,4,2,5};
    vector<int> a3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> count = {0,0,0};
    for (int i =0; i<answers.size(); i++){
        if(a1[i%5] == answers[i])count[0]++;
        if(a2[i%8] == answers[i])count[1]++;
        if(a3[i%10] == answers[i])count[2]++;
    }
    vector<int> answer;
    if(count[0] > count[1] && count[0] > count[2])answer = {1};
    else if(count[1] > count[0] && count[1] > count[2])answer = {2};
    else if(count[2] > count[0] && count[2] > count[1])answer = {3};
    else if(count[0] > count[2] && count[1] == count[0])answer = {1, 2};
    else if(count[0] > count[1] && count[2] == count[0])answer = {1, 3};
    else if(count[1] > count[0] && count[1] == count[2])answer = {2, 3};
    else answer = {1, 2, 3};
    return answer;
}