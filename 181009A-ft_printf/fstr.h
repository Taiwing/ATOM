/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:55:25 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/29 20:55:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSTR_H
# define FSTR_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fstr
{
				int		len;
				char	*str;
}				t_fstr;

t_fstr			*initfstr(void);
void			putfstr(t_fstr *s);
void			delfstr(t_fstr **s);

#endif
