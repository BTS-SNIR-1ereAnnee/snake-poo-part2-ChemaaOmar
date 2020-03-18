/*
 Projet: snake
 Auteur: Sylvain Guilbert
*/
#include <iostream>
#include "Point.h"
#include "Board.h"
#include "snake.h"
#include <unistd.h>

int usleep(useconds_t usec);

using namespace std;

//https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c

#define  TOUCHE_KEY_UP 1 // sert a définir les touche de mouvement
#define  TOUCHE_KEY_DOWN 2
#define  TOUCHE_KEY_LEFT 3
#define  TOUCHE_KEY_RIGHT 4

int kbhit(void)    /* Cette fonction retourne si une touche est appuyé par l'utilisateur https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c */
{
	int ch, r;


	nodelay(stdscr, TRUE);



	ch = getch(); //le getch sert a passer la main a l'utilisateur afin que ce dernier puisse saisir un caractère
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
	int derniereDir=TOUCHE_KEY_DOWN;

    // pointeurs sur l'unique instance de la classe UniqueObject
	Board *fenetre;
    // initialisation des pointeurs
	fenetre = Board::getInstance ();

	snake serpent(10,4);




	keypad (stdscr,true);
	noecho();
	while (true)
	{

		if(kbhit()) {
			switch (getch()){   
				case 259:					//gére les different deplacement	
				derniereDir = TOUCHE_KEY_UP; 	 
				serpent.move(TOUCHE_KEY_UP);//pour monter
				break;
				case 260:
				derniereDir = TOUCHE_KEY_LEFT;
				serpent.move(TOUCHE_KEY_LEFT);//pour tourner a gauche
				break;
				case 258:
				derniereDir = TOUCHE_KEY_DOWN;
				serpent.move(TOUCHE_KEY_DOWN);//pour aller a droite
				break;
				case 261:
				derniereDir = TOUCHE_KEY_RIGHT;
				serpent.move(TOUCHE_KEY_RIGHT);//pour aller a droite
				break;
			}



		}else{ //move left
			serpent.move (derniereDir);

		}
		serpent.affichSerpent(); //utilise la methode "affichSerpent" en utilisant la classe serpent 
		usleep (150000); //suspend le serpend pendant quelque microsecondes

	}
    //getchar();
	fenetre->kill();
	return 0;
};
