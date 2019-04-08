/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 01:47:34 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/17 23:33:09 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <unistd.h>

# define CLRSCR() write(1, "\033[H\033[2J", 3)

# define LBLACK    "\033[1;30m", 7
# define LRED      "\033[1;31m", 7
# define LGREEN    "\033[1;32m", 7
# define LYELLOW   "\033[1;33m", 7
# define LBLUE     "\033[1;34m", 7
# define LPURPLE   "\033[1;35m", 7
# define LCYAN     "\033[1;36m", 7
# define LGREY     "\033[1;37m", 7

# define BBLACK    "\033[0;30m", 7
# define BRED      "\033[0;31m", 7
# define BGREEN    "\033[0;32m", 7
# define BYELLOW   "\033[0;33m", 7
# define BBLUE     "\033[0;34m", 7
# define BPURPLE   "\033[0;35m", 7
# define BCYAN     "\033[0;36m", 7
# define BGREY     "\033[0;37m", 7

# define NO_COLOR "\033[0;m"

#endif
