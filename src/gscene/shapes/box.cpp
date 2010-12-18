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
#include "box.h"

#include <GL/glut.h>

Box::Box() : Node();

void Box::render() {
    _render();
   
    if (!wireframe) {
        glColor4f((GLFloat)fillColor[0],
            (GLFloat)fillColor[1],
            (GLFloat)fillColor[2],
            (GLFloat)fillColor[3]);
        glutSolidCube(1.0f); 
    }
   
    glColor4f((GLFloat)lineColor[0],
        (GLFloat)lineColor[1],
        (GLFloat)lineColor[2],
        (GLFloat)lineColor[3]);
    glutWireCube(1.0f);
}
