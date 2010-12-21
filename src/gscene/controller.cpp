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

#include "controller.h"
#include <GL/glut.h>
#include <map>

using namespace std;
map<unsigned char, control_func> hooks;

void controller_keydown(unsigned char key, int x, int y) {
    hooks[key](key, true);    
}

void controller_keyup(unsigned char key, int x, int y) {
    hooks[key](key, false);    
}

void controller_set_hook(const char* keys, control_func func) {
    char key;
    int i = 0;

    while (key = keys[i++]) {
        hooks[key] = func;
    }
}

void controller_start() {
    glutKeyboardFunc(controller_keydown);
    glutKeyboardUpFunc(controller_keyup);
}
