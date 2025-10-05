#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
Node* buildTree(int n, vector<tuple<int,int,int>>& edges) {
    unordered_map<int, Node*> nodes;

    for(auto &edge : edges){
        int parent, left, right;
        tie(parent,left,right) = edge;

        if(nodes.find(parent) == nodes.end())
            nodes[parent] = new Node(parent);
        Node* parentNode = nodes[parent];

        if(left != -1){
            if(nodes.find(left) == nodes.end())
                nodes[left] = new Node(left);
            parentNode->left = nodes[left];
        }

        if(right != -1){
            if(nodes.find(right) == nodes.end())
                nodes[right] = new Node(right);
            parentNode->right = nodes[right];
        }
    }
    return nodes[get<0>(edges[0])];
}
vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root==NULL) return {};
    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* node=it.first;
        int line=it.second;
        mpp[line]=node->data;
        if(node->left!=NULL) q.push({node->left,line-1});
        if(node->right!=NULL) q.push({node->right,line+1});
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<tuple<int,int,int>> edges(n);
    for(int i=0;i<n;i++){
        int p,l,r;
        cin >> p >> l >> r;
        edges[i] = make_tuple(p,l,r);
    }

    Node* root = buildTree(n, edges);
    vector<int> ans=bottomView(root);
    for(int val:ans){
        cout<<val<<" ";
    }
    return 0;
}

