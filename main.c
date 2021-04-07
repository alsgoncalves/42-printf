#include "includes/ft_printf.h"
#include <limits.h>

int main()
{
    //  char a;
    //  char b;
    //t_flag flags;
    // int num;
    //  int i;
    //char *str;
    int i;
    int n;
    // a = 'x';
    // b = '&';
    // // i = 0;
    // // num = 0;
    //str = "beautiful";
    // // flags = ft_initialize_flags();
    // // a = ft_check_type(str, flags);
    // // printf("Printing a : %c\n", a);
    
    // num = char_to_int(str);
    // printf("%i\n", num);
    // printf("%i\n", 130999870098765);
    // //printf("%.7896f\n", num);
    // printf("\n----- C H A RL S -----\n\n");

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

    // printf("\n----- S T RL I N G S -----\n\n");

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
    // // ft_printf("FT : Today is a %20.-50s day\n", str);
    // // printf("RL : Today is a %20.-50s day\n", str);

    // ft_printf("FT : Today is a %20.*s day\n", 50, str);
    // printf("RL : Today is a %20.*s day\n", 50, str);

    // ft_printf("FT : Today is a %20.*s day\n", -50, str);
    // printf("RL : Today is a %20.*s day\n", -50, str);

    // printf("\nNULL\n");
    // printf("RL %-3.s\n", NULL);
    // ft_printf("FT %-3.s\n", NULL);
    // printf("RL %-9.1s\n", NULL);
    // ft_printf("FT %-9.1s\n", NULL);
    // printf("RL %.*s\n", -2, NULL);
    // ft_printf("FT %.*s\n", -2, NULL);
    // printf("RL %.*s\n", -2, str);

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

    // printf("\n TEST 28 \n");
    // i = ft_printf("FT :%3.3s %3.3s ", "123", "4567");
    // printf("%i\n", i);
    // n = printf("RL :%3.3s %3.3s ", "123", "4567");
    // printf("%i\n", n);

    // printf("\n TEST 36 \n");
    // i = ft_printf("%.*s", -2, NULL);
    // printf("%i\n", i);
    // n = printf("%.*s", -2, NULL);
    // printf("%i\n", n);
    //  printf("%*c\n", 0, '0');
    //  ft_printf("%*c\n", 0, '0');

    //  printf("RL: %-c%-c%c*\n", 1, '0', 0);
    //  ft_printf("FT: %-c%-c%c*\n", 1, '0', 0);

//     //  printf("\n TEST MINE \n");
//     // i = ft_printf("%.-4s", NULL);
//     // printf("%i\n", i);
//     // n = printf("%.-4s", NULL);
//     // printf("%i\n", n);
//     printf("\nDIGIT ONLY \n");
//     printf("RL %d\n", 50);
//     ft_printf("FT %d\n", 50);
//     printf("\n");
//     printf("\nDOT \n");
	// printf("RL %.1d\n", 0);
    // ft_printf("FT %.1d\n", 0);
//     printf("\n");
//     printf("RL %10.0d\n", 1);
//     ft_printf("FT %10.0d\n", 1);
//     printf("\n");
//     printf("RL %.d\n", 30);
//     ft_printf("FT %.d\n", 30);
//     printf("\n");
//     printf("RL %.0d\n", 30);
//     ft_printf("FT %.0d\n", 30);
// // //     printf("\n");
// // //    // printf("%.1d\n", 30);

//     printf("\n\nMINUS DOT PREC VALUE \n");
//     printf("RL %.2d\n", 300);
//     ft_printf("FT %.2d\n", 300);
//     printf("\n");
//     printf("RL %.2d\n", -300);
//     ft_printf("FT %.2d\n", -300);
//     printf("\n");
//     printf("RL %.10d\n", -300);
//     ft_printf("FT %.10d\n", -300);
// //     printf("\n");
//     printf("RL %.10d\n", 300);
//     ft_printf("FT %.10d\n", 300);
//     printf("\n");
// 	printf("RL %-.2d\n", 3);
//     ft_printf("FT %-.2d\n", 3);
//     printf("\n");
//     printf("\n\nMINUS WIDTH -  DOT - PREC VALUE \n");
// 	printf("RL %-2.2d\n", 3);
//     ft_printf("FT %-2.2d\n", 3);
//     printf("\n");

// 	printf("RL %3.2d\n", 3);
//     ft_printf("FT %3.2d\n", 3);
//     printf("\n");

//     printf("RL %.*d\n", 10, -3);
//     ft_printf("FT %.*d\n", 10, -3);
//     printf("\n");

//     printf("RL %.*d\n", -10, -3);
//     ft_printf("FT %.*d\n", -10, -3);
//     printf("\n");

// 	printf("RL %-3.2d %10.42d\n", 3, 0);
//     ft_printf("FT %-3.2d %10.42d\n", 3, 0);

//     printf("\n");
// 	printf("RL %.42d\n", -20);
//     ft_printf("FT %.42d\n", -20);
//     printf("\n");
// 	printf("RL %.42d\n",-12);
//     ft_printf("FT %.42d\n", -12);

//     printf("\n");
//     printf("RL %.10d\n", 20);
//     ft_printf("FT %.10d\n", 20);
//     printf("\n");

//     printf("\n\nZERO W/ PRECISION \n");
//     printf("RL %21.10d\n", 20);
//     ft_printf("FT %21.10d\n", 20);
//     printf("\n");

//     //num = char_to_int(str);
//    // printf("%i\n", num);
//      printf("RL: %0-*.*d\n", 6, 2, 102);
//     ft_printf("FT: %0-*.*d\n", 6, 2, 102);
//     printf("\n");
//     printf("RL: %0-*.*d\n", 6, 2, 102);
//     ft_printf("FT: %0-*.*d\n", 6, 2, 102);
//     printf("\n");
//     printf("RL:%-0*.*d\n", 10, 21, -101);
//     ft_printf("FT:%-0*.*d\n", 10, 21, -101);

//      printf("RL:%-0*.*d\n", 10, 21, 101);
//     ft_printf("FT:%-0*.*d\n", 10, 21, 101);

//     printf("RL: 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
//     ft_printf("FT: 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
//     printf("\n");
// 	printf("RL: %0*d*0\n", 21, -1011);
//     ft_printf("FT: %0*d*0\n", 21, -1011);
//     printf("\n");
//     printf("RL: %-09d\n", 2554);
//     ft_printf("FT: %-09d\n", 2554);
//     printf("\n");
//     printf("RL: %09d\n", 2554);
//     ft_printf("FT: %09d\n", 2554);
//      printf("\n");
//      printf("RL: %09d\n", -2554);
//      ft_printf("FT: %09d\n", -2554);
//     printf("RL 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
//     ft_printf("FT 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);

    // printf("RL: 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
    // ft_printf("FT: 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
    //  printf("\n");
// 	printf("RL: --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1);
//     ft_printf("FT: --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1);

    // printf("\n");
	// printf("RL: %*.0d* \n", -10, 0);
    // ft_printf("FT: %*.0d* \n", -10, 0);

    // printf("\n");
	// printf("RL: %0*.10d*0-- \n", 21, 1);
    // ft_printf("FT: %0*.10d*0-- \n", 21, 1);

    //  printf("RL: %-0*.0d*\n", 10, -1011);
    // ft_printf("FT: %-0*.0d*\n", 10, -1011);
    // printf("\n");
    // printf("xx %10.2d**\n", 0);
    // ft_printf("oo %10.2d**\n", 0);

    // printf("\n");
    // printf("%d\n", 0);
    // ft_printf("%d\n", 0);

    printf(" --0*%0*.0d*0 0*%0*.10d*0--\n", -21, INT_MAX, 21, INT_MIN);
    ft_printf(" --0*%0*.0d*0 0*%0*.10d*0--\n", -21, INT_MAX, 21, INT_MIN);
    printf(" 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
    ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
    printf("\n");
    printf("RL %10.3d\n", 30);
    ft_printf("FT %10.3d\n", 30);
    printf("\n");
    printf("RL %10.d\n", UINT_MAX);
    ft_printf("FT %10.d\n", UINT_MAX);
    printf("\n");
    printf("RL %10.1d\n", -1);
    ft_printf("FT %10.1d\n", -1);
    printf("RL %10.2d\n", -1);
    ft_printf("FT %10.2d\n", -1);
    printf("\n");
    printf("\n");
	printf("RL %.2d\n", -10);
    ft_printf("FT %.2d\n", -10);
    printf("\n");
	printf("RL %.20d\n", -10);
    ft_printf("FT %.20d\n", -10);

    printf("\n");
	printf("RL %.2d\n", 10);
    ft_printf("FT %.2d\n", 10);
    printf("\n");
	printf("RL %.20d\n", 10);
    ft_printf("FT %.20d\n", 10);
    // printf("\n");
	printf("RL %10.3d\n", UINT_MAX);
    ft_printf("FT %10.3d\n", UINT_MAX);

     printf("\n");
    printf("RL %-0*.4d*0\n", 21, CHAR_MIN);
    ft_printf("FT %-0*.4d*0\n", 21, CHAR_MIN);

    printf("\n");
    printf("RL %-0*.5d*0\n", 10, -128);
    ft_printf("FT %-0*.5d*0\n", 10, -128);
     printf("\n");
	printf("RL %9.2d\n", UINT_MAX);
    ft_printf("FT %9.2d\n", UINT_MAX);

     return 0;
}