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
    int minOperations(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &i : nums)
            pq.push(i);
        int cnt = 0;
        while (pq.size() >= 2 && pq.top() < k) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            cnt++;
            if (b >= k) break;
            if (static_cast<long long>(a) * 2 + b > k) pq.emplace(INT_MAX);
            else pq.emplace(a * 2 + b);
        }
        return cnt;
    }
};