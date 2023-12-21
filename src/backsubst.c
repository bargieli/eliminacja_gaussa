#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
        if(mat->r != mat->c || mat->r != b->r || mat->c != x->r || b->c != 1 || x->c != 1) {
                return 2;
        }

        int n = mat->r;

        for(int i = n-1; i >= 0; i--) {
                double sum = 0.0;

                for (int j = i + 1; j < n; j++) {
                        sum += mat->data[i][j] * x->data[j][0];
                }

                if ( mat->data[i][i] == 0 ) {
                        return 1;
        }

                x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];

                }
                                /**
                                 * Tutaj należy umieścić właściwą implemntację.
                                 */

                                /* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
        
        for (int i =0; i < x->r; i++) {
                x->data[i][0] = b->data[i][0];
        }       

        return 0;
} 

