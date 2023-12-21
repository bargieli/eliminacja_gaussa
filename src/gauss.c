#include "gauss.h"
#include <stdio.h>

//IZABELA BARGIEŁ

double bezw(double a){
    if(a>0){
        return a;
    }
    return a*(-1);
}



double zaokragl_do_zera(double a) {
    if (bezw(a) < 1e-10) {
        return 0.0;
    }
    return a;
}



int eliminate(Matrix *mat, Matrix *b){
    for(int i=0; i<mat->c; i++){
        
        //1) wybor elementu glownego
        double akt_max = bezw(mat->data[i][i]);
        int akt_max_nr_rzedu = i;
        for(int j=i+1; j<mat->r; j++){
            if(bezw(mat->data[j][i])>akt_max){
                akt_max = bezw(mat->data[j][i]);
                akt_max_nr_rzedu = j;
            }
            
        }
        if(akt_max_nr_rzedu!=i){
            double pom;
            for(int j=0; j<mat->c; j++){
                pom = mat->data[i][j];
                mat->data[i][j] = mat->data[akt_max_nr_rzedu][j];
                mat->data[akt_max_nr_rzedu][j] = pom;
            }
            pom = b->data[i][0];
            b->data[i][0] = b->data[akt_max_nr_rzedu][0];
            b->data[akt_max_nr_rzedu][0] = pom;
            
        }
        
        //2) schodkowanie
        for(int j=i+1; j<mat->r; j++){
            if(mat->data[i][i]==0){
                return 1;
            }
            
            double mnoznik = mat->data[j][i]/mat->data[i][i];
            //printf("Mnoznik: %g\n", mnoznik);
            for(int jj=0; jj<mat->c; jj++){
                mat->data[j][jj]=mat->data[j][jj]-(mnoznik*mat->data[i][jj]);
                mat->data[j][jj] = zaokragl_do_zera(mat->data[j][jj]);
            }
            b->data[j][0] = b->data[j][0]-(b->data[i][0]*mnoznik);
            b->data[j][0] = zaokragl_do_zera(b->data[j][0]);
        }
    }

    return 0;
}

