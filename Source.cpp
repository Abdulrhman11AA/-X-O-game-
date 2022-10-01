#include<iostream >
using namespace std;
char square [3][3]={ '1','2','3','4','5','6','7','8','9' };
char player = 'x';
void print() {
	system("cls");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << " "<< square[i][j]<<"  ";
		}cout << " "<< endl;
	} 
} 
void play() {
	char position;
	cout << " enter your postion  : ";
	cin >> position;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (square[i][j] == position) {
				square[i][j] = player;
			}
		}
	}
	if (player == 'x') {
		player = 'o';
	}
	else
		player = 'x';
 }
char rules() {
	 int player_x = 0, player_O = 0,counter=0 ;
	 for (int i = 0; i < 3; i++) {
		 for (int j = 0; j < 3; j++) {
			  if (square[i][j] != 'x' || square[i][j] != 'o') counter++;
			 if (square[i][j] == 'x') player_x++;
			 else if (square[i][j] == 'o') player_O++;
			 if (player_x == 3 || player_O == 3) {
				 return player_x > player_O ? 'x' : 'o';
			 }
		 }
	 
		 player_x = 0; player_O = 0;
	 }
	 for (int i = 0; i < 3; i++) {
		 for (int j = 0; j < 3; j++) {
			 if (square[j][i] == 'x') player_x++;
			 else if (square[j][i] == 'o') player_O++;
			 if (player_x == 3 || player_O == 3) {
				 return player_x > player_O ? 'x' : 'o';
			 }
		 }

		 player_x = 0; player_O = 0;
	 }
	 if (square[0][0] == 'x' && square[1][1] == 'x' && square[2][2] == 'x') return 'x';
	 else if (square[0][0] == 'o' && square[1][1] == 'o' && square[2][2] == 'o') return 'o';
	 else if (square[0][2] == 'x' && square[1][1] == 'x' && square[2][0] == 'x') return'x';
	 else if (square[0][2] == 'o' && square[1][1] == 'o' && square[2][0] == 'o') return'o';
	 else if (counter == 0) return 'z';
	 
	 return '.';
	 
 } 
int main() {
		while (rules() == '.') {
			print();
			play();
		}
		if (rules() == '!')cout << " no winner \n";
		else cout << "the winner is the player " << rules() << " \n";
		system("pause");
	return 0;
}

