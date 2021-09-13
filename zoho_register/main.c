#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include<conio.h>

MYSQL *conn;

int loop = 0;
char temp[1000],temp1[1000], temp2[1000];
char *server = "localhost"; //check me first
char *user = "root";
char *password = "123321";
char *database = "zohoregister";

struct userdata{
    char userid[10];
    char name[20];
    char username[40];
    char password[100];
    char email[100];
    char number[20];
};

void enpass(struct userdata* data)
{
    char ch;
    int pos = 0;

    loop = 0;
    pos = 0;
    printf("\n\t\t Enter Password : ");
    while(1)
    {
        if(pos == 100)
        {
            temp[pos] = '\0';
            printf("\n\t Password out of bound only 100 characters will be taken as consideration");
            break;
        }
        ch = getch();
        if(ch == 13)
        {
            if(pos == 0)
                {
                    printf("\n\tPassword Field is empty");
                    getch();
                    break;
                }
            else
                {
                    temp[pos]= '\0';
                    break;
                }
        }
        else if(ch == 8)
        {
            if(pos > 0)
                {
                    printf("\b \b");
                    pos--;
                }
        }
        else
        {
            temp[pos] = ch;
            printf("*");
            pos++;
        }
    }
    strcpy(data->password,temp);

}
int pass(char *id)
{
    struct userdata data;
    MYSQL_RES *res;
    MYSQL_ROW row;
    system("CLS");
    printf("ZOHO REGISTER");
    printf("\n\n\t\t Confirm its you \n");
    enpass(&data);
    strcpy(temp,"select user_id from userdata where user_id = '");
    strcat(temp,id);
    strcat(temp,"' AND _password = '");
    strcat(temp,data.password);
    strcat(temp,"'");

    if(mysql_query(conn,temp))
    {
        fprintf(stderr,"%s \n",mysql_error(conn));
        exit(1);
    }
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);

    if(row == NULL)
    {
        printf("\n\n\t\t wrong password");
        getch();
        return 0;
    }
    else
    {
        return 1;
    }

}

void search()
{
    mysql_close(conn);
    dbcreate_connect();
    MYSQL_RES *res;
    MYSQL_ROW row;
    char string[40];
    system("CLS");
    printf("ZOHO REGISTER ");
    printf("\n\n\t\t search peoples : ");
    scanf(" %s",string);
    strcpy(temp,"select username from userdata where username like '%");
    strcat(temp,string);
    strcat(temp,"%'");
    if(mysql_query(conn,temp))
    {
        fprintf(stderr,"%s \n",mysql_error(conn));
    }
    res = mysql_use_result(conn);
    row = mysql_fetch_row(res);

    if(row == NULL)
    {
        printf("\n\n\t\t\t no users found");
    }
    else
    {
        printf("\n\n\t\t\t %s ",row[0]);
        while( (row = mysql_fetch_row(res))!= NULL )
        {
            printf("\n\n\t\t\t %s ",row[0]);
        }
    }

    getch();
}

