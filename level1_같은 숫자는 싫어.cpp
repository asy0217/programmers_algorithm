#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int now = arr[0]; //���� now�� arr[0]�� ����
    answer.push_back(now);
    for (int i = 0; i < arr.size(); i++) {
        if (now != arr[i]) { //�ٸ� ������ ��
            now = arr[i]; 
            answer.push_back(now); //���� answer�� now�� ���ҷ� push_back 
        }
    }
    return answer;
}