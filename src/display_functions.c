/**
 ******************************************************************************
 * @file     display_functions.h
 * @brief    Source file for the display functions
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the MIT license
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#include <stdio.h>
#include "display_functions.h"


void display_grid (Grid grid, PlayerList list, GridDesign design)
{
    const Style_t s = design.style;
    const Format_t f = design.format;

    if (s == STYLE_COMPACT && f == FORMAT_ID) {
        display_grid_CompactID(grid, list);
    }
    else if (s == STYLE_COMPACT && f == FORMAT_NAME) {
        display_grid_CompactName(grid, list);
    }
    else if (s == STYLE_TABLE && f == FORMAT_ID) {
        display_grid_TableID(grid, list);
    }
    else if (s == STYLE_TABLE && f == FORMAT_NAME) {
        display_grid_TableName(grid, list);
    }
    else {
        /* Should never be here */
        fprintf(stderr, "Error: impossible to write the tournament grid\n");
    }
}


void display_grid_CompactID(Grid grid, PlayerList list)
{
    const unsigned int n = list.nb_players;

    for (unsigned int i = 0; i < n; ++i) {
        printf("%d:%s\n", i+1, list.name[i]);
    }

    for (unsigned int i = 0; i < n; ++i) {
        printf("%d:", i+1);
        for (unsigned int j = 0; j < n-1; ++j) {
            printf("%d%s", grid.day[i][j], j != n-2 ? "," : "\n");
        }
    }
}


void display_grid_CompactName(Grid grid, PlayerList list)
{
    const unsigned int n = list.nb_players;

    for (unsigned int i = 0; i < n; ++i) {
        printf("%s:", list.name[i]);
        for (unsigned int j = 0; j < n-1; ++j) {
            unsigned int advIdx = grid.day[i][j];
            printf("%s%s", list.name[advIdx-1], j != (n-2) ? "," : "\n");
        }
    }
}


void display_grid_TableID(Grid grid, PlayerList list)
{
    const unsigned int n = list.nb_players;

    printf("ID  Player  ");
    for (unsigned int i = 1; i < n; ++i) {
        printf("  Day %d%s%s", i, (i > 9) ? "" : " ", (i != n-1) ? "" : "\n"); 
    }

    printf("--  --------");
    for (unsigned int i = 1; i < n; ++i) {
        printf("  ------%s", (i != n-1) ? "" : "\n");
    }

    for (unsigned int i = 0; i < n; ++i) {
        printf("%s%d  %-8.8s", (i > 8) ? "" : " ", i+1, list.name[i]);
        for (unsigned int j = 0; j < n-1; ++j) {
            printf("  %d    %s%s", grid.day[i][j], 
                    (grid.day[i][j] > 9) ? "" : " ", (j != n-2) ? "" : "\n");
        }
    }
}


void display_grid_TableName (Grid grid, PlayerList list)
{
    const unsigned int n = list.nb_players;

    printf("ID  Player  ");
    for (unsigned int i = 1; i < n; ++i) {
        printf("  Day %d  %s%s", i, (i > 9) ? "" : " ", (i != n-1) ? "" : "\n");
    }

    printf("--  --------");
    for (unsigned int i = 1; i < n; ++i) {
        printf("  --------%s", (i != n-1) ? "" : "\n");
    }

    for (unsigned int i = 0; i < n; ++i) {
        printf("%s%d  %-8.8s", (i > 8) ? "" : " ", i+1, list.name[i]);
        for (unsigned int j = 0; j < n-1; ++j) {
            unsigned int advIdx = grid.day[i][j];
            printf("  %-8.8s%s", list.name[advIdx-1], (j != n-2) ? "" : "\n");
        }
    }
}


void display_error_message(ErrorMessage errMsg)
{
    switch (errMsg.error_type) {
        case WRONG_NB_ARG: {
            fprintf(stderr, "Error: wrong number of arguments\n");
            break;
        }
        case UNKNOWN_OPTION: {
            fprintf(stderr, "Error: unknown option (%s)\n", errMsg.msg);
            break;
        }
        case UNKNOWN_STYLE: {
            fprintf(stderr, "Error: unknown style (%s)\n", errMsg.msg);
            break;
        }
        case UNKNOWN_FORMAT: {
            fprintf(stderr, "Error: unknown format (%s)\n", errMsg.msg);
            break;
        }
        case LIMIT_MIN_PLAYERS: {
            fprintf(stderr, "Error: not enough players (minimum is %d)\n", NB_MIN_PLAYERS);
            break;
        }
        case LIMIT_MAX_PLAYERS: {
            fprintf(stderr, "Error: too many players (maximum is %d)\n", NB_MAX_PLAYERS);
            break;
        }
        case NO_ERROR:
        default:        
            break;
    }
}