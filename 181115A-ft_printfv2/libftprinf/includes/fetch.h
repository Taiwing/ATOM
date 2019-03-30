/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:24:38 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 10:24:41 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FETCH_H
# define FETCH_H
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <unistd.h>
# include "params.h"

void	fetch(va_list ref, int n, int cast, void *ptr);

#endif
