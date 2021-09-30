#include "vec.h"
#include "minishell.h"
#include "guards.h"

static void	_ensure_capacity(t_vec *self, size_t n);

/* Constructor / Destructor */

t_vec vec_value(size_t capacity, size_t item_size)
{
	t_vec vec;

	vec.item_size = item_size;
	vec.lenght = 0;
	vec.capacity = capacity;
	vec.buffer = ft_calloc(capacity, item_size);
	OOM_GUARD(vec.buffer, __FILE__, __LINE__);
	return (vec);
}

void	vec_drop(t_vec *self)
{
	free(self->buffer);
	self->buffer = NULL;
	self->capacity = 0;
	self->length = 0;
}

/* Accessors */

size_t vec_length(const t_vec *self)
{
	return (self->lenght);
}

const void	*vec_item(const t_vec *self)
{
	return (self->buffer);
}

void	*vec_ref(const t_vec *self, size_t index)
{
	return (self->buffer + (index * self->item_size));
}

void	vec_get(const t_vec *self, size_t index, void *out)
{
	//TODO
}

void	vec_set(t_vec *self, size_t index, const void *value)
{
	self->item_size =
}

/* Helpers */

static void	_ensure_capacity(t_vec *self, size_t n)
{
	size_t new_capacity;

	if (n < self->capacity)
	{
		new_capacity = n * 2;
		self->buffer = ft_realloc(self->buffer, new_capacity * self->item_size);
		OOM_GUARD(self->buffer, __FILE__, __LINE__);
		self->capacity = new_capacity;
	}
}
