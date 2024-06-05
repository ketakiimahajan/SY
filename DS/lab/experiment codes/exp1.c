#include <stdio.h>
#include <stdlib.h>

// Define the complex number ADT
typedef struct {
    double real;
    double imaginary;
} Complex;

// Define the rational number ADT
typedef struct {
    int numerator;
    int denominator;
} Rational;

// Function to add two complex numbers
Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// Function to subtract two complex numbers
Complex subtractComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

// Function to check equality of two complex numbers
int isEqualComplex(Complex c1, Complex c2) {
    return c1.real == c2.real && c1.imaginary == c2.imaginary;
}

// Function to add two rational numbers
Rational addRational(Rational r1, Rational r2) {
    Rational result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}

// Function to subtract two rational numbers
Rational subtractRational(Rational r1, Rational r2) {
    Rational result;
    result.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}

// Function to multiply two rational numbers
Rational multiplyRational(Rational r1, Rational r2) {
    Rational result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}

// Function to check equality of two rational numbers
int isEqualRational(Rational r1, Rational r2) {
    return (r1.numerator * r2.denominator) == (r2.numerator * r1.denominator);
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050");
    int choice;
    
    do {
        printf("\n\nMenu:\n");
        printf("1. Add Complex Numbers\n");
        printf("2. Subtract Complex Numbers\n");
        printf("3. Multiply Complex Numbers\n");
        printf("4. Check Equality of Complex Numbers\n");
        printf("5. Add Rational Numbers\n");
        printf("6. Subtract Rational Numbers\n");
        printf("7. Multiply Rational Numbers\n");
        printf("8. Check Equality of Rational Numbers\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Add Complex Numbers
            {
                Complex c1, c2, result;
                printf("Enter the real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &c1.real, &c1.imaginary);
                printf("Enter the real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &c2.real, &c2.imaginary);
                result = addComplex(c1, c2);
                printf("Result: %lf + %lfi\n", result.real, result.imaginary);
                break;
            }
            case 2: // Subtract Complex Numbers
            {
                Complex c1, c2, result;
                printf("Enter the real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &c1.real, &c1.imaginary);
                printf("Enter the real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &c2.real, &c2.imaginary);
                result = subtractComplex(c1, c2);
                printf("Result: %lf + %lfi\n", result.real, result.imaginary);
                break;
            }
            case 3: // Multiply Complex Numbers
            {
                Complex c1, c2, result;
                printf("Enter the real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &c1.real, &c1.imaginary);
                printf("Enter the real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &c2.real, &c2.imaginary);
                result = multiplyComplex(c1, c2);
                printf("Result: %lf + %lfi\n", result.real, result.imaginary);
                break;
            }
            case 4: // Check Equality of Complex Numbers
            {
                Complex c1, c2;
                printf("Enter the real and imaginary parts of the first complex number: ");
                scanf("%lf %lf", &c1.real, &c1.imaginary);
                printf("Enter the real and imaginary parts of the second complex number: ");
                scanf("%lf %lf", &c2.real, &c2.imaginary);
                if (isEqualComplex(c1, c2)) {
                    printf("Complex numbers are equal.\n");
                } else {
                    printf("Complex numbers are not equal.\n");
                }
                break;
            }
            case 5: // Add Rational Numbers
            {
                Rational r1, r2, result;
                printf("Enter the numerator and denominator of the first rational number: ");
                scanf("%d %d", &r1.numerator, &r1.denominator);
                printf("Enter the numerator and denominator of the second rational number: ");
                scanf("%d %d", &r2.numerator, &r2.denominator);
                result = addRational(r1, r2);
                printf("Result: %d/%d\n", result.numerator, result.denominator);
                break;
            }
            case 6: // Subtract Rational Numbers
            {
                Rational r1, r2, result;
                printf("Enter the numerator and denominator of the first rational number: ");
                scanf("%d %d", &r1.numerator, &r1.denominator);
                printf("Enter the numerator and denominator of the second rational number: ");
                scanf("%d %d", &r2.numerator, &r2.denominator);
                result = subtractRational(r1, r2);
                printf("Result: %d/%d\n", result.numerator, result.denominator);
                break;
            }
            case 7: // Multiply Rational Numbers
            {
                Rational r1, r2, result;
                printf("Enter the numerator and denominator of the first rational number: ");
                scanf("%d %d", &r1.numerator, &r1.denominator);
                printf("Enter the numerator and denominator of the second rational number: ");
                scanf("%d %d", &r2.numerator, &r2.denominator);
                result = multiplyRational(r1, r2);
                printf("Result: %d/%d\n", result.numerator, result.denominator);
                break;
            }
            case 8: // Check Equality of Rational Numbers
            {
                Rational r1, r2;
                printf("Enter the numerator and denominator of the first rational number: ");
                scanf("%d %d", &r1.numerator, &r1.denominator);
                printf("Enter the numerator and denominator of the second rational number: ");
                scanf("%d %d", &r2.numerator, &r2.denominator);
                if (isEqualRational(r1, r2)) {
                    printf("Rational numbers are equal.\n");
                } else {
                    printf("Rational numbers are not equal.\n");
                }
                break;
            }
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
