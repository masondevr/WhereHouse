/**
 * camera interrupt handler and stuff
 */

#include <stdio.h>
#include <linux/gpio.h>
#include<stdlib.h>
#include <unistd.h>
#include <poll.h>
#include <fcntl.h>
#include <time.h>


int main() {
	char str[256];
	int fd, gpio = 26;
	struct pollfd pfd;
	char buf[8];

	// enable pin 21
	// TODO: change pin to beter option on Pi Zero W
	FILE * exp = fopen("/sys/class/gpio/export", "w");
	if (exp == NULL) {
		// TODO:
		printf("failed to export pin\n");
		exit(1);
	}
	sprintf(str, "%d", gpio);
	fprintf(exp, str);
	fclose(exp);
	printf("pin exported\n");
	system("sleep 0.050");
	
	// set to input
	sprintf(str, "/sys/class/gpio/gpio%d/direction", gpio);
	FILE *in = fopen(str, "w");
	if (in == NULL) {
		// TODO:
		printf("failed to set pin as input\n");
		exit(1);
	}
	fprintf(in, "in");
	fclose(in);
	printf("pin set as input\n");

	// set to rising edge trigger
	sprintf(str ,"/sys/class/gpio/gpio%d/edge", gpio);
	FILE *edge = fopen(str, "w");
	if (edge == NULL) {
		printf("failed to set rising edge\n");
		exit(1);
	}
	fprintf(edge, "rising");
	fclose(edge);
	printf("pin set to rising edge\n");

	// wait for the value to be 1
	sprintf(str, "/sys/class/gpio/gpio%d/value", gpio);
	
	printf("beginning to wait for interrupt\n");
	while (1) {
		if ((fd = open(str, O_RDONLY)) < 0) {
			fprintf(stderr, "Failed, gpio %d not exported.\n", gpio);
			// TODO: handle this error a better way
			exit(1);
		}
	
		pfd.fd = fd;
		pfd.events = POLLPRI;
	
		lseek(fd, 0, SEEK_SET);
		read(fd, buf, sizeof(buf));
		
		
		poll(&pfd, 1, -1);
		close(fd);
		FILE *fp;
		char path[1035];
		fp = popen("/usr/bin/python /home/user473/Documents/WhereHouse/Camera.py", 
			"r");
		if(fp == NULL) {
				printf("Error running python camera file");
				exit(1);
		}
		while(fgets(path, sizeof(path), fp) != NULL) {
			printf("%s", path);
		}
		pclose(fp);
		//printf("interrupt recieved\n");
		//system("python /home/user473/Documents/WhereHouse/Camera.py");
		//printf("resuming waiting...\n");
	
		lseek(fd, 0, SEEK_SET);
		read(fd, buf, sizeof(buf));
	}	
}
