# app.h

## Struct

### alooAppAndStatus

- **Description**: Returns GtkApplication and status.
- **Members**:
- - `GtkApplication *app`
- - `int status`

### alooAppOptions

- **Description**: Takes GApplicationFlags, argc and argv.
- **Members**:
- - `GApplicationFlags GAppFlags`
- - `int argc`
- - `char **argv`

## Macros

### `ALOO_IS_WINDOW(X)`

- **Description**: Checks if GtkWidget is a GtkWindow or not
- **body**:
- - `GTK_IS_WINDOW(X->child)`
- **Returns**: 0 or 1

## Functions

### CreateApp

- **Returns**: `struct alooAppAndStatus`
-
- **Description**: Create a App object.
-
- **Parameters**:
- - `char *app_id`
- - `struct alooAppOptions gAppOptions`
- - `void activateFn( GtkApplication *app, gpointer user*data)`

### alooHorizontalAlign

- ****Returns****: `alooWidget *`
- **Description**: Sets horizontal alignment of alooWidget.
- **Parameters**:
- - `alooWidget *widget`
- - `GtkAlign alignment`

### alooVerticalAlign

- ****Returns****: `alooWidget *`
- **Description**: Sets vertical alignment of alooWidget.
- **Parameters**:
- - `alooWidget *widget`
- - `GtkAlign alignment`

### alooAddEventListener

- **Returns**: `alooWidget *`
- **Description**: Adds event listener to a widget.
- **Paramters**:
- - `alooWidget *widget_instance`
- - `char * event_name`
- - `GCallback CallbackFn`
- - `gpointer data`

### alooSetWindowChild

- **Returns**: `GtkWidget *`
- **Description**: Sets Window child.
- **Parameters**:
- - `GtkWidget *window`
- - `GtkWidget child`

### alooPresentWindow

- **Returns**: `GtkWidget *`
- **Description**: Presents GtkWindow.
- **Parameters**:
- - `GtkWidget *window`

### alooAddNewButtonLabel

- **Returns**: `GtkWidget *`
- **Description**: Create new GtkButton.
- **Parameters**:
- - `const char *label`

### alooApplicationNewWindow

- **Returns**: `GtkWidget *`
- **Description**: Create a GtkWindow.
- **Parameters**:
- - `GtkApplication *app`

### alooSetWindowTitle

- **Returns**: `GtkWidget *`
- **Description**: Sets GtkWindow title.
- **Parameters**:
- - `GtkWidget *window`
- - `const char title`

### setWindowSize

- **Returns**: `alooWidget *`
- **Description**: Sets aloo Window size.
- **Parameters**:
- - `alooWidget window`
- - `int width`
- - `int height`

### alooGetBuilderObject

- **Returns**: `GObject *`
- **Description**: Gets GObject from builder.
- **Parameters**:
- - `GtkBuilder *builder`
- - `const char *name`

### setWindowApplication

- **Returns**: `alooWidget *`
- **Description**: Set the Window for Application.
- **Parameters**:
- - `alooWidget *window`
- - `GtkApplication *app`

### showWindow

- **Returns**: `void`
- **Description**: Shows Window.
- **Parameters**:
- - `alooWidget *window`

### `unrefObject`

- **Returns**: `void`
- **Description**: Unrefs object
- **Parameters**:
- - `gpointer object`
