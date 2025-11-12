/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:27:20 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/12 13:32:51 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

/* ______________________DEFINES_____________________*/
# define FT_PRINTF_H

/* ______________________INCLUDES_____________________*/
# include <stdarg.h>
# include <unistd.h>

// /* removeeeeeeeeeee me*/
// # include <stdio.h>

/* ______________________FUNCTIONS_____________________*/
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_puthex(size_t num, int fd);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);

#endif