/*
Problem: LeetCode - Symmetric Tree(https://leetcode.com/problems/symmetric-tree/)
Date: 02/28/2021
Written by: Hayoon Park
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        TreeNode* leftTreeRoot = root->left; //tree에서 비교하기 위해 좌측트리와 우측트리로 나눈다.
        TreeNode* rightTreeRoot = root->right;
        
        if (leftTreeRoot == NULL && rightTreeRoot == NULL) //tree가 좌우 둘 다 비어있는 경우 true
            return true;
        else if (leftTreeRoot == NULL || rightTreeRoot == NULL) //둘 중 하나만 비어있는 경우 false
            return false;
        else if (leftTreeRoot->val != rightTreeRoot->val) //두 트리의 root값이 다른 경우 false
            return false;
        else
            return compareNode(leftTreeRoot, rightTreeRoot); //이외의 경우 좌측트리와 우측트리로 나뉘어 확인한다.
    }
    
    bool compareNode(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == NULL && rightNode == NULL) 
            return true;
        else if (leftNode == NULL || rightNode == NULL)
            return false;
        else if (leftNode->val != rightNode->val) //위와 동일하다.
            return false;
        else
            return compareNode(leftNode->left, rightNode->right)&&compareNode(leftNode->right, rightNode->left); 
        //한 쪽 트리에서 좌측 자식 노드에 대응하는 노드는 다른 쪽 트리에서 우측 자식 노드에 대응한다
        //(예시: left,left - right,right / left,right - right,left / left,left,right - right,right,left / ...). 즉, 서로 반대되는 쪽으로 간다.
    }
};
/*
compare list
l-r
ll-rr/lr-rl
lll-rrr/llr-rrl/lrl-rlr/lrr-rll
*/
