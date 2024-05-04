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
    vector<int> decrypt(vector<int> &code, int k) {
        int n = code.size();
        vector<int> de(n);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            if (k >= 0)
                for (int j = 1; j <= k; j++)
                    sum += code[(i + j) % n];
            else {
                for (int j = -1; j >= k; j--) {
                    int idx = i + j;
                    while (idx < 0)
                        idx += n;
                    sum += code[idx];
                }
            }
            de[i] = sum;
        }
        return de;
    }
};