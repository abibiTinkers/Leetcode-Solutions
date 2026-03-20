bool isPalindrome(int x) {
    int temp=x;
    long rev=0;
    while(x>0 && x!=0){
        rev*=10;
        rev+=x%10;
        x/=10;

    }
    if(rev==temp){ return true;}
    
    if(x<0){
        return false;
    }
    return false;
}
