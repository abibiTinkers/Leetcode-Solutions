
int minFlips(char* s) {

    int length = strlen(s);
    int shift = 1;
    int minimum = INT_MAX;

    char* newString = (char*)malloc((2*length+1)*sizeof(char));

    for(int i=0;i<length;i++){
        newString[i]=s[i];
        newString[i+length]=s[i];
    }

    int start=0;
    int end=length;

    int count=0;

    // compute mismatch for first window
    for(int i=start;i<end;i++){
        if((i&1)==0){
            if(newString[i]!='0') count++;
        }
        else{
            if(newString[i]!='1') count++;
        }
    }

    minimum = count < minimum ? count : minimum;
    minimum = minimum < length-count ? minimum : length-count;

    do{

        // remove start element effect
        if((start&1)==0){
            if(newString[start]!='0') count--;
        }
        else{
            if(newString[start]!='1') count--;
        }

        // add new end element
        if((end&1)==0){
            if(newString[end]!='0') count++;
        }
        else{
            if(newString[end]!='1') count++;
        }

        start++;
        end++;

        minimum = count < minimum ? count : minimum;
        minimum = minimum < length-count ? minimum : length-count;

        shift++;

    }while(shift<=length);

    return minimum;
}
