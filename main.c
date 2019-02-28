#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "main.h"
#include <stdio.h>

static t_image  *add_sort(t_image *head, t_image *new)
{
    t_image     *ptr;

    ptr = head;
    if (!ptr)
        return (new);
    while (ptr->next)
    {
        if (new->len >= ptr->len)
            break ;
        ptr = ptr->next;
    }
    if (new->len >= ptr->len)
    {
        new->next = ptr;
        new->prev = ptr->prev;
        if (ptr->prev)
            ptr->prev->next = new;
        ptr->prev = new;
        return ((ptr == head) ? new : head);
    }
    ptr->next = new;
    new->prev = ptr;
    return (head);
}

static t_image  *add_image(char **split, t_image *head, int type, int id)
{
    t_image     *new;

    if (!(new = ft_memalloc(sizeof(*new))))
        return (NULL);
    new->id = id;
    new->type = type;
    new->len = ft_atoi(split[1]);
    new->tags = &split[2];
    return (add_sort(head, new));
}

static void     aff_list(t_image *img)
{
    while (img)
    {
        printf("#%d %c %d", img->id, img->type == HORIZONTAL ? 'H' : img->type == VERTICAL ? 'V' : '?', img->len);
        for (int i = 0; img->tags[i]; i++)
            printf(" %s", img->tags[i]);
        printf("\n");
        img = img->next;
    }
}

int             main(int ac, char **av)
{
    int         fd;
    char        *line;
    int         nb_image;
    t_data      data;
    int         id;

    if (ac == 1)
        return (0);
    if ((fd = open(av[1], O_RDONLY)) < 0)
        return (0);
    if (get_next_line(fd, &line) <= 0)
        return (0);
    if ((nb_image = ft_atoi(line)) <= 0 || nb_image > 100000)
        return (0);
    ft_memset(&data, 0, sizeof(data));
    id = 0;
    while (get_next_line(fd, &line) > 0)
    {
        char        **split;

        ft_putendl(line);
        if ((split = ft_split_whitespaces(line)) == NULL)
            return (0);
        if (!ft_strcmp(split[0], "H"))
        {
            if (!(data.h = add_image(split, data.h, HORIZONTAL, id++)))
                return (0);
            data.h_len++;
        }
        else if (!ft_strcmp(split[0], "V"))
        {
            if (!(data.v = add_image(split, data.v, VERTICAL, id++)))
                return (0);
            data.v_len++;
        }
        else
            return (0);
        free(line);
    }
    printf("got %d vertical and %d horizontal = %d\n", data.v_len, data.h_len, data.v_len + data.h_len);
    aff_list(data.v);
    aff_list(data.h);
    return (0);
}