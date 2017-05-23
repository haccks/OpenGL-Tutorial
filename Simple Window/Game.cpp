//
//  Game.cpp
//  OpenGL Tutorial
//
//  Created by haccks on 23/05/17.
//  Copyright © 2017 haccks. All rights reserved.
//

#include "Game.hpp"

Game::Game(){
	// Init GLFW
	if(glfwInit() == GL_FALSE){
		std::cout << "Failed to intialize GLFW" << std::endl;
		exit(-1);
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);   // This is must for Mac OS X
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* Game::create_window_object(){
	// Create a window object
	window = glfwCreateWindow(WIDTH, HEIGHT, "Simple Window", nullptr, nullptr);
	if(window == nullptr){
		std::cout << "Failed to create GLFW object" << std::endl;
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	
	return window;
}

GLvoid Game::init_glew(){
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		exit(-1);
	}
}

GLvoid Game::game_loop(){
	while(!glfwWindowShouldClose(window)){
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		
		// Sets the color value that OpenGL uses to reset the colorbuffer.
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);	// A state-setting function
		
		// Clears the entire color of current buffer to the color specified by glClearColor
		glClear(GL_COLOR_BUFFER_BIT);		//A state-using function
		
		// Swap frame buffers (OpenGL apply double buffer for rendering).
		glfwSwapBuffers(window);
	}
}

GLvoid Game::terminate_glfw(){
	glfwTerminate();
}


