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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        const int n = grid.size();
        vector<bool> occurOnce(n * n);
        vector<int> ans(2, 0);
        int gridSum = 0;
        for (const auto &v : grid) {
            for (const auto &i : v) {
                gridSum += i;
                occurOnce[i - 1] = !occurOnce[i - 1];
                if (occurOnce[i - 1] == false) {
                    ans[0] = i;
                }
            }
        }
        ans[1] = (n * n) * (n * n + 1) / 2 - gridSum + ans[0];
        return ans;
    }
};