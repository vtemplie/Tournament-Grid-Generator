/**
 ******************************************************************************
 * @file     typedef.h
 * @brief    Header file to contain the defines, structs and enums
 *           for the tournament functions
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
#define NUM_MIN_PLAYERS 2
#define NUM_MAX_PLAYERS 20

/** Enumeration for containing the types of display style */
typedef enum {
    STYLE_COMPACT,
    STYLE_TABLE
} Style;

/** Enumeration for containing the types of display format */
typedef enum {
    FORMAT_ID,
    FORMAT_NAME
} Format;

/** Object for containing the list of players */
typedef struct {
    unsigned int num_players;
    char name[NUM_MAX_PLAYERS][NAME_MAX_LENGTH + 1];
} PlayerList;

/** Object for designing the tournament grid */
typedef struct {
    unsigned int num_players;
    unsigned int day[NUM_MAX_PLAYERS]
                    [NUM_MAX_PLAYERS];
} Grid;



#endif