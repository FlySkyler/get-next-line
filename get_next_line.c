/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:30:14 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/14 21:05:24 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_bzero(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        str[i] = 0;
        i++;
    }
}

int check_end_line(const char *str)
{
    size_t i;

    i = 0;
    while(str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

static size_t ft_strlcpy1(char *dest, const char *src, size_t size)
{
    size_t i;

    i = 0;
    if (!src || !dest)
        return (0);
    if (size == 0)
        return (ft_strlen(src));
    while (src[i] && (i < ( size - 1)))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}

static void ft_next_line(char *str)
{
    size_t i;
    size_t str_len;

    i = 0;
    while(str[i] != '\n' && str[i] != 0)
        i++;
    if (str[i] == '\n')
        i++;
    str_len = ft_strlen(str + i);
    ft_strlcpy1(str, str + i, str_len + 1);
    ft_bzero(str + str_len);
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1] = "\0";
    ssize_t bytes_read;
    char *str;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    str = ft_strdup(buf);
    if (!str)
        return (NULL);
    bytes_read = 1;
    while (bytes_read && check_end_line(buf) == 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read < 0)
            return (ft_bzero(buf), free(str), NULL);
        buf[bytes_read] = '\0';
        str = ft_strjoin(str, buf);
        if(!str)
            return (NULL);
    }
    ft_next_line(buf);
    if (str[0] == '\0')
        return (free(str), NULL);
    //ft_bzero(buf);
    return (str);
}


// #include <fcntl.h>
// int main(void)
// {
//     char *str;
//     int i = 0;
//     int fd = open("test.txt", O_RDONLY);
//     while((str = get_next_line(fd)) != NULL)
//     {
//         printf("ligne %d : %s",++i,str);
//         free(str);
//     }
//     close(fd);
//     return (0);
// }