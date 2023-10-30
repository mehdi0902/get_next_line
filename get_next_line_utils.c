/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:57:23 by mben-abd          #+#    #+#             */
/*   Updated: 2023/10/27 21:21:46 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// la fonction found_newline va chercher 
// une nouvelle ligne dans la chainé en parametre

int	found_newline(t_list *stash)
{
	int		i;
	t_list	*actu;

	if (stash == NULL)
		return (0);
	actu = ft_lst_get_last(stash);
	i = 0;
	while (actu->content[i])
	{
		if (actu->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// cette fonction renvoie un pointeur vers 
// le dernier bout selectionné de notre stash

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*actu;

	actu = stash;
	while (actu && actu->next)
		actu = actu->next;
	return (actu);
}

// la fonction va calculer le nombre de char dans la ligne actuelle

void	generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

// fonction pour free la stash

void	free_stash(t_list *stash)
{
	t_list	*actu;
	t_list	*next;

	actu = stash;
	while (actu)
	{
		free(actu->content);
		next = actu->next;
		free(actu);
		actu = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
