/*
Problem: LeetCode - Two Sum(https://leetcode.com/problems/two-sum/)
Date: 01/13/2021
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer; //store the answer
        int numCheck; //stores the difference(gap)
        
        for(int i = 0; i < nums.size(); i++) { //check from nums[0]~nums[nums.size()-1]
            numCheck = target - nums[i]; //check the difference between target & nums[i]
            
            for(int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == numCheck) { //if the difference can be found in 'nums', 
                    answer.push_back(i); //add position into 'answer' vector
                    answer.push_back(j); 
                    break; //this requires exactly one solution. So if you find answer, break
                }
            }
        }
        return answer;
    }
};
