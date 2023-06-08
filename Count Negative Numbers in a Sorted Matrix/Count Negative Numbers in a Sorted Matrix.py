class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ctr = 0
        m = len(grid[0])
        for row in grid:
            st, ed = 0,m-1
            while st<=ed :
                mid = (st+ed)//2
                if row[mid]>=0:
                    st = mid + 1
                else: 
                    ed = mid - 1
            ctr+= m - st
        return ctr