#include<stdio.h>
#include<conio.h>
struct student
{
	int id;
	char name[20];
};

struct student stu;
FILE *fp,*fp1;
void getData()
{
	clrscr();
	printf("\n\t\t\tAdd new Student ");
	printf("\n= = = = = = = = = = = = = = = = = = = = = = =  = = =");
	printf("\n Enter Id ");
	scanf("%d",&stu.id);
	fflush(stdin);
	printf("\n Enter Name ");
	gets(stu.name);
}



void showData()
{
       //	printf("\n Id is \t\t%d ",stu.id);
       //	printf("\n Name is \t\t %s ",stu.name);
	printf("\n\t%d\t\t%s",stu.id, stu.name);
}

void delStu(int id)
{
	char uc;
	fp=fopen("studentdata.txt","r");
	fp1=fopen("temp.txt","w");
	while(fread(&stu, sizeof(stu),1,fp))
	{
		if(stu.id==id)
		{
			showData();
			getch();
			printf("\n Are you sure to Delete this record ");
			fflush(stdin);
			scanf("%c",&uc);
			if(uc=='y' || uc=='Y')
			{
				  printf("\n data Deleted......");
				  getch();

			}
			else
			{
				fwrite(&stu,sizeof(stu),1,fp1);
			}
		}

		else
		{
			fwrite(&stu, sizeof(stu),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove("studentdata.txt");
	rename("temp.txt","studentdata.txt");


}


void search(int id)
{
	int f=0;
	fp=fopen("studentdata.txt","r");
	if(fp==NULL)
	{
		printf("\n error while reading file ");
	}
	else
	{
		//printf("\n\t Id\t\tName");
		//printf("\n- - - - - - - - - - - - - - - - - - - - - ");
		while(fread(&stu,sizeof(stu),1,fp))
		{
			if(stu.id==id)
			{
			       //	showData();
			       f=1;
			       break;

			}
		}
		if(f==1)
			showData();
		else
			printf("\n No Matching Data found ");
	}
	fclose(fp);
	getch();

}

void updateData()
{
	printf("\n Id is %d ",stu.id);
	printf("\n Enter New Name ");
	fflush(stdin);
	gets(stu.name);
}

void main()

{
	int ch,id;
	int choice;
	char c='y';
	char uc;
	while(choice!=6)
	{
		clrscr();
		printf("\n\t\tStudent Management System");
		printf("\n* * * * * * * * * * * * * * * * * * * * * * ");
		printf("\n 1. Add new Student ");
		printf("\n 2. List All ");
		printf("\n 3. Edit ");
		printf("\n 4. Delete ");
		printf("\n 5. Find ");
		printf("\n 6. Exit ");
		printf("\n Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n Add new student ");

				fp=fopen("studentdata.txt","a");
				if(fp==NULL)
				{
					printf("\n Error while create a file ");
					getch();
				}
				else

				{
					while(c=='y' || c=='Y')
					{
						clrscr();
						getData();
						fwrite(&stu,sizeof(stu),1,fp);
						printf("\n Do you want to add more data y/n");
						fflush(stdin);
						scanf("%c",&c);
					}
					fclose(fp);

					getch();
				}
				getch();
			break;

			case 2:
				printf("\n List all ");
				fp=fopen("studentdata.txt","r");
				if(fp==NULL)
				{
					printf("\n error while reading file ");
				}
				else
				{
					printf("\n\t Id\t\tName");
					printf("\n- - - - - - - - - - - - - - - - - - - - - ");
					while(fread(&stu,sizeof(stu),1,fp))
					{
						showData();
					}
				}
				fclose(fp);
				getch();
			break;

			case 3:
				printf("\n Edit Student ");
				printf("\n Enter id ");
				scanf("%d",&id);
				fp=fopen("studentdata.txt","r");
				fp1=fopen("temp.txt","w");

				while(fread(&stu, sizeof(stu),1,fp))
				{
					if(stu.id==id)
					{
						showData();
						getch();
						printf("\n Are you sure to edit this record ");
						fflush(stdin);
						scanf("%c",&uc);
						if(uc=='y' || uc=='Y')
						{
							updateData();
							fwrite(&stu,sizeof(stu),1,fp1);
						}
						else
						{
							fwrite(&stu,sizeof(stu),1,fp1);
						}
					}
					else
					{
						fwrite(&stu, sizeof(stu),1,fp1);
					}
				}
				fclose(fp);
				fclose(fp1);
				remove("studentdata.txt");
				rename("temp.txt","studentdata.txt");

				getch();
			break;

			case 4:
				printf("\n Delete Student ");
				printf("\n Enter id ");
				scanf("%d",&id);
				delStu(id);
				getch();
			break;

			case 5:
				printf("\n Find Student ");
				printf("\n Enter id ");
				scanf("%d",&id);
				search(id);
				getch();
			break;

			case 6:
				printf("\n Thanks for using This App ");
				getch();
			break;

			default:
				printf("\n Invalid Choice ");
				getch();


		}//switch
	}//while
}//main