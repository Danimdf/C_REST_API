
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_Token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:12:48 by dmonteir          #+#    #+#             */
/*   Updated: 2021/08/19 15:13:38 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_api.h"
#include "mjson.h"

char *get_Token(t_call *api)
{
	struct memory		structToken;

	static const char	*postthis = POST;

	structToken.response = NULL;
	structToken.size = 0;

	api->curl = curl_easy_init();

	if (api->curl)
	{
		curl_easy_setopt(api->curl, CURLOPT_URL, URL_TOKEN);
		curl_easy_setopt(api->curl, CURLOPT_POSTFIELDS, postthis);
		curl_easy_setopt(api->curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(api->curl, CURLOPT_WRITEDATA, (void *)&structToken);

		api->res = curl_easy_perform(api->curl);
		mjson_get_string(structToken.response, strlen(structToken.response), "$.access_token", (char *)ID_TOKEN, 65);
		if(api->res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(api->res));
			exit(1);
		}
	}
	curl_easy_cleanup(api->curl);
	return (ID_TOKEN);
}
