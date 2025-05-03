#include <stdint.h>

int64_t	ft_rfibonacci(int64_t index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_rfibonacci(index - 2) + ft_rfibonacci(index - 1));
}
