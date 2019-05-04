/*
Group 10 Project:
	This project is to contruct the grading system.
	Please give the correct input for all parts.
	done by:
	1.Kelvin郭睿     1630013011  Menu/Inquire/Grade		45%
	2.Lennox谢旗洲   1630003056  Sort					25%
	3.Jason陈奕东    1630003004  Grade/Comment			20%
	4.Wayne王源      1630003050  Testing					10%
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int menu(void);//the menu interfacce
void Grade(void);//the grading system
void Inquire(void);//Inquire section
void Inquire1(void);//Inquire by index
void Inquire2(void);//Inquire by student ID
void Sort(void); //Sort Section
void sort1(int);
struct record
{
	char name[10];
	int ID;
	float ass1;
	float ass2;
	float ass3;
	float ass4;
	float ass5;
	float total;
};
struct record student[20];
struct record *p = &student[0];//a pointer that points to struct recode student
int length;//Global variable length

int main()//MAIN FUNCTION
{
	menu();
	return 0;
}
//This following part done by Kelvin 1630013011.
int menu(void)
{
	int num;
	int a, b;
	printf("What kind of function do you want to use?\n");
	printf("1.Grade\n2.Inquire\n3.Sort\n4.Quit\n");
	if(scanf("%d",&num)==1)
	{
		switch(num)//menu choices
		{
			case 1: 
				Grade();
				break;
			case 2: 
				Inquire();
				break;
			case 3: 
				Sort();
				break;
			case 4: 
				printf("Bye-bye!\n");//The program exits
				return -1;
			default: 
				printf("Please choose 1,2,3,or4\n");//Handle the input other than 1,2,3 ande 4.
				return -1;
		}
		return 0;
	}
	else 
		printf("Error input!Please input 1,2,3or4 then run again!\n");//Handle the input that is not integer.
	return 0;
}

//This follow part done by Kelvin 1630013011 and Jason 1630003004.
void Grade(void)//Grading section
{
	int i,j,k;
	int x;//the return value of fscanf 
	int index,n;//index is the number of assignment, and n is the number of questions.
	char g;//switch
	char chaa[30];
	int sum = 0,grade;//used to calculate the grade
	char a;//to judge whether need to grade the next assignment or not.
	int count=0;
	int totall;
	
	FILE *fp;// points to student.txt
	FILE *fp2;//points to marks.txt
	fp = fopen("students.txt","r");
	fp2 = fopen("marks.txt","w");
	fgets(chaa, 29, fp);
	for (i=0;i<20;i++)//used to read the file of "students.txt"
	{
		x=fscanf(fp,"%s %d",student[i].name,&student[i].ID);
		if(x==EOF)
			break;
	}
	length = i;// read the lines in the file and assigned them to global variable length.
	XUNHUAN:puts("Please input the index of the assignment: (1-5 only)");//used for goto statement
	count= count +1;
	scanf("%d", &index);
	printf("How many questions are there in assignment#%d (1-10)?\n", index);
	scanf("%d", &n);
	printf("Now you are grading assignment %d.\n", index);
	for (j=0;j<length;j++)
	{
		printf("Student#%d: %s (ID:%d)\n", j + 1, student[j].name, student[j].ID);
		for(k=1;k<=n;k++)
		{
			printf("Grade for Question#%d (A-F only):\n",k);
			scanf("%c", &g);
			scanf("%c", &g);
			g = toupper(g);//保证只有大写
			switch(g)
			{
			case 'A':grade = 4;sum = sum + grade;break;
			case 'B':grade = 3;sum = sum + grade;break;
			case 'C':grade = 2;sum = sum + grade;break;
			case 'D':grade = 1;sum = sum + grade;break;
			case 'F':grade = 0;sum = sum + grade;break;
			}
		}
		if (index==1)
		{
			student[j].ass1=sum/n;
			sum=0;
		}
			
		if (index==2)
		{
			student[j].ass2=sum/n;
			sum=0;
		}
		if (index==3)
		{
			student[j].ass3=sum/n;
			sum=0;
		}
			
		if (index==4)
		{
			student[j].ass4=sum/n;
			sum=0;
		}
			
		if (index==5)
		{
			student[j].ass5=sum/n;
			sum=0;
		}
			
	}
	printf("Do you want to grade another assignment? Input y/n.\n");
	scanf("%c",&a);//to judge whether to continue or not.
	scanf("%c",&a);//refresh the buffer.
	a=tolower(a);//保证全是小写
	if(a == 'y')
	{
		goto XUNHUAN;//jump to grade the next assignment
	}
	

	
	for (int z=0;z<length;z++)//transfer the average scores of all assignments to struct student.
	{
		student[z].total= (student[z].ass1 + student[z].ass2 + student[z].ass3 + student[z].ass4 + student[z].ass5)/(float)count;
	}
	fprintf(fp2, "%s","Name      ID   Ass1 Ass2 Ass3 Ass4 Ass5\n");
	for (k=0;k<length;k++)
	{
		fprintf(fp2,"%-10s%d %-4.2f %-4.2f %-4.2f %-4.2f %-4.2f\n",student[k].name,student[k].ID,student[k].ass1,student[k].ass2,student[k].ass3,student[k].ass4,student[k].ass5);
	}
	fclose(fp);
	fclose(fp2);
	
}

//The following part done by Kelvin 1630013011.
void Inquire(void)//Inquire part
{
	int x;
	int j;
	FILE *fp3;
	char s1[50];
	fp3 = fopen("marks.txt","r");
	fgets(s1, 49, fp3);
	for (j=0;j<20;j++)//To read the content of "marks.txt"
	{
		x=fscanf(fp3,"%s %d %f %f %f %f %f",student[j].name,&student[j].ID,&student[j].ass1,&student[j].ass2,&student[j].ass3,&student[j].ass4,&student[j].ass5);
		if(x==EOF)
			break;
	}
	length = j;//give value to length
	fclose(fp3);

	int select;
	printf("What kind of selects inquiry method do you want to use?\n");
	printf("1.By index\t2.By student ID \t3.Quit\n");
	scanf("%d",&select);
	switch(select)//the subset of Inquire.
	{
		case 1:
			Inquire1();
			break;
		case 2:
			Inquire2();
			break;
		case 3:
			menu();
			break;
		default:
			printf("Error input!Please input 1 or 2\n");//To handle the wrong input.
			break;
			
	}
}
//The following part done by Kelvin 1630013011.
void Inquire1(void)//Menu for Inquire
{
	
	int num;//is used to select the index.
	int i;
	printf("There are all the students'information for you choose.\n");
	for (i=1;i<=length;i++)
	{
		printf("%d. %-10s\t%d\n",i,student[i-1].name,student[i-1].ID);
	}
	printf("Which student do you want to select? Only input the index.\n");
	scanf("%d",&num);
	printf("Name\tID\tAss1\tAss2\tAss3\tAss4\tAss5\n");
	printf("%-5s\t%-5d\t%-4.2f\t%-4.2f\t%-4.2f\t%-4.2f\t%-4.2f\n",student[num-1].name,student[num-1].ID,student[num-1].ass1,student[num-1].ass2,student[num-1].ass3,student[num-1].ass4,student[num-1].ass5);
}

//The following part done by Kelvin 1630013011.
void Inquire2(void)//menu for Inquire
{
	int j;
	int idnum;//is used to select the student ID.
	printf("Please input student ID that you want to search.\n");
	scanf("%d",&idnum);
	for (j=0;j<length;j++)
	{
		if(idnum == student[j].ID)
			break;
	}
	printf("Name\tID\tAss1\tAss2\tAss3\tAss4\tAss5\n");
	printf("%-5s\t%-5d\t%-4.2f\t%-4.2f\t%-4.2f\t%-4.2f\t%-4.2f\n",student[j].name,student[j].ID,student[j].ass1,student[j].ass2,student[j].ass3,student[j].ass4,student[j].ass5);
}

//The following part is done by Lennox 1630003056.
void Sort(void) {
	int k = 0;
	int count = 0;
	char ch[50];
	FILE *read = fopen("marks.txt", "r");
	FILE *write = fopen("sorted.txt","w");
	fgets(ch, 49, read);
	while (fscanf(read, "%s %d %f %f %f %f %f", student[count].name, &student[count].ID, &student[count].ass1,&student[count].ass2,&student[count].ass3,&student[count].ass4,&student[count].ass5) != EOF) 
	{
		printf("%-10s %-5d %-5.2f %-5.2f %-5.2f %-5.2f %-5.2f\n", student[count].name, student[count].ID, student[count].ass1, student[count].ass2, student[count].ass3, student[count].ass4, student[count].ass5);
		student[count].total = student[count].ass1 + student[count].ass2 + student[count].ass3 + student[count].ass4 + student[count].ass5;
		count++;
	}
		if(student[0].ass1 != 0){
			k++;
		}
		if(student[0].ass2 != 0){
			k++;
		}
		if(student[0].ass3 != 0){
			k++;
		}
		if(student[0].ass4 != 0){
			k++;
		}
		if(student[0].ass5 != 0){
			k++;
		}

	sort1(count);
	printf("\nAfter sorted \nName       ID    Score\n");
	for (int c = 0; c < count; c++) 
	{
		printf("%-10s %-5d %-5.2f\n", student[c].name, student[c].ID, (student[c].total)/(float)k);
	}
	fprintf(write,"%s\n","Name       ID     Total");
	for (int z=0;z<count;z++)
	{
		fprintf(write,"%-10s %-6d %-6.2f\n",student[z].name, student[z].ID, student[z].total/(float)k);
	}
	fclose(read);
	fclose(write);
}

void sort1(int count) {
	for (int k = 0; k < count; k++) {
		for (int j = 0; j < count; j++) {
			if (student[k].total > student[j].total) {
				student[count + 1] = student[k];
				student[k] = student[j];
				student[j] = student[count + 1];
			}
		}
	}
}