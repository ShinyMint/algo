/*
Problem: LeetCode - Plus One(https://leetcode.com/problems/plus-one/)
Date: 02/17/2021
Written by: Hayoon Park
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back()++; //제일 아랫자리 수에 1일 더한다.
        if (digits.back() == 10) { //그 수가 10을 넘어간 경우(올림 발생)
            int position = digits.size() - 1; //아래에서 위로 읽기 위해 position을 지정
            while (true) { //break(올림이 발생하지 않음)까지 실행
                if (digits[position] == 10) {
                    if (position == 0) { //예시) [10, x, y, ...]
                        digits.insert(digits.begin(), 1); // [10, ...] -> [1, 10, ...]
                        digits[1] = 0; // [1, 10, ...] -> [1, 0, ...]
                    }
                    else { //올림이 발생한 position이 제일 앞이 아닌 경유
                        digits[position] = 0; //[..., 10, ...] -> [..., 0, ...]
                        digits[position-1]++; //10이 발생한 곳 바로 위 자릿수에 1을 더함 
                        position--; //자릿수를 하나 올림
                    }
                }
                else //올림이 발생하지 않은 경우
                    break; //while문에서 나옴(1의 자리에서부터 증가하므로 중간에 올림이 발생하지 않으면 그 위로는 올림이 발생하지 않기 때문)
            }
        }
        return digits;
    }
};
//반복문을 하나만 사용(while문)하였으나, if (position == 0) { ... } else { ... } 부분은 추가로 생략이 가능해 보임.
