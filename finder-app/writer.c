#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
	printf("Error: Invalid number of arguments.\n");
        printf("Usage: %s <file path> <text>\n", argv[0]);
        return 1;
    }

    char *writefile = argv[1];	//File path
    char *writestr = argv[2];	// String to apend	

    // Check if file exists before appending
    struct stat st = {0};
    if (stat(writefile, &st) == -1) {
        fprintf(stderr, "File %s does not exist — refusing to create it\n", writefile);
        syslog(LOG_ERR, "File %s does not exist — not appending", writefile);
        closelog();
        return 1;
    }
    openlog("writer", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG , "Writing %s to %s, where %s is the text string written to file (second argument) and %s is the  				 file created by the script", writestr, writefile, writestr, writefile);


    // Write text to file
    FILE *fp = fopen(writefile, "a");
    if (!fp) {
        perror("fopen failed");
        syslog(LOG_ERR, "Failed to open file %s for append", writefile);
        closelog();
        return 1;
    }

    fprintf(fp, "%s\n", writestr);
    fclose(fp);

    printf("Wrote text to %s\n", writefile);
    return 0;
}
