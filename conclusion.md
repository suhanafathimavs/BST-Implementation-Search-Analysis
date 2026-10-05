# Final Conclusion

The Binary Search Tree (BST) successfully stores and organizes the given identification numbers using lexicographic ordering with `strcmp()`.

For the given insertion order:

A102, A25, A7, B100, B12, A120, B3, A45

the BST contains 8 nodes and has a height of 5. Its inorder traversal is:

A102 A120 A25 A45 A7 B100 B12 B3

The theoretical best-case height for 8 nodes is 3, while the worst-case height is 7. Therefore, the original tree is neither perfectly balanced nor completely skewed.

The comparison between BST Search and Linear Search shows that BST Search can reduce the number of comparisons when the tree is reasonably balanced. For example, searching for A45 required 4 comparisons using BST Search, compared with 8 comparisons using Linear Search.

The insertion order has a major effect on BST performance. When the same identification numbers are inserted in sorted order, the BST becomes completely skewed and its height increases to 7. In this case, searching can require up to 8 comparisons, which is equivalent to Linear Search for 8 elements.

Key length also affects the actual cost of searching because the program uses `strcmp()`. Longer strings or strings with common prefixes may require more character comparisons.

Therefore, a normal BST is suitable for smaller datasets when the tree remains reasonably balanced. For a growing government database where consistently efficient searching is required, a self-balancing BST such as an AVL tree or Red-Black tree is more suitable because it maintains logarithmic height. If the database is stored in external memory, a B-tree is also a suitable approach.
