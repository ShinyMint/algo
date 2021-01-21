/*
Problem: LeetCode - Longest Common Prefix(https://leetcode.com/problems/longest-common-prefix/)
Date: 01/21/2021
Written by: Hayoon Park
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string answer; 
        if (strs.empty()) //strs가 입력이 없는 경우
            return answer; //비어있는 answer를 반환한다.
        else { //if ~ else문으로 처리한 이유: strs에 값이 없는 경우 standardStr에서 오류 발생
            string standardStr = strs[0]; //strs의 첫번째 단어를 기준으로 한다.
            
            for (int i = 0; i < standardStr.length(); i++) { //소문자를 비교할 위치를 정함
                for (int j = 1; j < strs.size(); j++) { //standardStr과 비교할 단어를 정함
                    if (standardStr[i] != strs[j][i]) //만약 단어 간 소문자가 다른 경우
                        return answer; //정지 후 answer를 출력한다.
                }
                answer.push_back(standardStr[i]); //비교한 소문자가 같은 경우 answer에 추가한다.
            }
            return answer;
        }
    }
};
/*
예시)
f l o w e r : strs[j = 0]
f l o w : strs[j = 1]
f l i g h t : : strs[j = 2]
행: i값, 열: j값

다른 풀이: 단어의 길이를 별도로 정해주는 방법(해당 풀이를 사용해도 rumtime, memory에는 차이가 없었음)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string answer; 
        if (strs.empty()) //strs가 입력이 없는 경우
            return answer; //비어있는 answer를 반환한다.
        else { //if ~ else문으로 처리한 이유: strs에 값이 없는 경우 standardStr에서 오류 발생
            string standardStr = strs[0]; //strs의 첫번째 단어를 기준으로 한다.
            int stringLength = standardStr.length();
            
            //추가된 부분!
            //첫번째 for문: 가장 짧은 단어의 길이 구하기
            for (int p = 0; p < strs.size(); p++) {
                if (stringLength > strs[p].length()) //strs의 첫번째 단어를 기준으로 더 짧은 단어가 있으면
                    stringLength = strs[p].length(); //그 단어를 기준으로 한다.
            }
            
            //두번때 for문: 단어 간 소문자 비교
            for (int i = 0; i < stringLength; i++) {
                for (int j = 1; j < strs.size(); j++) {
                    if (standardStr[i] != strs[j][i])
                        return answer;
                }
                cout << standardStr[i] << endl;
                answer.push_back(standardStr[i]);
            }
            return answer;
        }
    }
};
*/
