#ifndef GENERAL_H
#define GENERAL_H
#include <SFML\Graphics.hpp>

using namespace sf;

 class General abstract
{
public:
	static const int gameWidth = 1024;
	static const int gameHeight = 768;
	static float get_gamespeed();
};
#endif GENERAL_H