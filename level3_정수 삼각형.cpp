/*동적계획법 알고리즘:부분 문제를 정의 후 점화식을 구한다->반복문(bottom-up방식은 반복문을 이용해서 문제해결함)과
점화식을 이용하여, Bottom-up(작은 문제부터큰 문제로 확장하면서 문제해결하는 방식을 의미) 방식으로 문제해결*/
#include <string>
#include <vector>
#include <algorithm>
#define max_int 499

using namespace std;

int answer = 0;//배열d(경로의 합을 누적한 배열)의 각 행에서, 최대값이 answer에 대입됨
int height = 0;
int d[max_int][max_int] = { 0, };//각 경로의 합을 누적해서 저장해 놓을 배열
//ex){{7},{10,15},{18,max(10,15)+1,15},...}

int solution(vector<vector<int>> triangle) {
    d[0][0] = triangle[0][0];//각 경로의 합을 누적시킴
    answer = d[0][0];//첫번째 행에선 최대값이 d[0][0]이므로, d[0][0]을 answer에 대입함
    height = (int)triangle.size();//삼각형의 높이를 계산 
    for (int i = 1; i < height; i++) {//두번째 행부터 시작:각 경로의 합을 누적시킴
        for (int j = 0; j <= i; j++) {
            if (j == 0) {// 1) 삼각형 제일 왼쪽 끝인 경우
                d[i][j] = d[i - 1][j] + triangle[i][j]; //점화식 
            }
            else if (j == i) {// 2) 삼각형 제일 오른쪽 끝인 경우
                d[i][j] = d[i - 1][j - 1] + triangle[i][j]; //점화식
            }
            else {// 3) 삼각형 왼쪽, 오른쪽 끝인 아닌 내부인 경우
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j]; //점화식
            }
            answer = max(answer, d[i][j]);//한 행에 대해서 최대값 갱신:배열d(경로의 합을 누적한 배열)의 각 행에서, 최대값이 answer에 대입됨.
        }
    }
    return answer;
}