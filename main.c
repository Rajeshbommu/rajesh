#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
void details(void);
void password(void);
void namefun(void);
void searchfun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);

int main(){
	system("color 5");
	password();
	getch();
}

void namefun(){
	system("cls");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	FILE *fptr;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	fptr=fopen("rajesh.txt","ab+");
	if(fptr==NULL){
		printf("\nFailed to create the required file.");
	}
	else{
        printf("\nName:\t");
		gets(name);
		printf("Address:\t");
		gets(address);
		printf("Gender:\t");
		gets(gender);
		printf("Gmail:\t");
		gets(gmail);
		printf("Phone Number:\t");
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
	}
	fclose(fptr);
	system("cls");
	char ch;
	printf("\nDo you wanna add more datas.Press y for that:");
	Sleep(1000);
	fflush(stdin);
	while((ch=getch())=='y'){
		details();
	}
}

void searchfun(){
	FILE *fptr;
	int flag=0;
	int res;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	char name1[100];
	system("cls");
	fflush(stdin);
	printf("\n\xDB\xDB\xDB Enter the name of the person you want to see the detail:: ");
	gets(name1);
	fptr=fopen("rajesh.txt","r");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0){
			printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			printf("----------------------------------------");
		printf("\n\xB3\xB2\xB2\xB2 Name:\t%s",name);
		printf("\n\xB3\xB2\xB2\xB2 Address:\t%s",address);
		printf("\n\xB3\xB2\xB2\xB2 Gender:\t%s",gender);
		printf("\n\xB3\xB2\xB2\xB2 Gmail:\t%s",gmail);
		printf("\n\xB3\xB2\xB2\xB2 Phone Number:\t%.0lf",phone);
			printf("----------------------------------------");
		flag=1;
		Sleep(1000);
			printf("\nEnter y for details option.");
	while(getch()=='y'){
		details();
	}
	}
}
	if(flag==0){
		system("cls");
		printf("\nNo record found.");;
		printf("\nEnter a to enter file again or double y key to open details section:");
		if(getch()=='a'){
			system("cls");
			searchfun();
		}

	}


	fclose(fptr);
}
void listfun(){
		FILE *fptr;
	char name[100],address[100],gmail[100],gender[8];
	double phone;
	int f;
	fptr=fopen("rajesh.txt","r");
	system("cls");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
	printf("\n");
	while(fscanf(fptr,"%s %s %s %s %lf",name,address,gender,gmail,&phone)!=EOF){

			printf("------------------------------------------\n");
		printf("Name:%s\n",name);
		printf("Address:%s\n",address);
		printf("Gender:%s\n",gender);
		printf("Gmail:%s\n",gmail);
		printf("Phone:%.0lf\n",phone);
			f=1;
				printf("------------------------------------------");
				printf("\n\n");
		}
		Sleep(1000);
		printf("\nEnter y for details section:");
		while(getch()=='y'){
			details();
		}
			fclose(fptr);
			}



void modifyfun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8],gender1[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("rajesh.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	printf("Enter the name: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
			printf("\nEnter the new address:");
			scanf("%s",address1);
			printf("\nEnter the gender:");
			scanf("%s",gender1);
			printf("\nEnter the new gmail:");
			scanf("%s",gmail1);
			printf("\nEnter the new phone number:");
			scanf("%lf",&phone1);
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address1,gender1,gmail1,phone1);

		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("\nRecord Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("rajesh.txt","w");
	fclose(fptr);
	fptr=fopen("rajesh.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);

	}

	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for details option.");
	fflush(stdin);
	if(getch()=='y'){
		details();
	}
}
void deletefun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],gender[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("rajesh.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	printf("\nEnter the CONTACT name that you want to delete: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			printf("Record deleted successfully");

		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("rajesh.txt","w");
	fclose(fptr);
	fptr=fopen("rajesh.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,gmail,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,gmail,phone);

	}

	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for details option.");
	fflush(stdin);
	if(getch()=='y'){
		details();
	};
}
void exitfun(){
	system("cls");
	printf("\n\xDB\xDB\xDB\xDB TEAM MEMBERS \xDB\xDB\xDB\xDB");
	printf("\n\xDB rajesh");
}
void password(void){
	char passwords[20]={"rajesh"};
	int j;
	int z;
	char name[40]="Certified user login";
	z=strlen(name);
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	for(j=0;j<=z;j++){
		Sleep(60);
		printf(" %c",name[j]);
	}
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	printf("\nPassword:");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0){
		printf("\nCORRECT PASSWORD.");
		Sleep(1000);
		details();
	}
	else{
		printf("\nYou entered the wrong password.");
		Sleep(700);
		system("cls");
		password();
}

}


void details(){
	system("cls");
	printf("\n\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Contact storing library \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB 1.Add New \xB3\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB 2.Search  \xB3\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB 3.List    \xB3\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB 4.Modify  \xB3\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB 5.Delete  \xB3\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xDB 6.Exit    \xB3\xDB\xDB\xDB\xDB\xDB\xDB");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			searchfun();
			break;
		case '3':
			listfun();
			break;
		case '4':
			modifyfun();
			break;
		case '5':
			deletefun();
			break;
		case '6':
			exitfun();
			break;
		default:
			system("cls");
			printf("\nInvalid Enter.");
			getch();
}
}
