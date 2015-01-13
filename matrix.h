/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 22:48:20 by dda-silv          #+#    #+#             */
/*   Updated: 2015/01/13 23:24:10 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix4 {
	float	data[4*4];
}			matrix4;

float		matrix4_get(matrix4 *m, int i, int j) {
	return data[j + i * 4];
}

void		matrix4_set(matrix4 *m, int ik int j, float value) {
void		matrix4_set(matrix4 *m, int ik int j, float value) {
	data[j + i * 4] = value;
}

float		matrix4_product_cell(matrix4 *m1, matrix4 *m2, int i, int j) {
float		matrix4_product_cell(matrix4 *m1, matrix4 *m2, int i, int j) {
	float	value;
	int		k;

	value = 0;
	k = 0;
	while (k < 4) {
		value += matrix4_get(m1, i, k) * matrix4_get(m2, k, j);
		++k;
	}
	return (value);
}

matrix4		matrix4_product(matrix4 *m1, matrix4 *m2);
matrix4		matrix4_product(matrix4 *m1, matrix4 *m2) {
	matrix4	*result;
	int		i;
	int		j;
	float	value;

	result = (matrix4 *)malloc(sizeof(matrix4));
	if (!result)
		return (NULL);
	i = 0;
	while (i < 4) {
		j = 0;
		while (j < 4) {
			value = matrix4_product_cell(matrix4 *m1, matrix4 *m2, i, j);
			matrix4_set(result, i, j, value);
			++j;
		}
		++i;
	}
	return (result);
}

int			matrix4_equal(matrix4 *m1, matrix4 *m2) {
	int	i;
	int j;

	i = 0;
	while (i < 4) {
		j = 0;
		while (j < 4) {
			if (matrix4_get(m1, i, j) != matrix4_get(m2, i, j))
				return (0);
		}
		++i;
	}
	return (1);
}

#endif
