#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �� �ܾ� ���� : 2310��

int main(void) {
	char ch[6];
	char pt[6];
	int search = 0;
	scanf("%s", ch);
	FILE* fp = fopen("C:\\Users\\������\\Desktop\\Code\\Wordle\\all.txt", "r");
	while (!feof(fp)) {
		fgets(pt, 6, fp);
		if (!strcmp(ch, pt)) {
			search = 1;
			break;
		}
	}

	if (search == 0) {
		printf("No Search.");
	}
	else {
		printf("Search : %s", pt);
	}

	return 0;
}