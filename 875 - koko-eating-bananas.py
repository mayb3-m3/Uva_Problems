class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r, ans = 1, 10**9, 10**9
        while l <= r:
            mid, count = (l+r)//2, 0
            for i in piles:
                count += (i+mid-1)//mid
            if count > h:
                l = mid + 1
            else:
                ans = min(ans, mid)
                r = mid - 1
        return ans
