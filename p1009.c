char* convertToBinary(int n,char* rep,int p){
    
    for(int i=0;i<p-1;i++){
        rep[i]=(n%2)+'0';
        n/=2;
    }
    rep[p-1]='\0';
    printf("%s",rep);
    return rep;
}
int convertBack(char* str){
    int val=0;
    int length=strlen(str);
    for(int i=0;i<length;i++){
        val+=(str[i]-'0')*pow(2,i);
    }
    return val;
}
char* flip(char* ans,int length){
    for(int i=0;i<length-1;i++){
        if(ans[i]=='0'){
            ans[i]+=1;
        }
        else{
            ans[i]-=1;
        }
    }
    return ans;
}
int bitwiseComplement(int n) {
    int p=0;
    do{
        p++;
    }while(n>pow(2,p));
    char* rep=(char*)malloc((p+1)*sizeof(char));
    int ans=convertBack(flip(convertToBinary(n,rep,p+1),p+1));
    return ans;
}
