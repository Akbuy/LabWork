#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

struct Book
{
    int udk;
    std::string author;
    std::string title;
    int year;
    int copies;

    Book() : udk(0), author(std::string()), title(std::string()), year(0), copies(0) {}
    Book(int udk, std::string author, std::string title, int year, int copies)
        : udk(udk), author(author), title(title), year(year), copies(copies)
    {
    }
};

struct TreeNode
{
    Book val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(Book()), left(nullptr), right(nullptr) {}
    TreeNode(Book x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(Book x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BookLibrary
{
public:
    static TreeNode* insertBook(TreeNode* root, TreeNode* newBook);
    static TreeNode* deleteBooks(TreeNode* root, TreeNode* bookToDelete);
    static void printBooks(TreeNode* root);

    TreeNode* root;
};
