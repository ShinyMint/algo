/*
Problem: LeetCode - Merge Sorted Array(https://leetcode.com/problems/merge-sorted-array/)
Date: 02/20/2021
Written by: Hayoon Park
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) //nums2의 element들을 nums1의 뒷부분에 대입한다.
            nums1[m+i] = nums2[i]; // 예시) [1,2,3,0,0,0],[2,5,6]->[1,2,3,2,5,6]
        
        sort(nums1.begin(), nums1.end()); //nums1을 오름차순으로 정렬한다.
    }
};
/*
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200

방법 1) nums2를 nums1의 뒤에 넣은 후 전체정렬
[1,2,3,0,0,0],[2,5,6]->[1,2,3,2,5,6]->[1,2,2,3,5,6]
하나의 for문과 sort()를 이용하여 짧은 코드 생성 가능

방법 2) nums1에 nums2의 요소를 하나씩 대입
[1,2,3,0,0,0],[2,5,6]
->[1,2,2,3,0,0],[5,6]
->[1,2,2,3,5,0],[6]
->[1,2,2,3,5,6],[]
두 개 이상의 for문이 사용되므로 보류
*/
