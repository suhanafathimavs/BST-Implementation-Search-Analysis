#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 10

/* ---------- BST node ---------- */
typedef struct Node {
    char key[MAX_LEN];
    struct Node *left, *right;
} Node;

Node* createNode(const char *key) {
    Node *n = (Node*)malloc(sizeof(Node));
    strcpy(n->key, key);
    n->left = n->right = NULL;
    return n;
}

/* Insert into BST using strcmp (lexicographic) ordering */
Node* insert(Node *root, const char *key) {
    if (root == NULL)
        return createNode(key);

    int cmp = strcmp(key, root->key);

    if (cmp < 0)
        root->left = insert(root->left, key);
    else if (cmp > 0)
        root->right = insert(root->right, key);
    /* duplicates ignored */

    return root;
}

/* Inorder traversal -> prints keys in sorted order */
void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%s ", root->key);
    inorder(root->right);
}

/* Height of tree: empty = -1, single node = 0 */
int height(Node *root) {
    if (root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + (lh > rh ? lh : rh);
}

int countNodes(Node *root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* BST search that counts comparisons made */
Node* bstSearch(Node *root, const char *key, int *comparisons) {
    Node *cur = root;

    while (cur != NULL) {
        (*comparisons)++;

        int cmp = strcmp(key, cur->key);

        if (cmp == 0)
            return cur;

        cur = (cmp < 0) ? cur->left : cur->right;
    }

    return NULL;
}

/* Plain linear search over the original array, counting comparisons */
int linearSearch(char arr[][MAX_LEN], int n, const char *key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        if (strcmp(arr[i], key) == 0)
            return i;
    }

    return -1;
}

int cmpStr(const void *a, const void *b) {
    return strcmp((const char*)a, (const char*)b);
}

void freeTree(Node *root) {
    if (!root)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void runSearchDemo(Node *root, char arr[][MAX_LEN], int n,
                   const char *queries[], int qn) {
    for (int i = 0; i < qn; i++) {
        int bstCmp = 0, linCmp = 0;

        Node *found = bstSearch(root, queries[i], &bstCmp);
        int idx = linearSearch(arr, n, queries[i], &linCmp);

        printf(" Query \"%-6s\" -> %-9s | BST comparisons: %d | "
               "Linear comparisons: %d\n",
               queries[i],
               found ? "FOUND" : "NOT FOUND",
               bstCmp, linCmp);

        (void)idx;
    }
}

int main(void) {
    char ids[][MAX_LEN] = {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    int n = sizeof(ids) / sizeof(ids[0]);

    /* ---------------- Part (a): build BST in GIVEN insertion order ---------------- */
    Node *root = NULL;

    printf("Insertion order : ");

    for (int i = 0; i < n; i++) {
        printf("%s ", ids[i]);
        root = insert(root, ids[i]);
    }

    printf("\n\n(a) Inorder traversal of BST:\n ");
    inorder(root);

    printf("\n\n(a) Tree structure analysis:\n");

    printf(" Number of nodes : %d\n", countNodes(root));

    printf(" Height of tree : %d\n", height(root));

    printf(" Theoretical best-case height for %d nodes : "
           "floor(log2(n)) = %d\n",
           n, (int)(log(n) / log(2)));

    printf(" Theoretical worst-case height for %d nodes : "
           "n - 1 = %d\n\n", n, n - 1);

    /* ---------------- Part (b): BST search vs Linear search ---------------- */
    const char *queries[] = {"A45", "B100", "A7", "B999"};

    printf("(b) BST Search vs Linear Search comparisons:\n");

    runSearchDemo(root, ids, n, queries, 4);

    /* ---------------- Part (c): effect of insertion order on height ---------------- */
    char sortedIds[8][MAX_LEN];

    memcpy(sortedIds, ids, sizeof(ids));

    qsort(sortedIds, n, MAX_LEN, cmpStr);

    Node *skewedRoot = NULL;

    printf("\n(c) Rebuilding BST by inserting the SAME ids in SORTED order:\n ");

    for (int i = 0; i < n; i++) {
        printf("%s ", sortedIds[i]);
        skewedRoot = insert(skewedRoot, sortedIds[i]);
    }

    printf("\n Inorder traversal (should be identical set, same sorted sequence):\n ");
    inorder(skewedRoot);

    printf("\n Height of SKEWED tree (sorted insertion) : %d\n",
           height(skewedRoot));

    printf(" Height of ORIGINAL tree (given order) : %d\n",
           height(root));

    printf("\n Search comparisons on the SKEWED tree:\n");

    runSearchDemo(skewedRoot, ids, n, queries, 4);

    freeTree(root);
    freeTree(skewedRoot);

    return 0;
}
