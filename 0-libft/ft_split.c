/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:55:05 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/04 17:43:34 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words (const char *s, char c)
{
	int	i;// contador de letras
	int	z; // contador de palabras
	int	in_word;
	
	i = 0;
	z = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] !=  c)
		{
			if (in_word == 0)	
			{	
				z++;
				in_word = 1;
			}
		}
		else 
			(in_word = 0);
		i++;
	}
	return (z);
}

int	ft_count_letters (const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (s[i] != c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char **index;
	char *dest;
	int	len_words;
	int len_letters;
	int	i; // contador para free
	int j; // contador para index
	int z; // contador para dest

	i = 0;
	j = 0;
	z = 0;
	len_words = ft_count_words (s,c);
	//printf("%i\n", len);
	index = malloc ((len_words + 1) * sizeof(char*));
	if (!index)
		return (NULL);
	
	while (j < len_words)
	{
		while(s[z] == c)
			z++;
		while (s[z] != '\0' && s[z] != c)
		{
			len_letters = ft_count_letters(&s[z], c);
			//printf("%i\n", len_letters);
			dest = malloc((len_letters + 1) * sizeof(char));
			if (!dest)
			{
				index[j] = NULL;
				while (index[i] != NULL)
				{
					free(index[i]);
				}
				free(index);
				return (NULL);
			}
			ft_strlcpy (dest, &s[z], len_letters + 1);
			index[j] = dest;
			// printf("%s\n", dest);
			z += len_letters;
		}
		j++;
	}
	index[j] = NULL;
	return (index);
}

// int	main(void)
// {
// 	const char *s = "hola mundo ideal";
// 	char c = ' ';
// 	char **new = ft_split(s, c);
// 	int i = 0;
// 	while (new[i])
// 	{
// 		printf("%s\n", new[i]);
// 		++i;
// 	}
// 	return (0);
// }



// int	main(void)
// {
// 	char *s = "hola como estas yo bien";

// 	printf("%d\n", ft_count_words(s));
// 	printf("%d\n", ft_count_letters(s));
// 	return (0);
// }

/*
	while (s[z] != '\0')
	{
		if (s[z] != c)
		{
			len_letters = ft_count_letters(s, c);
			dest = malloc((len_letters + 1) * sizeof(char));
			if (!dest)
			{
				index[j] = NULL;
				while (index[i] != NULL)
				{
					free(index[i]);
				}
				free(index);
				return (NULL);
			}
			ft_strlcpy (dest, s, len_letters);
			index[j] = dest;
			j++;
		}
		z += len_letters;
	}
	index[j] = NULL;
	return (index);
}
*/