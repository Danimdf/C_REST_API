/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:44:37 by dmonteir          #+#    #+#             */
/*   Updated: 2021/08/22 17:25:07 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_api.h"

int main(int argc , char **argv)
{
	t_call	api;

	if(argc != 2)
	{
		printf("Error! Add only ./ and user login\n");
		exit(1);
	}

	curl_global_init(CURL_GLOBAL_DEFAULT);

	api.user= argv[1];
	api.curl = curl_easy_init();
	if (api.curl)
	{
		get_Token(&api);
		get_Data(&api);
	}
	curl_easy_cleanup(api.curl);
	curl_global_cleanup();
}
