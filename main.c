#include "includes/ft_printf.h"

int main()
{
     char a;
     char b;
    //t_flag flags;
    // int num;
    //  int i;
    char *str;
    a = 'x';
    b = '&';
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
    printf("\n----- C H A R S -----\n\n");

    printf("Check Minus & Width\n");
    ft_printf("FT : There is sun in planet : %-9c. But only : %9c there %-5c \n", a, a, b);
    printf("RL : There is sun in planet : %-9c. But only : %9c there %-5c \n", a, a, b);

    printf("\nCheck Width\n");
    ft_printf("FT : There is sun in planet : %10c. But only there\n", a);
    printf("RL : There is sun in planet : %10c. But only there\n", a);

    printf("\nCheck Star\n");
    ft_printf("FT : There is sun in planet : %*c. But only there\n", 5, a);
    printf("RL : There is sun in planet : %*c. But only there\n", 5, a);

    printf("\nCheck Star & Minus\n");
    ft_printf("FT : There is sun in planet : %-*c. But only there\n", 5, a);
    printf("RL : There is sun in planet : %-*c. But only there\n", 5, a);

    printf("\n----- S T R I N G S -----\n\n");

    //ft_printf("FT : Today is a %9s day\n", str);
    ft_printf("FT : Today is a %20s day\n", str);
    printf("RL : Today is a %20s day\n", str);

    printf("\n\n");
    ft_printf("FT : Today is a %-20s day\n", str);
    printf("RL : Today is a %-20s day\n", str);

    printf("\n\n");
    ft_printf("FT : Today is a %-2s day\n", str);
    printf("RL : Today is a %-2s day\n", str);

    printf("\n\n");
    ft_printf("FT : Today is a %2s day\n", str);
    printf("RL : Today is a %2s day\n", str);
    //num = char_to_int(str);
    //printf("%i\n", num);
    
    return 0;
}