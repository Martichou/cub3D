/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:18:00 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 00:19:36 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

typedef u_long	ioctlarg_t;

int		socket_init(t_cub3d *t)
{
	int _true = 1;
	struct sockaddr_in servaddr;

	if ((t->socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
		return (0);
	if(ioctl(t->socketfd, FIONBIO, &_true) == -1)
		return (0);
	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(t->port);
	if (bind(t->socketfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0 )
		return (0);
	return (1);
}

#define MAXLINE 1024

int		socket_frame(t_cub3d *t)
{
	socklen_t			len;
	int					n;
	struct sockaddr_in	cliaddr;
	static t_other		o;
	static int			init = 0;
	
	memset(&cliaddr, 0, sizeof(cliaddr));
	len = sizeof(cliaddr);
	n = recvfrom(t->socketfd, &o, sizeof(t_other),
		0, (struct sockaddr*)&cliaddr, &len);
	if (n != -1)
	{
		if (!init){
			send_movement(t, 1);
			init++;
		}
		t->other = &o;
		return (0);
	}
	return (0);
}