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

class Node {
public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*the solution should start from below*/

class Solution {
public:
    int findLHS(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int curN = nums[0], preCount = 0, curCount = 0;
        int mx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != curN) {
                if (preCount) mx = max(mx, preCount + curCount);
                if (nums[i] - curN == 1) {
                    preCount = curCount;
                    curCount = 0;
                } else {
                    preCount = curCount = 0;
                }
                curN = nums[i];
            }
            curCount++;
        }
        if (preCount) mx = max(mx, preCount + curCount);
        return mx;
    }
};