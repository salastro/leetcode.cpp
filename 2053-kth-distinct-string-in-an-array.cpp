#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isDistinct(vector<string> &arr, int i) {
    for (size_t j = 0; j < arr.size(); j++) {
      if (i != j && arr[i] == arr[j]) {
        return false;
      }
    }
    return true;
  }

  string kthDistinct(vector<string> &arr, int k) {
    size_t n = arr.size();
    vector<string> distinct;
    for (size_t i = 0; i < n; i++) {
      if (isDistinct(arr, i)) {
        distinct.push_back(arr[i]);
      }
    }

    if (k > distinct.size())
      return "";

    return distinct[k - 1];
  }
};

int main() {
  vector<string> arr = {"d", "b", "c", "b", "c", "a"};
  int k = 2;
  Solution sol;
  cout << sol.kthDistinct(arr, k) << endl;
  return 0;
}
