/*
Follow Direction

In this problem, your program will simulate a robot moving about a grid. You are given a set of directions. Your job is to compute your final position. 
  
 Details: 

 0) Directions will appear 1 per line. 
 1) You start facing North at 0,0. 
 2) Move directions will look like this: Move <signed 32-bit integer>.   
 3) Turn directions will look like this: Turn <left|right> 
 4) Turns are relative to the direction you are currently facing. 
 5) Interpret negative movement as moving backwards *without* changing direction. 
 6) Express your answer as comma-separated integer pair where the first number is the final displacement travelled along East-West, and the second is the final              displacement travelled along North-South.

 */

#include<stdio.h>
#include<stdlib.h>

struct position {
   int x;
   int y;
   int ch_x;  //1 means, robot faces in East direction, -1 means faces West, 0 means it faces North or South
   int ch_y;  //1 means, robot faces in North direction, -1 means faces sOuth, 0 means it faces E or W
};

static struct position x_y = {0,0,0,1};


void direction (char inst[], char direc[], int steps) {
    //For Turn
    if(!strcmp(inst,"Turn")){
	//For Turn right
	if(!strcmp(direc,"right")){
	    if(x_y.ch_y == 1){
		x_y.ch_y = 0;
		x_y.ch_x = 1;
	    }
	    else if(x_y.ch_x == 1){
		x_y.ch_x = 0;
		x_y.ch_y = -1;
	    }
	    else if(x_y.ch_y == -1){
		x_y.ch_y = 0;
		x_y.ch_x = -1;
	    }
	    else if(x_y.ch_x == -1){
		x_y.ch_x = 0;
		x_y.ch_y = 1;
	    }
	}
	//For Turn left
	if(!strcmp(direc,"left")){
	    if(x_y.ch_y == 1){
		x_y.ch_y = 0;
		x_y.ch_x = -1;
	    }
	    else if(x_y.ch_x == 1){
		x_y.ch_x = 0;
		x_y.ch_y = 1;
	    }
	    else if(x_y.ch_y == -1){
		x_y.ch_y = 0;
		x_y.ch_x = 1;
	    }
	    else if(x_y.ch_x == -1){
		x_y.ch_x = 0;
		x_y.ch_y = -1;
	    }
	}
    }
    //End of Turn 
    //Begin analysing Move
    if (!strcmp(inst,"Move")){
	//
	if (x_y.ch_x == 1){
	    x_y.x += steps;
	}
	else if(x_y.ch_x == -1){
	    x_y.ch_x -= steps;
	}
	else if (x_y.ch_y == 1){
	    x_y.y += steps;
	}
	else if(x_y.ch_y == -1){
	    x_y.ch_y -= steps;
	}
    }
    printf("\n Robot move x,y is (%d, %d) and direction is ch_x = %d ch_y = %d", x_y.x, x_y.y, x_y.ch_x, x_y.ch_y);
}

void main() {
    char inst[5]= "\0";
    char line[20] = "\0";
    char direc[5]= "\0";
    int steps= 0;
    FILE *fd = fopen("SampleInput.txt","r");
    printf("\n value of ch_x if 1 means, robot faces in East direction, -1 means faces West, 0 means it faces North or South \nValue of ch_y if 1 means, robot faces in North direction, -1 means faces sOuth, 0 means it faces East or West \n");

    while(!feof(fd)) {
	fgets(line, sizeof(line), fd);
	if (line[0] == 'M') {
	    sscanf(line, "%s %d", inst, &steps);
	    printf("\n Instruction is %s, steps is %d", inst, steps);
	    direction(inst, NULL, steps); 

	}
	else if(line[0] == 'T'){
	    sscanf(line,"%s %s", inst, direc);
	    printf("\n Instruction is %s, direction is %s", inst, direc);
	    direction(inst, direc, 0);
	}
	else printf("\nIncorrect Instruction. Only accept Move or Turn\n");
    }
    printf(" \n\n");
    fclose(fd);
    return;
}

