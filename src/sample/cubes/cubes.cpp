#include "gscene/node.h"
#include "gscene/viewer.h"
#include "gscene/shapes/box.h"

int main(int argc, char** argv) {
    Node rootNode;
    Box cube;

    cube.setFillColor(1.0f,0.0f,0.0f);
    cube.setLineColor(1.0f,1.0f,0.0f);
    rootNode.addChild(&cube);

    viewer_init(argc, argv, 640, 480); 
    viewer_start(&rootNode, "Cubes!");
    viewer_destroy();

    return 0;
}
