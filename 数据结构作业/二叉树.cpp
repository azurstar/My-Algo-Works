#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int MAXN = 1e3 + 5;
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL                                                               ) {}
};

// 建立二叉树
TreeNode* BuildTree(string preorder,int& index) {
    if (index >= preorder.length()) {
        return NULL;
    }
    if (preorder[index] == '#') {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    root->left = BuildTree(preorder, index);
    root->right = BuildTree(preorder, index);
    return root;
}

// 层序遍历 BFS
string levelOrder(TreeNode* root) {
    vector< vector<char>> data;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        if(q.back()==nullptr) data[q.size()].push_back('#');
        else data[q.size()].push_back(q.back()->val);
        q.push(q.back()->left);
    }
}

// 打印二叉树
void printTree(TreeNode* root,string preorder,int level=0) {
    int len = preorder.length();
    double n0 = log2(len+1) + 1;
    int n = n0;
    if(n0>n) n++;

}
//     A
//    / \
//   B   C
//  /
// D
int main() {
    ios::sync_with_stdio(0);cout.tie(0);
    int index = 0;
    string preorder="ABD#G###CE#H##F##";
    TreeNode* tree = BuildTree(preorder,index);
    printTree(tree,preorder);
    return 0;
}