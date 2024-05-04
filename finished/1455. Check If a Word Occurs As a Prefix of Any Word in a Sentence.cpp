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
    int isPrefixOfWord(string sentence, string searchWord) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stringstream ss;
        ss << sentence;
        string target;
        int idx = 0;
        while (ss >> target) {
            idx++;
            if (target.size() < searchWord.size()) continue;
            bool failed = 0;
            for (int i = 0; i < searchWord.size(); i++) {
                if (target[i] != searchWord[i]) {
                    failed = true;
                    break;
                }
            }
            if (!failed) return idx;
        }
        return -1;
    }
};