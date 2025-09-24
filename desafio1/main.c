#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  FILE *file_pointer = NULL;
  char buffer[512];
  int file_size;
  char parti1[16];
  char parti2[16];
  
  // Abre o arquivo
  file_pointer = fopen("mbr.bin", "r");
  if (file_pointer == NULL) {
    printf("Erro ao abrir o arquivo: %i", errno);
    return 1;
  }
  // Vai até o fim do arquivo
  fseek(file_pointer, 0L, SEEK_END);
  file_size = ftell(file_pointer);
  printf("O tamanho do arquivo é de %i bytes\n", file_size);

  // Volta pro começo do arquivo
  fseek(file_pointer, 0, SEEK_SET);
  // Lê o arquivo com o tamanho do buffer
  fread(buffer, sizeof buffer, 1, file_pointer);

  for (int i = 446; i <= 509; i++) {
    //printf("%x\n", buffer[i]);

  }
  for(int i = 0;i<16;i++){
    parti1[i] = buffer[446+i];
    printf("%d %x\n", i,parti1[i]);
  }
  for(int i = 0;i<16;i++){
    parti2[i] = buffer[462+i];
    printf("%d %x\n", i,parti2[i]);
  }
  printf("%p\n",&buffer[446]);
  char *p = &buffer[446];
  printf("%x\n",p);
  fclose(file_pointer);
  return 0;
}







//https://thestarman.pcministry.com/asm/mbr/PartTables.htm

//sudo fdisk /dev/sda
//p