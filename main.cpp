#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(void)
{

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		return -1;
	}

    // Triangle vertices
    float vertices[] = {
        -0.5f,-0.5f,
         0.5f,-0.5f,
         0.0f, 0.5f,
    };

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.1f, 0.2f, 0.3,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // There's two way for drawing a shape in immediate OpenGL.
        // 1. Using Mode Directly writing the vertices.
        // Drawing a rectangle
        glBegin(GL_QUADS);
            glColor3f(0.5f, 1.0f, 0.31f);
            glVertex2f( 0.6f,  0.6f);
            glVertex2f( 0.8f,  0.6f);
            glVertex2f( 0.8f,  0.8f);
            glVertex2f( 0.6f,  0.8f);
        glEnd();

        // 2. Using Client state with specific vertices.  
        // Drawing a triangle.
        glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(2, GL_FLOAT, 0, vertices);
            glColor3f(1.0f,0.5f,0.31f);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        glDisableClientState(GL_VERTEX_ARRAY);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}