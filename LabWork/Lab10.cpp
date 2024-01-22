#include "Lab10.h"

TreeNode* BookLibrary::insertBook(TreeNode* root, TreeNode* newBook)
{
    if (root == nullptr) return newBook;

    if (newBook->val.year < root->val.year)
    {
        root->left = insertBook(root->left, newBook);
    }
    else if (newBook->val.year > root->val.year)
    {
        root->right = insertBook(root->right, newBook);
    }

    return root;
}

TreeNode* BookLibrary::deleteBooks(TreeNode* root, TreeNode* bookToDelete)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (bookToDelete->val.year < root->val.year)
    {
        root->left = deleteBooks(root->left, bookToDelete);
    }
    else if (bookToDelete->val.year > root->val.year)
    {
        root->right = deleteBooks(root->right, bookToDelete);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = root->right;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }

        root->val.udk = temp->val.udk;
        root->val.author = temp->val.author;
        root->val.title = temp->val.title;
        root->val.year = temp->val.year;
        root->val.copies = temp->val.copies;

        root->right = deleteBooks(root->right, temp);
    }

    return root;
}

void BookLibrary::printBooks(TreeNode* root)
{
    if (root != nullptr)
    {
        printBooks(root->left);
        std::cout << "УДК: " << root->val.udk << ", Автор: " << root->val.author << ", Название: " << root->val.title
                  << ", Год издания: " << root->val.year << ", Количество: " << root->val.copies << "\n";
        printBooks(root->right);
    }
}
