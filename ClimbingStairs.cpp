/*
Problem: LeetCode - Climbing Stairs(https://leetcode.com/problems/climbing-stairs/)
Date: 02/20/2021
Written by: Hayoon Park
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n==1) //n==1일 때 지정
            return 1;
        else if (n==2) //n==2일 때 지정
            return 2;
        else {
            int preFormerStair = 1; //climbingStairs(n-2)를 설정한다.   
            int formerStair = 2; //climbingStairs(n-1)을 설정한다.
            int currentStair; //climbingStairs(n)을 저장한다.
            for (int i = 2; i < n; i++) { //n은 3부터 시작하므로 i=2부터 시작한다.
                currentStair = formerStair+preFormerStair; //climbingStairs(n)=climbingStairs(n-1)+climbingStairs(n-2)
                preFormerStair = formerStair; //다음 n이 1 증가했을 때를 위해 옮겨준다.
                formerStair = currentStair; //예) preFormerStair=climbingStairs((n-2)->(n-1)), formerStair=climbingStairs((n-1)->(n))
            }
            return currentStair;
        }
    }
};
/*
수학적인 풀이방법
n=1
1C1=1
n=2
2C2+1C0=1+1=2
n=3
3C3+2C1=1+2=3
n=4
4C4+3C2+2C0=1+3+1=5
n=5
5C5+4C3+3C1=1+4+3=8

1-(1):1
2-(1,1),(2):2
3-(1,1,1),(1,2):3
4-(1,1,1,1),(1,1,2),(2,2):5
5-(1,1,1,1,1),(1,1,1,2),(1,2,2):8
6-(1,1,1,1,1,1),(1,1,1,1,2),(1,1,2,2),(2,2,2):13
(n개의 계단을 올라가는 방법) = (n-2개의 계단을 올라가는 방법)(이후 2계단을 오른다) + (n-1개의 계단을 올라가는 방법)(이후 1계단을 오른다)
n-2개 이후 1+1계단을 오르지 않는 이유: n-1개의 계단을 올라가는 방법에 포함됨

기존 풀이 코드: else return climbStair(n-2)+climbStair(n-1) 여기서 시간초과 오류가 발생하므로 위의 코드로 변환
*/
