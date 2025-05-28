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

     // Habilidades Especiais
     int coneAoe[3][5] = {
          {0, 0, 1, 0, 0},
          {0, 1, 1, 1, 0},
          {1, 1, 1, 1, 1}
     };

     int cruzAoe[3][5] = {
          {0, 0, 1, 0, 0},
          {1, 1, 1, 1, 1},
          {0, 0, 1, 0, 0}
     };

     int octaAoe[3][5] = {
          {0, 0, 1, 0, 0},
          {0, 1, 1, 1, 0},
          {0, 0, 1, 0, 0}
     };
     
     // Colocando os navios
     int navio1[3] = {3, 3, 3};
     int navio2[3] = {3, 3, 3};
     int navio3[3] = {3, 3, 3};
     int navio4[3] = {3, 3, 3};

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

     for (int i = 0; i < (sizeof(navio3) / sizeof(navio3[0])); i++)
     {
          if (tabuleiro[i][6+i] == 0)
          {
               tabuleiro[i][6+i] = navio3[i];
          }
     }

     for (int i = 0; i < (sizeof(navio4) / sizeof(navio4[0])); i++)
     {
          if (tabuleiro[i+6][3-i] == 0)
          {
               tabuleiro[i+6][3-i] = navio4[i];
          }
     }

     // Usando habilidades
     // Cone
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (tabuleiro[i+1][j] == 0 && coneAoe[i][j] == 1)
               {
                    tabuleiro[i+1][j] = 5;
               } else if (tabuleiro[i+1][j] == 3 && coneAoe[i][j] == 1)
               {
                    tabuleiro[i+1][j] = 7;
               }  
          }   
     }

     // Cruz
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (tabuleiro[i+2][j+5] == 0 && cruzAoe[i][j] == 1)
               {
                    tabuleiro[i+2][j+5] = 5;
               } else if (tabuleiro[i+2][j+5] == 3 && cruzAoe[i][j] == 1)
               {
                    tabuleiro[i+2][j+5] = 7;
               }  
          }   
     }

     // Octaedro
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; j < 5; j++)
          {
               if (tabuleiro[i+7][j+5] == 0 && octaAoe[i][j] == 1)
               {
                    tabuleiro[i+7][j+5] = 5;
               } else if (tabuleiro[i+7][j+5] == 3 && octaAoe[i][j] == 1)
               {
                    tabuleiro[i+7][j+5] = 7;
               }  
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
     printf("Legenda: \n 0 - Água\n 3 - Navio\n 5 - Habilidade Especial\n 7 - Navio Atingido");
     
     return 0;
}