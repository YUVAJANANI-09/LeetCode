bool canConstruct(char* ransomNote, char* magazine) {
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        char *ptr = strchr(magazine, ransomNote[i]);
        if (ptr == NULL) {
            return false; 
        }
        *ptr = '*';
    }
    return true;
}