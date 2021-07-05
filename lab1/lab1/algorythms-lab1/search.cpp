#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

struct student
{
	char famil[20];
	char name[20], facult[20];
	int Nomzach;
};

void eios(void) {

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	student stud[3];
	int i;
	char flag;
	student compare;

	for (i = 0; i < 3; i++)
	{
		printf("¬ведите фамилию студента\n"); scanf("%20s", stud[i].famil);
	}
	for (i = 0; i < 3; i++)
	{
		printf("¬ведите им€ студента %s\n", stud[i].famil); scanf("%20s", stud[i].name);
	}
	for (i = 0; i < 3; i++)
	{
		printf("¬ведите название факультета студента %s %s\n", stud[i].famil, stud[i].name); scanf("%20s", stud[i].facult);
	}
	for (i = 0; i < 3; i++)
	{
		printf("¬ведите номер зачЄтной книжки студента %s %s\n", stud[i].famil, stud[i].name); scanf("%d", &stud[i].Nomzach);
	}

	for (i = 0; i < 3; i++)
	{
		printf("Cтудент %s %s обучаетс€ на факультете %s, номер зачЄтной книжки %d \n", stud[i].famil, stud[i].name,
			stud[i].facult, stud[i].Nomzach);
	}


	printf("\n¬ведите фамилию искомого студента (если не важно, введите 0)\n"); scanf("%20s", compare.famil);
	printf("¬ведите им€ искомого студента (если не важно, введите 0)\n"); scanf("%20s", compare.name);
	printf("¬ведите факультет искомого студента (если не важно, введите 0)\n"); scanf("%20s", compare.facult);
	printf("¬ведите номер зачЄтной книжки искомого студента (если не важно, введите 0)\n"); scanf("%d", &compare.Nomzach);

	for (i = 0; i < 3; i++) {

		flag = 1;
		if (strcmp(compare.famil, "0")) {

			if (strcmp(compare.famil, stud[i].famil)) {

				flag = 0;
			}
		}
		if (flag && strcmp(compare.name, "0")) {

			if (strcmp(compare.name, stud[i].name)) {

				flag = 0;
			}
		}
		if (flag && strcmp(compare.facult, "0")) {

			if (strcmp(compare.facult, stud[i].facult)) {

				flag = 0;
			}
		}
		if (flag && compare.Nomzach != 0) {

			if (compare.Nomzach != stud[i].Nomzach) {

				flag = 0;
			}
		}
		if (flag) {
			printf("Cтудент %s %s обучаетс€ на факультете %s, номер зачЄтной книжки %d \n", stud[i].famil, stud[i].name,
				stud[i].facult, stud[i].Nomzach);
		}
	}
}
