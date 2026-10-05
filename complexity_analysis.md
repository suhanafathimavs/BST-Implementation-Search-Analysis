# Complexity Analysis

## 1. BST Search

- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(n)
- Space Complexity: O(n)

## 2. Linear Search

- Best Case: O(1)
- Average Case: O(n)
- Worst Case: O(n)
- Space Complexity: O(1)

## 3. BST Insertion

- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(n)

## 4. Effect of Key Length

The program uses strcmp() to compare identification numbers.

For longer strings, more character comparisons may be required before a difference or equality is established.

Therefore, the actual cost of searching can depend on:
- Tree height
- Key length
- Common prefixes between keys

## 5. Effect of Insertion Order

For the given insertion order, the BST has a height of 5.

When the same identification numbers are inserted in sorted order, the tree becomes completely skewed and has a height of 7.

Thus, insertion order has a significant effect on BST search performance.

## 6. Theoretical Comparison

A balanced BST can provide O(log n) search performance.

A highly skewed BST can have O(n) search performance.

Linear search has O(n) average and worst-case time complexity.

Therefore, a balanced BST is more efficient than linear search for large datasets when the tree remains balanced.
