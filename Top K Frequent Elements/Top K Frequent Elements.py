# link : https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        most_common = counter.most_common(k)
        ans = []
        for key, value in most_common:
            ans.append(key)
        return ans
