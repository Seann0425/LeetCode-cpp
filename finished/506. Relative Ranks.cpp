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
    vector<string> findRelativeRanks(vector<int> &score) {
        map<int, int> sortMap;
        int n = score.size();
        int counter = 3;
        int ranking = 1;
        vector<string> rank(n);
        for (int i = 0; i < n; i++)
            sortMap[score[i]] = i;
        for (auto itr = sortMap.rbegin(); itr != sortMap.rend(); itr++, ranking++) {
            if (counter) {
                switch (counter) {
                case 3:
                    rank[itr->second] = "Gold Medal";
                    counter--;
                    break;
                case 2:
                    rank[itr->second] = "Silver Medal";
                    counter--;
                    break;
                default:
                    rank[itr->second] = "Bronze Medal";
                    counter--;
                    break;
                }
                continue;
            }
            rank[itr->second] = to_string(ranking);
        }
        return rank;
    }
};