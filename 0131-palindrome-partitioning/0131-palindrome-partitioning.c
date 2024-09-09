/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int len, col_idx;
static char ***res;
static int *cols;
bool is_palin(char *s, int left, int right)
{
    while (left < right) {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}
void backtracking(int i, char *s, int cur_idx, char **cur)
{
    if (i == len) {
        cols[col_idx] = cur_idx;
        res[col_idx] = malloc(cur_idx * sizeof(char*));
        for (int j = 0; j < cur_idx; j++) {
            res[col_idx][j] = malloc((strlen(cur[j]) + 1) * sizeof(char));
            strcpy(res[col_idx][j], cur[j]);
        }
        col_idx++;
        return;
    }
    for (int j = i; j < len; j++) {
        if (is_palin(s, i, j)) {
            strncpy(cur[cur_idx], s + i, j - i + 1);
            cur[cur_idx][j - i + 1] = '\0';
            cur_idx++;
            backtracking(j + 1, s, cur_idx, cur);
            cur_idx--;
        }
    }
    return;
}
char*** partition(char *s, int *returnSize, int **returnColumnSizes) 
{
    col_idx = 0;
    len = strlen(s);

    int size = (1 << len);
    res = malloc(size * sizeof(char**));
    cols = malloc(size * sizeof(int));

    char **cur = malloc(size * sizeof(char*));
    for (int i = 0; i < len; i++)
        cur[i] = malloc((len + 1) * sizeof(char));
    backtracking(0, s, 0, cur);
    for (int i = 0; i < len; i++)
        free(cur[i]);
    free(cur);

    *returnSize = col_idx;
    *returnColumnSizes = cols;
    return res;
}