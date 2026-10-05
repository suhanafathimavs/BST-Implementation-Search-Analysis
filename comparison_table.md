# BST vs Linear Search Comparison

| Feature | BST Search | Linear Search |
|---|---|---|
| Data Structure | Binary Search Tree | Array |
| Best Case | O(1) | O(1) |
| Average Case | O(log n) | O(n) |
| Worst Case | O(n) | O(n) |
| Space Complexity | O(n) | O(1) |
| Depends on Order | Yes | No |
| Performance on Balanced Data | Efficient | Slower for large data |
| Performance on Skewed BST | Similar to Linear Search | O(n) |

## Comparison for Given Input

| Query | Original BST | Linear Search | Skewed BST | Linear Search |
|---|---:|---:|---:|---:|
| A45 | 4 | 8 | 4 | 8 |
| B100 | 4 | 4 | 6 | 4 |
| A7 | 3 | 3 | 5 | 3 |
| B999 | 6 | 8 | 8 | 8 |

## Observation

The original BST requires fewer comparisons for some queries than linear search.

When the BST is constructed by inserting the IDs in sorted order, it becomes skewed and its search performance can approach linear search.

Therefore, the efficiency of a BST depends strongly on the shape of the tree and the insertion order.
