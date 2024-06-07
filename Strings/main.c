#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char a[100] = {'j', 'o', 'h', 'n', '\0'};
    char b[] = {'j', 'o', 'h', 'n', '\0'};
    char c[] = "john";
    
    printf("%s %s %s \n", a, b, c);
    scanf("%s", a);
    printf("%s \n", a);
    
    // Consume the newline character left by scanf
    char d = getchar();
    while (d != '\n' && d != EOF);
    
    fgets(a, sizeof(a), stdin);
    printf("%s \n", a);
    return 0;
}
