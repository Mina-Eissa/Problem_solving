# link: https://leetcode.com/problems/maximum-subsequence-score/
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        v = [[nums2[i], nums1[i]] for i in range(len(nums1))]
        v.sort(key=lambda x: x[0], reverse=True)
        pq = []
        sum = 0
        ans = 0
        for i in range(len(v)):
            heapq.heappush(pq, v[i][1])
            sum += v[i][1]
            if len(pq) == k:
                ans = max(ans, sum * v[i][0])
                sum -= heapq.heappop(pq)
        return ans
