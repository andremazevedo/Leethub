#ifndef STREAMUTILS_HPP
#define STREAMUTILS_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

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

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec);

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& matrix);

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<double>>& matrix);

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec);

std::ostream& operator<<(std::ostream& os, const std::vector<TreeNode*>& vec);

std::ostream& operator<<(std::ostream& os, const ListNode* head);

ListNode* makeList(const std::vector<int>& vec);

std::ostream& operator<<(std::ostream& os, const TreeNode* root);

TreeNode* makeTree(const std::vector<int>& vec);

#endif