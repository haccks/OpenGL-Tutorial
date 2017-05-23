//
//  Game.hpp
//  OpenGL Tutorial
//
//  Created by haccks on 23/05/17.
//  Copyright © 2017 haccks. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <GL/glew.h>      //Always include glew.h before glfw3.h
#include <GLFW/glfw3.h>
using namespace std;

#define HEIGHT 480
#define WIDTH 620

class Game{
private:
	GLFWwindow *window;
public:
	Game();
	GLFWwindow* create_window_object();
	GLvoid init_glew();
	GLvoid game_loop();
	GLvoid terminate_glfw();
	
};



#endif /* Game_hpp */
