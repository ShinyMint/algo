/*
Problem: LeetCode - Valid Parentheses(https://leetcode.com/problems/valid-parentheses/)
Date: 01/22/2021
Written by: Hayoon Park
*/
class Solution {
public:
    bool isValid(string s) { //괄호 확인 - 주요 예시 문제
        stack<char> checkStack; 
        //stack의 성질을 이용한다.(LIFO, last in first out) <=> queue(FIFO, first in first out)
        char checkChar;
        
        for (int i = 0; i < s.length(); i++) {
            checkChar = s[i];
            switch(checkChar) {
                case '(': //여는 괄호는 stack에 추가
                case '{':
                case '[':
                    checkStack.push(checkChar);
                    break;
                case ')': //닫는 괄호의 경우, 대응하는 괄호가 있을시 계속, 
                    if (checkStack.empty()) //여는 괄호가 없는 경우(예시: "}]") false 출력
                        return false;
                    else if (checkStack.top() == '(')
                        checkStack.pop();
                    else //해당하는 괄호가 없는 경우 false 출력
                        return false;
                    break;
                case '}':
                    if (checkStack.empty())
                        return false;
                    else if (checkStack.top() == '{')
                        checkStack.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (checkStack.empty())
                        return false;
                    else if (checkStack.top() == '[')
                        checkStack.pop();
                    else
                        return false;
                    break;
            }
        }
        if (checkStack.empty()) //괄호를 확인하고 남는 괄호가 있는지 확인
            return true;
        else
            return false;
    }
};
