void reverseString(char* s, int sSize) {
  int l=0;
  int r=sSize-1;
  char t;
  while(l<r)
  {
    t=s[l];
    s[l]=s[r];
    s[r]=t;
    l++;
    r--;
  }  
}