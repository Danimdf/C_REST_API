#ifndef FT_API_H

# define FT_API_H

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "mjson.h"
#include <mysql/mysql.h>
# define URL_TOKEN "https://api.intra.42.fr/oauth/token"
# define URL_USERS "https://api.intra.42.fr/v2/users/"



typedef struct memory
{
	char *response;
	size_t size;
} t_memory;

typedef struct s_call
{
	CURL *curl;
	CURLcode res;
	char *user;
} t_call;

typedef struct userData
{
	struct json_object *usual_full_name;
	struct json_object *email;
	struct json_object *id;
	struct json_object *login;
	struct json_object *pool_month;
	struct json_object *pool_year;
	struct json_object *wallet;
	struct json_object *campus;
	struct json_object *idx;
	struct json_object *country;
} t_userData;

typedef struct Data
{
	char country[45];
	char name_c[30];
} t_Data;

char ID_TOKEN[65];

int	main (int argc , char **argv);
char *get_Token(t_call *api);
size_t write_callback(void *data, size_t size, size_t nmemb, void *userp);
int	get_Data (t_call *api);
void parsing_Data(t_memory *all_Data, t_userData *parsing);
void labs_Populate(t_userData *parsing);

#endif
