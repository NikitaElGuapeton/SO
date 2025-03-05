#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";   // Usuario de MySQL
	char *password = "mysql";   // Contraseña de MySQL 
	char *database = "carrera_caballos"; // Nombre de la base de datos
	
	// Inicializar conexion
	conn = mysql_init(NULL);
	if (conn == NULL) {
		fprintf(stderr, "Error al inicializar MySQL: %s\n", mysql_error(conn));
		exit(1);
	}
	// Conectar a MySQL
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "Error de conexion: %s\n", mysql_error(conn));
		exit(1);
	}
	
	// Consulta SQL
	if (mysql_query(conn, "SELECT id_partida, limite_edad FROM partidas")) {
		fprintf(stderr, "Error al hacer la consulta: %s\n", mysql_error(conn));
		exit(1);
	}
	
	// Obtener resultado
	res = mysql_store_result(conn);
	if (res == NULL) {
		fprintf(stderr, "Error al obtener resultado: %s\n", mysql_error(conn));
		exit(1);
	}
	
	// Mostrar los resultados
    printf("ID de Partida | Limite de Edad\n");
	printf("------------------------------\n");
	while ((row = mysql_fetch_row(res))) {
		printf("%s             | %s años\n", row[0], row[1]);
	}
	// Liberar memoria y cerrar conexion
	mysql_free_result(res);
	mysql_close(conn);
	
	return 0;
}


