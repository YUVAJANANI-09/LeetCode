int strStr(char* haystack, char* needle) {
  int m=-1,c=0;
  for(int i=0;haystack[i];i++)
  {
    if(needle[c]==haystack[i])
    {
        if(m==-1) m=i;
        c++;
        if(!needle[c]) return m;
    }
    else
    {
        if(m!=-1)i=m;
        m=-1;
        c=0;
    }
  }  
  return -1;
}