#include "gscene/node.h"
#include "gscene/viewer.h"
#include "gscene/controller.h"
#include "gscene/shapes/box.h"

Node rootNode;
Box cube;

float rotX = 0.0f;
float rotY = 0.0f;


void manipulate(unsigned char key, bool keydown) {
    if (keydown) {
        switch (key) {
        case 'a': rotY--; break;
        case 'd': rotY++; break;
        case 'w': rotX--; break;
        case 's': rotX++; break;
        default: break;
        }
    
        rootNode.setRotation(rotX, rotY, 0.0);
    }

}

int main(int argc, char** argv) {

    cube.setFillColor(1.0f,0.0f,0.0f);
    cube.setLineColor(1.0f,1.0f,0.0f);
    rootNode.addChild(&cube);

    viewer_init(argc, argv, 640, 480, "Cubes!"); 
    
    controller_set_hook("awsd", manipulate);
    controller_start();
    
    viewer_start(&rootNode);
    viewer_destroy();

    return 0;
}
