#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int postIdx;

Node* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inst, int inend, unordered_map<int,int>& inMap){
    if(inst > inend || postIdx < 0) return NULL;

    int rootVal = postorder[postIdx--];
    Node* root = new Node(rootVal);

    int inIdx = inMap[rootVal];

    root->right = buildTreeHelper(inorder, postorder, inIdx + 1, inend, inMap);
    root->left = buildTreeHelper(inorder, postorder, inst, inIdx - 1, inMap);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int,int> inMap;
    for(int i=0;i<n;i++) inMap[inorder[i]] = i;

    postIdx = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, inMap);
}

void printLevelOrder(Node* root) {
    if(!root) return;
    queue<Node*> q;
    vector<string> res;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front(); q.pop();
        if(node){
            res.push_back(to_string(node->data));
            q.push(node->left);
            q.push(node->right);
        } else {
            res.push_back("null");
        }
    }

    while(!res.empty() && res.back() == "null") res.pop_back();

    for(size_t i = 0; i < res.size(); i++){
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> postorder(n), inorder(n);
    for(int i=0;i<n;i++) cin >> postorder[i];
    for(int i=0;i<n;i++) cin >> inorder[i];

    Node* root = buildTree(inorder, postorder);
    printLevelOrder(root);
    return 0;
}
