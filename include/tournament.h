/**
 ******************************************************************************
 * @file     tournament.h
 * @brief    Header file for the general tournament functions
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the MIT license
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#ifndef _TOURNAMENT_H
#define _TOURNAMENT_H

#include "typedefs.h"


/**
 * @brief   Get the list of players provided 
 *          by the user on stdin
 * 
 * @param[in,out]   list    List of players
 * @returns                 The details of the error if an error occurs
 * 
 */
ErrorMessage get_player_list (PlayerList *list);


/**
 * @brief   Get command-line arguments provided by the user
 *          to design the tournament grid
 * 
 * @param[in]       argc    Argument count provided the main function
 * @param[in]       argv    Argument vector provided the main function
 * @param[in,out]   design  Pointer to the design of the grid
 * @returns                 The details of the error if an error occurs
 * 
 */
ErrorMessage get_user_parameters (int argc, char* argv[], GridDesign *design);


/**
 * @brief   Generate the tournament grid
 * @details Determine when two participants meet each other according 
 *          to the Berger method and fills in the match table for each participant 
 *          in the tournament grid
 * 
 * @see     https://fr.wikipedia.org/wiki/Table_de_Berger
 * 
 * @param[in,out]   grid    Pointer to the tournament grid
 * @param[in]       list    List of players
 * @returns                 None
 * 
 */
void generate_tournament_grid (Grid *grid, PlayerList list);


#endif