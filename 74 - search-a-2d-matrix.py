class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        lr, lc, rr, rc = 0, 0, m-1, n-1
        while lr*n + lc <= rr*n + rc:
            mid = lr*n + lc + rr*n + rc
            mr, mc = mid//n, mid%n
            if matrix[mr][mc] == target:
                return True
            elif matrix[mr][mc] < target:
                lr, lc = (mid+1)//n, (mid+1)%n
            else:
                rr, rc = (mid-1)//n, (mid-1)%n
        return False
