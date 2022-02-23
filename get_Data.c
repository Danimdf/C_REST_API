/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_Data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:13:12 by dmonteir          #+#    #+#             */
/*   Updated: 2021/08/22 13:02:37 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_api.h"

int get_Data (t_call *api)
{
	t_memory all_Data;
	t_userData parsing;

	all_Data.response = NULL;
	all_Data.size = 0;

	struct curl_slist *headers = NULL;

	char auth[90] = "Authorization: Bearer ";
	strcat(auth, ID_TOKEN);

	char url[100] = URL_USERS;
	strcat(&url[strlen(url)], api->user);
	curl_global_init(CURL_GLOBAL_DEFAULT);

	api->curl = curl_easy_init();

	if(api->curl)
	{
		curl_easy_setopt(api->curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(api->curl, CURLOPT_URL, url);
		curl_easy_setopt(api->curl, CURLOPT_FAILONERROR, 1L);
		headers = curl_slist_append(headers, auth);
		curl_easy_setopt(api->curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(api->curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(api->curl, CURLOPT_WRITEDATA, (void *)&all_Data);

		api->res = curl_easy_perform(api->curl);

		if(api->res == CURLE_HTTP_RETURNED_ERROR)
		{
			fprintf(stderr, "curl_easy_perform() failed, please enter a valid login: %s\n",curl_easy_strerror(api->res));
			exit(1);
		}
		curl_easy_cleanup(api->curl);
		parsing_Data(&all_Data, &parsing);
		labs_Populate(&parsing);
		free (all_Data.response);
	}
	return (0);
}


