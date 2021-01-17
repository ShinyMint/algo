/*
Problem: LeetCode - Roman to Integer(https://leetcode.com/problems/roman-to-integer/)
Date: 01/17/2021
Written by: Hayoon Park
*/
class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        /*
        string s를 순서대로 읽으면서 더하되,
        특이 케이스(IV, IX, XL, XC, CD, CM)의 경우를 확인하며 값을 더해준다.
        => I, X, C의 경우에 뒤에 어떤 로마자가 오느냐에 따라 값이 달라지므로 
        해당 경우들만 확인하면서 계산한다.
        */
        for (int i = 0; i < s.length(); i++) {
            char roman = s[i];
            switch(roman) { //로마자를 각각 확인하기 위해 사용한다.
                case 'I': 
                    if (i == s.length() - 1) { //위치가 제일 뒤인 경우, 뒤를 확인하지 않고 해당 값을 더해준다.
                        answer += 1; //이 if문은 없어도 실행 가능하나, 실행시간이 감소하기 때문에 유지하였다.
                    }
                    else if (s[i+1] == 'V') { //IV 케이스 추가
                        answer += 4;
                        i++; //뒤 로마자와 연결되어 계산했으므로 한칸 더 뒤로 보낸다.
                    }
                    else if (s[i+1] == 'X') { //IX 케이스
                        answer += 9;
                        i++;
                    }
                    else {
                        answer += 1;
                    }
                    break;
                case 'V':
                    answer += 5;
                    break;
                case 'X':
                    if (i == s.length() - 1) {
                        answer += 10;
                    }
                    else if (s[i+1] == 'L') { //XL 케이스
                        answer += 40;
                        i++;
                    }
                    else if (s[i+1] == 'C') { //XC 케이스
                        answer += 90;
                        i++;
                    }
                    else {
                        answer += 10;
                    }
                    break;
                case 'L':
                    answer += 50;
                    break;
                case 'C':
                    if (i == s.length() - 1) {
                        answer += 100;
                    }
                    else if (s[i+1] == 'D') { //CD 케이스
                        answer += 400;
                        i++;
                    }
                    else if (s[i+1] == 'M') { //CM 케이스
                        answer += 900;
                        i++;
                    }
                    else {
                        answer += 100;
                    }
                    break;
                case 'D':
                    answer += 500;
                    break;
                case 'M':
                    answer += 1000;
                    break;
            }
        }
        return answer;
    }
};

/*
Roman Number
1 - I
2 - II
3 - III
4 - IV
5 - V
6 - VI
7 - VII
8 - VIII
9 - IX
10 - X

4, 9일 때 확인
4 - IV
9 - IX
40 - XL
90 - XC
400 - CD
900 - CM

기본값
I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000

V, L, D, M: add
I, X, C: if next is {(V,X),(L,C),(D,M)}, add others
*/
