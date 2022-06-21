#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// #define SHOW : Show Answer
#define SHOW

// 총 단어 개수 : 16962개
#define MAX 16962

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void) {
	system("mode con cols=60 lines=25");
	srand((int)time(NULL));

	char answer[10];
	int ran;
	int answer_num = 0;
	int count = 0;
	for (int r = 0; r < 2000; r++) {
		ran = rand() % 100;
		answer_num += ran;
		if (answer_num > MAX)
			answer_num -= MAX;
	}
	FILE* anfp = fopen("C:\\Users\\박정근\\Desktop\\Code\\Wordle\\all.txt", "r");
	while (!feof(anfp)) {
		fgets(answer, 6, anfp);
		if (answer[0] == '\n')
			continue;

		if (count != answer_num) {
			count++;
			continue;
		}
		break;
	}

	int hp = 6;
	int row = 0;
	int go = 1;

#ifdef SHOW
	printf("%d\n", answer_num);
	printf("Answer is %s\n", answer);
	row += 2;
#endif
	fclose(anfp);


	printf("\n");
	while (hp > 0) {
		char ch[6];
		char pt[6];

		int search = 0;
		if (go == 1) {
			row += 2;
			go = 0;
		}
		printf(" >> ");
		scanf("%s", ch);

		for (int z = 0; z < 5; z++) {
			ch[z] -= 32;
		}
		FILE* fp = fopen("C:\\Users\\박정근\\Desktop\\Code\\Wordle\\all.txt", "r");
		
		while (!feof(fp)) {
			fgets(pt, 6, fp);
			if (!strcmp(ch, pt)) {
				search = 1;
				break;
			}
		}
		fclose(fp);

		int co = 0;

		if (search == 0) {
			gotoxy(0, row);
			printf("It is not a word.");
			gotoxy(0, row - 1);
			printf("             ");
			gotoxy(0, row - 1);
			continue;
		}
		else {
			go = 1;
			gotoxy(0, row);
			printf("                      ");
			gotoxy(0, row);
			printf("\t\t\t");

			int queue[5] = { 0, };
			int queue_size = 0;
			for (int i = 0; i < 5; i++) {
				int done = 0;
				if (ch[i] == answer[i]) {
					textcolor(10);
					printf("[ %c ] ", ch[i]);
					textcolor(15);
					done = 1;
					co++;
					queue[queue_size++] = i;
				}
				else {
					for (int j = 0; j < 5; j++) {
						if (i == j)
							continue;
						if (ch[i] == answer[j]) {
							int con = 0;
							for (int q = 0; q < queue_size; q++) {
								if (queue[q] == j) {
									con = 1;
									break;
								}
							}
							if (con == 1)
								continue;
							textcolor(14);
							printf("[ %c ] ", ch[i]);
							textcolor(15);
							done = 1;
							queue[queue_size++] = j;
							break;
						}
					}
					if (done == 0) {
						printf("[ %c ] ", ch[i]);
					}
				}
			}
			printf("\n");
			hp--;
		}

		if (co == 5) {
			printf("Correct!\n");
			break;
		}
	}

	printf("\nThe answer is %s.\n", answer);

	return 0;
}