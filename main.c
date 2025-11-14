#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void print_screen();
void flush();
void convert(char user_choice);

char check_input(char *input);

int check_float(char *buffer);

float celsius_to_fahrenheit(float temp);
float celsius_to_kelvin(float temp);
float fahrenheit_to_celsius(float temp);
float fahrenheit_to_kelvin(float temp);
float kelvin_to_celsius(float temp);
float kelvin_to_fahrenheit(float temp);


const float nine_over_five = 9.0/5.0;
const float five_over_nine = 5.0/9.0;

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

float celsius_to_fahrenheit(float temp) {
    return 32.0 + (temp * nine_over_five);
}

float celsius_to_kelvin(float temp) {
    return 273.15 + temp;
}

float fahrenheit_to_celsius(float temp) {
    return five_over_nine * (temp - 32.0); 
}

float fahrenheit_to_kelvin(float temp) {
    return 273.15 + fahrenheit_to_celsius(temp);
}

float kelvin_to_celsius(float temp) {
    return temp - 273.15;
}

float kelvin_to_fahrenheit(float temp) {
    float celsius = kelvin_to_celsius(temp);
    return celsius_to_fahrenheit(celsius);
}

