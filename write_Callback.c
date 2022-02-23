/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_Callback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:59:59 by dmonteir          #+#    #+#             */
/*   Updated: 2021/08/21 16:40:45 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_api.h"

size_t write_callback(void *data, size_t size, size_t nmemb, void *userp)
{
	size_t realsize = size * nmemb;
	struct memory *mem = (struct memory *)userp;

	char *ptr = realloc(mem->response, mem->size + realsize + 1);
	if(ptr == NULL)
		return 0;

	mem->response = ptr;
	memcpy(&(mem->response[mem->size]), data, realsize);
	mem->size += realsize;
	mem->response[mem->size] = 0;

	return realsize;
}
