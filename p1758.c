int minOperations(char* s) {
    int i;
    int count=0;
    char prevChar= s[0];
    char nextChar= s[0]=='0'? '1':'0';
    for(i=0;i<strlen(s);i++){
        if(i%2==0){
            if(s[i]!=prevChar){
                //s[i]=prevChar;
                count++;
            }
        }else{
            if(s[i]!=nextChar){
                //s[i]=nextChar;
                count++;
            }
        }
    }
    int count2=0;
    for(i=0;i<strlen(s);i++){
        if(i%2==0){
            if(s[i]!=nextChar){
                //s[i]=nextChar;
                count2++;
            }
        }else{
            if(s[i]!=prevChar){
                //s[i]=prevChar;
                count2++;
            }
        }
    }
    int rv=count2<count?count2:count;
    return rv;
}
