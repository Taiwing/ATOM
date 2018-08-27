/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:20:33 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/21 09:20:48 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	l;
	int	r;

	l = root ? 1 : 0;
	if (root && root->left)
		l += btree_level_count(root->left);
	r = root ? 1 : 0;
	if (root && root->right)
		r += btree_level_count(root->right);
	return (l > r ? l : r);
}
