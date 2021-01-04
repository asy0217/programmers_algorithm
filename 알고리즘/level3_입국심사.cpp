/*answer�� Ž���ϱ�:�̺�Ž������ start, end, mid ����ؼ� Ž������ ����������
=>start==mid==end�� ���� Ž��������, Ž������*/
#include <string> 
#include <vector> 
#include <algorithm> 
#include <iostream> 
using namespace std;
long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end()); //�̺�Ž�� ������ ���� �ʼ�
    long long start = 0; //Ž�� ���۰�(answer �ּڰ�)
    long long end = (long long)times.front() * n; //Ž�� ����(answer �ִ�)
    long long mid = 0;
    long long len = times.size();
    while (start < end) {
        mid = (start + end) / 2; //mid�� ����
        long long total = 0;
        for (int i = 0; i < len; i++) {
            total += mid / times[i];
        }
        if (total < n)
            start = mid + 1; //total<n�̸�, mid�� ���� Ž��
        else end = mid; //total>=n�̸�,mid������ mid�� ���� Ž��
    }

    long long answer = start; //start==end==mid�� �� Ž���Ϸ�
    return answer;
}