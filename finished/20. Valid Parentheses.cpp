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
    bool isValid(string s) {
        stack<char> brackets;
        for (auto ch : s) {
            switch (ch) {
            case ')':
                if (!brackets.empty() && brackets.top() == '(') brackets.pop();
                else return false;
                break;
            case ']':
                if (!brackets.empty() && brackets.top() == '[') brackets.pop();
                else return false;
                break;
            case '}':
                if (!brackets.empty() && brackets.top() == '{') brackets.pop();
                else return false;
                break;
            default:
                brackets.push(ch);
                break;
            }
        }
        if (!brackets.empty()) return false;
        return true;
    }
};