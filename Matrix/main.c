
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

struct SparseElement{
    size_t row;
    size_t col;
    int value;
};

struct SparseMatrix{
    size_t rowLength;
    size_t colLength;
    size_t size;
    size_t length;
    struct SparseElement *A;
};

void AddElement(struct SparseMatrix *m, struct SparseElement e){
    if(m->length < m->size){
        m->A[(m->length)++] = e;
    }
}

void DisplaySparse(struct SparseMatrix *m){
    size_t index = 0;
    for(size_t i=0; i<m->rowLength; i++){
        for(size_t j=0; j<m->colLength; j++){
            if(m->A[index].row == i && m->A[index].col == j){
                printf("%d ", m->A[index].value);
                index++;
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

struct SparseMatrix * Adding(struct SparseMatrix *m, struct SparseMatrix *other){
    if(m->rowLength != other->rowLength || m->colLength != other->colLength){
        return NULL;
    }
    
    size_t i=0;
    size_t j=0;
    size_t index = 0;
    
    struct SparseMatrix *sm = (struct SparseMatrix *) malloc(sizeof(struct SparseMatrix));
    sm->rowLength = m->rowLength;
    sm->colLength = m->colLength;
    sm->size = (m->size + other->size);
    sm->length = 0;
    
    sm->A = (struct SparseElement *) malloc(sizeof(struct SparseElement)*sm->size);
    
    while(i<m->length && j<other->length){
        if(m->A[i].row < other->A[j].row){
            sm->A[index++] = other->A[i++];
        } else if(m->A[i].row > other->A[j].row){
            sm->A[index++] = m->A[j++];
        } else{
            if(m->A[i].col < other->A[j].col){
                sm->A[index++] = m->A[i++];
            } else if(m->A[i].col > other->A[j].col){
                sm->A[index++] = other->A[j++];
            } else{
                sm->A[index].row = m->A[i].row;
                sm->A[index].col = m->A[i].col;
                sm->A[index++].value = m->A[i++].value + other->A[j++].value;
            }
        }
        sm->length++;
    }
    
    for(; i<m->length; i++){
        sm->A[i].row = other->A[i].row;
        sm->A[i].col = other->A[i].col;
        sm->A[i].value = other->A[i].value;
        sm->length++;
    }
    
    for(; j<other->rowLength; j++){
        sm->A[j].row = other->A[j].row;
        sm->A[j].col = other->A[j].col;
        sm->A[j].value = other->A[j].value;
        sm->length++;
    }
    
    return sm;
}

int main(int argc, const char * argv[]) {
    
    /**
    struct TriDiagonalMatrix m;
    // calloc initialize the elements to 0
    m.size = 3*4 - 2;
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
     */
    
    struct SparseMatrix m = {5, 7, 6, 0};
    m.A = (struct SparseElement *) malloc(sizeof(struct SparseElement) * m.size);
    
    struct SparseElement e1 = {1, 2, 81};
    struct SparseElement e2 = {3, 4, 4};
    struct SparseElement e3 = {2, 2, 34};
    struct SparseElement e4 = {4, 2, 6};
    struct SparseElement e5 = {2, 5, 877};
    struct SparseElement e6 = {0, 1, 22};
    
    // add elements in ascending order
    AddElement(&m, e6);
    AddElement(&m, e1);
    AddElement(&m, e3);
    AddElement(&m, e5);
    AddElement(&m, e2);
    AddElement(&m, e4);
    
    DisplaySparse(&m);
    
    struct SparseMatrix other = {5, 7, 8, 0};
    other.A = (struct SparseElement *) malloc(sizeof(struct SparseElement) * m.size);
    
    
    struct SparseElement e7 = {3, 3, 66};
    struct SparseElement e8 = {1, 0, 66};
    
    // add elements in ascending order
    AddElement(&other, e6);
    AddElement(&other, e8);
    AddElement(&other, e1);
    AddElement(&other, e3);
    AddElement(&other, e5);
    AddElement(&other, e7);
    AddElement(&other, e2);
    AddElement(&other, e4);
    
    printf("\n");

    DisplaySparse(&other);
    
    printf("\n");
    
    struct SparseMatrix *r = Adding(&m, &other);
    DisplaySparse(r);
    
    return 0;
    
}
