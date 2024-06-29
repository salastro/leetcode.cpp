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
  int min_depth = INT_MAX;

public:
  int minDepth(TreeNode *root, int depth = 0) {
    if (!root)
      return 0;

    dfs(root);

    return min_depth;
  }

  void dfs(TreeNode *node, int depth = 0) {
    if (!node)
      return;

    if (!node->left && !node->right) {
      min_depth = min(min_depth, depth + 1);
    }

    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
  }
};

int main() {
  // // root = [3,9,20,null,null,15,7]
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);

  // root = [2,null,3,null,4,null,5,null,6]
  TreeNode *root2 = new TreeNode(2);
  root2->right = new TreeNode(3);
  root2->right->right = new TreeNode(4);
  root2->right->right->right = new TreeNode(5);
  root2->right->right->right->right = new TreeNode(6);

  Solution sol1;
  cout << sol1.minDepth(root1) << endl;
  Solution sol2;
  cout << sol2.minDepth(root2) << endl;

  return 0;
}
