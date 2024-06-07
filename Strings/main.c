#include <stdio.h>

size_t Length(const char* str){
    size_t i = 0;
    for(; str[i]!='\0'; i++);
    return i;
}

void Capitalized(char* str){
    for(size_t i=0; str[i]!='\0'; i++){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] -= 32;
        }
    }
}

void Uncaptalized(char* str){
   for(size_t i=0; str[i]!='\0'; i++){
       if(str[i] >= 97 && str[i] <= 122){
           str[i] += 32;
       }
   }
}

void Toggle(char* str){
   for(size_t i=0; str[i]!='\0'; i++){
       if(str[i] >= 65 && str[i] <= 90){
           str[i] += 32;
       } else if(str[i] >= 97 && str[i] <= 122){
           str[i] -= 32;
       }
   }
}

size_t CountWords(const char* str){
    size_t count=0;
    size_t word=0;
    for(size_t i=0; str[i]!='\0'; i++){
        if((str[i] >= 65 && str[i] <= 90) ||
           (str[i] >= 97 && str[i] <= 122)){
            if(word==0){
                count++;
                word=1;
            }
        } else{
            word=0;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    char a[100] = {'j', 'o', 'h', 'n', '\0'};
    char b[] = {'j', 'o', 'h', 'n', '\0'};
    char c[] = "john";
    
    printf("%s %s %s \n", a, b, c);
    /**
     scanf("%s", a);
     printf("%s \n", a);
     
     // Consume the newline character left by scanf
     char d = getchar();
     while (d != '\n' && d != EOF);
     
     fgets(a, sizeof(a), stdin);
     printf("%s \n", a);
     */
    
    char str[100] = "John   is   rich  .  ";
    printf("%s\n", str);
    
    
    
    return 0;
}
