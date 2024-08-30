# app.h

## Enumrations

### `alooAppFlags`

- **Description**: G Application Flags
- **Values**:
- - `APP_FLAGS_NONE`: G_APPLICATION_FLAGS_NONE
- - `APP_FLAGS_IS_LAUNCHER`: G_APPLICATION_FLAGS_IS_LAUNCHER
- - `APP_FLAGS_IS_SERVICE`: G_APPLICATION_FLAGS_IS_SERVICE

## Struct

### alooApp_Status

- **Description**: Returns GtkApplication and status.
- **Members**:
- - `GtkApplication *app`
- - `int status`

### alooAppOptions

- **Description**: Takes GApplicationFlags, argc and argv.
- **Members**:
- - `enum alooAppFlags appFlags`
- - `int argc`
- - `char **argv`

## Macros

### `ALOO_IS_WINDOW(X)`

- **Description**: Checks if GtkWidget is a GtkWindow or not
- **body**:
- - `GTK_IS_WINDOW(X->child)`
- **Returns**: 0 or 1

### NONE_FLAGS_OPTIONS

- **Description**: generates app options with APP_FLAGS_NONE
- **body**: `{ APP_FLAGS_NONE, argc, argv }`
- **Parameters**:
- - `int argc`
- - `char **argv`

### LAUNCHER_FLAGS_OPTIONS

- **Description**: generates app options with APP_FLAGS_IS_LAUNCHER
- **body**: `{ APP_FLAGS_IS_LAUNCHER, argc, argv }`
- **Parameters**:
- - `int argc`
- - `char **argv`

### SERVICE_FLAGS_OPTIONS

- **Description**: generates app options with APP_FLAGS_IS_SERVICE
- **body**: `{ APP_FLAGS_IS_SERVICE, argc, argv }`
- **Parameters**:
- - `int argc`
- - `char **argv`

## Functions

### CreateApp

- **Returns**: `struct alooApp_Status`
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

### `unrefBuilder`

- **Returns**: `void`
- **Description**: Unrefs aloo builder
-
- **Parameters**:**Parameters**:
- - `AlooBuilder *object`

### createBuilder

- **Description**: Create a Builder object
- **Return**: `AlooBuilder*`
- **No Parameters**

### builderAddFile

- **Description**: Adds a file with builder
- **Returms**: int
- **Parameters**:
- - `AlooBuilder*build`: build AlooBuilder object
- - `const char *filename`: filename UI file path with name
- - `GError **err`: err Error handler, Default `NULL`

### builderAddContent

- **Description**: Adds a file with builder
- **Returms**: int
- **Parameters**:
- - `AlooBuilder*build`: build AlooBuilder object
- - `const char *content`: content UI data
- - `gssize length`: length UI data length
- - `GError **err`: err Error handler, Default `NULL`

### builderAddResource

- **Description**: Adds a file with builder
- **Returms**: int
- **Parameters**:
- - `AlooBuilder*build`: build AlooBuilder object
- - `const char *resource_path`: resource_path UI resource path
- - `GError **err`: err Error handler, Default `NULL`
