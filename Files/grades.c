#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
	char name[30];
	int grade1;
	int grade2;
	int grade3;
	int maxGrade;
}Student;

void Error_Msg(char *msg) {
	puts(msg);
	exit(1);
}


int Max_grade(int grade1, int grade2, int grade3) {
	int i, max = grade1;
	int grades[3] = { grade1,grade2,grade3 };
	for (i=1; i < 3; i++)
	{
		if (grades[i] > max)
			max = grades[i];
	}
	return max;
}


int main() {
	FILE *in,*out;	// students.txt
	Student *students;			
	char c;
	int count=0,max=0,i=0;

	if ((in = fopen("Students.txt", "r")) == NULL) {
		Error_Msg("cannot open input file!");
	}


	for (c = getc(in); c != EOF; c = getc(in))
		if (c == '\n') // Increment count if this character is newline 
			count++; 

	count++;	//number of lines



	if ((students = (Student*)malloc((count) * sizeof(Student))) == NULL) 
		Error_Msg("Can't allocate memory!");

	rewind(in);



	for (i = 0; i < count; i++) {
		fscanf(in, "%s %d %d %d", students[i].name, &(students[i].grade1), &(students[i].grade2), &(students[i].grade3));
		students[i].maxGrade = Max_grade((students[i].grade1), (students[i].grade2), (students[i].grade3));
	}


	fclose(in);

	if ((in = fopen("Students.txt", "w")) == NULL) {
		Error_Msg("cannot open input file!");
	}
		
	for (i = 0; i < count; i++) {
		fprintf(in, "Name: %s grade: %d\n", students[i].name,students[i].maxGrade);
	}
	
	
	printf("\ndone...");
	fclose(in);
	getchar();
	return 0;
}