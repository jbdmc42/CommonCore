#include "minirt.h"

static int  verify_extension(char *arg, int len)
{
    if (arg[len - 3] == '.' && arg[len - 2] == 'r' && arg[len - 1] == 't')
        return (S);
    return (E);
}

int    input_validation(char *arg)
{
    int len;
    
    len = ft_strlen(arg);
    if (len < 4)
        return (E);
    if (!verify_extension(arg, len))
        return (E);
    return (S);
}
