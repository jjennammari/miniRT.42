/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemustaj <jemustaj@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:16:15 by jemustaj          #+#    #+#             */
/*   Updated: 2026/04/29 12:18:10 by jemustaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_tuple	*sum_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2);
t_tuple	*negate_tuple(t_tuple *v);
t_tuple	*scalar_multiply_tuple(t_tuple *tuple, double scalar);
t_tuple	*scalar_divide_tuple(t_tuple *tuple, double scalar);

/* Sum tuple sums the values of two tuples, creates a new tuple with those
 * values and returns that new tuple. 
 * This function can be used for summing a point and vector together to find
 * out where is the next point after following that vector from given point. */
t_tuple	*sum_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*new_tuple;
	double	sum_x;
	double	sum_y;
	double	sum_z;
	double	sum_w;

	sum_x = t1->x + t2->x;
	sum_y = t1->y + t2->y;
	sum_z = t1->z + t2->z;
	sum_w = t1->w + t2->w;
	new_tuple = create_tuple(sum_x, sum_y, sum_z, sum_w);
	return (new_tuple);
}

/* Subtract tuple takes two tuples and subtracks t2 values from t1 values,
 * creates new tuple with those values and returns it.
 * This function can be used to:
 * - find the vector pointing from t2 to t1 by subtracting between two points
 * - find a vector from current point to previous point by subtracting vector
 *   from current point
 * - create a vector representing the change between two vectors by sybtracting
 *   them from each others. */
t_tuple	*subtract_tuple(t_tuple *t1, t_tuple *t2)
{
	t_tuple	*new_tuple;
	double	dif_x;
	double	dif_y;
	double	dif_z;
	double	dif_w;

	dif_x = t1->x - t2->x;
	dif_y = t1->y - t2->y;
	dif_z = t1->z - t2->z;
	dif_w = t1->w - t2->w;
	new_tuple = create_tuple(dif_x, dif_y, dif_z, dif_w);
	return (new_tuple);
}

/* Negating tuple is used to know the opposite of vector. It subtracts the
 * tuple values from 0 to get the opposite values, creates a new vector with
 * them and returns it.
 * When you have a vector that points from surface towards to light source,
 * this can be useful when needed to know which vector points from the light
 * source back to the surface. */
t_tuple	*negate_tuple(t_tuple *v)
{
	t_tuple	*opposite_vector;
	double	x;
	double	y;
	double	z;
	double	w;

	x = 0 - v->x;
	y = 0 - v->y;
	z = 0 - v->z;
	w = 0 - v->w;
	opposite_vector = create_tuple(x, y, z, w);
	return (opposite_vector);
}

/* Scalar multiply means to multiply all tuple values with specific scalar
 * value given, creates a new tuple with those values and returns it.
 * This function is used when needed to find where the ray intersects sphere.*/
t_tuple	*scalar_multiply_tuple(t_tuple *tuple, double scalar)
{
	t_tuple	*new_tuple;
	double	mult_x;
	double	mult_y;
	double	mult_z;
	double	mult_w;

	mult_x = tuple->x * scalar;
	mult_y = tuple->y * scalar;
	mult_z = tuple->z * scalar;
	mult_w = tuple->w * scalar;
	new_tuple = create_tuple(mult_x, mult_y, mult_z, mult_w);
	return (new_tuple);
}

/* Scalar divide means to multiply all tuple values with specific scalar
 * value given, creates a new tuple with those values and returns it.
 * This function is used when needed to find where the ray intersects sphere.*/
t_tuple	*scalar_divide_tuple(t_tuple *tuple, double scalar)
{
	t_tuple	*new_tuple;
	double	div_x;
	double	div_y;
	double	div_z;
	double	div_w;

	if (fabs(scalar) < EPSILON)
		error_exit(1);
	div_x = tuple->x / scalar;
	div_y = tuple->y / scalar;
	div_z = tuple->z / scalar;
	div_w = tuple->w / scalar;
	new_tuple = create_tuple(div_x, div_y, div_z, div_w);
	return (new_tuple);
}
