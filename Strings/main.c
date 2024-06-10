#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t Length(const char* str){
    size_t i = 0;
    for(; str[i]!='\0'; i++);
    return i;
}

void Uncapitalized(char* str){
    for(size_t i=0; str[i]!='\0'; i++){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] += 32;
        }
    }
}

void Capitalized(char* str){
   for(size_t i=0; str[i]!='\0'; i++){
       if(str[i] >= 97 && str[i] <= 122){
           str[i] -= 32;
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

void Reverse(char* str){
    size_t l = Length(str);
    // Note '\0' might show up during the XOR process. Avoid directly using Length(str)
    for(size_t i=0; i<l/2; i++){
        str[i] = str[i] ^ str[l-1-i];
        str[l-1-i] = str[i] ^ str[l-1-i];
        str[i] = str[i] ^ str[l-1-i];
    }
}

int Palindrome(const char* str){
    size_t l = Length(str);
    for(size_t i=0; i<l/2; i++){
        if(str[i] != str[l-1-i]){
            return 0;
        }
    }
    return 1;
}

size_t Compare(const char* str1, const char* str2){
    size_t i=0, j=0;
    size_t index=0;
    
    while(i<Length(str1) && j<Length(str2)){
        if(str1[i++] != str2[j++]){
            return index;
        }
        index++;
    }
    return Length(str1);
}

void FindDuplicate(const char* str){
    char* copy = (char *) malloc(sizeof(char) * (Length(str)+1));
    
    size_t i=0;
    for(; i<Length(str); i++){
        copy[i] = str[i];
    }
    copy[i] = '\0';
    
    for(i=0; i<Length(copy); i++){
        size_t count = 0;
        for(size_t j=i+1; j<Length(copy); j++){
            if(copy[j] != -1 && copy[j] == copy[i]){
                count++;
                copy[j] = -1;
            }
        }
        if(count != 0){
            printf("%c: %zu duplicates.\n", copy[i], count);
        }
    }
    free(copy);
}

void FindDuplicateHashing(const char* str){
    size_t max= str[0];
    for(size_t i=0; str[i]!='\0'; i++){
        if(str[i] > max){
            max = str[i];
        }
    }
    size_t hashing[(max-65)+1];
    for(size_t i=0; i<(max-65)+1; i++){
        hashing[i] = 0;
    }
    for(size_t i=0; str[i]!='\0'; i++){
        hashing[str[i]-65]++;
    }
    for(size_t i=0; i<(max-65)+1; i++){
        if(hashing[i] > 1){
            printf("%c: %zu duplicates.\n", (char) i+65, hashing[i]-1);
        }
    }
}

// like hashing but uses bits to store info. Can't store counts(only 0/1)!
void FindDuplicateBitsOperation(const char* str){
    long long hashing=0;
    for(size_t i=0; str[i]!='\0'; i++){
        // mask
        long long m=1;
        if(str[i] >= 65 && str[i] <= 90){
            // 1 to 26 bit is for A-Z
            m = m << (str[i]-65);
        } else if(str[i] >= 97 && str[i] <= 122){
            // 27 to 52 bit is for a-z
            m = m << (str[i]-97+26);
        }
        
        if((hashing & m) > 0){
            printf("%c is duplicated.\n", str[i]);
        } else{
            // set ON
            hashing = hashing | m;
        }
    }
}

int Anagram(const char* str1, const char* str2){
    
    if(Length(str1) != Length(str2)){
        return 0;
    }
    
    size_t max1 = str1[0];
    size_t max2 = str2[0];
    for(size_t i=1; str1[i]!='\0'; i++){
        if(str1[i] > max1){
            max1 = str1[i];
        }
    }
    for(size_t j=1; str2[j]!='\0'; j++){
        if(str2[j] > max2){
            max2 = str2[j];
        }
    }
    if(max1 != max2){
        return 0;
    }
    
    size_t hashing1[max1+1];
    size_t hashing2[max1+1];
    for(size_t i=0; i<max1+1; i++){
        hashing1[i] = 0;
        hashing2[i] = 0;
    }
    // or using memcpy(hashing2, hashing1, sizeof(size_t)*(max1+1)); to initialize the second array
    
    for(size_t i=0; str1[i]!='\0'; i++){
        hashing1[str1[i]]++;
        hashing2[str2[i]]++;
    }
    for(size_t i=0; i < max1+1; i++){
        if(hashing1[i] != hashing2[i]){
            return 0;
        }
    }
    return 1;
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
     
    
    char str[100] = "John   is   rich  . gf";
    //Capitalized(str);
    //Uncapitalized(str);
    //Toggle(str);
    printf("%s\n", str);
    printf("The length of the string is: %zu\n", Length(str));
    printf("The # of words is: %zu\n", CountWords(str));
    
    Reverse(str);
    printf("%s\n", str);
    
    char str2[20] = "asdffdsa";
    char str3[20] = "asdffesa";
    printf("%s\n", str2);
    printf("Is palindrome?: %d\n", Palindrome(str2));
    
    printf("Compare: %zu\n", Compare(str3, str2));
    
    char str4[20] = "asdfAAfweraesaaB";
    FindDuplicate(str4);
    FindDuplicateBitsOperation(str4);
    
    printf("Size of long long: %zu\n", sizeof(long long));
    */
    
    char str5[20] = "asdfghjkd";
    char str6[20] = "kjhgfdsad";
    
    printf("Are 2 strings anagram: %d\n", Anagram(str5, str6));
    
    return 0;
}
