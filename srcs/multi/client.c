/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:44:28 by marandre          #+#    #+#             */
/*   Updated: 2019/12/11 21:16:40 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:18:00 by marandre          #+#    #+#             */
/*   Updated: 2019/12/11 19:43:56 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int     send_movement(t_cub3d *t, int bypass)
{
	struct sockaddr_in  servaddr;
	static t_other      other = {-1, -1};
	
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(t->port_other);
	servaddr.sin_addr.s_addr = inet_addr(t->address);
	if (!bypass && other.x_pos == t->x_pos && other.y_pos == t->y_pos)
		return (1);
	other.x_pos = t->x_pos;
	other.y_pos = t->y_pos;
	sendto(t->socketfd, &other, sizeof(t_other), 0,
		(const struct sockaddr *) &servaddr, sizeof(servaddr));
	return (1);
}