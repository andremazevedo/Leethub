#ifndef STREAMUTILS_HPP
#define STREAMUTILS_HPP

#include <iostream>
#include <optional>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <limits.h>
#include <cmath>
#include <cctype>
#include <sstream>

#define getName(VariableName) # VariableName

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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

std::ostream& operator<<(std::ostream& os, const ListNode* head);

ListNode* makeList(const std::vector<int>& vec);

std::ostream& operator<<(std::ostream& os, const TreeNode* root);

TreeNode* makeTree(const std::vector<std::optional<int>>& vec);

template<typename T>
void printArg(const T& arg) {
    if (std::is_same_v<T, std::string>) {
        std::cout << "\"" << arg << "\"";
    } else if (std::is_same_v<T, char>) {
        std::cout << "\"" << arg << "\"";
    } else {
        std::cout << arg;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        printArg(vec[i]);
        if (i < vec.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& matrix)
{
    os << "[";
    for (size_t row = 0; row < matrix.size(); ++row) {
        printArg(matrix[row]);
        if (row < matrix.size() - 1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

template<typename T>
void printVal(const T& arg);

// template<>
// void printVal<std::string>(const std::string& str);

template<typename T, typename... Types>
void printVal(const T& arg, const Types&... args);

// template<typename... Types>
// void printVal(const std::string& str, const Types&... args);

template<typename T>
void printName(const T& arg);

template<typename T, typename... Types>
void printName(const T& arg, const Types&... args);

template<typename T, typename... Types>
void printInput(const T& arg, const Types&... args);

template<typename T> void printOutput(T arg);

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

template<typename T>
void printVal(const T& arg)
{
    printArg(arg);
    std::cout << std::endl;
}

// template<>
// void printVal<std::string>(const std::string& str)
// {
//     std::cout << "\"" << str << "\"" << std::endl;
// }

template<typename T, typename... Types>
void printVal(const T& arg, const Types&... args)
{
    printArg(arg);
    std::cout << ", ";
    printName(args...);
}

// template<typename... Types>
// void printVal(const std::string& str, const Types&... args)
// {
//     std::cout << "\"" << str << "\", ";
//     printName(args...);
// }

template<typename T>
void printName(const T& arg)
{
    std::cout << arg << " = " << std::endl;
}

template<typename T, typename... Types>
void printName(const T& arg, const Types&... args)
{
    std::cout << arg << " = ";
    printVal(args...);
}

template<typename A, typename B>
void printInputArg(const A& name, const B& val)
{
    std::cout << name << " = ";
    printArg(val);
    std::cout << std::endl;
}

template<typename A, typename B, typename... Types>
void printInputArg(const A& name, const B& val, const Types&... args)
{
    std::cout << name << " = ";
    printArg(val);
    std::cout << ", ";
    printInputArg(args...);
}

template<typename T, typename... Types>
void printInput(const T& arg, const Types&... args)
{
    std::cout << "Input: ";
    printInputArg(arg, args...);
}

template<typename T> void printOutput(T arg) 
{
    std::cout << std::boolalpha << "Output: ";
    printArg(arg);
    std::cout << std::endl;
}


#endif
