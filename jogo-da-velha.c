#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

void main(void) {
    char done;
    printf("Jogo da veia (v1.0.00)\n");
    printf("Contra o CPU.\n");

    done = ' ';
    init_matrix();
    do{
        disp_matrix();
        get_player_move();
        done = check();
        if (done !=' ') {
            break;
        }
        get_computer_move();
        done = check();    
    } while (done == ' ');
    if (done == 'X'){
        printf("Ganhou!\n");
    } else {
        printf("Perdeu!\n");
    }
    disp_matrix();
}

void init_matrix(void){
    int i, j;
    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            matrix [i][j] = ' ';
        }
    }
}

void get_player_move(void){
    int x, y;

    printf("Digite, em coordenadas (x,y), onde gostaria de por o X:\n");
    scanf("%d %d", &x, &y);

    x--;y--;

    if (matrix[x][y] != ' '){
        printf("Posicao invalida, tente novamente. \n");
        get_player_move();
    } else {
        matrix[x][y] = 'X';
    }
}
void get_computer_move(void) { 
    /*int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (matrix[i][j] == ' '){
                break;
            } 
        }
         if (matrix[i][j] == ' '){
            break;
        }
    }
    
    if (i * j != 9){
        matrix[i][j] = 'O';
    } else {
        printf("Empate!\n");
        exit(0);
    }    
*/        
    int posx, posy, times = 0;

    for(int i = 0; i < 9; i++){
        posx = 1+(rand() % 3);
        posy = 1+(rand() % 3);
        times++;

        posx--;
        posy--;

        if (matrix[posx][posy] == ' '){
            break;
        }
    }
    if (times != 9) {
        matrix[posx][posy] = '0';
    } else {
        printf("Empate!\n");
        exit(0);
    }
}
void disp_matrix(void) {
    int t;
    
    for(t=0; t < 3; t++) {
        printf(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
        if (t != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}
char check(void) {
    int i;

    for (i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]){ //check lines
            return matrix[i][0];
        }
    }

    for (i = 0; i < 3; i++){
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]){ // check columns
            return matrix[0][i];
        }
    }   

    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){ // check primary diagonal
        return matrix[0][0];
    }     
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]){ // check secondary diagonal
        return matrix[0][2];
    }
    
  return ' ';
}