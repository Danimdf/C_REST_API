/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_Data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 00:56:22 by dmonteir          #+#    #+#             */
/*   Updated: 2021/08/22 21:18:07 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <json-c/json.h>
#include "ft_api.h"

void parsing_Data(t_memory *all_Data, t_userData *parsing)
{
	t_Data data;

	struct	json_object *parsed_json;
	int counter = 0;
	data.country[29] = '\0';

	parsed_json = json_tokener_parse(all_Data->response);

	json_object_object_get_ex(parsed_json, "id", &parsing->id);
	json_object_object_get_ex(parsed_json, "usual_full_name", &parsing->usual_full_name);
	json_object_object_get_ex(parsed_json, "email", &parsing->email);
	json_object_object_get_ex(parsed_json, "login", &parsing->login);
	json_object_object_get_ex(parsed_json, "pool_month", &parsing->pool_month);
	json_object_object_get_ex(parsed_json, "pool_year", &parsing->pool_year);
	json_object_object_get_ex(parsed_json, "wallet", &parsing->wallet);


	json_object_object_get_ex(parsed_json, "campus", &parsing->campus);
	parsing->idx = json_object_array_get_idx(parsing->campus, counter);
	json_object_object_get_ex(parsing->idx, "country", &parsing->country);

	memcpy(data.country, (void *)json_object_get_string(parsing->country), strlen(json_object_get_string(parsing->country))+1);

}
