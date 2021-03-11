#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    int char_count;
    va_list ap;

    va_start(ap, (char *)format);
    
    // calculate char_count

    va_end(ap);
    // To return total number of chars displayed by printf
    return (char_count);
}