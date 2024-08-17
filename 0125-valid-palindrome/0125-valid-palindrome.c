
int isAlphanum(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'); 
}

int convertAlphaLower(char c){
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int isPalindrome(char* s) {
    int l, r;

    r = strlen(s) - 1;

    l = 0;
    while (l < r){
        if(isAlphanum(s[l])){

            if(isAlphanum(s[r])){
                
                if (convertAlphaLower(s[l]) != convertAlphaLower(s[r])){

                    return 0;
                }

                l++;
                r--;
            }
            else 
                r--;
        }
        else 
            l++;
    }

    return (1);
}