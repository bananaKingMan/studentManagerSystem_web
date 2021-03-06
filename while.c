#include <stdio.h>
#include <stdlib.h>
exec sql include sqlca;

int connectDb();
void createTable();
void addStu();
void delStu();
void updStu();
void shoStu();

exec sql begin declare section;
	char userName[15];
	char passwd[15];
	int g_id;
	char g_name[25];
exec sql end declare section;

int main ()
{
	if (connectDb())
	{
		printf("Error: Connect\n");
		return -1;
	}
	printf("Welcome The Student Manager Systemi the command list is:\n");
	enum option{Exit, Create, Add, Delete, Update, Show, Others};
	printf("Exit\tCreate\tAdd\tDelete\tUpdat\tShow\tOthers\n 0\t1\t2\t3\t4\t5\t6\n");
	while (1)
	{	
		printf("Enter the command:");
		int options;
		scanf("%d", &options);
		switch (options)
		{
			case Exit:
				printf("Exit\n");
				return 0;
			case Create:
				printf("Create\n");
				createTable();
				break;
			case Add:
				printf("Add\n");
				break;
			case Delete:
				printf("Delete\n");
				break;
			case Update:
				printf("Update\n");
				break;
			case Show:
				printf("Show\n");
				break;
			default:
				printf("Others\n");
				break;
		}
		
	}
	return 0;
}

int connectDb()
{
	printf("Input the Accout:");
	scanf("%s", userName);
	printf("Input the Passwd:");
	scanf("%s", passwd);
	exec sql connect:userName identified by:passwd;
	return sqlca.sqlcode;

}
void createTable()
{
	exec sql create table sms(id number, name varchar2(25));
	if (sqlca.sqlcode)
	{
		printf("%s\n", sqlca.sqlerrm.sqlerrmc);
	}
	else
		printf("Create Success\n");
}
void addStu();
void delStu();
void updStu();
void shoStu();
