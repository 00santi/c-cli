#include "utils.h"
#include <stdio.h>
#include <ctype.h>


char check_input(char *input) {
    if (!isdigit(input[0])) { return '0'; }
    if (isalnum(input[1])) { return '0'; }

    char user_choice = input[0];
    if (user_choice == '1' || user_choice == '2' || user_choice == '3' || 
        user_choice == '4' || user_choice == '5' || user_choice == '6') {
        return user_choice;
    }

    return '0';
    
}

void flush() {
    int c;
    while ((c = getchar()) != EOF && c != '\n');
}


int check_float(char *buffer) {
    size_t i = 0;
    if (buffer[i] == '-' || buffer[i] == '+') 
        i += 1;
    
    int dot_count = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0') {
        if (buffer[i] == '.') {
            dot_count += 1;
            if (dot_count > 1) 
                return -1;
        }
        if (!isdigit(buffer[i])) { return -1; }
        i += 1;
        if (i > sizeof(buffer) - 1) { return -1; }
    }
    return 1;
}
