#include "Point.h"
#include "Board.h"
#include <iostream>


using namespace std;

Point::Point()
{
    m_x = m_y = 10;
    m_caractere = '@';
}

Point::Point(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
    m_caractere = '*';
}

Point::Point(int x, int y, char caractere)
{
    this->m_x = x;
    this->m_y = y;
    m_caractere = caractere;
}

void Point::setPoint(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}



void Point::moveDown()
{
    m_y++;
}


void Point::moveUp()
{
    m_y--;
}


void Point::moveRight()
{
    m_x++;
}


void Point::moveLeft()
{
    m_x--;
}


int Point::getX() const
{
    return m_x;
}


void Point::setX(int val)
{
    m_x = val;
}


int Point::getY() const
{
    return m_y;
}


void Point::setY(int val)
{
    m_y = val;
}

void Point::drawPoint() //Dessine les points

{
    Board *b;
    b = Board::getInstance(); 
    b->dessinerPoint(*this);
}


void Point::erasePoint() //Efface les points 
{
    Board *b;
    b = Board::getInstance();
    b->effacerPoint(*this);
}


void Point::debug()
{
    cout << "(" << this->m_x << "," << this->m_y << ")";
}


void Point::setChar(char caractere){
    m_caractere = caractere;
}


char Point::getChar(){
    return m_caractere;
}

Point::~Point()
{
    //dtor
}

