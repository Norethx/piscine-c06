/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:02:16 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/04/03 19:25:46 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change_pointer(char **str1, char **str2);

int		ft_strcmp(char *str1, char *str2);

void	ft_sort_matrix(char **str, int value)
{
	int	i;

	i = 1;
	while (i < value - 1)
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
		{
			change_pointer(&str[i], &str[i + 1]);
			i = 1;
		}
		i++;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	change_pointer(char **str1, char **str2)
{
	char	*aux_ptr;

	aux_ptr = *str1;
	*str1 = *str2;
	*str2 = aux_ptr;
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (0);
	ft_sort_matrix(argv, argc);
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
}
