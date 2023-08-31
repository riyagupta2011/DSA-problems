class Solution {
public:
    Node *dfs(Node *node,map<Node*,Node*> &m)
    {
         vector<Node*> neighbor;
        Node *clone=new Node(node->val);
        m[node]=clone;
        for(auto it:node->neighbors)
        {
            if(m.find(it)!=m.end())
            neighbor.push_back(m[it]);
            else
            neighbor.push_back(dfs(it,m));
        }
        clone->neighbors=neighbor;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> m;
        if(node==NULL)
        return NULL;
        if(node->neighbors.size()==0)
        {
           Node *newNode=new Node(node->val);
           return newNode;
        }
        return dfs(node,m);

    }
};