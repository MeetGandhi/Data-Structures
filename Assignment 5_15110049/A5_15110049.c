
\\Run in programming language C99 Strict (Gcc 4.9.2)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(char a[], int n, int length) {
    int i;
    for(i=0; i<length; i++) {
        if(a[i] == n)
            return i;
    }
    return 0;
}
void removelinefeed(char *l)
{
    int newl = strlen(l)-1;
    if (l[newl] == '\n')
        l[newl] = '\0';
}


void PostOrder(char in[], char pre[], int n) {
    int x = pre[0];
    int i = search(in, x, n);
    if(i > 0) {
        PostOrder(in, pre+1,i);
    }
    if(i >=0 && i!=n-1) {
        PostOrder(in+i+1,pre+i+1,n-i-1);
    }
    printf("%c",x);
}

int main() {
int n,i,j,h;
char c[20][100];
scanf("%d\n",&n);
//printf("\n The number of expressions , n = %d",n ) ;
//printf("Postorder traversal \n");
for(i=0;i<n;i++){
    int m=0;
    fgets(c[m],sizeof(c[m]),stdin);  
    removelinefeed(c[m]);
    //printf("\nc[%d]=%s",m,c[m]);
    fgets(c[m+1],sizeof(c[m+1]),stdin);
    removelinefeed(c[m+1]);
    //printf("\nc[%d]=%s",m+1,c[m+1]);
    char pre[strlen(c[0])];
    char in[strlen(c[1])];
    for(j=0;j<strlen(c[0]);j++){
        pre[j]=c[0][j];
    }
    for(h=0;h<strlen(c[1]);h++){
        in[h]=c[1][h];
    }
    //printf("%c",c[0][0]);
    int n = strlen(in)/sizeof(in[0]);
    PostOrder(in,pre,n);
    printf("\n");
}
}