/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 18:45:35 by dda-silv          #+#    #+#             */
/*   Updated: 2015/01/13 20:14:19 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/Xlib.h>
#include <stdio.h>

typedef struct s_env {
	void	*mlx;
	void	*win;
	int		suchk;
} Env;

int	key_hook(int keycode, Env *e) {
	printf("key down with keycode %d\n", keycode);
}

int	mouse_hook(int button, int x, int y, Env *e) {
	int	i;
	int	j;

	i = -10;
	while (i < 10) {
		j = -10;
		while (j < 10) {
	mlx_pixel_put(e->mlx, e->win, x+j, y+i, 0x000000);
			++j;
		}
		++i;
	}
}

#define SIZE 300
int loop_hook(Env *e) {
	int	i;
	int	j;

	e->suchk++;
	i = SIZE/3;
	while (i <= SIZE*2/3) {
		j = SIZE/3;
		while (j <= SIZE*2/3) {
			mlx_pixel_put(e->mlx, e->win, i, j, 0xF00000 * (i+j+e->suchk) / 10000.0);
			++j;
		}
		++i;
	}
}

int main() {
	Env	e;
	int	i;
	int	j;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, SIZE, SIZE, "Hello World");
	e.suchk = 0;
	i = 0;
	while (i < SIZE) {
		j = 0;
		while (j < SIZE) {
			if (i < SIZE/3 || j < SIZE/3 || i > SIZE*2/3 || j > SIZE*2/3)
				mlx_pixel_put(e.mlx, e.win, i, j, 0xFFFFFF);
			++j;
		}
		++i;
	}

	mlx_hook(e.win, KeyPress, KeyPressMask, key_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);

	return (0);
}
