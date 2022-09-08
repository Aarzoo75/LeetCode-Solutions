# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        p = head
        length = 0
        while p:
            length+=1
            p = p.next
      
        
        if length == 1 and n == 1:
            return head.next
        if length == n:
            return head.next
        p = head
        i =1
        while i<length-n:
            p = p.next
            i+=1
        p.next = p.next.next
        return head