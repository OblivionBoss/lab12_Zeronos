#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int r;
	r = rand()%13 + 1;
	return r;
	//Write the function to random the number from 1 to 13 and return that random number.
}

int calScore(int x,int y,int z){
	int sum,val[] = {x,y,z};
	sum = x+y+z;
	for(int k = 0; k < 3 ;k++){
		if(val[k] > 10){
			sum -= val[k];
		}
	}
	return sum%10;
	//Write the function to calculate the score with is the rightmost digit of summation of the scores from three cards.
	//Return the score. 
}

int findYugiAction(int s){	
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{
		int q;
		q = rand()%100+1;
		if(q <= 31){
			return 2;
		}
		else{
			return 1;
		}
		// If current score is 6,7,8, Yugi will draw with probability 69% and will stay with probability 31% 
		// Write conditions here using random number 
	}
}

void checkWinner(int p, int y){
	// Write condition for cout in this function
	cout << "\n---------------------------------\n";
	if(p == y){
		cout <<   "|             Draw!!!           |";
	} // when p is equal to y
	else if(p > y){
		cout <<   "|         Player wins!!!        |";
	} // when p is greater than y
	else{
		cout <<   "|          Yugi wins!!!         |";
	} // when p is less than y
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {};
	int yugiCards[3] = {};
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	for(int i = 0; i < 2; i++){
		playerCards[i] = drawCard();
	}
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],0);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
		if(playerAction == 1 or playerAction == 2){
			break;
		}
	}while(true);
	if(playerAction == 1){
		cout << "Player draws the 3rd card!!!" << "\n";
		playerCards[2] = drawCard();
		while(cardNames[playerCards[2]] == cardNames[playerCards[0]] or cardNames[playerCards[2]] == cardNames[playerCards[1]]){
			playerCards[2] = drawCard();
		}
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		playerScore = calScore(playerScore,cardScores[playerCards[2]],0);
		cout << "Your new score: " << playerScore << "\n";
	}
	cout << "------------ Turn end -------------------\n\n";
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	for(int j = 0; j < 2; j++){
		yugiCards[j] = drawCard();
	}
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]]  << "\n";
	yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],0);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
		yugiScore = calScore(yugiScore,cardScores[yugiCards[2]],0);
		cout << "Yugi's new score: " << yugiScore << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	checkWinner(playerScore,yugiScore);
	return 0;
}