void printprof(char* id)
{

    mysql_close(conn);
    dbcreate_connect();

    MYSQL_RES *res;
    MYSQL_ROW row;
    //printf(" id = %s",id);
    strcpy(temp,"select * from userdata where user_id =");
    strcat(temp,id);
    if (mysql_query(conn, temp)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	res = mysql_use_result(conn);
    row = mysql_fetch_row(res);
	printf("My profile :\n");
    printf("\n\t   user ID = %s \n", row[0]);
    printf("\n\t1. name = %s \n", row[1]);
    printf("\n\t2. username = %s \n", row[2]);
    printf("\n\t3. password = ***** \n", row[3]);
    printf("\n\t4. email = %s \n", row[4]);
    printf("\n\t5. number = %s \n", row[5]);
	/* close connection */
	mysql_free_result(res);
}

void signin(char* id)
{

    int oper,dec;
    do
    {
      loop = 0;
      system("CLS");
      printf("ZOHO REGISTER ");
      printf("\n\n\t\t 1. Take a Note \n\n\t\t 2. my notes \n\n\t\t 3. my profile \n\n\t\t 4. search users \n\n\t\t 5. edit profile \n\n\t\t 6. log out \n\n\t\t\t");
      scanf("%d",&oper);

      switch(oper)
      {
      case 1:
          system("CLS");
          printf("\n\n\n\t\t\t this feature is under developement");
          getch();
          loop = 1;
        break;
      case 2:
          system("CLS");
          printf("\n\n\n\t\t\t this feature is under developement");
          getch();
          loop = 1;
        break;
      case 3:
          system("CLS");
          printprof(id);
          getch();
          loop = 1;
        break;
      case 4:
          search();
        loop = 1;
        break;
      case 5:
          if(pass(id))
          {
            system("CLS");
            printprof(id);
            printf("\n\n\t\t Enter corresponding number to edit the value : ");
            scanf("%d",&dec);
            changeval(dec,id);
          }
        loop = 1;
        break;
      case 6:
        break;
      }
    }while(loop);



}

int check(int dec, char* string)
{
    MYSQL_RES *res;
    MYSQL_ROW row;

    int i=0,at = 0 ,ch=0;
    switch(dec)
    {
    case 1:
        strcpy(temp1,string);
         while(temp1[i] != '\0')
         {
            if ((temp1[i] >= 65 && temp1[i] <= 90) || (temp1[i] >= 97 && temp1[i] <= 122) || temp1[i] == 32 )
            {
                i++;
                continue;
            }
            else
            {
                printf("\n\t\t Name should not contain numbers or special characters!!!\n\t\t\t press any key to try again ... \n");
                getch();
                return 1;
            }

         }
         return 0;
    case 2:
         strcpy(temp1,string);
         strcpy(temp,"select username from userdata where username = '");
         strcat(temp,string);
         strcat(temp,"'");
         if(mysql_query(conn,temp))
         {
             fprintf(stderr, "%s\n", mysql_error(conn));
         }
         res = mysql_use_result(conn);
         row = mysql_fetch_row(res);
         //printf("\n res = %s row = %s ",res,row[0]);
         //printf(" row[0] = %d",row);
         if(row != NULL)
         {
             printf("\n\t\t This username is already taken !!!\n\t\t\t press any key to try again ... \n");
             getch();
             return 1;
         }
         while(i<strlen(temp1))
         {
            if(temp1[i] == 32 || temp1[i] == 37)
            {
                printf("\n\t\t User name should not contain spaces and special character (eg. %)!!!\n\t\t\t press any key to try again ... \n");
                getch();
                return 1;
            }
            if((temp1[i]>=65 && temp1[i] <= 90) || (temp1[i]>= 97 && temp1[i] <= 122) )
               {
                   ch++;
               }
                i++;
         }
         if(ch <= 0)
         {
            printf("\n\t\t username should contain at least one alphabet \n");
            getch();
            return 1;
         }
         return 0;
    case 3:
        return 0;
    case 4:
        strcpy(temp1,string);
         strcpy(temp,"select email from userdata where email = '");
         strcat(temp,string);
         strcat(temp,"'");
         if(mysql_query(conn,temp))
         {
             fprintf(stderr, "%s\n", mysql_error(conn));
         }
         res = mysql_use_result(conn);
         row = mysql_fetch_row(res);
         if(row != NULL)
         {
             printf("\n\t\t This E-mail is already taken !!!\n\t\t\t press any key to try again ... \n");
             getch();
             return 1;
         }
         while(i<strlen(temp1))
         {
            if(temp1[0]=='@')
            {
                printf("\n\t\t Invalid E-mail Address");
                return 1;
            }
            else if((temp1[i] >= 0 &&temp1[i] <= 45 ) || (temp1[i] >= 58 && temp1[i] <= 63 ) || (temp1[i] >= 91 &&temp1[i] <= 96 ) || (temp1[i] >= 123 &&temp1[i] <= 127 ) || temp1[i] == 47 )
            {
                printf("\n\t\t E-mail should not contain spaces and special character other than '@' !!!\n\t\t\t press any key to try again ... \n");
                getch();
                return 1;
            }
            else if(temp1[i] == '@')
            {
                at++;
                i++;
            }
            else if(temp1[i]=='.')
            {
                while (temp1[i+ch+1]!='\0')
                {
                   // printf("yo ");
                    ch++;
                }
                i++;
            }
            else
            {
                i++;
            }

         }
        // printf("\n at = %d ch = %d ",at,ch);
         if(at == 1 && ch <= 1 )
         {
             printf("\n\t Invalid E-mail address");
             getch();
             return 1;
         }
         mysql_free_result(res);
         return 0;
    case 5:
         strcpy(temp1,string);
         strcpy(temp,"select _number from userdata where _number = '");
         strcat(temp,string);
         strcat(temp,"'");
         if(mysql_query(conn,temp))
         {
             fprintf(stderr, "%s\n", mysql_error(conn));
         }
         res = mysql_use_result(conn);
         row = mysql_fetch_row(res);
         if(row != NULL)
         {
             printf("\n\t\t This number is already taken !!!\n\t\t\t press any key to try again ... \n");
             getch();
             return 1;
         }
         while(i<strlen(temp1))
         {
            if (!(temp1[i] >= 48 && temp1[i] <= 57))
            {
                printf("\n\t\t Should only contain number (eg. %)!!!\n\t\t\t press any key to try again ... \n");
                getch();
                return 1;
            }
                i++;
         }
         return 0;
    default:
        system("CLS");
        printf("\n\n\n\n \t\t\t error 01 : please contact Admin ...");
        getch();
        return 2;
    }
    return 2;
}

void getpass(struct userdata* data)
{

    char ch;
    int pos = 0;
    do{
            loop = 0;
            pos = 0;
            printf("\n\t Enter your New Password : ");
            while(1)
            {
                if(pos == 100)
                {
                    temp[pos] = '\0';
                    printf("\n\t Password out of bound only 100 characters will be taken as consideration");
                    break;
                }
                ch = getch();
                if(ch == 13)
                {
                    if(pos == 0)
                    {
                        printf("\n\tPassword Field is empty");
                        printf("\n\t Enter your New Password : ");
                    }
                    else
                    {
                        temp[pos]= '\0';
                        break;
                    }

                }
                else if(ch == 8)
                {
                    if(pos > 0)
                    {
                        printf("\b \b");
                        pos--;
                    }
                }
                else
                {
                    temp[pos] = ch;
                    printf("*");
                    pos++;
                }
            }
            printf("\n\n\t Enter your Password again : ");
            pos = 0;
            while(1)
            {
                if(pos == 100)
                {
                    temp1[pos] = '\0';
                    printf("\n\t Password out of bound only 100 characters will be taken as consideration");
                    break;
                }
                ch = getch();
                if(ch == 13)
                {
                        temp1[pos]= '\0';
                        break;
                }
                else if(ch == 8)
                {
                    if(pos > 0)
                    {
                        printf("\b \b");
                        pos--;
                    }
                }
                else
                {
                    temp1[pos] = ch;
                    printf("*");
                    pos++;
                }
            }
            if(strcmp(temp,temp1)!=0)
            {
                loop = 1;
                printf("\n\t\t password did not match \n\t\t press any key to try again ...");
                getch();
            }
            else
            {
                loop = 0;
                strcpy(data->password,temp);
            }
    }while(loop);

}

void changeval(int dec, char id[])
{

    system("CLS");
    printf("ZOHO REGISTER ");
    struct userdata data;
    switch(dec)
    {
    case 1:
        printf("\n\n\t\t Enter the name : ");
        scanf(" %[^\n]s",data.name);
        if(check(dec,data.name) == 0)
        {
            strcpy(temp,"update userdata set _name ='");
            strcat(temp,data.name);
            strcat(temp,"' where user_id = ");
            strcat(temp,id);
            if (mysql_query(conn,temp ))
            {
            fprintf(stderr, "%s\n", mysql_error(conn));
            exit(1);
            }
            system("CLS");
            printf("\n\n\n\t\t\t changes saved !!!...");
            getch();
        }
        else
        {
            getch();
        }
        break;
    case 2:
        printf("\n\n\t\t Enter the new username : ");
        scanf(" %[^\n]s",data.username);
        if(check(dec,data.username) == 0)
        {
            strcpy(temp,"UPDATE userdata SET username ='");
            strcat(temp,data.username);
            strcat(temp,"' where user_id = ");
            strcat(temp,id);
            //printf("\n temp = %s id  = %s \n",temp, id);
            if (mysql_query(conn,temp ))
            {
                fprintf(stderr, "%s\n", mysql_error(conn));
                exit(1);
            }
            system("CLS");
            printf("\n\n\n\t\t\t changes saved !!!...");
            getch();
        }
        else
            getch();
        break;
    case 3:
        getpass(&data);
        strcpy(temp,"update userdata set _password ='");
        strcat(temp,data.password);
        strcat(temp,"' where user_id = ");
        strcat(temp,id);
        if (mysql_query(conn,temp ))
        {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
        }
        system("CLS");
        printf("\n\n\n\t\t\t changes saved !!!...");
        getch();
        system("CLS");
        printf("\n\n\n\t\t\t YOU WILL BE LOGGED YOU PLEASE LOG IN WITH YOU NEW PASSWORD \n\n\t\t\t press any key to continue");
        getch();
        main();
        break;
    case 4:
        printf("\n\n\t\t Enter the email : ");
        scanf(" %s",data.email);
        if(check(dec,data.email) == 0)
        {
           strcpy(temp,"update userdata set _name ='");
           strcat(temp,data.email);
           strcat(temp,"' where user_id = ");
           strcat(temp,id);
           if (mysql_query(conn,temp ))
           {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
           }
           system("CLS");
            printf("\n\n\n\t\t\t changes saved !!!...");
            getch();
        }
        else
        {
            getch();
        }
        break;
    case 5:
        printf("\n\n\t\t Enter the number : ");
        scanf(" %s",data.number);
        if(check(dec,data.number) == 0)
        {
           strcpy(temp,"update userdata set _name ='");
           strcat(temp,data.number);
           strcat(temp,"' where user_id = ");
           strcat(temp,id);
           if (mysql_query(conn,temp ))
           {
              fprintf(stderr, "%s\n", mysql_error(conn));
              exit(1);
           }
           system("CLS");
            printf("\n\n\n\t\t\t changes saved !!!...");
            getch();
        }
        else
            getch();
        break;
    default:
        system("CLS");
        printf("\n\n\n\t\t\t error 02 :  please contact Admin ");
    }


}

void credentialcheck(char* id, int dec)
{
    struct userdata data;

    MYSQL_RES *res;
    MYSQL_ROW row;

    do
    {
        loop = 0;
        system("CLS");
        printf("ZOHO REGISTER");
        printf("\n\n\t\t Enter username : ");
        scanf(" %s",data.username);
        enpass(&data);
        strcpy(temp,"select user_id from userdata where username = '");
        strcat(temp,data.username);
        strcat(temp,"' AND _password = '");
        strcat(temp,data.password);
        strcat(temp,"'");

        if(mysql_query(conn,temp))
        {
            fprintf(stderr,"%s \n",mysql_error(conn));
            exit(1);
        }
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);

        if(row == NULL)
        {
            mysql_free_result(res);
            printf("\n\n\t\t Invalid username or password ");
            printf("\n\n\t\t 1. try again \n\n\t\t 2. forgot username \n\n\t\t 3. forgot password \n\n\t\t 4. back \n\n\t\t");
            scanf("%d",&dec);
            switch(dec)
            {
            case 1:
                loop = 1;
                break;
            case 2:
            case 3:
                system("CLS");
                printf("ZOHO REGISTER");
                printf("\n\n\t\t\t user verification ");
                printf("\n\n\t\t please enter registered email : ");
                scanf("%s",data.email);
                strcpy(temp,"select user_id from userdata where email ='");
                strcat(temp,data.email);
                strcat(temp,"'");
                if (mysql_query(conn,temp))
                {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                    exit(1);
                }
                res = mysql_store_result(conn);
                row = mysql_fetch_row(res);
                printf("row  = %s row = %d ",row[0],row);

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
                    printf("\n temp2 = %s ",temp2);
                    changeval(dec,temp2);
                }
                loop = 1;
                break;
            case 4:
                main();
                break;
            default:
                printf("\n\n\t\t Invalid key");
                getch();
                loop = 1;
                break;
            }
        }
        else
        {
            strcpy(id,row[0]);
        }

    }while(loop);


}

