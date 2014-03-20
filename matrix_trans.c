//Transpose of Matrix
//Mirror image of matrix
#include<stdio.h>


void transpose( int matrix[5][3], int row, int col){

    int i, j;
    for ( j = 0; j < col; j++ )
    {
	for (i =0; i < row; i++ )
	{
	
	    printf("%d ", matrix[i][j]);
	}
	printf("\n");
#if 0
	for(i = 0; i<col; i++){
	    for (j = 0; j<row; j++){
		printf("%d ", temp[i][j]);
	    }
	    printf("\n");
	}
#endif
    }

}
//Mirror image along Y
void mirror(int mat[5][3], int row, int col){
    int i, j;
    for (i = 0; i<row; i++){
	for (j = col-1; j >= 0; j--){
	    printf("%d ",mat[i][j]);
	}
	printf("\n");
    }
}


void main(){
    int mat[5][3];
    int i, j, k=0;
    printf("\n Matrix is :\n");
    for(i = 0; i<5; i++){
	for (j = 0; j<3; j++){
	    mat[i][j] = k;
	    k++;
	    printf("%d ", mat[i][j]);
	}
	printf("\n");
    }
    printf("\n Transpose of Mat\n");
#if 0
    for(i = 0; i<5; i++){
	for (j = 0; j<3; j++){
	    printf("%d ", mat[j][i]);
	}
	printf("\n");
    }
#endif    
    transpose(mat, 5, 3);
    printf("\n Mirror image of Matrix \n");
    mirror(mat, 5, 3);
    return;
}

