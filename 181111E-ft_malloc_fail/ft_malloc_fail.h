/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_fail.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 23:04:28 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/11 23:18:29 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_FAIL_H
# define FT_MALLOC_FAIL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void	*ft_malloc_fail(size_t size);

#endif
