#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 총 단어 개수 : 2310개

int main(void) {
	char ch[6];
	char pt[6];
	int search = 0;
	scanf("%s", ch);
	FILE* fp = fopen("C:\\Users\\박정근\\Desktop\\Code\\Wordle\\all.txt", "r");
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