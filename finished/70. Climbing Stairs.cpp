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
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;
        vector<int> F(n);
        F[0] = 1;
        F[1] = 2;
        for (int i = 2; i < n; i++) {
            F[i] = F[i - 1] + F[i - 2];
        }
        return F[n - 1];
    }
};