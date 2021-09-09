#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Author : kannan
//date   : 1-9-2021
// a program to demostrate the user-registration and log-in

int t = 0; //Global variable which stores no of users registered  

struct MyProfile    //list structure
{
	char Username[20];
	char Password[20];
	char name[20];
	char number[20];
	char email[20];	
	struct MyProfile* next; 	
};
void PrintProfile(struct MyProfile *prof) //will print the given list pointer 
{
	system("CLS");
	
	printf("\nName : %s",prof->name);
	printf("\nUsername : %s",prof->Username);
	printf("\nPassword : ********",prof->Password);
	printf("\nEmail : %s",prof->email);
	printf("\nNumber : %s\n\n",prof->number);
	puts("\t\t\tPress any key to continue...");
	getch();
}	

struct MyProfile* finalnodefinder(struct MyProfile* head) //will return the final node pointer
{
	struct MyProfile* temp1 = head;
	
	while(temp1->next!=NULL)
	{
		temp1 = temp1->next;	
	}
	if(temp1->next == NULL)
	{
		return temp1;
	}
	else
	{
		printf("\n something wrong try again \n");
	}
}
struct MyProfile* check(char username[],char passwd[],struct MyProfile* head) //returns the pointer of the list if username and password of that list matches
{
	struct MyProfile* temp = head;
	while(temp != NULL)
	{
		if(strcmp(temp->Username,username) == 0 && strcmp(temp->Password,passwd) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;	
}

int forgotPasswd(struct MyProfile* head) //forgot password section (will allow user to change their password if forgotten)
{
	struct MyProfile* temp5 = head;
	int m = 0;
	
	do
	{
		temp5 = head;
		char username[20],email[20],passwd[20];
		system("CLS");
		printf("ZOHO REGISTER \n\t");
		printf("\n\t Enter your username : ");
		scanf("%s",username);
		printf("\n\t Enter your email : ");
		scanf("%s",email);
	//if(NotExist(head,1,username,NULL)==1&&NotExist(head,1,username,NULL)==1)
	//{
		while(temp5 != NULL)
		{
		//	printf("\n struct_username = %s username = %s struct_mail = %s mail = %s\n ",temp5->Username,username,temp5->email,email);
			if(strcmp(temp5->Username,username) == 0 && strcmp(temp5->email,email) == 0)
			{
				printf("\n\t Enter the New Password : ");
				scanf(" %s",passwd);
				strcpy(temp5->Password,passwd);
				databaseUpdate(head);
				return 0;				
			}
			temp5 = temp5->next;
	//	}
		
		}
//		printf("\n struct_username = %s username = %s struct_mail = %s mail = %s\n ",temp5->Username,username,temp5->email,email);
	//else
		printf("\n\t Please check your username or email again!!! \n\t\t press any key to try again \n");
		m = 1;
		getch();
 	}while(m);
}

void SignIn(struct MyProfile *prof,struct MyProfile *head) //sign in page (this divided into two parts one will allow the user to enter username and password)
{															//( other part will allow the user to use features as a user in the page)	
	int operation = 0, loop = 0;
	char username[20], pass[20];	
	struct MyProfile* temp2;	
			do{                       //part 1 will allow user to log into the page and can reset password if want here
				system("CLS");
				printf("ZOHO REGISTER \n");
				printf("\n\t Please Sign In with registered Credentials \t Users count = %d \n\n",t);
				printf("\n\t Username: ");
				scanf("%s",&username);
				printf("\n\t Password: ");
				scanf("%s",&pass);
				
				if(check(username,pass,head) != NULL)
				{
					temp2=check(username,pass,head);
					system("CLS");
					break;
				}
				else
				{
					printf("\n\t Wrong Username or Password !! \n\t 1. try again \n\t 2. exit \n\t 3. Forgot password? \n\t");
					scanf("%d",&operation);
					if(operation == 1)
					{
						system("CLS");
						loop = 1;
					}
					else if(operation == 2)
					{
						exit(0);
					}
					else if(operation == 3)
					{
						forgotPasswd(head);
						loop = 1;
					}
				}
			}while(loop == 1);		
		
			
		do{                      //part 2 print the features that are available for the user
			system("CLS");
			printf("ZOHO REGISTER \n"); 	                                       
			printf("\n\n\t HI %s !!! \n\n\t 1. My Profile \n\t 2. exit \n\t 3. SignIn \n\t 4. SignUp \n\t 5. Search \n\t 6. Edit Profile \n\t",temp2->name);
			scanf("%d",&operation);
		
			switch(operation)
			{
				case 1:
					PrintProfile(temp2);
					loop = 1;
					break;
				case 2:
					exit(0);
					break;
				case 3:
					SignIn(prof,head);
					break;
				case 4:
//					struct MyProfile* next= NULL;
//					next = (struct MyProfile*)malloc(sizeof(struct MyProfile));
					prof =finalnodefinder(head);
//					PrintProfile(prof);
					SignUp(prof,head);
					break;
				case 5:
					search(head);
					loop = 1;
					break;
				case 6:
					if(securityCheck(temp2))
					editProfile(temp2,head);
					loop=1;
					break;				
				default:
					printf("\nYou Have Entered the wrong number, try again :)\n\n");
					loop = 1;
					break;			
			}
		}while(loop == 1);
}

int NotExist(struct MyProfile* head, int operator,char text[],struct MyProfile* next) //this function returns 1 if the entered data is exist on the already registered list 
{
	struct MyProfile* temp3 = head;
	
	switch(operator)
	{
		case 1:
			while(temp3 != next)
			{			
				if(strcmp(text,temp3->Username) == 0)
				{
					//printf("\ntext = %s head->text = %s\n",text,temp3->Username);
					return 1;		
				}
				temp3 = temp3->next;
			}
			return 0;
			break;
		case 2:
			while(temp3 != next)
			{
				if(strcmp(text,temp3->email) == 0)
				{
					return 1;
				}
				temp3 = temp3->next;
			}
			return 0;
			break;
		default:
		printf("\n something wrong please try again");						
	}
}

void SignUp(struct MyProfile *prof,struct MyProfile *head) // Signup (it will allow the new user to create a new list  that linked to the last list)
{
	if(t == 0)
	{
//		struct MyProfile* next= NULL;
//		next = (struct MyProfile*)malloc(sizeof(struct MyProfile));
		FILE* file = fopen("database.txt","a");
		
		prof->next = NULL;
			system("CLS");
		
		printf("ZOHO REGISTER \n");
		printf("\n\t Enter your credentails : \n");
	
		printf("\n\t Full Name : ");
		scanf("%s",head->name);

		printf("\n\t User Name : ");
		scanf("%s",head->Username);
			
		printf("\n\t Email : ");
		scanf("%s",head->email);
		
		
		printf("\n\t New Password : ");
		scanf("%s",head->Password);
	
		printf("\n\tMobile Number : ");
		scanf("%s",head->number);
		
		fprintf(file,"\nuserid = %d \n name = %s \n username : %s \n password : %s \n email : %s \n number : %s \n",t,head->name,head->Username,head->Password,head->email,head->number);
		fclose(file);
		
	}
	else
	{
		FILE* file = fopen("database.txt","a");
		struct MyProfile* next = NULL;
		next = (struct MyProfile*)malloc(sizeof(struct MyProfile));
		prof->next = next;
		next->next = NULL;
		system("CLS");
		
		printf("ZOHO REGISTER \n");
		printf("\n\t Enter your credentails : \n");
			
		printf("\n\t Full Name : ");
		scanf("%s",next->name);
	
		do{	
		printf("\n\t User Name : ");
		scanf("%s",next->Username);
		
		if(NotExist(head,1,next->Username,next))
		printf("\nthis username is already taken\n");
		
		}while(NotExist(head,1,next->Username,next));
		
		do{
		printf("\n\t Email : ");
		scanf("%s",next->email);
		
		if(NotExist(head,2,next->email,next))
		printf("\n this email is already taken \n");
		
		}while(NotExist(head,2,next->email,next));
		
		printf("\n\t New Password : ");
		scanf("%s",next->Password);
	
		
		printf("\n\t Mobile Number : ");
		scanf(" %s",next->number);
		
		fprintf(file,"\nuserid = %d \n name = %s \n username : %s \n password : %s \n email : %s \n number : %s \n",t,next->name,next->Username,next->Password,next->email,next->number);
		fclose(file);
	}
	t++;
	SignIn(prof,head);	
}

int partialStringSearch(char username1[],char username2[] )  //partial string searcher (eg. if an presents in kannan it will return 1 else it will retun 0 )
{
	int i = 0,j = 0,k = 0,m;
	
	if(strlen(username2) == 1)
	{
		for(i = 0;i<1;i++)
		{
			for(j = 0;j<strlen(username1);j++)
			{
				if(username1[j] == username2[i])
				return 1;
			}
		}
	}
	else
	{

		for(;i<strlen(username2);i++)
		{
			for(;j<strlen(username1);j++)
			{
				if(username2[i] == username1[j])
				{
					for(k=i+1,m=j+1;k<strlen(username2);k++,m++)
					{
						if(username2[k] != username1[m])
						{
							return 0;
						}
						if(k == strlen(username2)-1)
						return 1;
					}
								
				}
				if(j == strlen(username1)-1)
				{
					return 0;
				}
			}
		}
	}
	return 0;	
}
int search(struct MyProfile* head)   // search option
{
	struct MyProfile* temp6=head;
	int m=0;
	char string[20];
	
	system("CLS");
	printf("ZOHO REGISTER \n");
	printf("\n\t Enter the Username : ");
	scanf("%s",string);
	printf("\n\t user's found : ");
	
	while(temp6!=NULL)   
	{
		
		if(partialStringSearch(temp6->Username,string))  //searching username if exisit from the linked struct 
		{

			printf("\n \t\t %s \n",temp6->Username);
			m++;
		}
		temp6= temp6->next;
	}
	
	if(m==0)
	printf("\n \t No users found :(\n");
	printf("\n\t\tPress any key to continue ...");
	getch();
	return 1;
}

int editProfile(struct MyProfile* prof,struct MyProfile* head) //to edit your pofile details
{
	int operation;
	char string[20];
	char dec = 'n';
	do
	{	
		system("CLS");
		printf("ZOHO REGISTER \n");
		printf(" \n\tEdit Your Profile \n");
		printf("\n\t\t 1. Name : %s",prof->name);
		printf("\n\t\t 2. Username : %s",prof->Username);
		printf("\n\t\t 3. Password : ********",prof->Password);
		printf("\n\t\t 4. Email : %s",prof->email);
		printf("\n\t\t 5. Number : %s",prof->number);
		printf("\n\t\t 6. Go Back\n\n");
		scanf("%d",&operation);
		system("CLS");
		printf("ZOHO REGISTER \n");
		switch(operation)
		{
			case 1:
				printf("\n\t Enter the new name : ");
				scanf("%s",string);
				printf("\n\t\tdo you want to apply new changes ?(y/n) : ");
				scanf(" %c",&dec);
				if(dec=='y'||dec=='Y')
				{
					strcpy(prof->name,string);
					databaseUpdate(head);
				}
				break;
			case 2:
				do{
					printf("\n\t Enter the new username : ");
					scanf("%s",string);
					if(NotExist(head,1,string,NULL))
					{
						printf("\n\t The username is already taken\n");
						//break;	
					}
				  }while(NotExist(head,1,string,NULL));
				printf("\n\t\tdo you want to apply new changes ?(y/n) : ");
				scanf(" %c",&dec);
				if(dec=='y'||dec=='Y')
				{
					strcpy(prof->Username,string);
					databaseUpdate(head);
				}
				break;
			case 3:
				printf("\n\t Enter the new Password : ");
				scanf("%s",string);
				printf("\n\t\tdo you want to apply new changes ?(y/n) : ");
				scanf(" %c",&dec);
				if(dec=='y'||dec=='Y')
				{
					strcpy(prof->Password,string);
					databaseUpdate(head);
				}
				break;
			case 4:
				do{
					printf("\n\t Enter the new email : ");
					scanf("%s",string);
					if(NotExist(head,2,string,NULL))
					printf("\n\t The email is already taken \n");				
				}while(NotExist(head,2,string,NULL));
				printf("\n\t\tdo you want to apply new changes ?(y/n) : ");
				scanf(" %c",&dec);
				if(dec=='y'||dec=='Y')
				{
					strcpy(prof->email,string);
					databaseUpdate(head);
				}
				break;
			case 5:
				printf("\n\t Enter the new Number : ");
				scanf("%s",string);
				printf("\n\t\tdo you want to apply new changes ?(y/n) : ");
				scanf(" %c",&dec);
				if(dec=='y'||dec=='Y')
				{
					strcpy(prof->number,string);
					databaseUpdate(head);
				}
				break;
			case 6:
				return 1;
				break;					
			default:
				printf("\n\n\t\t you have entered the wrong number\n");
		}
		printf("\n\t\t still wanna edit your profile?(y/n) : ");
		scanf(" %c",&dec);
	}while(dec=='y'||dec=='Y');
	return 0;
}

int securityCheck(struct MyProfile* prof) // security check from the user (eg.password)
{
	char string[20];
	
	system("CLS");
	printf("ZOHO REGISTER \n");
	printf("\n\t Security Check to Confirm this is you ");
	printf("\n\n\t Enter you Password : ");
	scanf("%s",&string);
	if(strcmp(prof->Password,string) == 0)
	return 1;
	else
	{
		printf("\n\n \t Wrong password ...press any key ");
		getch();
		return 0;
	}
	
}

int databaseUpdate(struct MyProfile* head) //updates entire database if any changes have been made
{
	struct MyProfile* temp7 = head;
	FILE* file = fopen("database.txt","w");
	fclose(file);
	while(temp7 != NULL)
	{
		file = fopen("database.txt","a");
			fprintf(file,"\n name = %s \n username : %s \n password : %s \n email : %s \n number : %s \n\n",temp7->name,temp7->Username,temp7->Password,temp7->email,temp7->number);
		fclose(file);
		temp7 = temp7->next;
	}	
}	

int main(int argc, char *argv[])     //homepage
{	
	int operation, loop = 0;
	struct MyProfile prof;
	struct MyProfile* head;
	head = &prof;
	FILE* file = fopen("database.txt","w");
	fclose(file);
	
	do{
		printf("\n\t WELCOME TO ZOHO REGISTER !!! \n\n\t\t");
		printf(" 1. Sign In \n\t\t 2. Sign up \n\t\t 3. exit \n\t\t");       //Printing Home Page and getting an input from user to perform an operation
		scanf("%d",&operation);
		system("CLS");
		switch(operation)
		{
			case 1:
				if(t == 0)
				{
					printf("\n\t\t*****No Users Found***** (Please register as first user by pressing signup first)\n");   
					loop = 1;
					break;
				}
				SignIn(&prof,head);
				loop = 0;
				break;
			case 2:
				SignUp(&prof,head);
				loop = 0;
				break;
			case 3:
				exit(0);
				break;	
			default:
				printf("\nYou Have Entered the wrong number, try again :)\n\n");
				loop = 1;
				break;			
		}
	}while(loop == 1);
	return 0;
}
