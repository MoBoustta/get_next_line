#include "get_next_line.h"
size_t  ft_strlen(const char *str);
void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned int    i;
    unsigned char   *str;

    i = 0;
    str = (unsigned char*)s;
    while (n--)
    {
        if (str[i] == (unsigned char)c)
            return (&str[i]);
        i++;
    }
    return (NULL);
}
char	*ft_strchr(const char *s, int c)
{
    int		i;
    char	*str;

    i = 0;
    str = (char *)s;
    while (str[i] != '\0')
    {
        if (s[i] == c)
            return (&str[i]);
        i++;
    }
    if (s[i] == (char)c)
        return (&str[i]);
    return (NULL);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t		i;
    char		*sub_str;
    size_t		len_s;

    i = 0;
    if (!s)
        return (NULL);
    len_s = ft_strlen((char *)s);
    if (!(sub_str = malloc(len * sizeof(char) + 1)))
        return (NULL);
    while (s[start] != '\0' && i < len && start < len_s)
    {
        sub_str[i] = *(unsigned char *)(s + start);
        start++;
        i++;
    }
    sub_str[i] = '\0';
    return (char *)(sub_str);
}
void	*ft_memset(void *b, int c, size_t len)
{
    unsigned int	i;
    char			*bb;

    i = 0;
    bb = b;
    while (i < len)
    {
        bb[i] = c;
        i++;
    }
    return (bb);
}
char    *ft_strjoin(char *s1, char *s2)
{
    char		*s3;
    char		*tmp_s3;
    size_t		i;
    size_t		j;

    j = 0;
    i = 0;
    while (s1[i])
        i += 1;
    while (s2[j])
        j += 1;
    if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
        return (NULL);
    tmp_s3 = s3;
    while (*s1 != '\0')
        *tmp_s3++ = *s1++;
    while (*s2 != '\0' && *s2 != '\n')
        *tmp_s3++ = *s2++;
    *tmp_s3 = '\0';
    return (s3);
}
char *ft_strdup(char *s1)
{
    char *str;
    int   i;
    int   j;

    i = 0;
    j = 0;
    while (s1[j])
        j++;
    if (!(str = malloc(j + 1)))
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (char *)(str);
}
size_t  ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
