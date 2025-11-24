/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:27:20 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/24 15:15:02 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

/* ______________________DEFINES_____________________*/
# define FT_PRINTF_H

/* ______________________INCLUDES_____________________*/
# include <stdarg.h>
# include <unistd.h>

/* ______________________FUNCTIONS_____________________*/
size_t			ft_putstr_fd(char *s, int fd);
size_t			ft_putchar_fd(char c, int fd);
size_t			ft_puthex_ptr_fd(size_t num, int fd);
size_t			ft_putnbr_fd(int n, int fd);
size_t			ft_putunsignd_fd(unsigned int n, int fd);
size_t			ft_puthex_dec_fd(size_t num, int fd, int sig);

/*hm*/
int				ft_printf(const char *s, ...);

#endif