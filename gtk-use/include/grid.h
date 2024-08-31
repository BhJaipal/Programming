/**
 * @file grid.h
 * @author Jaipal001
 * @brief Aloo Grid related functions
 */
#ifndef ALOO_GRID_H
#define ALOO_GRID_H

#include "types.h"
#include <gtk/gtk.h>

/******************** Private Funcs ********************/

/**
 * @brief Adds widget to aloo grid
 *
 * @param grid grid in which child should be added
 * @param child child to be added
 * @param column column in which it should be added
 * @param row row in which it should be added
 * @param width column span of widget or how many column it takes
 * @param height row span of widget or how many row it takes
 * @return returns grid back
 */
alooWidget *__gridAttach(alooWidget *grid, alooWidget *child, int column,
						 int row, int width, int height);

/**
 * @brief Adds widget to aloo grid
 *
 * @param grid grid in which child should be added
 * @param child child to be added
 * @param column column in which it should be added
 * @param row row in which it should be added
 * @param width column span of widget or how many column it takes
 * @param height row span of widget or how many row it takes
 * @return returns grid back
 */
alooWidget *__gridAttachGtk(alooWidget *grid, GtkWidget *child, int column,
							int row, int width, int height);

/**
 * @brief Removes child from grid
 * @return returns grid back
 */
alooWidget *__gridRemove(alooWidget *grid, alooWidget *child);

/**
 * @brief Removes child from grid
 * @return returns grid back
 */
alooWidget *__gridRemoveGtk(alooWidget *grid, GtkWidget *child);

/**
 * @brief Creates new Aloo Grid Widget
 * @return returns grid
 */
alooWidget *__alooGridNew();

/**
 * @brief Set the Grid Column Spacing
 */
alooWidget *__setGridColumnSpacing(alooWidget *grid, int space);
/**
 * @brief Set the Grid Row Spacing
 */
alooWidget *__setGridRowSpacing(alooWidget *grid, int space);

/******************** Private Types ********************/

typedef alooWidget *(*__gridAttach_Type)(alooWidget *grid, alooWidget *child,
										 int column, int row, int width,
										 int height);

typedef alooWidget *(*__gridAttachGtk_Type)(alooWidget *grid, GtkWidget *child,
											int column, int row, int width,
											int height);

typedef alooWidget *(*__gridRemove_Type)(alooWidget *grid, alooWidget *child);

typedef alooWidget *(*__gridRemoveGtk_Type)(alooWidget *grid, GtkWidget *child);

typedef alooWidget *(*__alooGridNew_Type)();

typedef alooWidget *(*__setGridColumnSpacing_Type)(alooWidget *grid, int space);

typedef alooWidget *(*__setGridRowSpacing_Type)(alooWidget *grid, int space);

/******************** Public ********************/

struct _alooGrid {
	__gridAttach_Type attach;
	__gridAttachGtk_Type attachGtk;
	__gridRemove_Type remove;
	__gridRemoveGtk_Type removeGtk;
	__alooGridNew_Type new;
	__setGridColumnSpacing_Type column_spacing;
	__setGridRowSpacing_Type row_spacing;
};

extern struct _alooGrid Grid;

#endif // ALOO_GRID_H