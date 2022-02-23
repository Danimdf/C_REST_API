/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42labs_Populate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonteir <dmonteir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:54:28 by dmonteir          #+#    #+#             */
/*   Updated: 2021/08/22 21:00:30 by dmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_api.h"


void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

void labs_Populate(t_userData *parsing)
{
	char query[200];
	char confirm[100];
	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "root", "dmonteir42",
		"42Labs", 8080, NULL, 0) == NULL)
		finish_with_error(con);


	//if (mysql_query(con, "CREATE TABLE User(id MEDIUMINT, Name VARCHAR(255), Login VARCHAR(255), Email VARCHAR(255), Pool_Month VARCHAR(255), Pool_Year MEDIUMINT, Wallet MEDIUMINT, Country VARCHAR(255));"))
		//finish_with_error(con);

	sprintf(confirm, "DELETE FROM User WHERE id = %d;", json_object_get_int(parsing->id));
	if (mysql_query(con, confirm))
		finish_with_error(con);

	sprintf(query, "INSERT INTO User VALUES(%d, '%s', '%s', '%s', '%s', %d, %d, '%s')", json_object_get_int(parsing->id), \
																json_object_get_string(parsing->usual_full_name), \
																json_object_get_string(parsing->login), \
																json_object_get_string(parsing->email), \
																json_object_get_string(parsing->pool_month), \
																json_object_get_int(parsing->pool_year), \
																json_object_get_int(parsing->wallet), \
																json_object_get_string(parsing->country));


	if (mysql_query(con, query))
		finish_with_error(con);

	mysql_close(con);
	exit(0);
}
