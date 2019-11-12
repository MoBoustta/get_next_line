#include "get_next_line.h"
size_t  ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len)
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
    //free_d_shit(&s);
    return (char *)(sub_str);
}
char*ft_strjoin(char *s1, char *s2)
{
    int     s1_len;
    int     s2_len;
    char    *new_alloc;
    int     i;

    i = 0;
    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen((char *)s1);
    s2_len = ft_strlen((char *)s2);
    if (!(new_alloc = malloc(s1_len + s2_len + 1)))
        return (NULL);
    while (s1[i])
    {
        new_alloc[i] = s1[i];
        i++;
    }
    while (i < s1_len + s2_len)
    {
        new_alloc[i] = s2[i - s1_len];
        i++;
    }
    free_d_shit(&s1);
    new_alloc[i] = '\0';
    return ((char *)new_alloc);
}
char *ft_strdup(char *s1)
{
    char *str;
    int   i;
    int   j;

    i = 0;
    j = 0;
    if (s1 == NULL)
        s1 = ft_strdup("");
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
    //free_d_shit(&s1);
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
