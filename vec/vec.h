#ifndef VEC_H
# define VEC_H

#include <stdlib.h>
#include "libft.h"

/**
 * Vec - a dybamically growable array of any type.
 */

/**
 * The Vec struct is a "thick pointer".
 * Users of Vec should not access there members directly!
 * Instead, use the operations exposed in the function below.
 */
typedef struct s_vec
{
	const size_t	item_size;	/* size of an item in bytes */
	size_t			lenght;		/* number of items in Vec*/
	size_t			capacity;	/* number of items buffer can store */
	void			*buffer;	/* head memory storing items */
} t_vec;

/* Constructor / Destructor */

/**
 * Constuct a Vec value. Owner is reponsible for calling
 * Vec_drop when its lifetime expires.
 *
 * @param capacity - initial number of items it can store
 * @param item_size - sizeof an invidual item
 * @return initialized Vec value.
 */
t_vec		vec_value(size_t capacity, size_t item_size);

/**
 * Owner must call to expire a Vec value's lifetime.
 * frees any heap memory teh Vec owns.
 * Resets length, capacity to zero, buffer to NULL.
 */
void		vec_drop(t_vec *self);

/* Accessors */

/**
 * Returns the number of items in the Vec.
 */
size_t		vec_length(const t_vec *self);

/**
 * Returns a pointer to the items array _for reading only_.
 * You should not write to the return memory directly!
 */
const void	*vec_items(const t_vec *self);

/* Operations */

/**
 * Get a pointer to teh item at 'index'. You may
 * write to this reference, but not beyond it.
 */
void		*vec_ref(const t_vec *self, size_t index);

/**
 * Copy the item at 'index' to the memory of 'out'.
 */
void		vec_get(const t_vec *self, size_t index, void *out);

/**
 * Assign an item at 'index' to be a copy of 'value'.
 * Valid indeces include 0-length. When the index is equal
 * to length, the item is appended to the Vec.
 */
void		vec_set(t_vec *self, size_t index, const void *value);

#endif
