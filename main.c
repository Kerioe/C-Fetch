#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <sys/utsname.h>
#include "Filesys.h"

struct winsize w;

void GetTime() {
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	//24
	int a = 0;
	while (a < w.ws_col - 24) {
		printf(" ");
		a++;
	}
	printf("%s%s%s", BLINK, asctime (timeinfo), NORM2);
}

void Spects() {
	printf("\e[1;1H\e[2J");
	if (OperatingSystemType == 1) file = fopen("Graphics/Ubuntu.txt", "r");
	if (OperatingSystemType == 2) file = fopen("Graphics/Debian.txt", "r");
	if (OperatingSystemType == 3) file = fopen("Graphics/Arch.txt", "r");
	if (OperatingSystemType == 4) file = fopen("Graphics/Manjaro.txt", "r");
	if (OperatingSystemType == 99) file = fopen("Graphics/GameCube.txt", "r");
	FileLoader();

	struct utsname uname_pointer;

	ioctl(0, TIOCGWINSZ, &w);

	uname(&uname_pointer);


 	printf("%s%sUser%s ~ %s\n", BOLD, UNDERLINE,NORM2, uname_pointer.nodename);
 	printf("%s%sOperating System%s ~ %s %s\n", BOLD, UNDERLINE,NORM2, uname_pointer.version, uname_pointer.machine);
	printf("%s%sTerminal Size%s ~ %dx%d\n", BOLD, UNDERLINE, NORM2, w.ws_col, w.ws_row);

}

void debug() {
	printf("%s%sC Fetch Debug Mode%s\n", BOLD, BLINK, NORM2);
	printf("%s1: Ubuntu\n2: Debian\n3: Arch\n4: Manjaro\n%s", ITALIC, NORM2);
	printf("DEBUG > ");
	scanf("%i", &OperatingSystemType);
}

int main() {
	debug();
	ioctl(0, TIOCGWINSZ, &w);

	Spects();
	GetTime();
	int a = 0;
	while (a < w.ws_col) {
		printf("-");
		a++;
	}
	printf("\n");
	return 0;
}
