#include <string.h>
#include "scan_token.h"


bool scan_token(const char **p_input, const char *delimiters,
                char buf[], size_t buflen)
{
    if(**p_input!=*"\0"){
        
    //clear the buffer
    memset(buf,0,buflen);

    //find the length of the word
    size_t len = strcspn(*p_input,delimiters);

    //if the word is too large
    if(len>=buflen){
        strncpy(buf,*p_input,buflen-1);
        *p_input=*p_input+(buflen-1);
        return true;
    }

    //copy the word into buffer
    strncpy(buf,*p_input,len);

    //check whether it's the last word of the string
    if(*(*p_input+len)==*"\0"){
        *p_input=*p_input+len;
    }else{
        *p_input=*p_input+len+1;
    }
    return true;
    }
    return false;
}
