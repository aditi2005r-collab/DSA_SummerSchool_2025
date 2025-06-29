#include <stdio.h>
int octalToDecimal(int octal) {
    if (octal == 0) {
        return 0;
    }
    return (octal % 10) + 8 * octalToDecimal(octal / 10);
}
int main() {
    int octalNumber;
    printf("octal number: ");
    scanf("%o", &octalNumber);  
    int decimalNumber = octalToDecimal(octalNumber);  
    printf("Decimal : %d\n", decimalNumber);
    return 0;
}
