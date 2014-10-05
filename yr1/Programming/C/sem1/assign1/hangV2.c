//name: Neil McGettigan
//student id: C12810959
//program: Hangman
//date: 08/11/2012
//tested working in cygwin with gcc compiler

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define SIZE 32

main(){

	//since srand(1) doesn't work, seeding with time() should suffice
	srand(time(NULL));

	//creating variables
	/*
	  i - for loops,
	  choice - stores menu selection,
	  complete - is guess array complete? (win?)
	  tally - stores how many chars have been guessed already
	  lives - stores lives left,
	  pick - rand num for picking word,
	  play - whether user want to play again
	  wrong - stores whether or not a guess is right
	  try - stores user's char input to be checked
	*/

	int i, complete, tally, lives, pick, play, wrong;
	char try, choice;

	//word pool where word[] will be picked
	char arr1[]="bubbles";
	char arr2[]="expansive";
	char arr3[]="auctioneer";
	char arr4[]="octopus";
	char arr5[]="umbrella";


	char word[SIZE];	//stores the word to be guessed
	char guess[SIZE];	//stores user's progress
	char used[SIZE];	//stores the letters that have been used
	char winTry[SIZE];

	play=1; //initializing play to enter game loop

	//initializing variables, will come back here to "play again"
	while(play==1){

		memset(word, '\0', sizeof(word));	//memset to remove garbage
		memset(guess, '\0', sizeof(guess)); //basically sets all elements to '\0'
		memset(used, '\0', sizeof(used));
		memset(winTry, '\0', sizeof(winTry));
		//initializing variables, will come back here to "play again"
		lives=6; //start with 6 lives
		tally=0; //no letters used up yet so tally is 0
		complete=0; //we have not completed the unknown word, so 0
		pick=(rand()%5)+1;  //generate random number from 1-5 inclusive
		//printf("random num: %d\n",pick); //debug

		//pick is random and so choose word depending on pick
		switch(pick){
			case 1:
				for(i=0; i<strlen(arr1); i++){
					word[i]=arr1[i];
					guess[i]='_';
				}
				break;

			case 2:
				for(i=0; i<strlen(arr2); i++){
					word[i]=arr2[i];
					guess[i]='_';
				}
				break;

			case 3:
				for(i=0; i<strlen(arr3); i++){
					word[i]=arr3[i];
					guess[i]='_';
				}
				break;

			case 4:
				for(i=0; i<strlen(arr4); i++){
					word[i]=arr4[i];
					guess[i]='_';
				}
				break;

			case 5:
				for(i=0; i<strlen(arr5); i++){
					word[i]=arr5[i];
					guess[i]='_';
				}
				break;

			default:
				printf("Error.");

		}
		//So far all variables are created and initialized
		//printf("%s",word); //debug

		//make sure vital conditions are met
		while(lives>0 && complete!=1 && play==1){

			//impossible to get clear screen in c, so....
			for(i=0; i<80; i++){
				printf("\n");
			}

			printf("\nLives: %d\n", lives);
			printf("Guess: ");
			for(i=0; guess[i]!='\0'; i++){
				printf("%c ",guess[i]);
			}
			printf("\nUsed: ");
			for(i=0; used[i]!='\0'; i++){
				printf("%c  ",used[i]);
			}
			printf("\n\n\n\n\n");
			printf("Please enter desired option:\n");
			printf("(1) Guess a letter\n(2) Guess the word (all or nothing)\n");
			printf("(3) Exit program\n");

			scanf("%1s",&choice);
			getchar(); //soaks up the Enter key after input
			//printf(".%1s.\n",choice); //debug

			switch(choice){
				case '1':
					while(!isalpha(try)){ //check if input is letter
						printf("Enter guess: ");
						scanf("%1s",&try);
						if(!isalpha(try)){
							printf("Please input a valid character.\n\n");
						}
					}
					//if uppercase, change to lower for simplicity
					try=tolower(try);

					used[tally]=try;
					tally++;

					if(tally!=1){
						for(i=0; i<tally-1; i++){
							//printf("try: .%c.  used[%d]: %c\n",try,i, used[i]); //debug
							if(used[i]==try){
								printf("Character already used.\n");
								lives++; //counteract lives-- for non-new letter
								tally--; //go back one element 
								used[tally]='\0'; // write beack over duplicate
							}
						}
					}
					//check if entered a letter not in the word
					wrong=1;
					for(i=0; word[i]!='\0'; i++){
						if(word[i]==try){
							guess[i]=try;
							//printf("\nGot one.\n"); //debug
							wrong=0;
						}
					}
					if(wrong==1){
						lives--;
						printf("\nNope.\n[Press a key to continue]\n");
						getchar();
						getchar();
					}else{
						printf("\nYes!\n[Press a key to continue]\n");
						getchar();
						getchar();
					}

					//check if we have filled all the blanks successfully
					complete=1;
					for(i=0; guess[i]!='\0'; i++){
						if(guess[i]=='_'){
							complete=0;
						}
					}
					break;
				/*
				case '2':
					printf("Lives: %d\n\n", lives);
					break;

				case '3':
					printf("Guess: ");
					for(i=0; guess[i]!='\0'; i++){
						printf("%c ",guess[i]);
					}
					printf("\n\n");
					break;

				case '4':
					printf("Used: ");
					for(i=0; used[i]!='\0'; i++){
						printf("%c  ",used[i]);
					}
					printf("\n\n");
					break;
				*/
				case '2':
					printf("Insert your word guess: ");
					scanf("%s",&winTry);
					if(strcmp(winTry,word)==0){ //strcmp conpares two strings. 0 if equal.
						printf("\nYou got it. Well done!\n");
						printf("[Press a key to continue]");
						getchar();
						getchar();
						printf("\n");
						complete=1;
					}else{
						printf("\nSorry, no.\n");
						printf("[Press a key to continue]");
						getchar();
						getchar();
						printf("\n");
						lives=0;
					}
					break;

				case '3':
					printf("Goodbye.\n");
					play=0;
					break;

				default:
					printf("Invalid choice.\n\n");
			}

		}

		if(lives==0){
			printf("Out of Lives.\nYou Lose.\n");
			printf("The word was: %s\n\n",word);
		}

		if(complete==1){
			printf("You Win!\n\n");
		}
		if(play==1){
			while(choice!='y' && choice!='n'){
				printf("Play Again? (y/n): ");
				scanf("%1s",&choice);
				getchar(); //soaks up the Enter key after input
				printf("\n");

				choice=tolower(choice);

				if(choice=='n'){
					play=0;
					printf("Goodbye.\n");
				}else if(choice!='y'){
					printf("Not a valid input.\n");
				}
			}
			printf("[Press a key]");
			getchar();
		}
	}
}
