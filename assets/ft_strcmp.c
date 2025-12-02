int32_t	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 != 0 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(const uint8_t *) str1 - *(const uint8_t *) str2);
}