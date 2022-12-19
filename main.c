/* PACMAN 
AUTHOR: K RAJA SUNDAR (NFSU'27)
DATE: 14-12-2022*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char base[12][42];
int score=0, move_num=0, killer_num=6;
void build_print(char base[12][42]);
void killer(char base[12][42]), reviver(char base[12][42]),end(int score);
int random(int x, int y);

void main(){
    // storing the playing field as 2d array and defining field
    char base[12][42];
    int i, j;
    for(i=1;i<42;i++) {
        base[0][i]='_';
        base[11][i]='_';
    }
    for(i=1;i<12;i++) {
        base[i][0]='|';
        base[i][41]='|';
    }
    for(i=1;i<11;i++){
        for(j=1;j<41;j++){
            base[i][j]='.';
        }
    }
    int pos1=1,pos2=4;    //position of the player
    base[pos1][pos2]='@';
    // setting blocks
    srand(time(0));
    int placed=0;
    while(1){
        int rand1= (rand() % (10 - 1 + 1)) + 1, rand2= (rand() % (35 - 1 + 1)) + 1;
        if (base[rand1][rand2]=='.'){
            base[rand1][rand2]='|';
            placed++;
        }
        if (placed==35) break;
    }
    killer(base);
    build_print(base);
    // handling moves 
    while (1){
        char move=getch();
        if (move=='A'||move=='a'){
            move_num++;
            if (base[pos1][pos2-1]=='.'||base[pos1][pos2-1]==' '){
                base[pos1][pos2]=' ';
                pos2--;
                base[pos1][pos2]='@';
                if (base[pos1][pos2-1]=='.') score++;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                build_print(base);
            }
            else if (base[pos1][pos2-1]=='&'){
                end(score);
                break;
            }
            else if (base[pos1][pos2-1]=="#"){
                score+=10;
                killer_num--;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                printf("You have destroyed one killer!!!");
                build_print(base);
            }
        }
        else if (move=='d'||move=='D'){
            move_num++;
            if (base[pos1][pos2+1]=='.'||base[pos1][pos2+1]==' '){
                base[pos1][pos2]=' ';
                pos2++;
                base[pos1][pos2]='@';
                if (base[pos1][pos2+1]=='.') score++;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                build_print(base);
            }
            else if (base[pos1][pos2+1]=='&'){
                end(score);
                break;
            }
            else if (base[pos1][pos2+1]=="#"){
                score+=10;
                killer_num--;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                printf("You have destroyed one killer!!!");
                build_print(base);
            }
        }
        else if (move=='S'||move=='s'){
            move_num++;
            if (base[pos1+1][pos2]=='.'||base[pos1+1][pos2]==' '){
                base[pos1][pos2]=' ';
                pos1++;
                base[pos1][pos2]='@';
                if (base[pos1+1][pos2]=='.') score++;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                build_print(base);
            }
            else if (base[pos1+1][pos2]=='&'){
                end(score);
                break;
            }
            else if (base[pos1+1][pos2]=="#"){
                score+=10;
                killer_num--;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                printf("You have destroyed one killer!!!");
                build_print(base);
            }
        }
        else if (move=='W'||move=='w'){
            move_num++;
            if (base[pos1-1][pos2]=='.'||base[pos1-1][pos2]==' '){
                base[pos1][pos2]=' ';
                pos1--;
                base[pos1][pos2]='@';
                if (base[pos1-1][pos2]=='.') score++;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                build_print(base);
            }
            else if (base[pos1-1][pos2]=='&'){
                end(score);
                break;
            }
            else if (base[pos1-1][pos2]=="#"){
                score+=10;
                killer_num--;
                if (move_num%10!=0)
                    killer(base);
                else reviver(base);
                printf("You have destroyed one killer!!!");
                build_print(base);
            }
        }
        else {
            end(score);
            break;
        }
    }
}

// Message to end the game
void end(int score){
    printf("Game Over!!!\nYour Score is %d\nPress any key to exit...", score);
    getch();
}


// For printing the base whenever required
void build_print(char base[12][42]) {
    system("Cls");
    int i,j;
    for(i=0;i<12;i++){
        for (j=0;j<42;j++){
            printf("%c", base[i][j]);
        }
        printf("\n %c", 169);
    }
}

// Placing the killers
void killer(char base[12][42]){
    srand(time(0));
    int placed=0;
    int i,j;
    // first removing all the previous killers
    for(i=1;i<11;i++){
        for (j=1;j<41;j++){
            if (base[i][j]=='&'||base[i][j]=='#'){
                base[i][j]='.';
            }
        }
    }
    // Then putting the killer at random locations
    while(1){
        int rand1= (rand() % (10 - 1 + 1)) + 1, rand2= (rand() % (35 - 1 + 1)) + 1;
        if (base[rand1][rand2]=='.'){
            base[rand1][rand2]='&';
            placed++;
        }
        if (placed==killer_num+1) break;
    }
}

//Placing the revivers
void reviver(char base[12][42]){
    srand(time(0));
    int placed=0;
    int i,j;
    // first removing all the previous killers
    for(i=1;i<11;i++){
        for (j=1;j<41;j++){
            if (base[i][j]=='&'||base[i][j]=='#'){
                base[i][j]='.';
            }
        }
    }
    // Then putting the reviver at random locations
    while(1){
        int rand1= (rand() % (10 - 1 + 1)) + 1, rand2= (rand() % (35 - 1 + 1)) + 1;
        if (base[rand1][rand2]=='.'){
            base[rand1][rand2]='#';
            placed++;
        }
        if (placed==killer_num+1) break;
    }
}