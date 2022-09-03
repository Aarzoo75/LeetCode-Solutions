class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        med1 = med2 = i = j = 0
        n = len(A) + len(B)
        
        while (i + j) <= n / 2:
            if i < len(A) and j < len(B):
                med2 = med1
                if A[i] < B[j]:
                    med1 = A[i]
                    i += 1
                else:
                    med1 = B[j]
                    j += 1
            elif i < len(A):
                med2 = med1
                med1 = A[i]
                i += 1
            elif j < len(B):
                med2 = med1
                med1 = B[j]
                j += 1

        if n % 2 == 0:
            return (med1 + med2) / 2.0
        else:
            return med1