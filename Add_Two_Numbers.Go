func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    sum := 0
    current := new(ListNode)
    result := current

    for l1 != nil || l2 != nil {
        if l1 != nil {
            sum = sum + l1.Val
            l1 = l1.Next
        }

        if l2 != nil {
            sum = sum + l2.Val
            l2 = l2.Next
        }

        current.Next = &ListNode{sum % 10, nil}
        current = current.Next
        sum = sum / 10
    }

    if sum > 0 {
        current.Next = &ListNode{sum, nil}
    }

    return result.Next
}



// Explanation

// The numbers are represented in reverse order in LinkedList and hence we do not have to worry about reversing the list. The head of the LinkedList represent the least-significant digit of the numbers.

// Just like we add two numbers in Mathematics on a piece of paper, we begin summing the least-significant digits. As per the given constraint, each digit in the node is in the range 0..9 so the sum may overflow.

// For e.g., 4 + 9 = 13. In this case, we set the current node digit to 3 and carry 1 to the next iteration. The maximum sum can be 9 + 9 = 18. So carry will be either 1 or 0.
