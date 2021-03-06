#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	for (int i = 1; i < argc; i++) {

	   char buffer[1024];
	   int ReadFile;

	   /* open input and output files */
	   ReadFile = open(argv[i], O_RDONLY);

	   /* If unable to open file */
	   if (ReadFile == -1) {
		perror("Error");
		return(-1);
	   }

	   /* read and write byte by byte */
	   /* read function returns 0 when EOF - END OF FILE */
	   while ( read(ReadFile, buffer, 1) > 0 ) { 
		/* write to standard output, file discriptor = 1 */
		write(1, buffer, 1);
	   }

	   /* close file */
	   close(ReadFile);
	}
}
