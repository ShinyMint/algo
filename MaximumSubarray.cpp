/*
Problem: LeetCode - Maximum Subarray(https://leetcode.com/problems/maximum-subarray/)
Date: 02/16/2021
Written by: Hayoon Park
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = -100000; //주어진 문제에서 -10^5 < nums[i] < 10^5로 제한됨
        for (int i = 0; i < nums.size(); i++) { //subArray의 시작 위치를 옮겨간다.
            int subSize = nums.size() - i; //subArray의 크기를 증가시킨다.
            int tempsum = 0; //subArray의 합계를 저장한다.
            for (int j = 0; j < subSize; j++) {
                tempsum += nums[i+j]; //subArray의 시작점에서 한 개씩 더해간다.
                if (maxSub <= tempsum) //subArray배열의 크기가 그 전의 array들 보다 큰 경우 교체
                    maxSub = tempsum;
            }
        }
        return maxSub;
    }
};
/*
예시) nums = [2, 3, -4, 1]
2, 2+3, 2+3+(-4), 2+3+(-4)+1
        3, 3+(-4), 3+(-4)+1
                -4, (-4)+1
                        1
*/
