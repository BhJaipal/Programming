# widget.h

## Functions

### `GTK_TO_ALOO`

- **Resturns**: `alooWidget *`
- **Description**: Creates alooWidget from GtkWidget.
- **Parameters**:
- - `GtkWidget *widget`

### `OBJECT_TO_ALOO`

- **Resturns**: `alooWidget *`
- **Description**: Create alooWidget from GObject.
- **Parameters**:
- - `GObject *obj`

### `OBJECT_TO_GTK_WIDGET`

- **Resturns**: `GtkWidget *`
- **Description**: Creates GtkWidget from builder.
- **Parameters**:
- - `GtkBuilder *builder`
- - `const char *name`

### `alooWidgetFromBuilder`

- **Resturns**: `alooWidget *`
- **Description**: Creates alooWidget from builder.
- **Parameters**:
- - `GtkBuilder *builder`
- - `const char *name`

### `alooSetOrientation`

- **Resturns**: `alooWidget *`
- **Description**: Sets orientation of alooWidget.
- **Parameters**:
- - `alooWidget *widget`
- - `GtkOrientation orien`

### `NewWidget`

- **Resturns**: `alooWidget *`
- **Description**: Create a widget.
- **Parameters**:
- - `WidgetType type`
- - `GtkWidget *child`

### `setWidgetName`

- **Resturns**: `alooWidget *`
- **Description**: Set the Name of widget.
- **Parameters**:
- - `alooWidget *widget`
- - `const char *name`
