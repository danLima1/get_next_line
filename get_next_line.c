/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-lima <dde-lima@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:55:04 by dde-lima          #+#    #+#             */
/*   Updated: 2024/11/12 18:17:02 by dde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *remove_line(char *backup)
{
	char *new_backup;
	int i;
	int j;

	i = 0;
	j = 0;
	while(backup[i] && backup[i] != '\n')
		i++;
	if(!backup[i])
	{
		free(backup);
		return (NULL);
	}
	new_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if(!new_backup)
		return (NULL);
	i++;
	while(backup[i])
		new_backup[j++] = backup[i++];
	free(backup);
	new_backup[j] = '\0';
	return (new_backup);
}

static char *get_line(char *backup)
{
	int i;
	char *line;

	if (!*backup)
		return (NULL);
	i = 0;
	while (backup[i] != '\0' &&  backup[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i++;
	ft_strlcpy(line, backup, i + 1);
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return(line);
}

static char *read_file(int fd, char *backup)
{
	char *buffer;
	int bytes_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(backup, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free (buffer);
	if(bytes_read < 0)
		return (NULL);
	else
		return (backup);
}

char *get_next_line(int fd)
{
	static char *backup = NULL;
	char *line;
	if (fd < 0  || BUFFER_SIZE < 1)
		return (NULL);
	backup = read_file(fd, backup);
	if(!backup)
		return (NULL);
	line = get_line(backup);
	backup = remove_line(backup);
	return (line);
}


// #include <stdio.h>
// int main(void)
// {
// 	int fd;
// 	char *line;


// 	fd = open("file.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Erro ao abrir o arquivo");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Linha: %s", line);
// 		free(line);
// 	}
// 	return (0);
// }

