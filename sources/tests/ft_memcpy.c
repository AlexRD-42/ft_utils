#include <stdint.h>
#include <stddef.h>

void	*ft_memcpy(void *restrict dst_void, const void *restrict src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	dst = (char *) dst_void;
	while (length > sizeof(void*) && ((uintptr_t)dst & (sizeof(void*) - 1)))
	{
		*dst++ = *src++;
		length--;
	}
	while (length >= sizeof(void*))
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst += sizeof(void*);
		src += sizeof(void*);
		length -= sizeof(void*);
	}
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}