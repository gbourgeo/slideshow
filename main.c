#include <fcntl.h>
#include "libft.h"
#include "main.h"

int             main(int ac, char **av)
{
    int         fd;
    char        *line;
    int         nb_image;
    int         i;
    t_data      data;

    if (ac == 1)
        return (0);
    if ((fd = open(av[1], O_RDONLY)) < 0)
        return (0);
    if (get_next_line(fd, &line) <= 0)
        return (0);
    if ((nb_image = ft_atoi(line)) <= 0 || nb_image > 100000)
        return (0);
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        t_image     *ptr;
        char        **split;

        if ((ptr = malloc(sizeof(*ptr))) == NULL)
            return (0);
        if ((split = ft_split_whitespaces(line)) == NULL)
            return (0);
        if (!ft_strcmp(split[0], 'H'))
            ;
        else if (!ft_strcmp(split[0], 'V'))
            ;
        else
            return (0);
    }
}