#include <iostream>
#include <cstdlib>
using namespace std;
/*
 * function name: main()
 * description	: a) using enum to declare kinds of vegetable seeds
 * 		  b) using 2-dimension array to develop a patch and every block of patch need to be planted 4 seeds
 * 		  c) using 'srand(0)' to determine what kinds of seed should be planted 
 * 		     (five times at most for every kind of vegetables)
 * 		  d) watering the plant (range: self-centered nine-square division)
 * 		  e) Input the coordinates
 * 		  f) continue for unresonable coordinates
 * 		  g) determine whether the plant has already growed.
 * input	: int ,int
 * return	: int 
 * 		*/ 

//function of input the 'int-symbol' to an array that help us to know what seed in the block of patch
void I_randomArray (int p[5][7]);

//function of input the char into 3-dimension array
void randomArray (char p[2][5][7]);

//function of calculate how many plants are mature
void growingPlant (int [5][7], int [5][7], int [5][7]);

//function of output the full patch
void printfArray (char [2][5][7], int [5][7]);

//function of receiving the coordinate and watering the specific block of patch 
int wateringPlant(int[5][7], int ,int );

//enumerate kinds of vegetables
enum vegetable {T, C, W, S, P, Y, G};

int main (){
	int growedPlant[5][7]={0};		// declare integer array for calculating the growedPlant
	char p1[2][5][7];				// declare the 3-dimension character array 
	int patch[5][7];				// declare integer array for the 5*7 patch
	int W_patch[5][7]={0};			// declare integer array for the watered patch
	int x=0,y=0;					// declare integer array for input 
	
	I_randomArray(patch);			// using number to save the vegetable seeds
	randomArray(p1);				// using character to save the vegetable seeds
	printfArray (p1, growedPlant);	// output the original patch

	while (1){
		cin>>x>>y;					// input the coordinate

		wateringPlant(W_patch, x, y);	//watering plant
		
		/* specific coordinate (-1,-1): break
		 * unreasonable coordinate (out of range of array) ex:(7,1): continue
		 */ 
		if (x==-1 && y==-1) break;						
		else if (x<0 || x>4 || y<0 || y>6) continue;
		else {
			growingPlant(patch, growedPlant, W_patch); 	// calculate how many plant has already growed
			printfArray(p1, growedPlant);				// output the patch
		}
	}
	return 0; 
}

void I_randomArray (int p[5][7]){
	int i=0,j=0;
	int temp;
	int counter[7]={0}; 	// counting the times of the seed be planted
	
	srand(0);				// set up the random seed
	
	for (i=0;i<5;i++){
		for (j=0;j<7;j++){
			do {
				temp = rand()%7; 		// get 0~6 from random number
			}
			while (counter[temp]>=5);	// prevent any of seeds that are planted more than five times
				
				//save corresponding integer into array
				switch (temp){
					case T: p[i][j]=T;  break;
					case C: p[i][j]=C;  break;
					case W: p[i][j]=W;  break;
					case S: p[i][j]=S;  break;
					case P: p[i][j]=P;  break;
					case Y: p[i][j]=Y;  break;
					case G: p[i][j]=G;  break;
				}
			counter[temp]++;
		}
	} 
}

void growingPlant (int p[5][7], int gP[5][7], int I_p[5][7]){
	for (int i=0 ; i<5 ; i++){
		for (int j=0 ; j<7 ;j++){

			// calculate how many plants in a block have already been mature
			switch(p[i][j]){
				case T: gP[i][j]=2*I_p[i][j]/3; break;
				case C: gP[i][j]=2*I_p[i][j]/3; break;
				case W: gP[i][j]=4*I_p[i][j]/9; break;
				case S: gP[i][j]=2*I_p[i][j]/3; break;
				case P: gP[i][j]=4*I_p[i][j]/3; break;
				case Y: gP[i][j]=4*I_p[i][j]/3; break;
				case G: gP[i][j]=4*I_p[i][j]/3; break;
			}
		}
	}
}

void randomArray (char p[][5][7]){
	// the same as the function 'I_randomArray' but this saves 'character' into 3-dimension array
	int i=0,j=0;
	int temp;
	int counter[7]={0};
	
	srand(0);
	
	for (i=0;i<5;i++){
		for (j=0;j<7;j++){
			do {
				temp = rand()%7;
			}
			while (counter[temp]>=5);
			// in x = 0, save specific lower case letter
			// in x = 1, save specific Capital letter
			switch (temp){
				case T: p[0][i][j]='t'; p[1][i][j]='T';  break;
				case C: p[0][i][j]='c'; p[1][i][j]='C';  break;
				case W: p[0][i][j]='w'; p[1][i][j]='W';  break;
				case S: p[0][i][j]='s'; p[1][i][j]='S';  break;
				case P: p[0][i][j]='p'; p[1][i][j]='P';  break;
				case Y: p[0][i][j]='y'; p[1][i][j]='Y';  break;
				case G: p[0][i][j]='g'; p[1][i][j]='G';  break;
			}
			counter[temp]++;
		}
	} 
}

void printfArray(char p[][5][7], int gP[5][7]){
	int count1, count2;
	
	for (int i=0;i<5;i++){
		cout <<"+---------------------------+"<<endl;
		 
		for (int j=0;j<2;j++){
			for (int k=0;k<7;k++){
				count1 = gP[i][k];
				count2 = gP[i][k];
				
				cout <<"|";
				for (int l=0 ;l<2;l++){
					// determine that the position shouold be output Capital or Lower case letter
					if (j==0 && count1>0) {
						cout <<p[1][i][k];
						count1 --;
					}
					else if (j==0 && count1<=0){
						cout <<p[0][i][k];
					}
					else if (j==1 && count2 >2){
						cout <<p[1][i][k];
						count2 --;
					}
					else if (j==1 && count2 <=2){
						cout <<p[0][i][k];
					}
					if (l<1) cout <<" ";
				}
			}
			cout <<"|"<<endl;
		}
	}
	cout <<"+---------------------------+"<<endl;
}
		


int wateringPlant(int I_patch[5][7], int x,int y){
	// using array to save the watering times for every block of patch
	// using chain-if to circle the boundary
	if (x>=1 && x<=3 && y>=1 && y<=5){
		for (int i=x-1; i<=x+1 ; i++){
			for (int j=y-1; j<=y+1 ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (x==0 && y==0){
		for (int i=x; i<=x+1 ; i++){
			for (int j=y; j<=y+1 ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (x==4 && y==0){
		for (int i=x-1; i<=x ; i++){
			for (int j=y; j<=y+1 ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (x==0 && y==6){
		for (int i=x; i<=x+1 ; i++){
			for (int j=y-1 ; j<=y ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (x==4 && y==6){
		for (int i=x-1; i<=x ; i++){
			for (int j=y-1 ; j<=y ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (y>=1 && y<=5 && x==0){
		for (int i=x; i<=x+1 ; i++){
			for (int j=y-1 ; j<=y+1 ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (y>=1 && y<=5 && x==4){
		for (int i=x-1; i<=x ; i++){
			for (int j=y-1 ; j<=y+1 ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (y==0 && x<=3 && x>=1){
		for (int i=x-1; i<=x+1 ; i++){
			for (int j=y ; j<=y+1 ;j++){
				I_patch[i][j]++;
			}
		}
	}
	else if (y==6 && x<=3 && x>=1){
		for (int i=x-1; i<=x+1 ; i++){
			for (int j=y-1 ; j<=y ;j++){
				I_patch[i][j]++;
			}
		}
	}
	return I_patch[5][7];	//return the watered patch to the main function 
}
