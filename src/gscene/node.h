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

#ifndef NODE_H
#define NODE_H

#include <list>

using namespace std;

class Node {
private:
    list<Node*> children;

public:
    float fillColor[4];
    float lineColor[4];

    float translation[3];
    float rotation[3];
    float scale[3];

    Node();
    void setColor(float r, float g, float b);
    void setColor(float r, float g, float b, float a);

    void setFillColor(float r, float g, float b);
    void setFillColor(float r, float g, float b, float a);

    void setLineColor(float r, float g, float b);
    void setLineColor(float r, float g, float b, float a);

    void setTranslation(float x, float y, float z);
    void setRotation(float x, float y, float z);
    void setScale(float x, float y, float z);

    void addChild(Node* n);
    void render();
}

#endif
