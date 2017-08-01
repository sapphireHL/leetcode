/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return nullptr;
        if(m.find(node) == m.end()){
            m[node] = new UndirectedGraphNode(node->label);
            for(auto i:node->neighbors)
                m[node]->neighbors.push_back(cloneGraph(i));
        }
        return m[node];
    }
};
