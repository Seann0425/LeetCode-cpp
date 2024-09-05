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
    string removeKdigits(string num, size_t k) {
        const auto N = num.size();
        stack<size_t> mono;
        vector<size_t> nextSmaller(N, numeric_limits<size_t>::max());
        for (size_t i = N - 1; i < N; i--) {
            while (!mono.empty() && num[mono.top()] >= num[i]) {
                mono.pop();
            }
            if (!mono.empty()) nextSmaller[i] = mono.top();
            mono.push(i);
        }
        string res;
        for (size_t i = 0; i < N; i++) {
            if (k > 0 && (nextSmaller[i] - i <= k || N - i <= k)) {
                k--;
            } else if (num[i] == '0' && res.empty()) continue;
            else res.push_back(num[i]);
        }
        if (res.empty()) res.push_back('0');
        return res;
    }
};