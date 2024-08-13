bool isSubsequence(char * s, char * t){
    int length = strlen(s);
    if (length == 0)    return true;
    int c = 0;

    for (int i = 0; i < strlen(t); i++){
        if (t[i] == s[c])   c++;
    }

    if (c == length)    return true;
    return false;
}