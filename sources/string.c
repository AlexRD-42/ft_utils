/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:32:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 09:39:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



const
char	*ft_strfind(const char *str, const char *charset, uint8_t ref)
{
	size_t	i;
	size_t	lookup_table[256 / sizeof(size_t)];

	i = 0;
	while (i < (256 / sizeof(size_t)))
		lookup_table[i++] = 0UL;
	while (*charset != 0)
	{
		((uint8_t *)lookup_table)[(uint8_t) *charset] = 1;
		charset++;
	}
	ref = (ref != 0);
	((uint8_t *)lookup_table)[0] = ref;
	while (((uint8_t *)lookup_table)[(uint8_t) *str] != ref)
		str++;
	if (*str != 0)
		return (str);
	return (NULL);
}

size_t	ft_replace(char *str, unsigned char old_char, unsigned char new_char)
{
	size_t	count;

	count = 0;
	while (*str != 0)
	{
		if (*str == old_char)
		{
			*str = new_char;
			count++;
		}
		str++;
	}
	return (count);
}

// Null terminate this you baboon
char	**ft_arena_split(const char *str, const char *charset, size_t *count)
{
	char			**array;
	char			*offset;
	size_t			length;
	uint8_t			lut[256];
	const size_t	words = ft_count_tokens(str, ft_setlut256(lut, charset), &length);

	array = malloc(length + words * (sizeof(char *) + 1));
	if (array == NULL)
		return (NULL);
	offset = (char *) array + words * sizeof(char *);
	*count = 0;
	while (*str != 0)
	{
		while (*str != 0 && ft_ischarset(*str, charset) == 1)
			str++;
		length = 0;
		while (ft_ischarset(str[length], charset) == 0)
			length++;
		if (length == 0)
			break ;
		array[*count] = ft_memcpy(offset, str, length);
		array[(*count)++][length] = 0;
		offset += length + 1;
		str += length;
	}
	return (array);
}

// Change this back to uint32_t once you figured out strtoull
int32_t	*ft_split_numbers(const char *str, const char *charset, size_t *count)
{
	int32_t			*array;
	size_t			length;
	uint8_t			lut[256];
	const uint8_t	*ustr = (const uint8_t *) str;
	const size_t	tokens = ft_count_tokens(str, ft_setlut256(lut, charset), NULL);

	array = malloc(tokens * sizeof(int32_t));
	if (array == NULL)
		return (NULL);
	*count = 0;
	while (*ustr != 0)
	{
		while (lut[*ustr] == 1)
			ustr++;
		length = 0;
		while (lut[ustr[length]] == 0)
			length++;
		if (length == 0)
			break ;
		array[(*count)++] = ft_atoi((const char *) ustr);
		ustr += length;
	}
	return (array);
}

// size_t	ft_count_tokens(const char *str, const char *charset, size_t *bytes)
// {
// 	size_t	bytes_local;
// 	size_t	count;
// 	size_t	lookup_table[256 / sizeof(size_t)];
// 	uint8_t	*lut_ptr;

// 	lut_ptr = (uint8_t *) lookup_table;
// 	count = 0;
// 	bytes_local = 0;
// 	while (count < 256 / sizeof(size_t))
// 		lookup_table[count++] = 0UL;
// 	while (*charset != 0)
// 		lut_ptr[*(const uint8_t *) charset++] = 1u;
// 	while (lut_ptr[*(const uint8_t *) str])
// 		str++;
// 	count = (*str != 0);
// 	lut_ptr[0] = 1u;
// 	while (*str != 0)
// 	{
// 		count += lut_ptr[(uint8_t)str[0]] && !lut_ptr[(uint8_t)str[1]];
// 		bytes_local += !lut_ptr[(uint8_t)str[0]];
// 		str++;
// 	}
// 	if (bytes != NULL)
// 		*bytes = bytes_local;
// 	return (count);
// }

size_t	ft_count_tokens(const char *str, const uint8_t *lut, size_t *bytes)
{
	const uint8_t	*ustr = (const uint8_t *) str;
	size_t			bytes_local;
	size_t			count;

	bytes_local = 0;
	while (lut[*ustr] == 1)
		ustr++;
	count = *ustr != 0;
	while (*ustr != 0)
	{
		count += lut[ustr[0]] && !lut[ustr[1]];
		bytes_local += !lut[ustr[0]];
		ustr++;
	}
	if (bytes != NULL)
		*bytes = bytes_local;
	return (count);
}
