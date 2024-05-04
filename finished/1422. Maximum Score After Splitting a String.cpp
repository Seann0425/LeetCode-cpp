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
    int maxScore(string s) {
        vector<int> leftZero(s.size() - 1), rightOne(s.size() - 1);
        for (int i = 0, sum = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') sum++;
            leftZero[i] = sum;
        }
        for (int i = rightOne.size() - 1, sum = 0; i >= 0; i--) {
            if (s[i + 1] == '1') sum++;
            rightOne[i] = sum;
        }
        int ans = 0;
        for (int i = 0; i < leftZero.size(); i++) {
            ans = max(ans, leftZero[i] + rightOne[i]);
        }
        return ans;
    }
};