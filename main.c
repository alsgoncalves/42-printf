#include "ft_printf.h"

int main()
{
     char a;
    //t_flag flags;
    // int num;
    //  int i;
    //char *str;
    a = 'x';
    // i = 0;
    // num = 0;
   // str = "Beaut";
    // // flags = ft_initialize_flags();
    // // a = ft_check_type(str, flags);
    // // printf("Printing a : %c\n", a);
    
    // num = char_to_int(str);
    // printf("%i\n", num);
    // printf("%i\n", 130999870098765);
    // //printf("%.7896f\n", num);
    printf("Check Minus & Width\n");
    ft_printf("FT : There is sun in planet : %-9c. But only there\n", a);
    printf("RL : There is sun in planet : %-9c. But only there\n", a);

    printf("Check Width\n");
    ft_printf("FT : There is sun in planet : %10c. But only there\n", a);
    printf("RL : There is sun in planet : %10c. But only there\n", a);

    printf("Check Star\n");
    ft_printf("FT : There is sun in planet : %*c. But only there\n", 5, a);
    printf("RL : There is sun in planet : %*c. But only there\n", 5, a);

    printf("Check Star & Minus\n");
    ft_printf("FT : There is sun in planet : %-*c. But only there\n", 5, a);
    printf("RL : There is sun in planet : %-*c. But only there\n", 5, a);
    //num = char_to_int(str);
    //printf("%i\n", num);
    
    return 0;
}