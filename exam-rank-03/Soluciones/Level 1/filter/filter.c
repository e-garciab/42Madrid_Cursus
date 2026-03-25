#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void ft_filter(char *buffer, const char *target)
{
    int i = 0;
    int target_len = strlen(target);
    int j, k;

    /*
     * ALGORITMO DE BÚSQUEDA Y REEMPLAZO:
     * - Recorrer el buffer carácter por carácter
     * - En cada posición, verificar si coincide con el patrón
     * - Si coincide, escribir asteriscos y saltar la longitud del patrón
     * - Si no coincide, escribir el carácter original
     */
    
    while (buffer[i])
    {
        j = 0;
        // Verificar si hay coincidencia desde la posición actual
        while (target[j] && (buffer[i + j] == target[j]))
            j++;
        
        if (j == target_len) // Coincidencia completa encontrada
        {
            // Escribir asteriscos en lugar del patrón
            k = 0;
            while (k < target_len)
            {
                write(1, "*", 1);
                k++;
            }
            i += target_len; // Saltar el patrón completo
        }
        else
        {
            // No hay coincidencia, escribir carácter original
            write(1, &buffer[i], 1);
            i++;
        }
    }
}


int	main(int argc, char **argv)
{
	char	temp[BUFFER_SIZE];
	char	*result; //es el buffer acumulado final, crece cada iteración
	char	*tmp; // es un guardián solo para no perder result si realloc falla. 
	ssize_t	bytes;
	size_t	total;

	if (argc != 2 || argv[1][0] == '\0')
		return (1);
	result = NULL;
	total = 0;
	while ((bytes = read(0, temp, BUFFER_SIZE)) > 0)
	{
		tmp = realloc(result, total + bytes);
		if (!tmp)
		{
			free(result);
			perror("Error");
			return (1);
		}
		result = tmp;
		memmove(result + total, temp, bytes); //memove copia bytes de un sitio a otro (memove(destino, origen, cuantos bytes))
		total += bytes;
        result[total] = '\0';
	}
	if (bytes < 0) //error de lectura
	{
		free(result);
        perror("Error");
        return (1);
	}
	if (!result) //no se leyó nada (stdin vacío)
		return (0);
	ft_filter(result, argv[1]);
	free(result);
	return (0);
}