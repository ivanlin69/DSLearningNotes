
#include <stdio.h>
#include <stdlib.h>
/**
struct DiagonalMatrix{
    int *A;
    size_t size;
};

void Set(struct DiagonalMatrix *m, size_t x, size_t y, int value){
    if(x==y && x < m->size){
        m->A[x] = value;
    }
}

int Get(const struct DiagonalMatrix *m, size_t x, size_t y){
    if(x < m->size && y < m->size){
        if(x==y){
            return m->A[x];
        }
    }
    return 0;
}

void Display(const struct DiagonalMatrix *m){
    for(size_t i=0; i<m->size; i++){
        for(size_t j=0; j<m->size; j++){
            if(i==j){
                printf("%d ", m->A[i]);
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    printf("\n");
}

 
struct LowerTriangularMatrix{
    int *A;
    size_t size;
};

// row based
size_t GetIndex(size_t x, size_t y){
    return x*(x+1)/2 + y;
}

void Set(struct LowerTriangularMatrix *m, size_t x, size_t y, int value){
    if(x < m->size && y < m->size && x >= y){
        m->A[GetIndex(x, y)] = value;
    }
}

int Get(const struct LowerTriangularMatrix *m, size_t x, size_t y){
    if(x < m->size && y < m->size){
        return m->A[GetIndex(x, y)];
    }
    return 0;
}

void Display(const struct LowerTriangularMatrix *m){
    for(size_t i=0; i<m->size; i++){
        for(size_t j=0; j<m->size; j++){
            if(i>=j){
                printf("%d ", m->A[GetIndex(i, j)]);
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    printf("\n");
}


 */


 struct TriDiagonalMatrix{
     int *A;
     size_t size;
 };

 // starts from lower line
 size_t GetIndex(size_t size, size_t x, size_t y){
     int value = (int)x - (int)y;
     switch (value){
         case 1:
             return y;
         case 0:
             return size-1 + y;
         default:
             return 2*size -1 + y-1;
    }
 }

 void Set(struct TriDiagonalMatrix *m, size_t x, size_t y, int value){
     if(abs( (int)x - (int)y) <= 1){
         m->A[GetIndex(m->size, x, y)] = value;
     }
 }

 int Get(const struct TriDiagonalMatrix *m, size_t x, size_t y){
     if(abs( (int)x - (int)y) <= 1){
         return m->A[GetIndex(m->size, x, y)];
     }
     return 0;
 }

 void Display(const struct TriDiagonalMatrix *m){
     for(size_t i=0; i<m->size; i++){
         for(size_t j=0; j<m->size; j++){
             if(abs( (int)i - (int)j) <= 1){
                 printf("%d ", m->A[GetIndex(m->size, i, j)]);
             } else{
                 printf("%d ", 0);
             }
         }
         printf("\n");
     }
     printf("\n");
 }

int main(int argc, const char * argv[]) {
    
    struct TriDiagonalMatrix m;
    // calloc initialize the elements to 0
    m.size = 4;
    m.A = (int *) calloc(m.size*(m.size+1)/2, sizeof(int));
    
    
    Set(&m, 1, 1, 20);
    Set(&m, 2, 1, 20);
    Set(&m, 3, 3, 20);
    Set(&m, 2, 2, 20);
    Set(&m, 0, 0, 20);
    Set(&m, 3, 2, 20);
    Display(&m);
    
    printf("%d ", Get(&m, 3, 1));
    
    free(m.A);
    
    return 0;
    
}
