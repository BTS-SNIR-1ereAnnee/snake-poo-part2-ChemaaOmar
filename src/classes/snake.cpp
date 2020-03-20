#include "Point.h"
#include "snake.h"
#include "Board.h"
#include <iostream>


using namespace std ;

//Constructeur par défaut
snake::snake()
{
    for(int i = 0; i < taille; i++)
    {
        serpent[i].setPoint(0,i);
    }
}

//Constructeur 
snake::snake(int x,int y)
{
    for(int i = 0; i < taille; i++)
    {
        serpent[i].setPoint(x,i+y);
    }
}


void snake::afficheSerpent()    //Affiche le serpent
{
    for(int i = 0; i < taille; i++)
    {
        serpent[i].drawPoint(); 
    }
}


void snake::move(int direction) //Déplace le serpent
{
    for(int i = taille; i > 0 ; i--)
    {
        serpent[i].erasePoint();
        serpent[i] = serpent[i-1];

    }

    if(direction == 1)
    {
        serpent[0].moveUp();
    }

    else if(direction == 2)
    {
        serpent[0].moveDown();
    }
    else if(direction == 3)
    {
        serpent[0].moveLeft();
    }
    else if(direction == 4)
    {
        serpent[0].moveRight();
    }

}


bool snake::collisionBord(){  //Quand le serpent touche un bord le programme s'arrete
    Board *b;
    b = Board::getInstance(); 
    if(serpent[0].getX() == 0 || serpent[0].getY() == 0 || serpent[0].getX() == b->getSizeX()-1 || serpent[0].getY() == b->getSizeY()-1)
        return TRUE;

    return FALSE;
}

bool snake::collisionSerpent(){

    for(int i=1;i<taille;i++)
    {
        if(serpent[0].getX()==serpent[i].getX() && serpent[0].getY()==serpent[i].getY()){
            return TRUE;
        }
    }
    return FALSE;
}