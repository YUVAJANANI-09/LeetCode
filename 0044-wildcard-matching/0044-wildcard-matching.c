bool isMatch(char* s, char* p) {
   if(!*s && !*p)return true;
   if(!*s && *p){
    while(*p){
        if(*p != '*')return false;
        p++;
    }
    return true;
   }
   if(!*p)return false;

    while(*p && *s && (*p == *s || *p == '?')){
        p++;
        s++;
    }

    if(!*s && !*p)return true;
    if(!*s && *p){
        while(*p){
            if(*p != '*')return false;
            p++;
        }
        return true;
    }
   if(!*p || (*p != *s && *p != '*'))return false;

   int counter = 0;
   int qst_counter = 0;

    while(*p && *s){
        if(*p == *s){
            p++;
            s++;
            counter++;
            if(!*p && *s && counter == 1){
                p--;
                counter--;
            }
        }else if(*p == '*'){
            //Anything goes
            p++;
            if(!*p){
                return true;
            }            
            qst_counter = 0;
            counter = 0;
        }else if(*p == '?'){
            //only one character is removed
            p++;
            s++;
            qst_counter++;
            counter++;
            if(!*p && *s && counter == qst_counter){
                return true;
            }
        }else{
            p -= counter;
            s -= counter - 1;
            qst_counter = 0;
            counter = 0;
        }
        if(!*p && *s && counter > 0){
            p -= counter;
            s -= counter - 1;
            qst_counter = 0;
            counter = 0;
        }
    }

    if(!*s && !*p && counter)return true;
    if(!*s && *p){
        while(*p){
            if(*p != '*')return false;
            p++;
        }
        return true;
    }
    return false;
}