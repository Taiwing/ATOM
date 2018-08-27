/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:21:12 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/21 09:35:02 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_get_level_size(t_btree *root, int level, int *size)
{
	if (level == 0)
		(*size)++;
	else if (level > 0)
	{
		if (root->left)
			ft_get_level_size(root->left, level - 1, size);
		if (root->right)
			ft_get_level_size(root->right, level - 1, size);
	}
}

void	ft_get_level_items(t_btree *root, int level, void **tab, int *pos)
{
	if (level == 0)
		tab[(*pos)++] = root->item;
	else if (level > 0)
	{
		if (root->left)
			ft_get_level_items(root->left, level - 1, tab, pos);
		if (root->right)
			ft_get_level_items(root->right, level - 1, tab, pos);
	}
}

void	**ft_get_level(t_btree *root, int level, int *size)
{
	int		pos;
	void	**tab;

	pos = 0;
	ft_get_level_size(root, level, size);
	if ((*size) != 0)
	{
		tab = (void **)malloc(sizeof(void *) * (*size));
		ft_get_level_items(root, level, tab, &pos);
		return (tab);
	}
	return (0);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
		int current_level, int is_first_elem))
{
	int		i;
	int		curlvl;
	int		lvlsize;
	void	**level;

	if (!root || !applyf)
		return ;
	curlvl = 0;
	lvlsize = 0;
	level = ft_get_level(root, curlvl, &lvlsize);
	while (level)
	{
		i = -1;
		while (++i < lvlsize)
			(*applyf)(level[i], curlvl, !i);
		free(level);
		lvlsize = 0;
		level = ft_get_level(root, ++curlvl, &lvlsize);
	}
}
