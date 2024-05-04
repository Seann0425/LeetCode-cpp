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

const size_t N = 1 + 37;

constexpr array<int, N> ans = []() consteval {
    array<int, N> tmp;
    tmp[0] = 0;
    tmp[1] = 1;
    tmp[2] = 1;
    for (size_t i = 3; i < N; i++) {
        tmp[i] = tmp[i - 1] + tmp[i - 2] + tmp[i - 3];
    }
    return tmp;
}();

class Solution {
public:
    int tribonacci(int n) {
        return ans[n];
    }
};