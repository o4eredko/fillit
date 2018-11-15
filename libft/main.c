#include "libft.h"

int main()
{
    t_dancing_list *list;
    long cord[2];
    size_t size;
    char *line;

    line = "abcd";
    list = ft_dlstnew((const void*)line, 5, 1, 4);
    printf("%s", (char*)list->content);
    return 0;
}