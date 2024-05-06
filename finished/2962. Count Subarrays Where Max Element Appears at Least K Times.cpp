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
    long long countSubarrays(vector<int> &nums, int k) {
        // find maximum
        int maximum = *max_element(nums.begin(), nums.end());

        // sliding
        size_t right = 0;
        int cur_cntr = 0;
        long long cntr = 0;
        for (size_t left = 0; left < nums.size(); left++) {
            while (right < nums.size() && cur_cntr < k)
                cur_cntr += (nums[right++] == maximum ? 1 : 0);
            if (right == nums.size() && cur_cntr < k) return cntr;
            cntr += static_cast<long long>(nums.size() - right + 1);
            if (nums[left] == maximum) cur_cntr--;
        }
        return cntr;
    }
};