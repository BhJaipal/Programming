#include "../include/grid.h"
#include "../include/widget.h"

alooWidget *gridAttach(alooWidget *grid, alooWidget *child, int column, int row,
					   int width, int height) {
	gtk_grid_attach(ALOO_GRID_TO_GTK(grid), ALOO_WIDGET_TO_GTK(child), column,
					row, width, height);
	return grid;
}
alooWidget *gridAttachGtk(alooWidget *grid, GtkWidget *child, int column,
						  int row, int width, int height) {
	gtk_grid_attach(ALOO_GRID_TO_GTK(grid), child, column, row, width, height);
	return grid;
}

alooWidget *gridRemove(alooWidget *grid, alooWidget *child) {
	gtk_grid_remove(ALOO_GRID_TO_GTK(grid), ALOO_WIDGET_TO_GTK(child));
	return grid;
}
alooWidget *gridRemoveGtk(alooWidget *grid, GtkWidget *child) {
	gtk_grid_remove(ALOO_GRID_TO_GTK(grid), child);
	return grid;
}

alooWidget *alooGridNew() { return NewWidget(ALOO_GRID, gtk_grid_new()); }

alooWidget *setGridColumnSpacing(alooWidget *grid, int space) {
	gtk_grid_set_column_spacing(ALOO_GRID_TO_GTK(grid), space);
	return grid;
}

alooWidget *setGridRowSpacing(alooWidget *grid, int space) {
	gtk_grid_set_row_spacing(ALOO_GRID_TO_GTK(grid), space);
	return grid;
}
