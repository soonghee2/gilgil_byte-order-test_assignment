#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t plus(uint32_t n1, uint32_t n2){
	return n1+n2;
}

uint32_t read_binfile_to_uint32_t(char *filename){
	FILE* f;
	uint32_t temp;

	f=fopen(filename, "rb");
	if (filename ==NULL){
		fprintf(stderr, "error oepning file: %s", filename);
		exit(EXIT_FAILURE);
	}

	size_t read_size =fread(&temp, sizeof(uint32_t), 1, f);
	if (read_size != 1){
		fprintf(stderr, "error reading file: %s", filename);
		fclose(f);
		exit(EXIT_FAILURE);
	}
	
	fclose(f);
	return ntohl(temp);
}

char* write(uint32_t n){
	int length = snprintf(NULL, 0 ,"%d(0x%x)", n, n);
	if (length<0){exit(EXIT_FAILURE);}

	char *str = (char *)malloc(length+1);
	if (str == NULL){
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	snprintf(str, length +1, "%d(0x%x)", n, n);
	return str;
}

int main(int argc, char *argv[]){

	if(argc != 3){
		fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	uint32_t n1, n2, n3;
	char *filename1=argv[1];
	char *filename2=argv[2];
	char *str1, *str2, *str3;

	n1=read_binfile_to_uint32_t(filename1);
	n2=read_binfile_to_uint32_t(filename2);
	n3=n1+n2;

	str1=write(n1);
	str2=write(n2);
	str3=write(n3);

//	printf("%s + %s = %s", write(n1), write(n2), write(n3));
	//printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n3, n3);
	printf("%s + %s = %s", str1, str2, str3);

	free(str1);
	free(str2);
	free(str3);
	
	return 0;
}
