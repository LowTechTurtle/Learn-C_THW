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
	int replaced_args = 0;
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
				replaced_args += 1;
				break;
			}
		}
	}
	check(replaced_args == template.MR_args, "The number of replaced argument is wrong");

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

	rv = apr_procattr_dir_set(attr, cmd -> dir);
	check(rv == APR_SUCCESS, "Failed to set root to %s", cmd -> dir);

	rv = apr_procattr_cmdtype_set(attr, APR_PROGRAM_PATH);
	check(rv == APR_SUCCESS, "Failed to set cmd type");

	rv = apr_proc_create(&newproc, cmd -> exe, cmd -> args, NULL, attr, p);
	check(rv == APR_SUCCESS, "Failed to run command");

	rv = apr_proc_wait(&newproc, cmd -> exit_code, &cmd -> exit_why, APR_WAIT);
	check(rv == APR_CHILD_DONE, "Failed to wait");

	check(cmd -> exit_code == 0, "%s exited badly", cmd -> exe);
	check(cmd -> exit_why == APR_PROC_EXIT, "%s was killed or crashed", cmd -> exe);

	return 0;

error:
	return -1;
}

Shell GIT_SH = { 
	.dir = "/tmp",
	.exe = "git",
	.args = {"git", "clone", "URL", "pkg-build", NULL},
	.MR_args = 1
};

Shell TAR_SH = {
	.dir = "/tmp/pkg-build",
	.exe = "tar",
	.args = {"tar", "-xzf", "FILE", "--strip-components", "1", NULL},
	.MR_args = 1
};

Shell CURL_SH = {
	.dir = "/tmp",
	.exe = "curl",
	.args = {"curl", "-L", "-o", "TARGET", "URL", NULL},
	.MR_args = 2
};

Shell CONFIGURE_SH = {
	.dir = "/tmp/pkg-build",
	.exe = "./configure",
	.args = {"configure", "OPTS", NULL},
	.MR_args = 1
	,
};

Shell MAKE_SH = {
	.exe = "make",
	.dir = "/tmp/pkg-build",
	.args = {"make", "OPTS", NULL},
	.MR_args = 1
};

Shell INSTALL_SH = {
	.exe = "sudo",
	.dir = "/tmp/pkg-build",
	.args = {"sudo", "make", "TARGET", NULL},
	.MR_args = 1
};
