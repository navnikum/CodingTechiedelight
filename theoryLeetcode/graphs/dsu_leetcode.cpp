class Solution {
// dsu data structure with Path compression and weighted union
    vector<int> parent;
    vector<int> rnk;
    void make_set(vector<int> &p){
        for(int i=0; i<p.size(); i++) 
            p[i] = i;
    }
    int find(int v){
        return (v == parent[v])? v: parent[v] = find(parent[v]);
    }
    void union_set (int x, int y){
        x = find(x), y = find(y);
        if (x != y){
            if (rnk[x] < rnk[y])
                swap (x, y);

            parent[y] = x;
            if (rnk[x] == rnk[y])
                rnk[x]++;
        }
    }
// https://leetcode.com/problems/redundant-connection/
// dsu on given edges vector
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;     // n = no. of vertex = 1 + no. of edges
        parent.resize(n, 0);
        rnk.resize(n, 0);
        make_set(parent);
        vector<int> res(2,0);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int set_u = find(u);
            int set_v = find(v);
            if (set_u == set_v)
                res[0] = u, res[1] = v;

            union_set(u, v);    
        }
        return res;
    }
// https://leetcode.com/problems/friend-circles/submissions/
// dsu on adj matrix 
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        //int count = n;
        if (n == 0) return 0;
        parent.resize(n, 0);
        rnk.resize(n, 0);
        make_set(parent);
        for(int i=0; i< n; i++) {
            for(int j=0; j< i; j++) {
                if ( i != j  &&  M[i][j]){
                    int set_u = find(i);
                    int set_v = find(j);
                    if (set_u != set_v)
                        union_set(i, j);
                        //count--;            
                }
            }
        }

        unordered_set<int> circles;
        for (int i = 0; i < n; ++i)
            circles.insert(find(i));

        return circles.size();
        //return count;
    }
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/submissions/
// dsu on x,y- coordinates
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n, 0);
        rnk.resize(n, 0);
        make_set(parent);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    int set_u = find(i);
                    int set_v = find(j);
                    if (set_u != set_v)
                        union_set(i, j);
                }
            }
        }

        unordered_set<int> unique;
        for (int i = 0; i < n; ++i)
            unique.insert(find(i));

        return n - unique.size();        
    }

public: // using map
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int> > xmp, ymp;
        // pushing stone IDs into xmp, ymp maps
        for(int i=0; i<n; i++) {
            xmp[stones[i][0]].push_back(i);
            ymp[stones[i][1]].push_back(i);
        }
        parent.resize(n, 0);
        rnk.resize(n, 0);
        make_set(parent);
        for(int i=0; i<n; i++) {
            for(int j : xmp[stones[i][0]]) union_set(i, j);
            for(int j : ymp[stones[i][1]]) union_set(i, j);
        }

        unordered_set<int> unique;
        for (int i = 0; i < n; ++i)
            unique.insert(find(i));

        return n - unique.size();        
    }
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int k = connections.size(), count = 0;
        if (k < n-1)
            return -1;
        
        parent.resize(n, 0);
        rnk.resize(n, 0);
        make_set(parent);

        for(auto it : connections){
            int u_set = find(it[0]);
            int v_set = find(it[1]);
            if (u_set != v_set)
                union_set(it[0], it[1]);
        }

        unordered_set<int> unique;
        for (int i = 0; i < n; ++i)
            unique.insert(find(i));

        return unique.size()-1;
    }
// https://leetcode.com/problems/satisfiability-of-equality-equations/
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26, 0);
        rnk.resize(26, 0);
        make_set(parent);

        for(auto it : equations){
            int u_set = find(it[0] -'a');
            int v_set = find(it[3] -'a');
            if (u_set != v_set  && it[1] == '=')
                union_set(it[0] - 'a', it[3] - 'a');            
        }

        for(auto it : equations){
            int u_set = find(it[0] -'a');
            int v_set = find(it[3] -'a');
            if (u_set == v_set  && it[1] == '!')
                return false;            
        }
            
        return true;
    }
// https://leetcode.com/problems/accounts-merge/
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n, 0);
        rnk.resize(n, 0);
        make_set(parent);

        // union based on emailID sharing => merging
        unordered_map<string, int> mail2id; 
        int acc_idx = 0;
        for(auto it : accounts){
            for(int i=1; i < it.size(); i++){
                string email = it[i];
                if (mail2id.find(email) != mail2id.end())
                    union_set(acc_idx, mail2id[email]);
                else 
                    mail2id[email] = acc_idx;
            }
            acc_idx++;
        }
        // merged emails
        unordered_map<int, set<string>> name2emails;
        acc_idx = 0;
        for(auto it : accounts){
            int p_set = find(acc_idx);    // merged account index
            for(int i=1; i < it.size(); i++)
                name2emails[p_set].insert(it[i]);
        
        acc_idx++;
        }

        // convert to required format
        vector<vector<string>> res;
        for (auto p : name2emails) {
          res.push_back({});
          res.back().push_back(accounts[p.first].front()); // add owner's name
          res.back().insert(res.back().end(), p.second.begin(), p.second.end());
        } 
        return res;
    }    
};





