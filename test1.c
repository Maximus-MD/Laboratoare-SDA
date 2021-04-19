#include <stdio.h>
#define N 50
#define M 50
int main(){
    int tab[N][M];
    int n,m,i,j,s,p;
    printf("Dati nr. de rinduri si nr. de coloane:");
    scanf("%d%d",&n, &m);
    printf("-----------------------------------------\n");
    printf("Dati elementele tabloului:\n ");
    for( i=0; i<n; i++){
        for( j=0; j<m;j++ ){
            scanf("%d",&tab[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------\n");
    printf("Elementele tabloului sunt:\n");

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    s=0;
    for(i=0; i<n; i+=2){
        for(j=0; j<m; j++){
            if(tab[i][j]>0)
            s=s+tab[i][j];
      }
    }

    p=1;
    for(i=0; i<n; i++){
        for(j=1; j<m; j+=2){
            if(tab[i][j]<5)
            p=p*tab[i][j];
        }
    }
    printf("--------------------------\n");
    printf("Suma elementelor pozitive din liniile pare este = %d\n",s);
    printf("Produsul elemenetelor mai mici ca 5 din liniile impare este = %d\n",p);
    printf("----------------------------------------------------------------");

return 0;
}
