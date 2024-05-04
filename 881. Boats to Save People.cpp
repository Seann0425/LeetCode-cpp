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
    int numRescueBoats(vector<int> &people, int limit) {
        int cntr = 0;
        const auto N = people.size();
        sort(people.begin(), people.end(), greater<>());
        vector<bool> carried(N);
        size_t i, j;
        for (i = 0; i < N; i++) {
            if (carried[i]) continue;
            carried[i] = true;
            while (j > i && people[i] + people[j] <= limit)
                j--;
            while (j <= i || carried[j] || people[i] + people[j] > limit)
                j++;
            if (j < N) carried[j] = true;
            cntr++;
        }
        return cntr;
    }
};