#ifndef MAIN_H
# define MAIN_H

enum
{
    VERTICAL,
    HORIZONTAL,
};

typedef struct  s_image
{
    int             type;
    int             len;
    char            **tags;
    struct s_image  *next;
    struct s_image  *prev; // ?
}               t_image;

typedef struct  s_data
{
    t_image     *v;
    t_image     *h;
}               t_data;

#endif
