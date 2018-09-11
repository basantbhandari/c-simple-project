/*                                                                                                                                developed by Basant Bhandari                                                                                                                           */


#include<stdio.h>
#include<conio.h>
#include<math.h>
 //global variable declaration
 int gameover;
 const int width= 80;
 const int height= 20;
 int x,y,fruitX,fruitY,score,i,j,k,flag;
 int tailX[100], tailY[100];
 int ntail;
 int prevX,prevY,prev2X,prev2Y;
 enum edirection {STOP=0,LEFT,RIGHT,UP,DOWN };
 enum edirection dir;

 //function prototype
   void setup();
   void draw();
   void input();
   void logic();
   
void main(){
	setup();
    
    while (!gameover){
	     draw();
	     input();
	     logic();
	     //delay purpose
	       for(i= 0; i<55550000; i++){
		   }
	}
	 
	getch();
}
// function define

     void setup(){
     	gameover=0;
     	dir= STOP;
     	x= width/2;
     	y= height/2;
     	fruitX= ( rand()%width );
     	fruitY= ( rand()%height );
        score= 0;
 	
    }
    
    void draw(){
    	system("cls");
                                  //drawing frame
//top horizontal
	for(i=0; i<(width); i++){       
		printf("#");
	}
	printf("\n");
	
//left and right vertical                             
 	for(  i=0; i<height ; i++){
 		 	for(  j=0; j<width ; j++){
 		 		
 		 		   if( j==0 || j== (width-1) ){
 		 		   	
 		 		        printf("#");	
 		 		       
				   }else if(i==y && j==x){
				   	
                        printf("O");  
					                     				   	
				   }else if(i==fruitY && j==fruitX ) {
				   	
				        printf("F");
				      
				   }else{
						flag= 0;
					    for( k= 0; k< ntail; k++){
					    	if( tailX[k]==j && tailY[k]==i ){
					    		printf("o");
					    		flag= 1;
							}
						}
						if(!flag){
							
					        printf(" ");
				  	     }
 		           }
	    }
 	   printf("\n");
	 }
//bottom horizontal
     	for(i=0; i<(width); i++){         
		printf("#");
	    }
     	printf("\n");
     	printf("SCORE = %d",score);
    }
    
    void input(){
    	 
    	 if(kbhit()){
 	           
 	           switch(getch()){
 	           	case 'a':
 	           		dir= LEFT;
 	           		break;
 	           		
 	           	case 'd':
 	           		dir= RIGHT;
 	           		break;
				
			case 'w':
				dir= UP;
 	           		break;	
 	           		
			case 's':
 	           		dir= DOWN;
 	           		break;
			case 'x':
 	           		gameover= 1;
 	           		break;						
 	            
				}
 	
 			}
    }
    
    void logic(){
    	
    	   prevX= tailX[0];
    	   prevY= tailY[0];
    	   tailX[0]= x;
    	   tailY[0]= y;
    	    for( i=1; i<ntail; i++){
    	    	prev2X= tailX[i];
    	    	prev2Y= tailY[i];
    	    	tailX[i]= prevX;
    	    	tailY[i]= prevY;
    	    	prevX = prev2X;
    	    	prevY = prev2Y;
			}
    	   
 	       switch(dir){
 	     	case LEFT:
 	     		x--;
 	       		break;
 	       	
 	       	case RIGHT:
 	     		x++;
 	       		break;
 	       		
 	       	case UP:
 	       		y--;
 	       		break;
 	       	
			case DOWN:
				y++;
			    break;
			default:
				break;
		
			}
 	        
 	       if( x > width || x < 0 || y > height || y < 0 ){
 	       	   gameover= 1;
			}
			for(i=0; i<ntail; i++ ){
				if(tailX[i]==x && tailY[i]==y){
					gameover= 1;
				}
			}
			if( x==fruitX && y==fruitY ){
				score +=10;
         		fruitX= ( rand()% width);
     	        fruitY= ( rand()% height);
				ntail++;
			}

    }

