/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcano-mu <mcano-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:03:02 by mcano-mu          #+#    #+#             */
/*   Updated: 2024/03/07 12:10:52 by mcano-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FOPEN_MAX
#  define FOPEN_MAX 256
# endif

char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(const char *s);
char		*get_next_line(int fd);
char		*ft_read_fd(int fd, char *str);
char		*ft_get_line(char *buffer);
char		*ft_new_buffer(char *buffer);

#endif
