#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char wordDatabase[10000][6] = {
"aaron","aback","abaft","abase","abash","abate","abbey","abbot","abeam","abele","abets","abhor","abide","abies","abler","abode","abomb","abort","about","above","abuse","abuzz","abysm",
"abyss","accra","acerb","acers","ached","aches","acids","acorn","acres","acrid","acted","actor","acute","adage","adapt","added","adder","addle","adept","adhoc","adieu","adios","adlib",
"adman","admen","admin","admit","admix","adobe","adobo","adopt","adore","adorn","adult","aegir","aegis","aeons","aerie","aesop","affix","afire","afoot","afoul","afros","after","again",
"agape","agate","agave","agent","agile","aging","agism","aglow","agone","agony","agora","agree","ahead","aided","aider","aides","aimed","aimer","aired","aisle","alack","alarm","album",
"alder","alert","algae","algal","alias","alibi","alice","alien",

"align","alike","aline","alive","alkyl","allah","allay","alley","allot","allow","alloy","aloes","aloft","aloha","alone","along","aloof","aloud","alpha","altar","alter","amass",
"amaze","amber","ambit","amble","ameba","ameer","amend","amens","amide","amigo","amine","amino","amiss","amity","amman","among","amour","ample","amply","amuck","amuse","anamy",
"andes","anele","angel","anger","angle","anglo","angry","angst","anion","anise","ankle","annal","annex","annoy","annul","anode","antic","antsy","anvil","aorta","apace","apart",
"apery","aphid","apian","aping","apish","apnea","appal","apple","apply","appro","april","apron","apses","apsis","aptly","arabs","araks","arbor","arced","ardor","areal","areas",
"arena","arent","argon","argot","argue","argus","arias","aries","arise","armed","armor","aroma",

}; // 5/11 200°³
int workDatabaseSize = 100;

int main(void) {
	srand(time(NULL));
	printf("%s", wordDatabase[rand() % 200]);
}