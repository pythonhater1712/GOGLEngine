#include "include/engine.hpp"
#include "include/Colors.hpp"

class Debuggers {
    public:
        void printMatrix(glm::mat4 matrix) {
            std::cout << "Matrix: ";
                for (int i = 0; i < 4; i++) {
                    std::cout << std::endl;
                    std::cout << "[" << i << "] ";
                for (int j = 0; j < 4; j++) {
                    std::cout << matrix[i][j] << ", ";
                }
            }
        }
};

class Engine {
    public:
        Engine(uint32_t width, uint32_t height, const char* title) :
        w(width, height, title), r(w) {
            glfwSetKeyCallback(w.GetWindow(), keyCallback);
        }

        // |-- RENDERING --------------------------------------------------------------------|



            // |-- DRAWING ------------------------------------------------------------------|

            bool eClearColor(const Colors c) {
                ColorsF f = ColorIntToFloat(c);

                glClearColor(f.r, f.g, f.b, f.a);
                glClear(GL_COLOR_BUFFER_BIT);

                return true;
            }

            void eDraw() {
                glBindVertexArray(r.GetVAO());
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            }

                // |-- TRANSFORMATIONS ----------------------------------------------------------|

                void eResetTransform() {
                    r.ResetTransform();
                }
                
                void eScale(float x, float y, float z) {
                    r.Scale(x, y, z);
                }

                void eRotate(float degrees) {
                    r.Rotate(degrees);
                }

                void eTranslate(float x, float y) {
                    r.Translate(x, y);
                }

        // |-- TEXTURING --------------------------------------------------------------------|

        
        
        // |-- SHADERING --------------------------------------------------------------------|        

        // |-- WINDOWING --------------------------------------------------------------------|

        GLFWwindow* eGetWindow() {
            return w.GetWindow();
        }

        void ePollEvents() {
            glfwPollEvents();
            glfwSwapBuffers(w.GetWindow());
        }

        ~Engine() {

        }

    private:
        Window w;
        bool eWindowShouldClose = glfwWindowShouldClose(w.GetWindow());

        Shaders s;

        Render r;

        typedef enum Transformations {
            T_TRANSLATION = 0,
            T_ROTATION = 1,
            T_SCALING = 2
        } Transformations;

        typedef enum ShaderTypes {
            ST_TEXTURED = 0,
            ST_FLAT = 1
        } ShaderTypes;

        // |-- TEXTURING --------------------------------------------------------------------|

        class TextureLoader {
            public:
                void LoadTexture(const std::string texturePath, const std::string textureName) {
                    texture = Textures(texturePath.c_str());
                    textureSet.insert({textureName, texture});
                }

                void GetTetxure(const std::string textureName) {
                    auto currentTexture = textureSet.find(textureName);
                    if (currentTexture == textureSet.end()) {
                        LoadTexture(defaultTexture, "unknownTexture");
                        std::cout << "Unknown Texture specified. Using default texture: " << defaultTexture << std::endl;
                    }
                    texture = currentTexture->second;
                }

            private:
                Textures texture;
                std::unordered_map<std::string, Textures> textureSet;
        };
        
        // |-- SHADERING --------------------------------------------------------------------|

        void useShaderProgram(ShaderTypes type) {
            switch (type) {
                case ST_TEXTURED:
                    glUseProgram(s.texturedShaderProgram);
                    break;
                case ST_FLAT:
                    glUseProgram(s.flatShaderProgram);
                    break;
            }
        }

        // |-- WINDOWING --------------------------------------------------------------------|

        static void keyCallback(GLFWwindow* w, int key, int scancode, int action, int mods) {
            if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
                std::cout << "SPACE key pressed" << std::endl;
            }
        }
};

int main(int argc, char* argv[]) {
    if (argv[1] == "d") {
        #define DEBUG_MODE
    }
    
    // Textures t(defaultTexture.c_str());

    Engine e(960, 600, "GOGLEngine");

    while (!glfwWindowShouldClose(e.eGetWindow())) {
        e.eClearColor(Black);

        //glActiveTexture(GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, t.texture);

        //glUseProgram(s.texturedShaderProgram);                        DONE
        //t.SetTextureSlot1(s);

        //r.ResetTransform();                                           DONE
        //r.Scale(0.5f, 0.5f, 0.5f);                                    DONE
        //r.Translate(0.66f, 0.75f);                                    DONE
        //r.Transform(s.texturedShaderProgram);                         DONE

        //glBindVertexArray(r.GetVAO());                                DONE
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);          DONE
        e.eDraw();

        e.ePollEvents();

    }

    return 0;
}

/*
    13/4/26 to do:
    understand how textures work                                        DONE
    make two rectangles appear on screen independently of each other    DONE
    handle input (via engine class probably)                            DONE
    find a way to handle multiple textures                              DONE
    finish engine class                                                 

    25/5/26 to do:
    transfer engine class to engine.hpp
    make engine class functionable and fully transition to it
    make a backup/copy of engine for other games when functioning

    27/05/26 to do:
    make texture manager class and transfer texture logic to that       
    add function to handle textureLoader in engine class                
    
    01/06/26 to do:
    TextureLoader instance takes on the form of texture currently loaded
*/