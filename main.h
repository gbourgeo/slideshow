#ifndef MAIN_H
# define MAIN_H

enum
{
    VERTICAL,
    HORIZONTAL,
};

typedef struct  s_image
{
    int             id;
    int             type;
    int             len;
    char            **tags;
    struct s_image  *next;
    struct s_image  *prev; // ?
}               t_image;

typedef struct  s_data
{
    t_image     *v;
    int         v_len;
    t_image     *h;
    int         h_len;
}               t_data;

#endif
