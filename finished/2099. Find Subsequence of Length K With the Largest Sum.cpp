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
private:
    class Number {
    public:
        int val;
        int idx;
        Number(int x, int y) {
            val = x;
            idx = y;
        }
    };

    struct cmp {
        bool operator()(const Number &a, const Number &b) {
            return a.val < b.val;
        }
    };
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        priority_queue<Number, vector<Number>, cmp> firstK;
        for (int i = 0; i < nums.size(); i++)
            firstK.push(Number(nums[i], i));
        vector<Number> process;
        for (int i = 0; i < k; i++) {
            process.push_back(firstK.top());
            firstK.pop();
        }
        sort(process.begin(), process.end(), [](const Number &a, const Number &b) { return a.idx < b.idx; });
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
            ans[i] = process[i].val;
        return ans;
    }
};