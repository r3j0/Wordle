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

"arose","arras","array","arrow","arson","artsy","ascot","ashen","ashes","asian","aside","asked","asker","askew","aspic","assay","asses","asset","aster","astir",
"aswan","ataxy","atilt","atlas","atoll","atoms","atone","attar","attic","audio","audit","auger","augur","aunts","aunty","aural","auras","auric","avail","avast",
"avens","avers","avert","avian","avoid","await","awake","award","aware","awash","awful","awing","awoke","axial","axing","axiom","axles","axons","aztec","azure",
"babas","babel","babes","backs","bacon","baddy","bader","badge","badly","bagel","baggy","bails","baits","baked","baker","bakes","baldy","baled","bales","balky",
"balls","bally","balms","balmy","balsa","banal","bands","bandy","bangs","banjo","banks","banns","barbs","bards","bared","barer","bares","barge","barks","barky",

"barmy","barns","baron","barre","basal","based","baser","bases","basic","basil","basin","basis","basks","basso","baste","batch","bated","bates","bathe","baths",
"batik","baton","batty","baulk","bawdy","bawls","bayed","bayer","bayou","bazar","beach","beads","beady","beaks","beams","beamy","beans","beany","beard","bears",
"beast","beats","beaus","beaut","beaux","bebop","becks","bedim","beech","beefs","beefy","beeps","beers","beery","beets","befit","befog","began","begat","beget",
"begin","begot","begun","beige","being","belay","belch","belie","belle","bells","belly","below","belts","bench","bends","beret","bergs","berme","berry","berth",
"beryl","beset","besom","besot","bests","betel","betsy","bevel","bevvy","bhang","bible","biddy","bided","bides","bidet","bifid","bigot","bijou","biker","bikes",

"biles","bilge","bills","billy","bimbo","binds","binge","bingo","biota","biped","birch","birds","birth","bison","bitch","biter","bites","bitts","bitty","blabs",
"black","blade","blame","bland","blank","blare","blase","blast","blate","blaze","bleak","bleat","bleed","bleep","blend","bless","blimp","blind","blink","blips",
"bliss","blitz","bloat","blobs","block","blocs","bloke","blond","blood","bloom","blots","blown","blows","blowy","bluer","blues","bluff","blunt","blurb","blurs",
"blurt","blush","board","boars","boast","boats","bobby","boded","bodes","bodge","boers","boeuf","bogey","boggy","bogie","bogus","boils","bolts","bombs","bonce",
"bonds","boned","bones","boney","bongo","bongs","bonny","bonus","boobs","booby","booed","books","booms","boons","boors","boost","booth","boots","booty","booze",

}; // 5/20 5 / 48
int workDatabaseSize = 100;

int main(void) {
	srand(time(NULL));
	printf("%s", wordDatabase[rand() % 200]);
}