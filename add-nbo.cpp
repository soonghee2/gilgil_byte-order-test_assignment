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

int main(int argc, char *argv[]){

	if(argc != 3){return 1;}
	
	uint32_t n1, n2, n3;
	char *filename1=argv[1];
	char *filename2=argv[2];

	n1=read_binfile_to_uint32_t(filename1);
	n2=read_binfile_to_uint32_t(filename2);
	n3=plus(n1, n2);
	
//	printf("%s + %s = %s", write(n1), write(n2), write(n3));
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", n1, n1, n2, n2, n3, n3);
	return 0;
}
