#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

/*the solution should start from below*/

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *root = new TreeNode;
        if (nums.size() == 1) {
            root->val = nums[0];
            return root;
        }
        if (nums.size() == 2) {
            root->val = nums[1];
            TreeNode *left = new TreeNode;
            left->val = nums[0];
            root->left = left;
            return root;
        }
        int mid = nums.size() / 2;
        root->val = nums[mid];
        vector<int> leftTree, rightTree;
        leftTree.assign(nums.begin(), nums.begin() + mid);
        rightTree.assign(nums.begin() + (mid + 1), nums.end());
        root->left = sortedArrayToBST(leftTree);
        root->right = sortedArrayToBST(rightTree);
        return root;
    }
};