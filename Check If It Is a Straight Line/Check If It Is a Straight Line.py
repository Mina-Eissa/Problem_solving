class Solution:
    def checkStraightLine(self, coor: List[List[int]]) -> bool:
        def slope(a:List[int],b:List[int]):
            if a[1]==b[1]:
                return 0
            if a[0]==b[0]:
                return a[0]
            return (a[1]-b[1])/(a[0]-b[0])
        s = slope(coor[1],coor[0])
        for i in range(1,len(coor)):
            if slope(coor[i],coor[i-1])!=s:
                return False
        return True