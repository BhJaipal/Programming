#include "grid.h"
#include "macros.h"
#include "utils/error.h"
#include "widget.h"

alooWidget *__gridAttach(alooWidget *grid, alooWidget *child, int column,
						 int row, int width, int height) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_attach(ALOO_GRID_TO_GTK(grid), Widget.to_gtk(child), column, row,
					width, height);
	return grid;
}
alooWidget *__gridAttachGtk(alooWidget *grid, GtkWidget *child, int column,
							int row, int width, int height) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_attach(ALOO_GRID_TO_GTK(grid), child, column, row, width, height);
	return grid;
}

alooWidget *__gridRemove(alooWidget *grid, alooWidget *child) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_remove(ALOO_GRID_TO_GTK(grid), Widget.to_gtk(child));
	return grid;
}
alooWidget *__gridRemoveGtk(alooWidget *grid, GtkWidget *child) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_remove(ALOO_GRID_TO_GTK(grid), child);
	return grid;
}

alooWidget *__alooGridNew() { return Widget.new(ALOO_GRID, gtk_grid_new()); }

alooWidget *__setGridColumnSpacing(alooWidget *grid, int space) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_set_column_spacing(ALOO_GRID_TO_GTK(grid), space);
	return grid;
}

alooWidget *__setGridRowSpacing(alooWidget *grid, int space) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_set_row_spacing(ALOO_GRID_TO_GTK(grid), space);
	return grid;
}

GtkGrid *__toGridGtk(alooWidget *wid) {
	if (!Widget.check.isGrid(wid)) {
		throw_error("Invalid grid");
		return GTK_GRID(Grid.new()->child);
	}
	return GTK_GRID(wid->child);
}

struct _alooGrid Grid = {
	__gridAttach,  __gridAttachGtk,		   __gridRemove,		__gridRemoveGtk,
	__alooGridNew, __setGridColumnSpacing, __setGridRowSpacing, __toGridGtk,
};