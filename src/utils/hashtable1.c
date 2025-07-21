/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:16:52 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/17 16:17:05 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hashlist	*hashlist_new(char *key, int value)
{
	t_hashlist	*new;

	new = malloc(sizeof(t_hashlist));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->key = ft_strdup(key);
	if (!new->key)
	{
		free(new);
		return (NULL);
	}
	new->value = value;
	return (new);
}

void	hashlist_addfront(t_hashlist **lst, t_hashlist *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	hashlist_addback(t_hashlist **lst, t_hashlist *new)
{
	t_hashlist	*temp;

	if (!(*lst))
	{
		hashlist_addfront(lst, new);
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

static void	hashlist_clearnodes(t_hashlist **lst)
{
	if (*lst)
	{
		hashlist_clearnodes(&(*lst)->next);
		if ((*lst)->key)
			free((*lst)->key);
		free(*lst);
		*lst = NULL;
	}
}

void	hashlist_clear(t_hashlist **lst)
{
	if (lst)
		hashlist_clearnodes(lst);
	free(lst);
	lst = NULL;
}
