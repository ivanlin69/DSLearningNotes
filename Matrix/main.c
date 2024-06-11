
#include <stdio.h>
#include <stdlib.h>

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


int main(int argc, const char * argv[]) {
    
    struct DiagonalMatrix m;
    // calloc initialize the elements to 0
    m.A = (int *) calloc(10, sizeof(int));
    m.size = 10;
    
    Set(&m, 1, 1, 20);
    Display(&m);
    
    free(m.A);
    
    return 0;
    
}
