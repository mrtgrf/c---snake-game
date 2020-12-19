#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,foodX,foodY,score;
int tailX[100], tailY[100];
int nTail;
enum control={left,right,up,down};
control cont;

void Setup(){
     gameOver=false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;	
}	
void Board(){
	for(int i=0;i<width;i++){
		cout<<"*"<<endl;
	}
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(j==0){
				cout<<"*";
			}
			if(i==y && j==x){
				cout<<"O";
			}
			else if(i==foodY && j==foodX){
				cout<<"F";
			}
			else{
				bool print=false;
				for(int k=0;k<nTail;k++){
					if(tailX[k]==j && tailY[k]==i){
						cout<<"o";
						print=true;
					}
				}
				if(!print){
					cout<<" ";
				}
				if(j==width-1){
					cout<<"*"<<endl;
				}
			}
		}
	}
	for(int i=0;i<width+2;i++){
			cout<<"*"<<endl;
			cout<<"Score: "<<score<<endl;
	}
}
void Controller(){
	switch(){
		case 'w':
			cont = up;
			break;
		case 's':
		    cont = down;
			break;
		case 'a':
		    cont = right;
			break;
		case 'd':
		    cont = left;
			break;			
	}
	
}
void Logic(){
	int prevX=tailX[i];
	int prevY=tailY[i];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	for(int i=1;i<nTail;i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(cont){
		case left:
			x--;
			break;
		case right:
		    x++;
			break;
		case down:
		    y++;
			break;
		case up:
		    y--;
			break;			
	}
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
 
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
	if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main(int argc, char** argv) {
	Setup();
	while(!gameOver){
		Board();
		Controller();
		Logic();
	}
	
	return 0;
}
