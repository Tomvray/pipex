int ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_isalnum(int c)
{
	if (ft_isalpha((unsigned char) c) || ft_isdigit((unsigned char) c))
		return (1);
	return (0);
}

int ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}