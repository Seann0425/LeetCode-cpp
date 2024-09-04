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
    int minMaxDifference(int num) {
        string mx = to_string(num);
        char yo = '@';
        for (auto &digit : mx) {
            if (digit != '9' && yo == '@') {
                yo = digit;
                digit = '9';
            } else if (digit == yo) {
                digit = '9';
            }
        }
        string mn = to_string(num);
        yo = '@';
        for (auto &digit : mn) {
            if (digit != '0' && yo == '@') {
                yo = digit;
                digit = '0';
            } else if (digit == yo) {
                digit = '0';
            }
        }

        return stoi(mx) - stoi(mn);
    }
};