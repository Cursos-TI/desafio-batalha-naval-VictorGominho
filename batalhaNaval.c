#include <stdio.h>

int main() {
     int tabuleiro[10][10];
     // Preenchendo o tabuleiro de "água"
     for (int i = 0; i < 10; i++)
     {
          for (int u = 0; u < 10; u++)
          {
               tabuleiro[i][u] = 0;
          }   
     }
     
     int navio1[3] = {3, 3, 3};
     int navio2[3] = {3, 3, 3};
     // Colocando os navios
     for (int i = 0; i < (sizeof(navio1) / sizeof(navio1[0])); i++)
     {
          if (tabuleiro[2][i+2] == 0) // Checando se o espaço só tem água
          {
               tabuleiro[2][i+2] = navio1[i];
          }      
     }

     for (int i = 0; i < (sizeof(navio2) / sizeof(navio2[0])); i++)
     {
          if (tabuleiro[i+5][7] == 0)
          {
               tabuleiro[i+5][7] = navio2[i];
          }
     }

     // Mostrando o tabuleiro
     for (int i = 0; i < 10; i++)
     {
          for (int u = 0; u < 10; u++)
          {
               printf("%d ", tabuleiro[i][u]);
          }
          printf("\n");
     }   
}