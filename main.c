#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "conversions.h"
#include "utils.h"


void print_screen();
void convert(char user_choice);


void print_screen() {
    printf("What conversion type do you want to do?\n");
    printf("Type 1 for Celsius -> Fahrenheit conversion\n");
    printf("Type 2 for Celsius -> Kelvin conversion\n");
    printf("Type 3 for Fahrenheit -> Celsius conversion\n");
    printf("Type 4 for Fahrenheit -> Kelvin conversion\n");
    printf("Type 5 for Kelvin -> Celsius conversion\n");
    printf("Type 6 for Kelvin -> Fahrenheit conversion\n");
    printf("Type anything else to exit program\n");
}


void convert(char user_choice) {
    while (1) {
        printf("Enter a number to convert, or Q to quit: ");
        char buffer[32];
        fgets(buffer, 32, stdin);
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] != '\n') {
            flush();
        }

        printf("\n");
        if (tolower(buffer[0]) == 'q') exit(0);
        if (-1 == check_float(buffer)) {
            printf("invalid number, please try again.\n");
            continue;
        }

        float temp = strtof(buffer, NULL);
        float result = 0;
        switch (user_choice) {
            case '1':
                result = celsius_to_fahrenheit(temp);
                break;
            case '2':
                result = celsius_to_kelvin(temp);
                break;
            case '3':
                result = fahrenheit_to_celsius(temp);
                break;
            case '4':
                result = fahrenheit_to_kelvin(temp);
                break;
            case '5':
                result = kelvin_to_celsius(temp);
                break;
            case '6':
                result = kelvin_to_fahrenheit(temp);
                break;
            default:
                printf("Unexpected error: tried to process invalid user choice");
                exit(-1);
                break;
        }

        printf("Converted temperature: %.4f\n", result);
        printf("---------------------------------\n");
        break;
    }
}

int main() {

    while (1) {
        print_screen();

        char input[3];
        fgets(input, 3, stdin);

        char user_choice = check_input(input);
        if (user_choice == '0') { 
            break; 
        }

        size_t len = strlen(input);
        if (len > 0 && input[len-1] != '\n') {
            flush(); 
        }

        convert(user_choice);
    }
    
    return 0;
}
