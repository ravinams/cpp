/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Logger.h
 * Author: oracle
 *
 * Created on February 16, 2018, 9:31 AM
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

// Define logging levels
#define SIMPLOG_FATAL    -2    // A fatal error has occured: program will exit immediately
#define SIMPLOG_ERROR    -1    // An error has occured: program may not exit
#define SIMPLOG_INFO     0     // Nessessary information regarding program operation
#define SIMPLOG_WARN     1     // Any circumstance that may not affect normal operation
#define SIMPLOG_DEBUG    2     // Standard debug messages
#define SIMPLOG_VERBOSE  3     // All debug messages

// Public functions
typedef struct {
    void ( *const writeLog )( int loglvl, const char* str, ... );
    void ( *const writeStackTrace )( void );
    void ( *const setLogDebugLevel )( int level );
    void ( *const setLogFile )( const char* file );
    void ( *const setLogSilentMode )( bool silent );
    void ( *const setLineWrap )( bool wrap );
    void ( *const flushLog )( void );
    void ( *const loadConfig )( const char* config );
} simplog_namespace;
extern simplog_namespace const simplog;

#endif /* LOGGER_H */

