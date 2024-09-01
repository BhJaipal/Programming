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
/// @brief Removes child from grid
/// @return returns grid back
alooWidget *__gridRemove(alooWidget *grid, alooWidget *child);

/// @brief Removes child from grid
/// @return returns grid back
alooWidget *__gridRemoveGtk(alooWidget *grid, GtkWidget *child);

/// @brief Creates new Aloo Grid Widget
/// @return returns grid
alooWidget *__alooGridNew();

/** @brief Set the Grid Column Spacing */
alooWidget *__setGridColumnSpacing(alooWidget *grid, int space);
/** @brief Set the Grid Row Spacing */
alooWidget *__setGridRowSpacing(alooWidget *grid, int space);

/******************** Private Types ********************/

struct _alooGrid {
	/**
	 * @brief Adds widget to aloo grid
	 * @param grid grid in which child should be added
	 * @param child child to be added
	 * @param column column in which it should be added
	 * @param row row in which it should be added
	 * @param width column span of widget or how many column it takes
	 * @param height row span of widget or how many row it takes
	 * @return returns grid back
	 */
	alooWidget *(*attach)(alooWidget *grid, alooWidget *child, int column,
						  int row, int width, int height);
	/**
	 * @brief Adds widget to aloo grid
	 * @param grid grid in which child should be added
	 * @param child child to be added
	 * @param column column in which it should be added
	 * @param row row in which it should be added
	 * @param width column span of widget or how many column it takes
	 * @param height row span of widget or how many row it takes
	 * @return returns grid back
	 */
	alooWidget *(*attachGtk)(alooWidget *grid, GtkWidget *child, int column,
							 int row, int width, int height);
	/// @brief Removes child from grid
	/// @return returns grid back
	alooWidget *(*remove)(alooWidget *grid, alooWidget *child);
	/// @brief Removes child from grid
	/// @return returns grid back
	alooWidget *(*removeGtk)(alooWidget *grid, GtkWidget *child);
	/// @brief Creates new Aloo Grid Widget
	/// @return returns grid
	alooWidget *(*new)();
	/** @brief Set the Grid Column Spacing */
	alooWidget *(*column_spacing)(alooWidget *grid, int space);
	/** @brief Set the Grid Row Spacing */
	alooWidget *(*row_spacing)(alooWidget *grid, int space);
	/// @brief Returns Gtk Grid
	GtkGrid *(*toGtk)(alooWidget *widget);
};

/******************** Public ********************/

extern struct _alooGrid Grid;

#endif // ALOO_GRID_H