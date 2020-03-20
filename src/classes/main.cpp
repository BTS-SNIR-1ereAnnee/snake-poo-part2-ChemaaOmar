#include <iostream>
#include "Point.h"
#include "Board.h"
#include "snake.h"
#include <unistd.h>
using namespace std;

//Définis les touches de mouvement
#define  TOUCHE_KEY_UP 1 
#define  TOUCHE_KEY_DOWN 2
#define  TOUCHE_KEY_LEFT 3
#define  TOUCHE_KEY_RIGHT 4

//Cette fonction retourne si une touche est appuyée par l'utilisateur
int kbhit(void)
{
	int ch, r;
	nodelay(stdscr, TRUE);
	ch = getch();
	if( ch == ERR)
		r = FALSE;
	else
	{
		r = TRUE;
		ungetch(ch);
	}
	echo();
	nodelay(stdscr, FALSE);
	return(r);
}


int main()
{
	int derniereDir=TOUCHE_KEY_UP;//Bouge le serpent vers le haut quand on lance le programme
    Board *fenetre;
    fenetre = Board::getInstance ();
    snake serpent(10,10);
	keypad (stdscr,true);
	curs_set(0);

	
	while (!(serpent.collisionBord() || serpent.collisionSerpent()))	//Permet au deplacement du serpent
	{	if(kbhit())
		{
			switch (getch()){

				
				case 259:
				derniereDir = TOUCHE_KEY_UP;  //Bouge en haut
				break;

				
				case 260:
				derniereDir = TOUCHE_KEY_LEFT;	//Bouge a gauche 
				break;

				case 258:
				derniereDir = TOUCHE_KEY_DOWN;//Bouge a droite
				break;

				
				case 261:
				derniereDir = TOUCHE_KEY_RIGHT; //Bouge en bas
				break;
			}
			serpent.move(derniereDir);//Déplace serpent

		}else{
			serpent.move(derniereDir);
		}

		serpent.afficheSerpent();//Affiche serpent
		usleep (100000);
	}
			
			clear();
			fenetre->kill();
			return 0;
};
