# link :https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.pq = []
        self.K = k
        for val in nums:
            self.add(val)

    def add(self, val: int) -> int:
        heapq.heappush(self.pq, val)
        if len(self.pq) > self.K:
            heapq.heappop(self.pq)
        return self.pq[0]
