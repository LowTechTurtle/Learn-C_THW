#include<assert.h>
#include<ctype.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<apr-1/apr_fnmatch.h>
#include<apr-1/apr_uri.h>
#include<apr-1/apr_pools.h>
int main()
{
	const char* x = "*banana";
	const char* y = "super addictive banana";
	if (apr_fnmatch(x, y, 0) == APR_SUCCESS)
		printf("banana\n");

	apr_uri_t info;
	char url[1000];
	fgets(url, sizeof(url), stdin);
	apr_pool_initialize();
	apr_pool_t *p;
	apr_pool_create(&p, NULL);
	apr_uri_parse(p, url, &info);
	printf("info.scheme: %s\n info.path: %s\n info.query: %s\n", info.scheme, info.path, info.query);
	apr_pool_destroy(p);
	return 0;
}
