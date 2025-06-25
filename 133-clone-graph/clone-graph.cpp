/*
// Definition for a Node.
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


Few things to observe
Use BFS
Q : 2, 4
SET : 1, 2, 4, 3

CLONE; 1, 2, 4, 3

*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        Node* clone = new Node(node->val);
        
        map<int, Node*> created;

        queue<Node*> bfs;
        bfs.push(node);
        created[clone->val] = clone;

        while ( !bfs.empty() ) {
            Node* top = bfs.front();
            bfs.pop();
            Node* curr = created[top->val];

            for (auto neigh: top->neighbors) {
                if ( created.find(neigh->val) == created.end() ) {
                    bfs.push(neigh);
                    created[neigh->val] = new Node(neigh->val);
                }
                Node* clone_neigh = created[neigh->val];

                curr->neighbors.push_back(clone_neigh);
            }
        }


        return clone;        
    }
};