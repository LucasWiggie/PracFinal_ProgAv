// Prac1_ProgAv.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <string>
#include <iostream>
#include <GL/glut.h>
#include "Game.h"

using namespace std;

// CONSTANTES
const int WINDOW_WIDTH = 820;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 100;
const int WINDOW_POSITION_Y = 100;
const char TITLE[] = "PARTE 1";

const GLclampf RED = 0.2;
const GLclampf GREEN = 0.6;
const GLclampf BLUE = 0.5;
const GLclampf ALPHA = 1;

bool fullScreenMode = false;

Game game;

void writeLine(string text) {
    cout << text << endl;
}

void initGraphics() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED, GREEN, BLUE, ALPHA);

    game.Init();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game.Render();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspectRatio, 1.0f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    
    game.Update();
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int px, int py) {
    game.ProcessKeyPressed(key, px, py);
    glutPostRedisplay();
}

void specialKey(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_F11:
        fullScreenMode = !fullScreenMode;
        if (fullScreenMode == true) glutFullScreen();
        else {
            glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
            glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
        }
        break;
    }
}

void mouseMoved(int x, int y) {
    game.ProcessMouseMovement(x, y);

    glutPostRedisplay();
}

void mouseClicked(int button, int stage, int x, int y) {
    game.ProcessMouseClick(button, stage, x, y);

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    writeLine("Generando la ventana...");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow(TITLE);

    writeLine("Registrando funciones de tratamiento de eventos");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyPressed);
    glutMouseFunc(mouseClicked);
    glutMotionFunc(mouseMoved);
    glutSpecialFunc(specialKey);

    writeLine("Iniciando gráficos...");
    initGraphics();

    writeLine("Iniciando bucle infinito...");
    glutMainLoop();

    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
