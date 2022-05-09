#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char wordDatabase[10000][6] = {
"aaron","aback","abaft","abase","abash","abate","abbey","abbot","abeam","abele","abets","abhor","abide","abies","abler","abode","abomb","abort","about","above","abuse","abuzz","abysm",
"abyss","accra","acerb","acers","ached","aches","acids","acorn","acres","acrid","acted","actor","acute","adage","adapt","added","adder","addle","adept","adhoc","adieu","adios","adlib",
"adman","admen","admin","admit","admix","adobe","adobo","adopt","adore","adorn","adult","aegir","aegis","aeons","aerie","aesop","affix","afire","afoot","afoul","afros","after","again",
"agape","agate","agave","agent","agile","aging","agism","aglow","agone","agony","agora","agree","ahead","aided","aider","aides","aimed","aimer","aired","aisle","alack","alarm","album",
"alder","alert","algae","algal","alias","alibi","alice","alien",
}; // 5/9 100°³
int workDatabaseSize = 100;

int main(void) {
	srand(time(NULL));
	printf("%s", wordDatabase[rand() % 100]);
}