/*
MIT License

Copyright (c) 2024 Lithinium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef RAM_H
#define RAM_H

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* DEFINES */

#define MAX_BUFF 64

/* Get the Total of the RAM in KiloBytes */
unsigned long getTotalRam(void);
/* Get the Total of the Avaible RAM in KiloBytes */
unsigned long getAvaibleRam(void);
/* Get the Total of the Used RAM in KiloBytes */
unsigned long getUsedRam(void);

#endif
