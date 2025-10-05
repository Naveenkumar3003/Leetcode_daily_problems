class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def buildTreeLevelOrder(arr):
    n = len(arr)
    if n == 0 or arr[0] == -1:
        return None
    root = Node(arr[0])
    queue = [root]
    i = 1
    while queue and i < n:
        current = queue.pop(0)
        if i < n and arr[i] != -1:
            current.left = Node(arr[i])
            queue.append(current.left)
        i += 1
        if i < n and arr[i] != -1:
            current.right = Node(arr[i])
            queue.append(current.right)
        i += 1
    return root

def longestPathSum(root):
    if root is None:
        return (0, 0)
    left_sum, left_len = longestPathSum(root.left)
    right_sum, right_len = longestPathSum(root.right)
    if left_len > right_len:
        return (left_sum + root.value, left_len + 1)
    elif right_len > left_len:
        return (right_sum + root.value, right_len + 1)
    else:
        return (max(left_sum, right_sum) + root.value, left_len + 1)

n = int(input())
arr = list(map(int, input().split()))
root = buildTreeLevelOrder(arr)
total_sum, path_len = longestPathSum(root)
print(total_sum)

