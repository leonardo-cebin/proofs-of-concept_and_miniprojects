#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int states[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, i;
  char yy, yx;
  int line = 0;
  int b = 0, z;
  int row, correct;
  int player = 1, place;
  bool active = true;
  int verifyLine, count = 1;

  for (i = 0; i < 8; i++)
    states[i] = 0;

  printf("SHALL WE PLAY A GAME (Y/N) \n");
  scanf("%c", &yy);
  if (yy == 'Y' || yy == 'y') {
    puts("Ok, escolha seu jogo!\n1. Jogo da Velha\n2. Guerra Termonuclear");
    scanf("%d", &i);
    if (i == 2) {

      sleep(1);

      printf("\n\n\n\n\n\n                              ____/ (  (    )   )  "
             "\\___\n         "
             "                   /( (  (  )   _    ))  )   )\\\n              "
             "            ((     (   )(    )  )   (   )  )\n                 "
             "       ((/  ( _(   )   (   _) ) (  () )  )\n                   "
             "    ( (  ( (_)   ((    (   )  .((_ ) .  )_\n                   "
             "   ( (  )    (      (  )    )   ) . ) (   )\n                  "
             "   (  (   (  (   ) (  _  ( _) ).  ) . ) ) ( )\n                "
             "     ( (  (   ) (  )   (  ))     ) _)(   )  )  )\n             "
             "       ( (  ( \ ) (    (_  ( ) ( )  )   ) )  )) ( )\n          "
             "           (  (   (  (   (_ ( ) ( _    )  ) (  )  )   )\n      "
             "              ( (  ( (  (  )     (_  )  ) )  _)   ) _( ( )\n   "
             "                  ((  (   )(    (     _    )   _) _(_ (  (_ )\n"
             "                      (_((__(_(__(( ( ( |  ) ) ) )_))__))_)___)\n"
             "                        ((__)        \\||lll|l||///          "
             "\\_))\n                               (   /(/ (  )  ) )\\   "
             ")\n                             (    ( ( ( | | ) ) )\\   )\n"
             "                                (   /(| / ( )) ) ) )) )\n      "
             "                      (     ( ((((_(|)_)))))     )\n           "
             "                  (      ||\(|(|)|/||     )\n                  "
             "         (        |(||(||)||||        )\n                      "
             "       (     //|/l|||)|\\ \\     )\n                           "
             "(/ / //  /|//||||\\  \\ \\  \\ _)\n   "
             "\n--------------------------------------------------"
             "");
    } else if (i == 1) {
      system("clear");
      while (active) {
        printf("\n\n\n\n\n");

        if (player == 1) {
          printf("Eh o turno do jogador 0%d (X)\n", player);

          printf("| 1 | 2 | 3 |\n");

          printf("| 4 | 5 | 6 |\n");

          printf("| 7 | 8 | 9 |\n\n\nEscolha sua casa: ");
          scanf("%d", &place);

          if (states[place - 1] == 0) {
            states[place - 1] = 1;

          } else {
            printf("JOGADA INVALIDA: ESSA CASA JA FOI ESCOLHIDA!\nTENTE "
                   "NOVAMENTE:");
            scanf("%d", &place);
            states[place - 1] = 1;
          }

          player++;
        } else {
          printf("Eh o turno do jogador 0%d (O)\n", player);

          printf("| 1 | 2 | 3 |\n");

          printf("| 4 | 5 | 6 |\n");

          printf("| 7 | 8 | 9 |\n\n\nEscolha sua casa: ");
          scanf("%d", &place);

          if (states[place - 1] == 0) {
            states[place - 1] = 2;
          } else {
            printf("JOGADA INVALIDA: ESSA CASA JA FOI ESCOLHIDA!\nTENTE "
                   "NOVAMENTE:");
            scanf("%d", &place);
            states[place - 1] = 2;
          }

          player--;
        }

        count++; // Contador para empates

        system("clear");

        for (row = 0; row < 9; row += 3) {
          line = 0;

          while (line < 5) {
            if (line == 0) {
              printf("####################################");
            }
            for (z = 0; z < 3; z++) {
              correct = z + row;

              if (line == 1 || line == 4) {
                if (states[correct] == 0) {
                  printf("#..........#");
                } else if (states[correct] == 1) {
                  printf("#...##.##..#");
                } else if (states[correct] == 2) {
                  printf("#...#..#...#");
                }

              } else if (line == 2 || line == 3) {
                if (states[correct] == 0) {
                  printf("#..........#");
                } else if (states[correct] == 1) {
                  printf("#....###...#");
                } else if (states[correct] == 2) {
                  printf("#..#....#..#");
                }
              }
            }
            printf("\n");
            line++;
          }
        }
        printf("####################################");

        for (verifyLine = 0; verifyLine < 8; verifyLine += 3) {
          if ((states[verifyLine] == states[verifyLine + 1] &&
               states[verifyLine + 1] == states[verifyLine + 2]) &&
              states[verifyLine] != 0) {

            active = false;

            // Atualização de tela
            system("clear");

            // Tentativa de riscar horizontalmente onde há vitória
            for (row = 0; row < 9; row += 3) {
              line = 0;

              while (line < 5) {
                if (line == 0) {
                  if (row != 0)
                    printf("####################################");
                }
                for (z = 0; z < 3; z++) {
                  correct = z + row;

                  if (line == 1 || line == 4) {
                    if (states[correct] == 0) {
                      printf("#..........#");
                    } else if (states[correct] == 1) {
                      printf("#...##.##..#");
                    } else if (states[correct] == 2) {
                      printf("#...#..#...#");
                    }

                  } else if (line == 2 || line == 3) {
                    if (states[correct] == 0) {
                      printf("#..........#");
                    } else if ((states[correct] == 1 || states[correct] == 2) &&
                               row == verifyLine) {
                      printf("////////////");
                    } else if (states[correct] == 1 && row != verifyLine) {
                      printf("#....###...#");
                    } else if (states[correct] == 2 && row != verifyLine) {
                      printf("#..#....#..#");
                    }
                  }
                }
                printf("\n");
                line++;
              }
            }
            printf("####################################");

            // Checagens horizontais 100% sem bugs TESTADO!
          }
        }

        for (verifyLine = 0; verifyLine < 3; verifyLine++) {
          if ((states[verifyLine] == states[verifyLine + 3] &&
               states[verifyLine + 3] == states[verifyLine + 6]) &&
              states[verifyLine] != 0) {

            // printf("\n%d\t%d\t%d", verifyLine, verifyLine + 3, verifyLine +
            // 6);   DEBUG
            active = false;

            // Atualização de tela
            system("clear");

            // Tentativa de riscar verticalmente onde há vitória
            for (row = 0; row < 9; row += 3) {
              line = 0;

              while (line < 5) {
                if (line == 0) {
                  if (row != 0)
                    printf("####################################");
                }
                for (z = 0; z < 3; z++) {
                  correct = z + row;

                  if (line == 1 || line == 4) {
                    if (states[correct] == 0) {
                      printf("#..........#");
                    } else if (states[correct] == 1 && z == verifyLine) {
                      printf("#...##|##..#");
                    } else if (states[correct] == 1) {
                      printf("#...##.##..#");
                    } else if (states[correct] == 2 && z == verifyLine) {
                      printf("#...#||#...#");
                    } else if (states[correct] == 2) {
                      printf("#...#..#...#");
                    }

                  } else if (line == 2 || line == 3) {
                    if (states[correct] == 0) {
                      printf("#..........#");
                    } else if (states[correct] == 1 && z == verifyLine) {
                      printf("#....#|#...#");
                    } else if (states[correct] == 1) {
                      printf("#....###...#");
                    } else if (states[correct] == 2 && z == verifyLine) {
                      printf("#..#.||.#..#");
                    } else if (states[correct] == 2) {
                      printf("#..#....#..#");
                    }
                  }
                }
                printf("\n");
                line++;
              }
            }
            printf("####################################");
            // Aqui terminam os riscadores
          }
        }
        if ((states[0] == states[4] && states[4] == states[8] &&
             states[4] != 0)) {
          active = false;
          // Diagonal esquerda

        } else if ((states[2] == states[4] && states[4] == states[6] &&
                    states[2] != 0)) {
          active = false;

          // Diagonal direita
        }
        if (count == 10) {
          printf("\n\nFOI UM EMPATE!\n\nAGUARDE...");

          sleep(3);

          states[0] = states[1] = states[2] = states[3] = states[4] =
              states[5] = states[6] = states[7] = states[8] = 0;
          count = 1;
        }
      }
    }

    if (!active) {

      if (player == 1) {
        printf("\n\n\nJOGADOR 2 VENCE!");
      } else {
        printf("\n\n\nJOGADOR 1 VENCE!");
      }
    }

    return 0;
  }
}
