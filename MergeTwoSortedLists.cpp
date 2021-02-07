/*
Problem: LeetCode - Merge Two Sorted Lists(https://leetcode.com/problems/merge-two-sorted-lists/)
Date: 02/07/2021
Written by: Hayoon Park
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(); //list
        ListNode* answerNode = answer; // 한 개의 객체
        if (l1 == NULL) // 각 l1, l2가 비어있는 경우 다른 ListNode를 출력
            return l2;
        else if (l2 == NULL)
            return l1;
        else {
            while ((l1 != NULL) && (l2 != NULL)) { // l1, l2 둘 중 하나가 비워지기 전까지
                if (l1->val > l2->val) { // 등호를 붙여도 동일
                    answerNode->next = l2; // l2 값 하나씩 추가
                    l2 = l2->next; // l2의 값을 옮김
                }
                else { // l1->val <= l2->val
                    answerNode->next = l1;
                    l1 = l1->next;
                }
                answerNode = answerNode->next; //answer 다음 내용 추가 준비
            } //while 문을 나오면 l1, l2 중 하나는 비워지고, 나머지는 남아있음
            if (l1 == NULL) //남아있는 list를 뒤에 붙여준다.
                answerNode->next = l2;
            else if (l2 == NULL) 
                answerNode->next = l1;
            return answer->next;
        }
    }
};
// ListedNode에 대한 이해력 부족으로 인해 난이도가 조금 있었음
