/**
 ******************************************************************************
 * @file     tournament.c
 * @brief    Source file for the general tournament functions
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
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "tournament.h"
#include "display_functions.h"


ErrorMessage get_player_list (PlayerList *list)
{
    list->nb_players = 0;

    char line[NAME_MAX_LENGTH];
    ErrorMessage errMsg = {NO_ERROR, "none"};

    /* Reading the list oy players */
    while (fgets(line, sizeof(line), stdin) != NULL) {

        /* Remove the newline character if it exists */
        char *newline = strchr(line, '\n');
        if (newline != NULL)
            *newline = 0;

        if (list->nb_players <= NB_MAX_PLAYERS) {
            strcpy(list->name[list->nb_players], line);
            list->nb_players += 1;
        } else {
            list->nb_players += 1;
        }
    }

    /* Add a fictive player if the number of players is odd */
    if (list->nb_players < NB_MAX_PLAYERS
        && list->nb_players > NB_MIN_PLAYERS
        && list->nb_players % 2 != 0) {

        strcpy(list->name[list->nb_players], "Bye");
        list->nb_players += 1;
    }

    if (list->nb_players < NB_MIN_PLAYERS)
        errMsg.error_type = LIMIT_MIN_PLAYERS;

    if (list->nb_players > NB_MAX_PLAYERS)
        errMsg.error_type = LIMIT_MAX_PLAYERS;

    return errMsg;
}


void generate_tournament_grid(Grid *grid, PlayerList list)
{
    grid->nb_players = list.nb_players;
    unsigned int n = list.nb_players;

    /* Day where the player i meets the player j */
    unsigned int r = 0;

    for (unsigned int i = 1; i < n+1; ++i) {
        for (unsigned int j = 1; j < n+1; ++j) {
            if (i < j) {
                if (j != n) {
                    r = (i+j-1 < n) ? i+j-1 : i+j-n;
                } else {
                    r = (2*i <= n) ? 2*i-1 : 2*i-n;
                }
                grid->day[i-1][r-1] = j;
                grid->day[j-1][r-1] = i;
            }
        }
    }
}


ErrorMessage get_user_parameters (int argc, char* argv[], GridDesign *design)
{
    ErrorMessage errMsg = {NO_ERROR, "none"};

    int idx = 1;
    while (idx < argc) {

        if (strcmp(argv[idx], "-s") == 0 
            || strcmp(argv[idx], "--style") == 0) 
        {
            if (idx + 1 != argc) {
                if (strcmp(argv[idx+1], "table") == 0){
                    design->style = STYLE_TABLE;
                }
                else if (strcmp(argv[idx+1], "compact") == 0){
                    design->style = STYLE_COMPACT;
                }
                else {
                    errMsg.error_type = UNKNOWN_STYLE;
                    errMsg.msg = argv[idx+1];
                    break;
                }
                idx += 2;
            } else {
                errMsg.error_type = WRONG_NB_ARG;
                break;
            }
        }
        else if (strcmp(argv[idx], "-f") == 0 
                 || strcmp(argv[idx], "--format") == 0) 
        {
            if (idx + 1 != argc) {
                if (strcmp(argv[idx+1], "id") == 0){
                    design->format = FORMAT_ID;
                }
                else if (strcmp(argv[idx+1], "name") == 0){
                    design->format = FORMAT_NAME;
                }
                else {
                    errMsg.error_type = UNKNOWN_FORMAT;
                    errMsg.msg = argv[idx+1];
                    break;
                }
                idx += 2;
            } else {
                errMsg.error_type = WRONG_NB_ARG;
                break;
            }
        } 
        else {
            errMsg.error_type = UNKNOWN_OPTION;
            errMsg.msg = argv[idx];
            break;
        }
    }
    
    return errMsg;
}


int main(int argc, char* argv[]) 
{
    PlayerList list;
    Grid grid;
    GridDesign design = {FORMAT_ID, STYLE_COMPACT};
    ErrorMessage error1, error2;
    int status = 0;
    
    error1 = get_user_parameters(argc, argv, &design);
    if (error1.error_type != NO_ERROR) {
        display_error_message(error1);
        status = 1;
    }

    error2 = get_player_list(&list);
    if (error2.error_type != NO_ERROR) {
        display_error_message(error2);
        status = 1;
    }
    
    if (status != 1) {
        generate_tournament_grid(&grid, list);
        display_grid(grid, list, design);
    }

    return status;
}

