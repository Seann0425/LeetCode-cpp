#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() < sentence2.size()) sentence1.swap(sentence2);
        const auto n1 = sentence1.size(), n2 = sentence2.size();
        // deal with the case where sentence2 is the prefix or suffix of sentence1
        if (auto i = sentence1.find(sentence2); i == 0 || i == n1 - n2) return true;
        // then use two pointers to make sure that we can completely run through sentence2
        size_t l = 0, r = n2 - 1;
        while (l < n2 && sentence1[l] == sentence2[l]) l++;
        if
    }
};