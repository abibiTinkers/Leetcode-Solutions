
int numSpecial(int** mat, int matSize, int* matColSize) {
    int count = 0;
    int flag=0;//found a 1 or not found 1
    for(int i = 0; i < matSize; i++){
        for(int j = 0; j < matColSize[i]; j++){
            if(mat[i][j]==1){
                flag=1;
                //check row
                for(int k=0;k<matColSize[i] ;k++){
                    if(k!=j && mat[i][k]==1){
                        flag=0;
                        break;
                    }
                }
                 for(int k = 0; k < matSize && flag; k++){
                    if(k != i && mat[k][j] == 1){
                        flag = 0;
                        break;
                    }
                }
                if(flag==1){
                    count++;
                }

            }
        }
    }
    return count;
}
