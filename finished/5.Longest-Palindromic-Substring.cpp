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
    string longestPalindrome(string s) {
        const int n = static_cast<int>(s.size());
        vector<vector<bool>> Palindrome(n, vector<bool>(n, true));
        for (int diff = 1; diff < n; diff++) {
            for (int i = 0; i + diff < n; i++) {
                Palindrome[i][i + diff] = (Palindrome[i + 1][i + diff - 1] && s[i] == s[i + diff]);
            }
        }
        for (int length = n; length > 0; length--) {
            for (int begin = 0; begin + length <= n; begin++) {
                if (Palindrome[begin][begin + length - 1]) return s.substr(begin, length);
            }
        }
        return "";
    }
};