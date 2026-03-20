bool checkOnesSegment(char* s) {
    //int length=strlen(s);
    char previous='0';
    int count=0;

    for(int i=0;s[i]!='\0';i++){
        if(previous=='0' && s[i]=='1'){
            count++;
        }
        previous=s[i];
    }
    bool rv= count<=1? true:false;
    return rv;
}
