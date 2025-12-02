/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:35:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 09:35:19 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reallocates memory to a bigger size, copies old array
// If the old array is NULL, this is effectively just malloc
void	*ft_realloc(void *src, size_t src_size, size_t dst_size)
{
	void	*dst;

	dst = (void *) malloc (dst_size);
	if (dst != NULL)
	{
		*((unsigned char *) dst) = 0;
		if (src != NULL)
			ft_memcpy(dst, src, src_size);
	}
	free(src);
	return (dst);
}

// Pointer cast is necessary otherwise caller would need to cast void **
void	**ft_free_array(void *array, size_t length)
{
	if (array == NULL)
		return (NULL);
	while (length-- > 0)
	{
		free(((void **) array)[length]);
		((void **) array)[length] = NULL;
	}
	free(array);
	return (NULL);
}
