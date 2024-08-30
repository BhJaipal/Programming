# grid.h

## Macros

### `ALOO_GRID_TO_GTK(x)`

- **body**: `GTK_GRID(x->child)`
- **Description**: Returns GtkGrid of alooWidget.
- **Parameters**: `GtkWidget *x`

## Functions

### `gridAttach`

- **Returns**: `alooWidget *`
- **Description**: Adds widget to aloo grid.
- **Parameters**:
- - `alooWidget *grid`
- - `alooWidget *child`
- - `int column`
- - `int row`
- - `int width`
- - `int height`

### `gridAttachGtk`

- **Returns**: `alooWidget *`
- **Description**: Adds widget to aloo grid.
- **Parameters**:
- - `alooWidget *grid`
- - `GtkWidget *child`
- - `int column`
- - `int row`
- - `int width`
- - `int height`

### `gridRemove`

- **Returns**: `alooWidget *`
- **Description**: Removes child from grid.
- **Parameters**:
- - `alooWidget *grid`
- - `alooWidget *child`

### `gridRemoveGtk`

- **Returns**: `alooWidget *`
- **Description**: Removes child from grid.
- **Parameters**:
- - `alooWidget *grid`
- - `GtkWidget *child`

### `alooGridNew`

- **Returns**: `alooWidget *`
- **Description**: Creates new Aloo Grid Widget.
- **No Parameters**

### `setGridColumnSpacing`

- **Returns**: `alooWidget *`
- **Description**: Set the Grid Column Spacing.
- **Parameters**:
- - `alooWidget *grid`
- - `int space`

### `setGridRowSpacing`

- **Returns**: `alooWidget *`
- **Description**: Set the Grid Row Spacing.
- **Parameters**
- - `alooWidget *grid`
- - `int space`
