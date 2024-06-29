#include <climits>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }

    int left = height(root->left);
    int right = height(root->right);
    int diff = abs(left - right);

    if (diff > 1) {
      return false;
    }

    bool isLeft = isBalanced(root->left);
    bool isRight = isBalanced(root->right);

    return isLeft && isRight;
  }

  int height(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
  }
};

int main() {
  // // root = [3,9,20,null,null,15,7]
  TreeNode *root1 = new TreeNode(1);
  root1->right = new TreeNode(2);
  root1->left = new TreeNode(3);
  root1->left->left = new TreeNode(9);
  root1->left->right = new TreeNode(20);
  root1->left->right->left = new TreeNode(15);
  root1->left->right->right = new TreeNode(7);

  // root = [2,null,3,null,4,null,5,null,6]
  TreeNode *root2 = new TreeNode(2);
  root2->right = new TreeNode(3);
  root2->right->right = new TreeNode(4);
  root2->right->right->right = new TreeNode(5);
  root2->right->right->right->right = new TreeNode(6);

  // root = [2,1,4,null,null,3,5,null,null,null,6]
  TreeNode *root3 = new TreeNode(2);
  root3->left = new TreeNode(1);
  root3->right = new TreeNode(4);
  root3->right->left = new TreeNode(3);
  root3->right->right = new TreeNode(5);
  root3->right->right->right = new TreeNode(6);

  Solution sol1;
  cout << sol1.isBalanced(root1) << endl;
  Solution sol2;
  cout << sol2.isBalanced(root2) << endl;
  Solution sol3;
  cout << sol3.isBalanced(root3) << endl;

  return 0;
}
