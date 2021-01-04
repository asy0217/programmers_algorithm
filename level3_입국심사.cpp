/*answer값 탐색하기:이분탐색으로 start, end, mid 사용해서 탐색범위 좁혀나가기
=>start==mid==end될 때가 탐색값으로, 탐색종료*/
#include <string> 
#include <vector> 
#include <algorithm> 
#include <iostream> 
using namespace std;
long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end()); //이분탐색 이전에 정렬 필수
    long long start = 0; //탐색 시작값(answer 최솟값)
    long long end = (long long)times.front() * n; //탐색 끝값(answer 최댓값)
    long long mid = 0;
    long long len = times.size();
    while (start < end) {
        mid = (start + end) / 2; //mid값 설정
        long long total = 0;
        for (int i = 0; i < len; i++) {
            total += mid / times[i];
        }
        if (total < n)
            start = mid + 1; //total<n이면, mid의 우측 탐색
        else end = mid; //total>=n이면,mid포함한 mid의 좌측 탐색
    }

    long long answer = start; //start==end==mid일 때 탐색완료
    return answer;
}