#ifndef STREAMUTILS_HPP
#define STREAMUTILS_HPP

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec);

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& matrix);

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<double>>& matrix);

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec);

std::ostream& operator<<(std::ostream& os, const ListNode* head);

ListNode* makeList(const std::vector<int>& vec);

#endif