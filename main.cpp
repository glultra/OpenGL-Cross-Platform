#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Camera.hpp>
#include <Shader.h>
#include <stb_image.h>
#include <iostream>

// Definintions
#define SCR_WIDTH 600
#define SCR_HEIGHT 600
#define SCR_TITLE "Depth Testing"

// Properities
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
double lastX = (SCR_WIDTH/2.0f);
double lastY = (SCR_HEIGHT/2.0f);
double lastFrame = 0.0f;
double deltaTime = 0.0f;
bool isCursorHidden = true;

// Method Protypes
void framebuffer_size_callback(GLFWwindow*window ,int width, int height);
void proccess_input(GLFWwindow*window);
void mouse_cursor_position(GLFWwindow* window, double width, double height);
void update_time(float time);
GLuint load_texture(const char* path);

// Vertices
// Rectnagle vertices
float vertices[] = {
    /*Top Position* /		/* Color */			/* TexCoords */
	-0.5f,-0.5f, 0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	 0.5f,-0.5f, 0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
	 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	-0.5f, 0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
	-0.5f,-0.5f, 0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	/* Bottom Position */		/* Color */			/* TexCoords */
	-0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	 0.5f,-0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
	 0.5f, 0.5f,-0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	 0.5f, 0.5f,-0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	-0.5f, 0.5f,-0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
	-0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	/* Left Position */		/* Color */			/* TexCoords */
	-0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	-0.5f, 0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	-0.5f,-0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
	-0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	/* Right Position */		/* Color */			/* TexCoords */
	 0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	 0.5f, 0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
	 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	 0.5f,-0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
	 0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	/* Back Position */		/* Color */			/* TexCoords */
   	-0.5f, 0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	 0.5f, 0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
	 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
   	-0.5f, 0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
   	-0.5f, 0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	/* Front Position */		/* Color */			/* TexCoords */
	-0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	 0.5f,-0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
	 0.5f,-0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	 0.5f,-0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	-0.5f,-0.5f, 0.5f,		1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
	-0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
};

int main(){
       // Init GLFW and its Version
       glfwInit();

       glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
       glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
       glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
       glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

       // Create Window
       GLFWwindow * window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE, NULL,NULL);

       // Check Window
       if(!window){ 
           std::cout << "Failed to open Window\n";
           glfwTerminate(); 
           return -1;
       }

       // Options
       glfwMakeContextCurrent(window);
       glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
       glfwSetCursorPosCallback(window, mouse_cursor_position);
       glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
       //glfwSetWindowPos(window, 700, 100);

       // Check Glad or Glew (any opengl loader)
       if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
           std::cout << "Failed to load OpenGL\n";
           glfwTerminate();
           return -1;
       }

       // Settings 
       glEnable(GL_DEPTH_TEST);

       // Buffer
        GLuint VBO,VAO;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

        // Attribute 1 which is Position Attribute.
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Attribute 2 which is Texture Coordinates Attribute.
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        
        // Attribute 3 which is Texture Coordinates Attribute.
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        // Texture
        GLuint texture1 = load_texture("examples/res/Texture/leaf.jpg");

       // Shader
       Shader shader = Shader{"shader.vert", "shader.frag"};
       shader.use();
       shader.setInt("myTexture", 0);

       // Camera
       camera.Yaw = -90.4001;

       // Game Loop
       while(!glfwWindowShouldClose(window)){
            /* <----------Update----------> */
            float time = glfwGetTime();
            update_time(time);
            proccess_input(window);

            // Coordinates
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::scale(model, glm::vec3(0.5f));
            glm::mat4 projection = glm::mat4(1.0f);

            projection = glm::perspective(glm::radians(45.0f),  float(SCR_WIDTH) / float(SCR_HEIGHT), 0.1f, 100.0f);
            view = camera.GetViewMatrix();

            /* <----------Render----------> */
            glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            // Draw
            shader.use();
            shader.setMat4("view", view);
            shader.setMat4("model", model);
            shader.setMat4("projection", projection);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture1);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            

            // Swap Buffers
            glfwSwapBuffers(window);

            // Pollevents
            glfwPollEvents();
       }
}

void framebuffer_size_callback(GLFWwindow*window ,int width, int height){
    glViewport(0,0,width,height);
}

void proccess_input(GLFWwindow*window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    else if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    else if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);

    if(glfwGetKey(window, GLFW_KEY_H)){
        if(isCursorHidden){
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            isCursorHidden = false;
        }
        else if(!isCursorHidden){
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            isCursorHidden = true;
        }
    }

}
void mouse_cursor_position(GLFWwindow* window, double xPos, double yPos){
    static bool isFirstMouse = true;
    if(isFirstMouse){
        lastY = yPos;
        lastX = xPos;
        isFirstMouse = false;
    }

    float xoffset = xPos - lastX;
    float yoffset = lastY - yPos;
    lastX = xPos;
    lastY = yPos;
    
    camera.ProcessMouseMovement(xoffset, yoffset);
}
void update_time(float time){
    deltaTime = time - lastFrame;
    lastFrame = time;
    // Find fps
}

GLuint load_texture(const char* texture_path){
    unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	/* Filter Options */
	// Note : Don't take care so much about this filters if rn, if you would like you can delete. 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(texture_path, &width, &height, &nrChannels, 0);

	if (data)
	{
		// Note it's a better way to see that what our file is like png, jpg or jpeg ?
		GLenum format;
		if (nrChannels == 1)
			format = GL_RED;
		if (nrChannels == 3) // jpg file
			format = GL_RGB;
		if (nrChannels == 4) // png file
			format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture\n";
	}

	stbi_image_free(data);

	return textureID;
}