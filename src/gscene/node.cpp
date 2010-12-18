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
}

void Node::setColor(float r, float g, float b) {
    setColor(r, g, b, 1.0);
}

void Node::setColor(float r, float g, float b, float a) {
    setFillColor(r,g,b,a);
    setLineColor(r,g,b,a);
}

void Node::setFillColor(float r, float g, float b) {
    setFillColor(r, g, b, 1.0);
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
       
        *iter->setFillColor(r, g, b, a);
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
       
        *iter->setLineColor(r, g, b, a);
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
    list.push_back(n);
}

void Node::render() {

    glTranslatef((GLFloat)translation[0],
        (GLFloat)translation[1],
        (GLFloat)translation[2]);
    
    glRotatef((GLFloat)rotation[0], (GLFloat)1.0f, (GLFloat)0.0f, (GLFloat)0.0f);
    glRotatef((GLFloat)rotation[1], (GLFloat)0.0f, (GLFloat)1.0f, (GLFloat)0.0f);
    glRotatef((GLFloat)rotation[2], (GLFloat)0.0f, (GLFloat)0.0f, (GLFloat)1.0f);
    
    glScalef((GLFloat)scale[0],
        (GLFloat)scale[1],
        (GLFloat)scale[2]);

    list<Node*>::iterator iter;
    for (iter = children.begin(); 
        iter != children.end();
        iter++) {
       
        glPushMatrix(); 
        *iter->render();
        glPopMatrix();
    }

}
