#include "shell.h"
#include "dbg.h"
#include<stdarg.h>

int Shell_exec(Shell template, ...)
{
	apr_pool_t *p = NULL;
	int rc = -1;
	apr_status_t = APR_SUCCESS;
	va_list argp;
	const char* key = NULL;
	const char* arg = NULL;
	int i = 0;

	rv = apr_pool_create(&p, NULL);

	check(rv == APR_SUCCESS, "FAILED to create pool.");

	va_start(argp, template);

	for (key = va_arg(argp, const char*);
			key != NULL; key = va_arg(argp, const char*)) {
		arg = va_arg(argp, const char*);

		for (i = 0; template.args[i] != NULL; i++) {
			if (strcmp(template.args[i], key) == 0) {
				template.args[i] = args;
				break;
			}
		}
	}

	rc = Shell_run(p, &template);
	apr_pool_destroy(p);
	va_end(p);
	return rc;

error:
	if (p) {
		apr_pool_destroy(p);
	}
	return rc;
}

int Shell_run(apr_pool_t *p, Shell *cmd)
{
	apr_procattr_t* attr;
	apr_status_t rv;
	apr_proc_t newproc;

	rv = apr_procattr_create(&attr, p);
	check(rv == APR_SUCCESS, "Failed to create proc attr");

	rv = apr_procattr_io_set(attr, APR_NO_PIPE, APR_NO_PIPE, APR_NO_PIPE);
	check(rv == APR_SUCCESS, "Failed to set IO of command");
