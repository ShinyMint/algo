/*
Problem: LeetCode - Implement strStr(https://leetcode.com/problems/implement-strstr/)
Date: 02/14/2021
Written by: Hayoon Park
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1; //기준을 false로 정함
        if (needle.empty())
            result = 0; //needle이 비어있는 경우 0출력
        else if (haystack.empty()) //haystack == "" && needle != ""
            result = -1;
        else { //haystack != "" && needle != ""
            char checkNeedle = needle[0]; //needle의 첫부분으로 탐색한다.
            for (int i = 0; i < haystack.length(); i++) { //haystack를 순서대로 탐색한다.
                if (checkNeedle == haystack[i]) { //찾으려는 needle의 첫번째 위치와 같은 알파벳을 발견시,
                    result = i; //해당 위치를 저장
                    for (int j = 0; j < needle.length(); j++) { //해당 위치에서부터 needle과 비교
                        if (needle[j] != haystack[result+j]) { //만약 찾는 needle과 다를 때 (예시: "mississipi", "issip"
                            result = -1; //false 출력 후 다시 탐색
                            break;
                        }
                        else if (j == needle.length()-1) //needle 끝까지 동일한 경우(needle이 haystack 내부에 존재하는 경우)
                            return result;
                    }
                }
            }
        }
        return result;
    }
};
