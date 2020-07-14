#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>

int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
        if((fp1 = fopen(argv[1], "r")) == NULL){
            perror("file1 open error");
            exit(-1);
        }
        if((fp2 = fopen(argv[2], "r")) == NULL){
            perror("file2 open error");
            exit(-1);
        }
	
	size_t n;
	uint32_t n1, n2;
        if((n = fread(&n1, sizeof(uint32_t), 1, fp1)) == -1){
            perror("file1 read error");
            exit(-1);
        }
        if((n = fread(&n2, sizeof(uint32_t), 1, fp2)) == -1){
            perror("file2 read error");
            exit(-1);
        }

        if((n1 = ntohl(n1)) == -1){
            perror("NBO to HBO failed");
            exit(-1);
        }
        if((n2 = ntohl(n2)) == -1){
            perror("NBO to HBO failed");
            exit(-1);
        }

        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);
	
	return 0;
}
