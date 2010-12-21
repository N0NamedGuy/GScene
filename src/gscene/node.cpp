/* GScene API
 * Copyright (C) 2010 David Serrano
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "node.h"
#include <list>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

Node::Node() {
    setColor(1.0f,1.0f,1.0f);
    setTranslation(0.0f, 0.0f, 0.0f);
    setRotation(0.0f, 0.0f, 0.0f);
    setScale(1.0f, 1.0f, 1.0f);
    wireframe = false;
}

void Node::setColor(float r, float g, float b) {
    setColor(r, g, b, 1.0f);
}

void Node::setColor(float r, float g, float b, float a) {
    setFillColor(r,g,b,a);
    setLineColor(r,g,b,a);
}

void Node::setFillColor(float r, float g, float b) {
    setFillColor(r, g, b, 1.0f);
}

void Node::setFillColor(float r, float g, float b, float a) {
    fillColor[0] = r;
    fillColor[1] = g;
    fillColor[2] = b;
    fillColor[3] = a;

    list<Node*>::iterator iter;
    for (iter = children.begin(); 
        iter != children.end();
        iter++) {
       
        (*iter)->setFillColor(r, g, b, a);
    }
}

void Node::setLineColor(float r, float g, float b) {
    setLineColor(r, g, b, 1.0);
}

void Node::setLineColor(float r, float g, float b, float a) {
    lineColor[0] = r;
    lineColor[1] = g;
    lineColor[2] = b;
    lineColor[3] = a;

    list<Node*>::iterator iter;
    for (iter = children.begin(); 
        iter != children.end();
        iter++) {
       
        (*(*iter)).setLineColor(r, g, b, a);
    }
}

void Node::setTranslation(float x, float y, float z) {
    translation[0] = x;
    translation[1] = y;
    translation[2] = z;
}

void Node::setRotation(float x, float y, float z) {
    rotation[0] = x;
    rotation[1] = y;
    rotation[2] = z;
}

void Node::setScale(float x, float y, float z) {
    scale[0] = x;
    scale[1] = y;
    scale[2] = z;
}

void Node::addChild(Node* n) {
    children.push_back(n);
}

void Node::render() {
    _render();
}

void Node::_render() {

    glTranslatef((GLfloat)translation[0],
        (GLfloat)translation[1],
        (GLfloat)translation[2]);
    
    glRotatef((GLfloat)rotation[0], (GLfloat)1.0f, (GLfloat)0.0f, (GLfloat)0.0f);
    glRotatef((GLfloat)rotation[1], (GLfloat)0.0f, (GLfloat)1.0f, (GLfloat)0.0f);
    glRotatef((GLfloat)rotation[2], (GLfloat)0.0f, (GLfloat)0.0f, (GLfloat)1.0f);
    
    glScalef((GLfloat)scale[0],
        (GLfloat)scale[1],
        (GLfloat)scale[2]);

    list<Node*>::iterator iter;
    for (iter = children.begin(); 
        iter != children.end();
        iter++) {
       
        glPushMatrix(); 
        (*(*iter)).render();
        glPopMatrix();
    }

}