int SignUp()
{
       struct userdata data;
       MYSQL_RES *res;
       MYSQL_ROW row;

       int i=0,at,ch=0;
       system("CLS");
       printf(" Welcome to ZOHO REGISTER");


       if (mysql_query(conn, "SELECT MAX(user_id) FROM userdata;"))  //getting userID start (will store maximum value of user id + 1)
       {
        fprintf(stderr, "%s\n", mysql_error(conn));
       }
       res = mysql_use_result(conn);
       row = mysql_fetch_row(res);
       at = atoi(row[0])+1;
       sprintf(data.userid,"%d",at);
       mysql_free_result(res);                    //getting userID end

       do           //getting full name of an user using scanset
       {
         loop = 0;
         i = 0;
         printf("\n\n\t Enter Your Full Name : ");
         scanf(" %[^\n]s",data.name);
         strcpy(temp1,data.name);
         while(temp1[i] != '\0')
         {
            if ((temp1[i] >= 65 && temp1[i] <= 90) || (temp1[i] >= 97 && temp1[i] <= 122) || temp1[i] == 32 )
            {
                i++;
                continue;
            }
            else
            {
                loop = 1 ;
                printf("\n\t\t Name should not contain numbers or special characters!!!\n\t\t\t press any key to try again ... \n");
                getch();
                break;
            }

         }
       }while(loop);                     //getting name end

       do                                         //getting User name of an user which should be unique and should not contain spaces or special character
       {
         i=0;
         loop = 0;
         printf("\n\t Enter Your  Username : ");
         scanf(" %[^\n]s",data.username);
         strcpy(temp1,data.username);
         strcpy(temp,"select username from userdata where username = '");
         strcat(temp,data.username);
         strcat(temp,"'");
         if(mysql_query(conn,temp))
         {
             fprintf(stderr, "%s\n", mysql_error(conn));
         }
         res = mysql_use_result(conn);
         row = mysql_fetch_row(res);
         //printf("\n res = %s row = %s ",res,row[0]);
         //printf(" row[0] = %d",row);
         if(row != NULL)
         {
             loop = 1;
             printf("\n\t\t This username is already taken !!!\n\t\t\t press any key to try again ... \n");
             getch();
             mysql_free_result(res);
         }
        // mysql_free_result(res);
         while(i<strlen(temp1))
         {
            if(temp1[i] == 32 || temp1[i] == 37)
            {
                loop = 1 ;
                printf("\n\t\t User name should not contain spaces and special character (eg. %)!!!\n\t\t\t press any key to try again ... \n");
                getch();
                break;
            }
            if((temp1[i]>=65 && temp1[i] <= 90) || (temp1[i]>= 97 && temp1[i] <= 122) )
               {
                   ch++;
               }
                i++;
         }
         if(ch <= 0)
         {
             loop = 1;
             printf("\n\t\t user should contain at least one alphabet \n");
         }
       }while(loop);
       mysql_free_result(res);                    //getting User name end

       getpass(&data);                    //getting password

       do                                         //getting email of an user which should be unique and should not contain spaces or special character
       {
         i=0,at = 0, ch = 0;
         loop = 0;
         printf("\n\n\t Enter Your E-mail : ");
         scanf(" %[^\n]s",data.email);
         strcpy(temp1,data.email);
         strcpy(temp,"select email from userdata where email = '");
         strcat(temp,data.email);
         strcat(temp,"'");
         if(mysql_query(conn,temp))
         {
             fprintf(stderr, "%s\n", mysql_error(conn));
         }
         res = mysql_use_result(conn);
         row = mysql_fetch_row(res);
         //printf("\n res = %s row = %s ",res,row[0]);
         //printf(" row[0] = %d",row);
         if(row != NULL)
         {
             loop = 1;
             printf("\n\t\t This E-mail is already taken !!!\n\t\t\t press any key to try again ... \n");
             getch();
             mysql_free_result(res);
         }
        // mysql_free_result(res);
         while(i<strlen(temp1))
         {
            if(temp1[0]=='@')
            {
                loop = 1;
                printf("\n\t\t Invalid E-mail Address");
                break;
            }
            else if((temp1[i] >= 0 &&temp1[i] <= 45 ) || (temp1[i] >= 58 && temp1[i] <= 63 ) || (temp1[i] >= 91 &&temp1[i] <= 96 ) || (temp1[i] >= 123 &&temp1[i] <= 127 ) || temp1[i] == 47 )
            {
                loop = 1 ;
                printf("\n\t\t E-mail should not contain spaces and special character other than '@' !!!\n\t\t\t press any key to try again ... \n");
                getch();
                break;
            }
            else if(temp1[i] == '@')
            {
                at++;
                i++;
            }
            else if(temp1[i]=='.')
            {
                while (temp1[i+ch+1]!='\0')
                {
                   // printf("yo ");
                    ch++;
                }
                i++;
            }
            else
            {
                i++;
            }

         }
        // printf("\n at = %d ch = %d ",at,ch);
         if(at != 1 || ch <= 1 )
         {
             loop =1;
             printf("\n\t Invalid E-mail address");
         }
       }while(loop);
       mysql_free_result(res);                //getting email end

       do                                         //getting number of an user which should be unique and should not contain spaces or special character
       {
         i=0;
         loop = 0;
         printf("\n\t Enter Your  Number : ");
         scanf(" %[^\n]s",data.number);
         strcpy(temp1,data.number);
         strcpy(temp,"select _number from userdata where _number = '");
         strcat(temp,data.number);
         strcat(temp,"'");
         if(mysql_query(conn,temp))
         {
             fprintf(stderr, "%s\n", mysql_error(conn));
         }
         res = mysql_use_result(conn);
         row = mysql_fetch_row(res);
         //printf("\n res = %s row = %s ",res,row[0]);
         //printf(" row[0] = %d",row);
         if(row != NULL)
         {
             loop = 1;
             printf("\n\t\t This number is already taken !!!\n\t\t\t press any key to try again ... \n");
             getch();
             mysql_free_result(res);
         }
        // mysql_free_result(res);
         while(i<strlen(temp1))
         {
            if (!(temp1[i] >= 48 && temp1[i] <= 57))
            {
                loop = 1 ;
                printf("\n\t\t Should only contain number (eg. %)!!!\n\t\t\t press any key to try again ... \n");
                getch();
                break;
            }
                i++;
         }
       }while(loop);
       mysql_free_result(res);                    //getting  number end

       strcpy(temp,"INSERT into userdata VALUES(");
       strcat(temp,data.userid);
       strcat(temp,",'");
       strcat(temp,data.name);
       strcat(temp,"','");
       strcat(temp,data.username);
       strcat(temp,"','");
       strcat(temp,data.password);
       strcat(temp,"','");
       strcat(temp,data.email);
       strcat(temp,"','");
       strcat(temp,data.number);
       strcat(temp,"')");

       //printf(" string = %s ",temp);
       if (mysql_query(conn,temp))
       {
        fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	   }
	   printf("\n\n\t\t press any key to save changes ...");
	   getch();
	   system("CLS");
       printf(" \n\n\t\t you have successfully registered \n\n\t\t Welcome to ZOHO REGISTER \n\n\t\t\t press any key to continue ...");
       getch();
       main();
}


