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
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        deque<size_t> dq(deck.size());
        iota(dq.begin(), dq.end(), 0);
        vector<int> reordered(deck.size());
        sort(deck.begin(), deck.end());
        size_t idx = 0;
        while (true) {
            reordered[dq.front()] = deck[idx++];
            dq.pop_front();
            if (!dq.empty()) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else break;
        }
        return reordered;
    }
};