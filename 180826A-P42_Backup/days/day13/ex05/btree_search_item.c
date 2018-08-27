/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:17:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/21 09:32:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *))
{
	void	*ptr;

	ptr = 0;
	if (!root || !cmpf)
		return (ptr);
	if (root->left && ptr == 0)
		ptr = btree_search_item(root->left, data_ref, cmpf);
	if (root->item && (*cmpf)(root->item, data_ref) == 0 && ptr == 0)
		ptr = root->item;
	if (root->right && ptr == 0)
		ptr = btree_search_item(root->right, data_ref, cmpf);
	return (ptr);
}
