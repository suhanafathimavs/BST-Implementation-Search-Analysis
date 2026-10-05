# BST Implementation & Search Analysis

Binary Search Tree implementation and performance analysis using C.

## Objective

To implement a Binary Search Tree (BST) using government identification numbers, perform inorder traversal, compare BST search with linear search, and analyse the effect of key length and insertion order on BST height and search performance.

## Input Data

The identification numbers used are:

`A102, A25, A7, B100, B12, A120, B3, A45`

## Parts Covered

### Part (a) – BST Implementation

The identification numbers are inserted into a Binary Search Tree using lexicographic ordering with `strcmp()`.

Inorder traversal:

`A102 A120 A25 A45 A7 B100 B12 B3`

Number of nodes: **8**

Height of the original BST: **5**

Theoretical best-case height: **3**

Theoretical worst-case height: **7**

### Part (b) – BST Search vs Linear Search

The program compares the number of comparisons required by BST search and linear search for selected identification numbers.

| Query | Original BST | Linear Search |
|---|---:|---:|
| A45 | 4 | 8 |
| B100 | 4 | 4 |
| A7 | 3 | 3 |
| B999 | 6 | 8 |

### Part (c) – Effect of Insertion Order and Key Length

The same identification numbers are inserted in sorted order to demonstrate the effect of insertion order.

Height of original BST: **5**

Height of sorted-insertion BST: **7**

The sorted insertion produces a completely skewed tree, resulting in worst-case BST height.

Key length can also affect the actual cost of `strcmp()`, since longer keys or keys with common prefixes may require more character comparisons.

## Files

- `bst_analysis.c` – C source code
- `input.txt` – Input identification numbers
- `output.txt` – Program output
- `trace_table.md` – Important intermediate steps
- `comparison_table.md` – BST and linear search comparison
- `complexity_analysis.md` – Time and space complexity analysis
- `conclusion.md` – Final conclusion and recommended approach

## Complexity

- BST Search: O(log n) average/best case for a balanced tree
- BST Search: O(n) worst case
- Linear Search: O(n)
- BST insertion: O(log n) average/best case and O(n) worst case
- Inorder traversal: O(n)
- Space complexity: O(n)

## Conclusion

The experiment shows that BST search can reduce the number of comparisons compared with linear search when the tree is reasonably balanced. However, the insertion order has a major effect on the height of a normal BST. For the given data, the original tree has height 5, while sorted insertion produces a height of 7, which is the worst possible height for 8 nodes.

For a growing database where efficient searching is required, self-balancing trees such as AVL trees or Red-Black trees are suitable because they maintain logarithmic height. B-trees are also suitable for database and external-storage applications.
