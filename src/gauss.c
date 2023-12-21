#include "gauss.h"
#include <stdio.h>

/*
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    
    for(int i=0; i<mat->c-1; i++){
        
        //1) wybor elementu glownego
        double akt_max = mat->data[i][i];
        int akt_max_nr_rzedu = i;
        for(int j=i+1; j<mat->r; j++){
            if(mat->data[j][i]>akt_max){
                akt_max = mat->data[j][i];
                akt_max_nr_rzedu = j;
            }
        }
        if(akt_max_nr_rzedu!=i){
            double pom;
            for(int j=0; j<mat->c-1; j++){
                pom = mat->data[i][j];
                mat->data[i][j] = mat->data[akt_max_nr_rzedu][j];
                mat->data[akt_max_nr_rzedu][j] = pom;
            }
        }
        
        //2) schodkowanie
        for(int j=i+1; j<mat->r; j++){
            if(mat->data[j][i]==0){
                return 1;
            }
            
            double mnoznik = mat->data[i][i]/mat->data[j][i];
            for(int jj=0; jj<mat->c-1; jj++){
                mat->data[j][jj]-=(mat->data[j][jj]*mnoznik);
            }
        }
        
        /*
        for(int ii=0; ii<mat->r; ii++){
            for(int iii=0; iii<mat->c; iii++){
                printf("%g ", mat->data[ii][iii]);
            }
            printf("\n");
        }
	*/
        

    }
    return 0;
}

