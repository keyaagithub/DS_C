#include <stdio.h>

int main() {
    int A[10][10],B[100][3],C[10][10];
    int r,c,i,j,k,s;
    
    printf("Enter the no.of rows and columns of sparse matrix: ");
    scanf("%d%d",&r,&c);
    printf("Enter the elements of sparse matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&A[i][j]);
        }
    }
    
    k=1,s=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(A[i][j] != 0){
                B[k][0]=i;
                B[k][1]=j;
                B[k][2]=A[i][j];
                k++;
                s++;
            }
        }
    }
    B[0][0]=r;
    B[0][1]=c;
    B[0][2]=s;
    
    printf("Compact form of sparse matrix:\n");
    for(i=0;i<s+1;i++){
        for(j=0;j<3;j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    int x,y,z;
    x=B[0][0];
    y=B[0][1];
    z=B[0][2];
    
    C[0][0]=y;
    C[0][1]=x;
    C[0][2]=z;
    k=1;
    
    if(z>0){
        for(j=0;j<y;j++){
            for(i=1;i<z+1;i++){
             if(B[i][1] == j){
                C[k][0]=B[i][1];
                C[k][1]=B[i][0];
                C[k][2]=B[i][2];
                k++;
             }
            }
        }
    }

    printf("Transpose of compact form of sparse matrix:\n");
    for(i=0;i<z+1;i++){
        for(j=0;j<3;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
