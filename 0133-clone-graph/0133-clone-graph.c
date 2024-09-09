/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */


typedef struct Node N;

#define m_size 101

N* m[m_size];

N* createNode(N* s) {
    if (!s) return NULL;

    int v = s->val;
    int n = s->numNeighbors;
    if (m[v] == NULL) {
        m[v] = malloc(sizeof(N));
        m[v]->val = v;
        m[v]->neighbors = calloc(n, sizeof(N*));
        m[v]->numNeighbors = n;
        for (int i = 0; i < n; i++) {
            int neighbor_v = s->neighbors[i]->val;
            if (m[neighbor_v] == NULL) {
                m[neighbor_v] = createNode(s->neighbors[i]);
            }
            m[v]->neighbors[i] = m[neighbor_v];
        }
    }
    return m[v];
}

N* cloneGraph(N *s) {
    for (int i = 0; i < m_size; i++) m[i] = NULL;
    return createNode(s);
}