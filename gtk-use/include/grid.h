#ifndef ALOO_GRID_H
#define ALOO_GRID_H

#include "types.h"
#include <gtk/gtk.h>

/**
 * @brief Returns GTK_GRID of alooWidget
 * @param x alooWidget with ALOO_GRID type
 */
#define ALOO_GRID_TO_GTK(x) GTK_GRID(x->child)

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
alooWidget *gridAttach(alooWidget *grid, alooWidget *child, int column, int row,
					   int width, int height);

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
alooWidget *gridAttachGtk(alooWidget *grid, GtkWidget *child, int column,
						  int row, int width, int height);

/**
 * @brief Removes child from grid
 * @return returns grid back
 */
alooWidget *gridRemove(alooWidget *grid, alooWidget *child);

/**
 * @brief Removes child from grid
 * @return returns grid back
 */
alooWidget *gridRemoveGtk(alooWidget *grid, GtkWidget *child);

/**
 * @brief Creates new Aloo Grid Widget
 * @return returns grid
 */
alooWidget *alooGridNew();

/**
 * @brief Set the Grid Column Spacing
 */
alooWidget *setGridColumnSpacing(alooWidget *grid, int space);
/**
 * @brief Set the Grid Row Spacing
 */
alooWidget *setGridRowSpacing(alooWidget *grid, int space);

#endif // ALOO_GRID_H