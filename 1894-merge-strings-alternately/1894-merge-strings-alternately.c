char* mergeAlternately(char* word1, char* word2) {

    int i = 0;
    int j = 0;

    char* temp =
        (char*)malloc(sizeof(char) * (strlen(word1) + strlen(word2) + 1));

    while (word1[i] != '\0' && word2[i] != '\0') {
        temp[j++] = word1[i];
        temp[j++] = word2[i];
        i++;
    }

    if (word1[i] == '\0') {
        while (word2[i] != '\0') {
            temp[j++] = word2[i++];
        }
    } else {
        while (word1[i] != '\0') {
            temp[j++] = word1[i++];
        }
    }
    temp[j] = '\0';
    return temp;
}