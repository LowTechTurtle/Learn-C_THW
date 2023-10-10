#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<assert.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void Database_close(struct Connection *conn);

void die(const char *message, struct Connection *conn)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	if (!conn) {
		exit(1);
	} else {
		Database_close(conn);
		exit(1);
	}
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s \n", addr -> id, addr -> name, addr -> email);
}

//db load read information from a file to the db we create
void Database_load(struct Connection *conn)
{
	int rc = fread(conn -> db, sizeof(struct Database), 1, conn -> file);
	if (rc != 1) {
		die("Failed to load database", conn);
	}
}

//get memory from a heap to initiate the database, the content of the database is load from the file named filename
struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn) {
		die("Memory Error", conn);
	}
	conn -> db = malloc(sizeof(struct Database));
	if (!conn -> db) {
		die("Memory Erorr", conn);
	}

	if (mode == 'c') {
		conn -> file = fopen(filename, "w");
	} else {
		conn -> file = fopen(filename, "r+");
	
	if (conn -> file) {
		Database_load(conn);
		}
	}

	if (!conn->file) {
		die("Failed to open the file", conn);
	}
	return conn;
}

//free memory to prevent mem leak
void Database_close(struct Connection *conn)
{
	if (conn) {
		if (conn -> file) {
			fclose(conn -> file);
		}
		if (conn -> db) {
			free(conn -> db);
		}
		free(conn);
	}
}

//write the content of the database to the db file
//the uses of fflush is probably to write anything that's on the buffer, so that we dont miss anything in our file
void Database_write(struct Connection *conn)
{
	rewind(conn -> file);
	int rc = fwrite(conn -> db, sizeof(struct Database), 1, conn -> file);
	if (rc != 1) {
		die("Failed to write database", conn);
	}
	rc = fflush(conn -> file);
	if (rc == -1) {
		die("Cannot flush database", conn);
	}
}

//this simply create a database with their id equal to their indice in array and set = 0 - a lil convention in this file
void Database_create(struct Connection *conn)
{
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++) {
		struct Address addr = {.id = 1, .set =0};
		conn -> db -> rows[i] = addr;
	}
}

//simply write the name, email to the id in the database
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if (addr -> set) {
		die("Already set, delete it first", conn);
	}
	
	addr -> set = 1;

	//TODO: fix the bug
	if (strlen(name) >= MAX_DATA) {
		die("Too long name", conn);
	}
	char *res = strncpy(addr -> name, name, MAX_DATA);
	if (!res) {
		die("Name copy failed", conn);
	}
	
	if (strlen(email) >= MAX_DATA) 
		die("Too long email", conn);


	res = strncpy(addr -> email, email, MAX_DATA);
	if (!res) {
		die("Email copy failed", conn);
	}
}
//simply print out id, name, email in the database with the given id
void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];
	if (addr->set) {
		Address_print(addr);
	} else {
		die("ID is not set", conn);
	}
}

//called delete but it just update their status( set = 0) and remove name, email
//one way is just "copying structure prototypes"
void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

//print out everying in the database
void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn -> db;
	
	for (i = 0; i < MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];

		if (cur -> set) {
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		die("USAGE: ex17 <dbfile> <action> [Action params]", NULL);
	}

	char *filename = argv[1];
	char action = argv[2][0];
//get memory for datas, load data in
	struct Connection *conn = Database_open(filename, action);
	int id = 0;

	if (argc >3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records", conn);

	switch (action) {
		case 'c': 
			//create the database
			Database_create(conn);
			//update in the database file
			Database_write(conn);
			break;
		case 'g':
			if (argc != 4)
				die("Need an id to get", conn);

			Database_get(conn, id);
			break;

		case 's':
			if (argc != 6)
				die("Need id, name, email to set", conn);

			//set some vars and write into the database file
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;

		case 'd':
			if (argc != 4) 
				die("Need id to delete", conn);
			//delete and update database file
			Database_delete(conn, id);
			Database_write(conn);
			break;


		default:
			die("Invalid action: c = create, g = get, d = delete, l = list", conn);
	}

	//finally close file and free memory to prevent mem leak
	Database_close(conn);
	return 0;
}
