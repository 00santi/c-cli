#include <stdio.h>


float celsius_to_fahrenheit(float temp);
float celsius_to_kelvin(float temp);
float fahrenheit_to_celsius(float temp);
float fahrenheit_to_kelvin(float temp);
float kelvin_to_celsius(float temp);
float kelvin_to_fahrenheit(float temp);


const float nine_over_five = 9.0/5.0;
const float five_over_nine = 5.0/9.0;


int main() {
    printf("!!!! test test test test\n");
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

