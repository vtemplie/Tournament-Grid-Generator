/**
 ******************************************************************************
 * @file     typedef.h
 * @brief    Header file to contain the defines, structs and enums
 *           for the tournament and display functions
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the MIT license
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#ifndef _TYPEDEFS_H
#define _TYPEDEFS_H

#define NAME_MAX_LENGTH 20
#define NB_MIN_PLAYERS 2
#define NB_MAX_PLAYERS 20


/** Enumeration for the types of display style */
typedef enum {
    STYLE_COMPACT,
    STYLE_TABLE
} Style_t;


/** Enumeration for the types of display format */
typedef enum {
    FORMAT_ID,
    FORMAT_NAME
} Format_t;


/** Enumeration for the types of errors */
typedef enum {
    NO_ERROR,
    WRONG_NB_ARG,
    UNKNOWN_OPTION,
    UNKNOWN_STYLE,
    UNKNOWN_FORMAT,
    LIMIT_MIN_PLAYERS,
    LIMIT_MAX_PLAYERS
} Error_t;


/** Object for containing the list of players */
typedef struct {
    unsigned int nb_players;
    char name[NB_MAX_PLAYERS][NAME_MAX_LENGTH + 1];
} PlayerList;


/** Object for containing the tournament grid */
typedef struct {
    unsigned int nb_players;
    unsigned int day[NB_MAX_PLAYERS][NB_MAX_PLAYERS];
} Grid;


/** Object for containing the details of the error that occurred */
typedef struct {
    Error_t error_type;     /* Error type */
    char* msg;              /* Additional information about the error */ 
} ErrorMessage;


/** Object for containing the design of the grid */
typedef struct {
    Format_t format;
    Style_t style;
} GridDesign;



#endif