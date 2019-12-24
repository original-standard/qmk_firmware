/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef JOY_EIGHT_H

#define JOY_EIGHT_H

#include "quantum.h"

#include "pointing_device.h"

#define LAYOUT( \
    K00, K01, K02, \
    K10, K11, K12, \
    K20, K21, K22 \
) \
{ \
    { K00, K01, K02}, \
    { K10, K11, K12}, \
    { K20, K21, K22} \
}

#endif