#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
        if (mp.find(cur) != mp.end()) {
            return mp[cur];
        }

        Node* clone = new Node(cur->val);
        mp[cur] = clone;

        for (auto it : cur->neighbors) {
            clone->neighbors.push_back(dfs(it, mp));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};

void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (node == NULL || visited[node]) return;
    
    visited[node] = true;
    cout << "Node " << node->val << " के Neighbors हैं: ";
    for (auto n : node->neighbors) {
        cout << n->val << " ";
    }
    cout << endl;

    for (auto n : node->neighbors) {
        printGraph(n, visited);
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);

    Solution solver;
    Node* clonedRoot = solver.cloneGraph(node1);

    cout << "--- क्लोन किया हुआ ग्राफ ---" << endl;
    unordered_map<Node*, bool> visited;
    printGraph(clonedRoot, visited);

    return 0;
}