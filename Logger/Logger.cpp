/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <execinfo.h>
#include <stdint.h>
#include "Logger.h"


// Logger settings constants
static int  dbgLevel        = SIMPLOG_DEBUG;    // Default Logging level
static char logFile[255]    = "default.log";    // Default log file name
static bool silentMode      = false;            // Default silent mode setting
static bool lineWrap        = true;             // Default setting for line wrapping

