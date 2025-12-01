#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
 char password[100];
 int length, digit = 0, upper = 0, lower = 0, special = 0, score = 0;
 printf("Enter your password: ");
 scanf("%s", password);
 length = strlen(password);
 for (int i = 0; i < length; i++) {
     if (isdigit(password[i]))
 digit = 1;
 else if (isupper(password[i]))
 upper = 1;
 else if (islower(password[i]))
 lower = 1;
 else
 special = 1;
 }
 if (length >= 8) score++;
 if (digit) score++;
 if (upper && lower) score++;
 if (special) score++;
 printf("\nPassword Analysis:\n");
 printf("------------------\n");
 printf("Length: %d\n", length);
 printf("Digits: %s\n", digit ? "Yes" : "No");
 printf("Uppercase & Lowercase: %s\n", (upper && lower) ? "Yes" : "No");
 printf("Special characters: %s\n", special ? "Yes" : "No");
 printf("\nStrength: ");
 if (score == 4)
 printf("Strong\n");
 else if (score == 3)
 printf("Medium\n");
 else
     printf("Weak\n");
 return 0;
}
