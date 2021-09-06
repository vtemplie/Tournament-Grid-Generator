/**
 ******************************************************************************
 * @file     display_functions.h
 * @brief    Header file for the display functions
 *           
 ******************************************************************************
 * @attention
 * 
 *  Licensed under the MIT license
 *  Contributor(s): Vincent TEMPLIER
 * 
 ******************************************************************************
 */

#ifndef _DISPLAY_FUNCTIONS_H
#define _DISPLAY_FUNCTIONS_H

#include "typedefs.h"

/**
 * @brief   Display the tournament according to the user options
 * 
 * @param[in]   grid    Tournament grid
 * @param[in]   list    List of players
 * @param[in]   design  Design of the grid
 * @returns             None
 * 
 */
void display_grid (Grid grid, PlayerList list, GridDesign design);


/**
 * @brief   Displays the tournament grid in a compact way 
 *          with the id of each opponent faced by each participant
 * 
 * @example 1:Djokovic
 *          2:Nadal
 *          3:Federer
 *          4:Murray
 *          1:4,2,3
 *          2:3,1,4
 *          3:2,4,1
 *          4:1,3,2
 * 
 * @param[in]   grid    Tournament grid
 * @param[in]   list    List of players
 * @returns             None
 * 
 */
void display_grid_CompactID (Grid grid, PlayerList list);


/**
 * @brief   Displays the tournament grid in a compact way 
 *          with the name of each opponent faced by each participant
 * 
 * @example Djokovic:Murray,Nadal,Federer
 *          Nadal:Federer,Djokovic,Murray
 *          Federer:Nadal,Murray,Djokovic
 *          Murray:Djokovic,Federer,Nadal
 * 
 * @param[in]   grid    Tournament grid
 * @param[in]   list    List of players
 * @returns             None
 * 
 */
void display_grid_CompactName (Grid grid, PlayerList list);


/**
 * @brief   Displays the tournament grid in a table 
 *          with the id of each opponent faced by each participant
 * 
 * @example ID  Player    Day 1   Day 2   Day 3 
 *          --  --------  ------  ------  ------
 *           1  Djokovic  4       2       3     
 *           2  Nadal     3       1       4         
 *           3  Federer   2       4       1     
 *           4  Murray    1       3       2     
 * 
 * @param[in]   grid    Tournament grid
 * @param[in]   list    List of players
 * @returns             None
 * 
 */
void display_grid_TableID (Grid grid, PlayerList list);


/**
 * @brief   Displays the tournament grid in a table 
 *          with the name of each opponent faced by each participant
 * 
 * @example ID  Player    Day 1     Day 2     Day 3   
 *          --  --------  --------  --------  --------
 *           1  Djokovic  Murray    Nadal     Federer 
 *           2  Nadal     Federer   Djokovic  Murray  
 *           3  Federer   Nadal     Murray    Djokovic
 *           4  Murray    Djokovic  Federer   Nadal  
 * 
 * @param[in]   grid    Tournament grid
 * @param[in]   list    List of players
 * @returns             None
 * 
 */
void display_grid_TableName (Grid grid, PlayerList list);


/**
 * @brief   Display an error message related to the error that occurred
 * @details The message is printed on stderr
 * 
 * @param[in]   errMsg  Details of the error
 * @returns             None
 * 
 */
void display_error_message (ErrorMessage errMsg);


#endif