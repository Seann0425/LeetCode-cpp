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
    int minimumRecolors(string blocks, int k) {
        // sliding window
        vector<int> counter(2, 0); // 0 for white, 1 for black
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') counter[0]++;
            else counter[1]++;
        }
        int minimum = counter[0];
        for (int i = 1; i <= blocks.size() - k; i++) {
            if (blocks[i - 1] == 'W') counter[0]--;
            else counter[1]--;
            if (blocks[i + k - 1] == 'W') counter[0]++;
            else counter[1]++;
            minimum = min(minimum, counter[0]);
        }
        return minimum;
    }
};