char * convert(char * s, int numRows){
    
    int len = strlen(s),
        k = 0;
    char* res = malloc(sizeof(char) * (len + 1));

    if (numRows > 1)
    {
        for (int i = 0; i < len; i += (2 * numRows) - 2)
            res[k++] = s[i];

        for (int row = 2; row < numRows; ++row)
        {
            for (int i = row - 1; i < len; )
            {
                res[k++] = s[i];
                if ((i += ((2 * numRows) - (2 * row))) >= len) break;
                res[k++] = s[i];
                i += ((2 * numRows) - (2 * (numRows - row + 1)));
            }
        }

        for (int i = numRows - 1; i < len; i += (2 * numRows) - 2)
            res[k++] = s[i];

        res[k] = '\0';
    }
    else strcpy(res, s);

    return res;
}