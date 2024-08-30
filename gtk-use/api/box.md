# box.h

## Macros

### `ALOO_BOX_TO_GTK_BOX(x)`

- **body**: GTK_BOX(ALOO_BOX_WIDGET(x))
- **Description**: Return GtkBox of widget
- **Parameters**: `alooWidget *x`

## Functions

### `ALOO_BOX_WIDGET`

- **Returns**: `GtkWidget *`
- **Parameters**:
- - `alooWidget *x`

### `ALOO_IS_BOX`

- **Returns**: `gboolean`
- **Parameters**:
- - `alooWidget *x`

### `newAlooBox`

- **Returns**: `alooWidget *`
- **Parameters**:
- - `GtkOrientation orientation`
- - `int spacing`

### `setBoxOrientation`

- **Returns**: `alooWidget *`
- **Description**: Sets Box Orientation.
- **Parameters**:
- - `alooWidget *box`
- - `GtkOrientation orientation`

### `getBoxOrientation`

- **Returns`**: GtkOrientation`
- **Description**: Gets Box Orientation.
- **Parameters**:
- - `alooWidget *box`

### `boxAppendGtk`

- **Returns**: `alooWidget *`
- **Description**: Appends GtkWidget child to box.
- **Parameters**:
- - `alooWidget *box`
- - `GtkWidget *widget`

### `boxPrependGtk`

- **Returns**: `alooWidget *`
- **Description**: Prepends GtkWidget child to box.
- **Parameters**:
- - `alooWidget *box`
- - `GtkWidget *widget`

### `boxRemoveGtk`

- **Returns**: `alooWidget *`
- **Description**: Removes GtkWidget child from box.
- **Parameters**:
- - `alooWidget *box`
- - `GtkWidget *widget`

### `boxAppend`

- **Returns**: `alooWidget *`
- **Description**: Appends alooWidget child to box.
- **Parameters**:
- - `alooWidget *box`
- - `alooWidget *widget`

### `boxPrepend`

- **Returns**: `alooWidget *`
- **Description**: Prepends alooWidget child to box.
- **Parameters**:
- - `alooWidget *box`
- - `alooWidget *widget`

### `boxRemove`

- **Returns**: `alooWidget *`
- **Description**: Removes alooWidget child from box.
- **Parameters**:
- - `alooWidget *box`
- - `alooWidget *widget`

### `boxInsertChildAfter`

- **Returns**: `alooWidget *`
- **Description**: Adds child after a certain widget of box.
- **Parameters**:
- - `alooWidget *box`
- - `alooWidget *child`
- - `alooWidget *after`

### `setBoxSpacing`

- **Returns**: `alooWidget *`
- **Description**: Set Box Spacing.
- **Parameters**:
- - `alooWidget *box`
- - `int spacing`

### `getBoxSpacing`

- **Returns**: `int`
- **Description**: Gets box spacing.
- **Parameters**:
- - `alooWidget *box`

### `getBoxHomogeneous`

- **Returns**: `gboolean`
- **Description**: Gets box homogeneous.
- **Parameters**:
- - `alooWidget *box`

### `setBoxHomogeneous`

- **Returns**: `alooWidget *`
- **Description**: Sets box homogeneous.
- **Parameters**:
- - `alooWidget *box`
- - `gboolean homogeneous`

### `getBoxBaselinePosition`

- **Returns**: `GtkBaselinePosition`
- **Description**: Gets Box baseline position.
- **Parameters**:
- - `alooWidget *box`

### `setBoxBaselinePosition`

- **Returns**: `alooWidget *`
- **Description**: Sets Box baseline position.
- **Parameters**:
- - `alooWidget *box`
- - `GtkBaselinePosition position`
