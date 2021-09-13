#include <mysql.h>
#include <stdio.h>
main() {
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
	char *user = "root";
	char *password = "root"; /* set me first */
	char *database = "mysql";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server, user, password,
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	/* send SQL query */
	if (mysql_query(conn, "show tables")) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	res = mysql_use_result(conn);

	/* output table name */
	printf("MySQL Tables in mysql database:\n");

	while ((row = mysql_fetch_row(res)) != NULL)
		printf("%s \n", row[0]);

	/* close connection */
	mysql_free_result(res);
	mysql_close(conn);
}


    mysql_free_result(res);

    do
    {
            loop = 0;
            printf("\n\n\t\t Enter password : ");
            scanf("%s",data.password);
            strcpy(temp,"select user_id from userdata where username = '");
            strcat(temp,data.username);
            strcat(temp,"'");
            strcat(temp," AND _password = '");
            strcat(temp,data.password);
            strcat(temp,"'");
            //printf("\n temp = %s",temp);
            if (mysql_query(conn,temp))
            {
                fprintf(stderr, "%s\n", mysql_error(conn));
                exit(1);
            }
            res = mysql_use_result(conn);
            //printf("\n id = %s , row = %s, row[0] = %s",id,row,row[0]);
            row = mysql_fetch_row(res);

            strcpy(id,row[0]);

            if(row == NULL)
            {
                printf("\n\n\t\t invalid password ");
                printf("\n\n\t\t 1. try again \n\t\t 2. forgot password \n\t\t 3. back \n\t\t\t");
                scanf("%d",&dec);
                switch(dec)
                {
                case 1:
                    loop = 1;
                    break;
                case 2:
                        printf("\n\n\t\t Enter you email : ");
                        scanf("%s",data.email);
                        strcpy(temp,"select user_id from userdata where email ='");
                        strcat(temp,data.email);
                        strcat(temp,"'");
                        if (mysql_query(conn,temp))
                        {
                            fprintf(stderr, "%s\n", mysql_error(conn));
                            exit(1);
                        }
                        res = mysql_use_result(conn);
                        row = mysql_fetch_row(res);
                        if(row == NULL)
                        {
                            printf("\n\n\t\t Invalid email ");
                            getch();
                        }
                        else
                        {
                            strcpy(temp2,row[0]);
                            //printf("row = %s",temp1);
                            //getch();
                            changeval(3,temp2);
                        }
                        loop = 1;
                        break;
                case 3:
                        main();
                        break;
                default:
                        printf("\n\n\t\t wrong input ");
                        getch();
                        loop = 1;
                }
            }

    }while(loop);

