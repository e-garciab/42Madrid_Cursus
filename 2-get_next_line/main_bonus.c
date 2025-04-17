/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/04/02 14:38:56 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1, fd2, fd3, fd4, fd5, fd6, fd7;
    char *line;
    int line_counter;
    int eof_flags[7] = {0}; // Array para marcar si un archivo ha llegado a su fin

    // Abrir los archivos para leer
    fd1 = open("./txt/test.txt", O_RDONLY);
    fd2 = open("./txt/test2.txt", O_RDONLY);
    fd3 = open("./txt/test3.txt", O_RDONLY);
    fd4 = open("./txt/test4.txt", O_RDONLY);
    fd5 = open("./txt/test5.txt", O_RDONLY);
    fd6 = open("./txt/test6.txt", O_RDONLY);
    fd7 = open("./txt/test7.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1 || fd5 == -1 || fd6 == -1 || fd7 == -1)
    {
        printf("Error al abrir uno de los archivos.\n");
        return (1);
    }

    line_counter = 1;

    // Leer líneas de los archivos y mostrarlas
    while (1)
    {
        int all_eof = 1;  // Variable que marca si todos los archivos llegaron al final

        // Leer de cada archivo
        line = NULL;

        if (!eof_flags[0])
        {
            line = get_next_line(fd1);
            if (line == NULL) eof_flags[0] = 1;
            if (line) {
                printf("Archivo 1, Linea %d: %s", line_counter, line);
                free(line);
            }
        }

        if (!eof_flags[1])
        {
            line = get_next_line(fd2);
            if (line == NULL) eof_flags[1] = 1;
            if (line) {
                printf("Archivo 2, Linea %d: %s", line_counter, line);
                free(line);
            }
        }

        if (!eof_flags[2])
        {
            line = get_next_line(fd3);
            if (line == NULL) eof_flags[2] = 1;
            if (line) {
                printf("Archivo 3, Linea %d: %s", line_counter, line);
                free(line);
            }
        }

        if (!eof_flags[3])
        {
            line = get_next_line(fd4);
            if (line == NULL) eof_flags[3] = 1;
            if (line) {
                printf("Archivo 4, Linea %d: %s", line_counter, line);
                free(line);
            }
        }

        if (!eof_flags[4])
        {
            line = get_next_line(fd5);
            if (line == NULL) eof_flags[4] = 1;
            if (line) {
                printf("Archivo 5, Linea %d: %s", line_counter, line);
                free(line);
            }
        }

        if (!eof_flags[5])
        {
            line = get_next_line(fd6);
            if (line == NULL) eof_flags[5] = 1;
            if (line) {
                printf("Archivo 6, Linea %d: %s", line_counter, line);
                free(line);
            }
        }

        if (!eof_flags[6])
        {
            line = get_next_line(fd7);
            if (line == NULL) eof_flags[6] = 1;
            if (line) {
                printf("Archivo 7, Linea %d: %s", line_counter, line);
                free(line);
            }
        }

        // Comprobamos si todos los archivos han llegado a su fin
        for (int i = 0; i < 7; i++)
        {
            if (!eof_flags[i])
            {
                all_eof = 0;  // Si algún archivo aún tiene líneas para leer, seguimos
                break;
            }
        }

        // Si ya no hay más líneas en ningún archivo, salimos del bucle
        if (all_eof)
            break;

        line_counter++;
        printf("-----------------------\n");
    }
    
    // Cerrar los archivos
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
    close(fd6);
    close(fd7);

    return 0;
}
