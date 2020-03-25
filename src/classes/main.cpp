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
	noecho();

	

bool collision = FALSE;
    while (!collision)
    {
        if(kbhit())
        {
            switch (getch())
            {
            case 259:
                derniereDir = TOUCHE_KEY_UP;
                break;
            case 260:
                derniereDir = TOUCHE_KEY_LEFT;
                break;
            case 258:
                derniereDir = TOUCHE_KEY_DOWN;
                break;
            case 261:
                derniereDir = TOUCHE_KEY_RIGHT;

                break;
            }

        }
        serpent.move(derniereDir);
        collision = serpent.collisionBord() || serpent.collisionSerpent();
        serpent.afficheSerpent();
        usleep (150000);

    }
    //getchar();
    fenetre->kill();
    return 0;
};