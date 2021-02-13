/*
Problem: LeetCode - Remove Duplicates From Sorted Array(https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
Date: 02/13/2021
Written by: Hayoon Park
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) //주어진 nums가 비어있는 경우(nums = [])
            return nums.size(); //아래 answer에 push_back()할 때 오류가 생기므로 바로 return
        vector<int> answer; //중복을 없애기 위해 새로운 vector 선언
        answer.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            if (answer.back() != nums[i]) //nums를 탐색하면서 중복되지 않은 element를 발견 한 경우
                answer.push_back(nums[i]); //answer에 새로 추가(중복된 경우 건너뜀(else continue;))
        }
        nums = answer;
        return nums.size();
    }
};
