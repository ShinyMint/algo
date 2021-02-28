/*
Problem: LeetCode - Maximum Depth of Binary Tree(https://leetcode.com/problems/maximum-depth-of-binary-tree/)
Date: 03/01/2021
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
    int maxDepth(TreeNode* root) {
        int height = 0; //높이를 저장할 변수 생성
        if (root == NULL) //트리가 비어있는 경우
            return height; //높이는 0으로 출력
        else
            height++; //비어있지 않으면 높이 1 증가
        return checkHeight(root, height);
    }
    
    int checkHeight(TreeNode* root, int height) {
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        if (leftNode == NULL && rightNode == NULL) //노드의 양 측 자식 노드가 비어있는 경우(제일 바닥에 있는 경우)
            return height; //더 내려갈 곳이 없으므로 높이를 출력한다.
        else {
            height++; //아래에 더 내려갈 노드가 있으므로 높이를 1 증가시킨다.
            if (leftNode == NULL) //둘 중 하나의 노드가 비어있는 경우 다른 쪽의 자식 노드로 진행하도록 한다.(사용 이유: 비어있는 항목을 부르려고 하면 에러가 생긴다.)
                return checkHeight(rightNode, height);
            else if (rightNode == NULL)
                return checkHeight(leftNode, height);
            else
                return max(checkHeight(leftNode, height), checkHeight(rightNode, height)); //양 쪽 노드가 모두 존재하면 둘 중 더 큰 값을 불러온다.
        }
    }
};
/*
저번에 올린 Symmetric Tree와 유사함
*/
