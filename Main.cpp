#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() 
{
	glfwInit();

	//tell GLFW we want to use OpenGL 3.3 core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//tell GLFW we want to use the core profile - only modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);


	if(window == nullptr) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//introduce window's context to the current thread
	glfwMakeContextCurrent(window);

	// Load OpenGL function pointers using GLAD
	gladLoadGL();

	//set the viewport size
	glad_glViewport(0, 0, 800, 600);

	//specifies the color of window's background
	glClearColor(0.02f, 0.13f, 0.17f, 1.0f); //back buffer

	//clear the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT); //front buffer

	//swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	//Main While Loop
	while(!glfwWindowShouldClose(window)) 
	{
		//if we don't poll events, the window will freeze or become unresponsive
		//take care of all GLFW events
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}