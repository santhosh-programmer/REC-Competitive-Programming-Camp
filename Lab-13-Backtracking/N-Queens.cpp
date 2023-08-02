// CLEAN CODE WILL BE UPDATED SOON

class Solution {
public: 
    vector<vector<string>> ans;
    void print(int n, vector<vector<int>> adj) {
        vector<string> tans;
        for(int i=0;i<n;i++) {
            string s="";
            for(int j=0;j<n;j++) {
                if(adj[i][j]) s=s+'Q';
                else s=s+'.';
            }
            tans.push_back(s);
        }
        ans.push_back(tans);

    }
    void find(int n, int row, vector<vector<int>> &adj) {
        for(int i=0;i<n;i++) {
            int f=1;
            for(int j=row-1;j>=0;j--) {
                if(adj[j][i]) {
                    f=0;
                    break;
                }
            }
            if(f) {
                for(int x=row-1,y=i-1; x>=0 && y>=0; x--,y--) {
                    if(adj[x][y]) {
                        f=0;
                        break;
                    }
                }
            }
            if(f) {
                for(int x=row-1,y=i+1; x>=0 && y<n; x--,y++) {
                    if(adj[x][y]) {
                        f=0;
                        break;
                    }
                }
            }
            if(f) {
                adj[row][i]=1;
                if(row+1==n) {
                    print(n,adj);
                    adj[row][i]=0;
                    break;
                }
                else {
                    find(n,row+1,adj);
                    adj[row][i]=0;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> adj(n,vector<int> (n,0));
        find(n,0,adj);
        return ans;
    }
};
