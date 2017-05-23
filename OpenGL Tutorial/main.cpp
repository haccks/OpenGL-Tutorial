//
//  main.cpp
//  OpenGL Tutorial
//
//  Created by haccks on 23/05/17.
//  Copyright © 2017 haccks. All rights reserved.
//

#include "Game.hpp"

GLvoid key_callback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mode);

int main(int argc, const char * argv[]) {
	Game game;
	GLFWwindow* window = game.create_window_object();
	glfwSetKeyCallback(window, key_callback);
	game.init_glew();
	game.game_loop();
	game.terminate_glfw();
	return 0;
}

GLvoid key_callback(GLFWwindow *window, GLint key, GLint scancode, GLint action, GLint mode){
	// When a user presses the escape key, we set the WindowShouldClose property to true,
	// closing the application
	if(key == GLFW_KEY_ESCAPE && GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

