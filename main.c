#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// #define SHOW : Show Answer

// 총 단어 갯수 : 16962개
#define MAX 16962

// Path ( Database )
char path[250] = "( all.txt directory )";

void color(int text, int back) { // Text Color Set Function
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (back<<4) + text);
}

void gotoxy(int x, int y) { // Cursor Move Function
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printLine(int n, char data[][6], int status[][6]) { // print line ( with color ) function
	gotoxy(10, n * 2);
	for (int i = 0; i < 5; i++) {
		// Check Color
		if (status[n - 1][i] == 0)
			color(15, 0);
		else if (status[n - 1][i] == 1)
			color(0, 15);
		else if (status[n - 1][i] == 2)
			color(0, 14);
		else if (status[n - 1][i] == 3)
			color(0, 10);
		else
			color(4, 4);

		// Data Print
		if (data[n - 1][i] == '\0')
			printf("[   ]");
		else
			printf("[ %c ]", data[n-1][i]);

		color(15, 0);
		printf(" ");
	}
}

void printBoard(int start, char data[][6], int status[][6]) { // print board function
	for (int i = start; i <= 6; i++)
		printLine(i, data, status);
}

int main(void) {
	system("mode con cols=49 lines=25");
	srand((int)time(NULL));

	char da[6][6] = {0,}; // Character Data
	int st[6][6] = {0,}; // Status Data ( Green, Yellow )

	char answer[10]; // Answer
	int answer_num = 0; // Answer Number

	int ran; // (for arithmetic)
	int count = 0; // (for searching)

	// Random Answer
	for (int r = 0; r < 20000; r++) {
		ran = rand() % 100;
		answer_num += ran;
		if (answer_num > MAX)
			answer_num -= MAX;
	}
	
	// Find Answer ( number )
	FILE* anfp = fopen(path, "r");
	
	while (!feof(anfp)) {
		fgets(answer, 6, anfp);
		if (answer[0] == '\n')
			continue;

		if (count == answer_num) {
			break;
		}

		count++;
	}

	fclose(anfp);

	int hp = 0; // Hp ( Now Line )

#ifdef SHOW
	// Answer Print
	gotoxy(0, 0);
	printf("%d / Answer is %s", answer_num, answer);
#endif

	while (hp < 6) {
		char ch[6]; // Input Data
		char pt[6]; // (for searching)

		int search = 0; // Whether the string existed in txt
		int overlap = 0; // Whether the string overlap

		printBoard(1, da, st); // Print All ( First )

		gotoxy(5, 14); // Input
		printf(" >> ");
		scanf("%s", ch);

		for (int z = 0; z < 5; z++) {// Case Upper
			if(ch[z] >= 97 && ch[z] <= 122)
				ch[z] -= 32;
		}

		// Overlap
		for (int o = 0; o < hp; o++) {
			if (!strcmp(ch, da[o])) {
				overlap = 1;
				break;
			}
		}

		// Find string
		FILE* fp = fopen(path, "r");
		
		while (!feof(fp)) {
			fgets(pt, 6, fp);
			if (!strcmp(ch, pt)) {
				search = 1;
				break;
			}
		}
		fclose(fp);

		int co = 0; // Check Answer ( 5 : All Correct )

		if (overlap == 1) { // Overlap
			gotoxy(5, 13);
			printf("Already Use.");
			gotoxy(5, 14);
			printf("                     ");
			continue;
		}
		else {
			if (search == 0) { // Can't Find
				gotoxy(5, 13);
				printf("It is not a word.");
				gotoxy(5, 14);
				printf("                     ");
				continue;
			}
			else {
				gotoxy(5, 13);
				printf("                     ");
				gotoxy(5, 14);
				printf("                     ");

				strcpy(da[hp], ch);

				// Check Green
				int queue[5] = { 0, };
				int queue_size = 0;
				for (int i = 0; i < 5; i++) {
					st[hp][i] = 1;
					if (ch[i] == answer[i]) {
						st[hp][i] = 3;
						co++;
						queue[queue_size++] = i;
					}
				}

				// Check Yellow
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						if (i == j || st[hp][i] == 3)
							continue;
						if (ch[i] == answer[j]) {
							int con = 0;
							for (int q = 0; q < queue_size; q++) {
								if (queue[q] == j) {
									con = 1;
									break;
								}
							}
							if (con == 0) {
								st[hp][i] = 2;
								queue[queue_size++] = j;
								break;
							}
						}
					}
				}
				hp++;

				if (co == 5) { // All Correct
					gotoxy(5, 14);
					printf("Correct!");
					break;
				}
			}
		}
	}

	printLine(hp, da, st); // Last line print & Answer Print
	gotoxy(5, 15);
	printf("The answer is %s. \n\n", answer);

	return 0;
}
