#include <stdint.h>
#include <stddef.h>

void	*ft_memcpy2(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	dst = (char *) dst_void;
	while (length > sizeof(void*) && ((uintptr_t)dst & (sizeof(void*) - 1)))
	{
		*dst++ = *src++;
		length--;
	}
	for (length; length >= sizeof(void*); length-=8)
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst += sizeof(void*);
		src += sizeof(void*);
	}
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}