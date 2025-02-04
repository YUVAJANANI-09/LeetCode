int myAtoi(char* s) {
     int i, sign, rangeFlag = false;
    long int n;
    for (i = 0; isspace(s[i]); i++) 
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        i++;
    for (n = 0; isdigit(s[i]); i++) {
    	n = 10 * n + (s[i] - '0');
    	if( (sign * n) < INT_MIN ) 
    		return INT_MIN;
    	if( (sign * n) > INT_MAX ) 
    		return INT_MAX;
    }
    return sign * n;
}