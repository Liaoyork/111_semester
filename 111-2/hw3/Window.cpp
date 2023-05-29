#include "Window.h"

#include <termios.h>

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "View.h"


using namespace std;


void Window::render() {
    system("clear");
    // TODO: Render the window
}

// You don't have to modify
void Window::run() {
    struct termios ter;
    tcgetattr(0, &ter);
    ter.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &ter);

    render();
    while (!exit) {
        char key;
        key = cin.get();
        if (key == 27) {
            key = cin.get();
            if (key == 91) {
                key = cin.get();
                ArrowKey arrowKey;
                if (key == 65) {
                    arrowKey = ArrowKey::UP;
                } else if (key == 66) {
                    arrowKey = ArrowKey::DOWN;
                } else if (key == 67) {
                    arrowKey = ArrowKey::RIGHT;
                } else if (key == 68) {
                    arrowKey = ArrowKey::LEFT;
                }
                onArrowKeyPress(arrowKey);
            }
        } else if (key == 10) {
            onEnterPress();
        } else {
            onNormalKeyPress(key);
        }
        render();
    }
}
