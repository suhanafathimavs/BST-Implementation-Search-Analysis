# BST Insertion Trace Table

The BST is constructed using the given insertion order.

| Step | Key Inserted | Comparison / Path | Position |
|---|---|---|---|
| 1 | A102 | Tree is empty | Root |
| 2 | A25 | A25 < A102 | Left of A102 |
| 3 | A7 | A7 < A102 → A7 < A25 | Left of A25 |
| 4 | B100 | B100 > A102 | Right of A102 |
| 5 | B12 | B12 > A102 → B12 > B100 | Right of B100 |
| 6 | A120 | A120 > A102 → A120 < B100 | Left of B100 |
| 7 | B3 | B3 > A102 → B3 > B100 → B3 < B12 | Left of B12 |
| 8 | A45 | A45 < A102 → A45 > A25 → A45 < A7 | Left of A7 |

## Final Inorder Traversal

A102 A120 A25 A45 A7 B100 B12 B3

## Tree Height

Original insertion-order BST height = 5.

Sorted insertion BST height = 7.
