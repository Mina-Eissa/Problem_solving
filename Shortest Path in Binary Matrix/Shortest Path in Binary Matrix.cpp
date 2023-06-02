class Solution {
public:
    const int dx[8]={-1,1,0,0,-1,-1,1,1};
    const int dy[8]={0,0,-1,1,-1,1,1,-1};
    bool valid(int&i,int&j,int&n){
        return i>=0 && j>=0 && i<n && j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),x,y;
        if(grid[0][0]==1||grid[n-1][n-1]==1)
            return -1;
        queue<vector<int>>q;
        vector<int> cur;
        q.push({0,0,1});
        while(!q.empty()){
            cur=q.front();
            q.pop();
            if(cur[0]==n-1&&cur[1]==n-1)
                return cur[2];
            
            for(int idx=0;idx<8;idx++){
                x=cur[0]+dx[idx],y=cur[1]+dy[idx];
                if(valid(x,y,n)&&grid[x][y]==0)
                    q.push({x,y,cur[2]+1}),grid[x][y]=1;
            }
        }
        return -1;
    }
};