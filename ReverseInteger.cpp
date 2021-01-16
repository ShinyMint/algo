/*
Problem: LeetCode - Reverse Integer(https://leetcode.com/problems/reverse-integer/)
Date: 01/16/2021
Written by: Hayoon Park
*/
class Solution {
public:
    int reverse(int x) {
        
        vector<int> reverseInt; //x의 각 자리의 수를 역으로 저장하기 위한 역할을 한다.
        int answer = 0; //reverse된 x값을 저장한다.
        
        while (x != 0) { //주어진 x의 모든 자리를 확인할 때까지 한다.
            int temp = x % 10; //제일 뒤의 자리수를 얻는다.
            reverseInt.push_back(temp); //reverseInt에 추가한다.
            x /= 10; //저장하여 빠진 자리를 제거해준다.
        }
        
        /*
        정방향 x = a[0] * 10 ^ (n-1) + a[1] * 10 ^ (n-2) + ... + a[p] * 10 ^ q + ... + a[n-1] * 10 ^ 0 (n: 주어진 수의 자릿수, p + q = n - 1)
        역방향 x = a[n-1] * 10 ^ (n-1) + a[n-2] * 10 ^ (n-2) + ... + a[p] * 10 ^ q + ... + a[0] * 10 ^ 0 (p = q)
        이라고 가정하고,
        reverseInt = {a[n-1], a[n-2], ..., a[0]} 으로 저장되어 있으므로
        각각 10 ^ (n-1), 10 ^ (n-2), ..., 10 ^ 0(= 1)을 곱해준다.
        */
        
        long check = 0; //추가할 값이 int의 범위에 속하지는 확인하기 위한 변수이다.
        for (int i = 0; i < reverseInt.size(); i++) {
            check = reverseInt[i] * pow(10, reverseInt.size() - i - 1); //각가의 자리수에 10^p를 곱해준다.
            if ((answer + check > 2147483647) || (answer + check < -2147483648)) { //만약 새로운 값을 추가했을 때 int 범위를 넘어간다면,
                return 0; //0을 return하고 종료한다. (answer = 0; break;)
            }
            else {
                answer += check; //정상적인 int범위에서 처리가 가능한 경우 그대로 더해준다.
            }
        }
        
        return answer;
        /*
        다른 풀이:
        위의 해설에서
        정방향 x = a[0] * 10^(n-1) + a[1] * 10^(n-2) + ... + a[p] * 10 ^ q + ... + a[n-1] * 10 ^ 0 (n: 주어진 수의 자릿수, p + q = n - 1)
        역방향 x = a[n-1] * 10^(n-1) + a[n-2] * 10^(n-2) + ... + a[p] * 10 ^ q + ... + a[0] * 10 ^ 0 (p = q)
        => q의 값을 바꾸는 것으로 reverseInt를 생략하여 메모리를 줄일 수 있다.
        */
    }
};
