/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:32:18 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/17 16:21:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FETCH_H
# define FETCH_H

# include <wchar.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <sys/types.h>

void	fetch(va_list ref, int n, int cast, void *ptr);

#endif
