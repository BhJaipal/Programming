# types.h

## Struct

### `alooWidget`

- **Description**: widget for my aloo library
- **Members**:
- - `GtkWidget *child`: actual GtkWidget
- - `WidgetType type`: Type of widget

## Macros

### `ALOO_WIDGET_TO_GTK(x)`

- **Description**: Macro to convert alooWidget to GtkWidget
- **body**: x->child
- **Parameters**:
- - `alooWidget *x`

## Enumerations

### `WidgetType`

- **Description**: Type of alooWidget
- **Values**:
- - `ALOO_BOX`: Used for Gtk Box
- - `ALOO_GRID`: Used for Gtk Grid
- - `ALOO_ROW`: Used for Gtk Row
- - `ALOO_COLUMN`: Used for Gtk Column
- - `ALOO_BUTTON`: Used for Gtk Button
- - `ALOO_LABEL`: Used for Gtk Label
- - `ALOO_NEW_WIDGET`: Can be used to create new custom widget and used with all