void dbcreate_connect()   //will create a database  and table named zohoregister and userdata respectively if not exist and connect to it
{

    conn = mysql_init(NULL);
    if (conn == NULL)
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    if (mysql_real_connect(conn, server, user, password, NULL, 0, NULL, 0) == NULL)
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
    }

    if (mysql_query(conn, "CREATE DATABASE IF NOT EXISTS zohoregister"))
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
    }

    mysql_close(conn);
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
    }
    if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL)
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
    }

	if (mysql_query(conn, "create table if not exists userdata(user_id int, _name varchar(40), username varchar(40), _password varchar(100), email varchar(100), _number varchar(20), primary key(user_id));"))
    {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}

int main()
{
    dbcreate_connect();

    int oper = 0,dec = 0 ;
    char id[10];
    do
    {
        loop = 0;
        system("CLS");
        printf("ZOHO REGISTER \n");
        printf("\n\t 1. Sign-IN");
        printf("\n\t 2. Sign-UP");
        printf("\n\t 3. EXIT\n\t\t\t");
        scanf("%d",&oper);

        switch(oper)
        {
        case 1:
            credentialcheck(id,dec);
            signin(id);
            loop = 1;
            break;
        case 2:
            SignUp();
            break;
        case 3:
            exit(0);
            break;
        default:
            loop = 1;
            system("CLS");
            printf("\n\n\t\t you have entered wrong key \n\n\t\t\t press any key to continue ...");
            getch();
        }

    }while(loop);


}

