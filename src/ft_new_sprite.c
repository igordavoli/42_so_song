#include "../so_long.h"

t_img   ft_new_sprite(void *mlx, char *sprite)
{
    t_img   img;

    img.ref = mlx_xpm_file_to_image(mlx, sprite, &img.width, &img.height);
    img.pixels = mlx_get_data_addr(img.ref, &img.bits, &img.line, &img.end);
    img.x = 0;
    img.y = 0;
    return (img);
}
