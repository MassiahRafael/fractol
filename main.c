#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i;
	int j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 350, 350, "Hello world!");
	img.img = mlx_new_image(mlx, 350, 350);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
//	my_mlx_pixel_put(&img, 174, 174, 0x00FF0000);
	j = 0;
	while(j < 350)
	{
		i = 0;
		while(i < 350)
		{
			if(((i - 174)*(i - 174) + (j - 174)*(j - 174)) < 100*100)
				my_mlx_pixel_put(&img, j, i, 0x00FF0000);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
