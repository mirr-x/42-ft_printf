/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molahrac <molahrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 06:27:20 by molahrac          #+#    #+#             */
/*   Updated: 2025/11/27 21:56:23 by molahrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

/* ______________________DEFINES_____________________*/
# define FT_PRINTF_BONUS_H

/* ______________________INCLUDES_____________________*/
# include <stdarg.h>
# include <unistd.h>

/*_______________________STRUCTERS____________________*/
typedef struct s_flags_bonus
{
	int	hashtag;
	int	plus;
	int	space;
}	t_flags_bonus;

/* ______________________FUNCTIONS_____________________*/
size_t			ft_putstr_fd(char *s, int fd);
size_t			ft_putchar_fd(char c, int fd);
size_t			ft_puthex_ptr_fd(size_t num, int fd);
size_t			ft_putnbr_fd(int n, int fd, t_flags_bonus *flag);
size_t			ft_putunsignd_fd(unsigned int n, int fd);
size_t			ft_puthex_dec_fd(unsigned int num, int fd, int sig, \
								t_flags_bonus *flags);
int				ft_printf(const char *s, ...);

#endif