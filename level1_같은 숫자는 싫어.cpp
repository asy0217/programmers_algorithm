#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int now = arr[0]; //변수 now에 arr[0]값 저장
    answer.push_back(now);
    for (int i = 0; i < arr.size(); i++) {
        if (now != arr[i]) { //다른 숫자일 때
            now = arr[i]; 
            answer.push_back(now); //벡터 answer에 now를 원소로 push_back 
        }
    }
    return answer;
}