// WAF to calculate HCF of two numbers(TSRS)
//WAF to calculate number is prime or not
//WAF to calculate next prime number
//WAF to calculate N prime numbers
//WAF to print all prime number between two number
//WAF  to print fist N fibonacci series
//WAF to calculate factorial of two numbers
//WAF to calculate combination of any numbers
//WAF to print PASCAL tringle

#include<stdio.h>

int hcf(int a, int b);
int is_prime(int n);
int next_prime(int n);
void prime_number(int n);
void print_prime_between(int a, int b);
void fibonacci_n_terms(int n);
int fact(int n);
int comb(int n, int r);
void pascal_triangle(int rows);


int hcf(int a, int b) {
    int h;
    for (h = (a < b ? a : b); h >= 1; h--) {
        if (a % h == 0 && b % h == 0)
            return h; 
    }
    return 1;
}

int is_prime(int n) {
    if (n <= 1) return 0; 
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}


int next_prime(int n) {
    while (!is_prime(++n));
    return n;
}

void prime_number(int n) {
    int x = 2;
    while (n) {
        if (is_prime(x)) {
            printf("%d ", x);
            n--;
        }
        x++;
    }
    printf("\n");
}

void print_prime_between(int a, int b) {
    for (int x = a; x <= b; x++) {
        if (is_prime(x))
            printf("%d ", x);
    }
    printf("\n");
}


void fibonacci_n_terms(int n) {
    int a = 0, b = 1, c;
    for(int i=0;i<n;i++){
        if(i<=1){
           c =i;
        }
        else if(i==2){
            b=a; 
        }
        else{
           c=a+b;
           a=b;
           b=c; 
        }
    }
    
    while (n > 2) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
        n--;
    }
    printf("\n");
}

int fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


int comb(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}


void pascal_triangle(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", comb(i, j));
        }
        printf("\n");
    }
}

int main() {
    int a, b, n, choice;
    
    printf("Enter your choice:\n");
    printf("1. HCF of two numbers\n");
    printf("2. Check if a number is prime\n");
    printf("3. Next prime number\n");
    printf("4. First N prime numbers\n");
    printf("5. Prime numbers between two numbers\n");
    printf("6. First N Fibonacci numbers\n");
    printf("7. Pascal's Triangle\n");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("HCF of %d and %d is %d\n", a, b, hcf(a, b));
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &n);
            if (is_prime(n))
                printf("%d is a prime number\n", n);
            else
                printf("%d is not a prime number\n", n);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("Next prime number after %d is %d\n", n, next_prime(n));
            break;
        case 4:
            printf("Enter the number of prime numbers to print: ");
            scanf("%d", &n);
            prime_number(n);
            break;
        case 5:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            print_prime_between(a, b);
            break;
        case 6:
            printf("Enter the number of Fibonacci terms: ");
            scanf("%d", &n);
            fibonacci_n_terms(n);
            break;
        case 7:
            printf("Enter the number of rows for Pascal's Triangle: ");
            scanf("%d", &n);
            pascal_triangle(n);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}
