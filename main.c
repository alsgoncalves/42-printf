#include "includes/ft_printf.h"

int main()
{
    //  char a;
    //  char b;
    //t_flag flags;
    // int num;
    //  int i;
    char *str;
    int i;
    int n;
    // a = 'x';
    // b = '&';
    // i = 0;
    // num = 0;
    str = "beautiful";
    // // flags = ft_initialize_flags();
    // // a = ft_check_type(str, flags);
    // // printf("Printing a : %c\n", a);
    
    // num = char_to_int(str);
    // printf("%i\n", num);
    // printf("%i\n", 130999870098765);
    // //printf("%.7896f\n", num);
    // printf("\n----- C H A R S -----\n\n");

    // // printf("\nCheck Width\n");
    // // ft_printf("FT : There is sun in planet : %c. But only there\n", a);
    // // printf("RL : There is sun in planet : %c. But only there\n", a);

    // // printf("Check Minus & Width\n");
    // // ft_printf("FT : There is sun in planet : %-9c. But only : %9c there %-5c \n", a, a, b);
    // // printf("RL : There is sun in planet : %-9c. But only : %9c there %-5c \n", a, a, b);

    // // printf("\nCheck Width\n");
    // // ft_printf("FT : There is sun in planet : %10c. But only there\n", a);
    // // printf("RL : There is sun in planet : %10c. But only there\n", a);

    // // printf("\nCheck Star\n");
    // // ft_printf("FT : There is sun in planet : %*c. But only there\n", 5, a);
    // // printf("RL : There is sun in planet : %*c. But only there\n", 5, a);

    // // printf("\nCheck Star & Minus\n");
    // // ft_printf("FT : There is sun in planet : %-*c. But only there\n", 5, a);
    // // printf("RL : There is sun in planet : %-*c. But only there\n", 5, a);

    // // printf("\nCheck Star & Minus in Var\n");
    // // ft_printf("FT : There is sun in planet : %-*c. But only there\n", 5, a);
    // // printf("RL : There is sun in planet : %*c. But only there\n", -5, a);

    // printf("\n----- S T R I N G S -----\n\n");

    // //ft_printf("FT : Today is a %9s day\n", str);
    // ft_printf("FT : Today is a %20s day\n", str);
    // printf("RL : Today is a %20s day\n", str);

    // printf("\n\n");
    // ft_printf("FT : Today is a %-20s day\n", str);
    // printf("RL : Today is a %-20s day\n", str);

    // printf("\n\n");
    // ft_printf("FT : Today is a %-2s day\n", str);
    // printf("RL : Today is a %-2s day\n", str);

    // printf("\n\n");
    // ft_printf("FT : Today is a %2s day\n", str);
    // printf("RL : Today is a %2s day\n", str);

    // printf("\n\n");
    // ft_printf("FT : Today is a %s day\n", str);
    // printf("RL : Today is a %s day\n", str);

    // printf("\n\nTESTING PRECISION\n\n");

    // printf("\nDOT\n");
    // ft_printf("FT : Today is a %15.20s day\n", str);
    // printf("RL : Today is a %15.20s day\n", str);


    // printf("\nDOT\n");
    // ft_printf("FT : Today is a %.s day\n", str);
    // printf("RL : Today is a %.s day\n", str);

    // printf("\nDOT & STAR\n");
    // ft_printf("FT : Today is a %.*s day\n", 4, str);
    // printf("RL : Today is a %.*s day\n", 4, str);

    // printf("\nMINUS, DOT & STAR\n");
    // ft_printf("RL : Today is a %-20.*s day\n", 50, str);
    // printf("RL : Today is a %-20.*s day\n", 50, str);

    // printf("\nSTAR, DOT & ZERO\n");
    // ft_printf("RL : Today is a %*.1s day\n", 4, str);
	// printf("RL : Today is a %*.1s day\n", 4, str);

    // printf("\nSTAR(witdh), DOT & PRECISION_VALUE\n");
    // ft_printf("FT : Today is a %*.20s day\n", 4, str);
	// printf("RL : Today is a %*.20s day\n", 4, str);
    // // printf("RL : Today is a %*.20s day\n", 20, str);
    // // printf("RL : Today is a %*.20s day\n", 19, str);
    // // printf("RL : Today is a %*.*s day\n", 4, 20, str);

    // printf("\n DOT & VALUE\n");
    // ft_printf("FT : Today is a %.10s day\n", str);
	// printf("RL : Today is a %.10s day\n", str);

    // printf("\n DOT & SMALLER PRECISION THAN LEN \n");
    // ft_printf("FT : Today is a %.5s day\n", str);
	// printf("RL : Today is a %.5s day\n", str);

    // printf("\n WIDTH + PRECISION \n");
    // ft_printf("FT : Today is a %10.4s day\n", str);
	// printf("RL : Today is a %10.4s day\n", str);

    // printf("\n TEST 18 \n");
    // printf("%d\n", ft_printf("FT : %*.3s %.3s\n", 10, "123", "4567"));
	// printf("%d\n", printf("RL : %*.3s %.3s\n", 10, "123", "4567"));

    // printf("\n TEST MINE \n");
    // printf("%d\n", ft_printf("FT : Today is %*.3s %.3s\n", 10, "123", "4567"));
	// printf("%d\n", printf("RL : Today is %*.3s %.3s\n", 10, "123", "4567"));

    // printf("\n TEST 16 \n");
    // i = ft_printf("%*.s %.1s", 10, "123", "4567");
    // printf("%i\n", i);
    // n = printf("%*.s %.1s", 10, "123", "4567");
    // printf("%i\n", n);

    // printf("\n TEST 22 \n");
    // i = ft_printf("<FT : %*.5s %*.5s ", -10, "123", 10, "4567");
    // printf("%i\n", i);
    // n = printf("<RL : %*.5s %*.5s ", -10, "123", 10, "4567");
    // printf("%i\n", n);

    // printf("\n TEST 25 \n");
    // i = ft_printf("FT : %10.s %1.s ", "123", "4567");
    // printf("%i\n", i);
    // n = printf("RL : %10.s %1.s ", "123", "4567");
    // printf("%i\n", n);

    printf("\n TEST 28 \n");
    i = ft_printf("FT :%3.3s %3.3s ", "123", "4567");
    printf("%i\n", i);
    n = printf("RL :%3.3s %3.3s ", "123", "4567");
    printf("%i\n", n);
    //num = char_to_int(str);
    //printf("%i\n", num);
    
    return 0;
}