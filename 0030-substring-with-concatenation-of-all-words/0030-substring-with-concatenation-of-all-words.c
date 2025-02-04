typedef struct entry{
    char* word;
    int occurred;
    int occurrence;
    struct entry* next;
    
} dic_entry;

dic_entry* add_entry(dic_entry* dic, char* word)
{
    dic_entry* new_entry = (dic_entry*)malloc(sizeof(dic_entry));
    new_entry->word = (char*)malloc(sizeof(char)*(strlen(word)+1));
    strcpy(new_entry->word, word);
    new_entry->occurred = 0;
    new_entry->occurrence = 1;
    new_entry->next = NULL;
    dic_entry* head = dic;
    
    if(dic == NULL)
    {
        head = new_entry;
    }
    else
    {
        while(dic->next)
        {
            dic = dic->next;
        }
        
        dic->next = new_entry;
    }
    return head;
}
dic_entry* find_entry(dic_entry* dic, char* word, int len)
{
    
    dic_entry* head = dic;
    while(head)
    {
        if(!strncmp(head->word, word, len))
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
void reset(dic_entry* dic)
{
    dic_entry* head = dic;
    
    while(head)
    {
        head->occurred = 0;
        head = head->next;
    }
}
void free_dic(dic_entry* dic)
{
    dic_entry* head = dic;
    dic_entry* temp;
    
    while(head)
    {
        free(head->word);
        temp = head;
        head = head->next;
        free(temp);
    }
}
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    
    int* result = (int*)malloc(sizeof(int));
    int resultCount = 0;
    dic_entry* dic = NULL;
    dic_entry* temp;
    int j;
    int string_len = (int)strlen(s);
    if (wordsSize == 0)
    {
        *returnSize = 0;
        return result;
    }
    int word_len = strlen(words[0]);
    for(int i = 0; i < wordsSize; i++)
    {
        
        temp = find_entry(dic, words[i], word_len);
        
        if(temp != NULL)
        {
            temp->occurrence++;
        }
        else
        {
            dic = add_entry(dic, words[i]);
        }
        
    }
    for(int i = 0; i <= string_len - wordsSize*word_len; i++)
    {
        for(j = 0; j < wordsSize; j++)
        {
            temp = find_entry(dic, s+j*word_len+i, word_len);
            if(temp)
            {
                temp->occurred++;
                if (temp->occurred > temp->occurrence)
                    break;
            }
            else
            {
                break;
            }
        }
        if(j == wordsSize)
        {
            result[resultCount++] = i;
            result = (int*)realloc(result, sizeof(int)*(resultCount+1));
        }
        reset(dic);
    }
    free_dic(dic);
    *returnSize = resultCount;
    return result;   
}