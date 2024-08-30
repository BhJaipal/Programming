# style.h

## Functions

### importCssFromPath

- **Returns**: `void`
- **Description**: Import CSS file from path
- **Parameters**:
- - `const char *name`: name path of css file

### importCssFromData

- **Returns**: `void`
- **Description**: content css content
- **Parameters**:
- - `const char *content`: content
- - `gssize length`: content length

### importCssFromFile

- **Returns**: `void`
- **Description**: Import CSS file from content
- **Parameters**:
- - `GFile *file`: file CSS GFile

### `setWidth`

- **Returns**: alooWidget *
- **Description**: Set the Width of widget.
- **Parameters**:
- - `alooWidget *wid`
- - `int width`

### `setHeight`

- **Returns**: alooWidget *
- **Description**: Set the Height of widget.
- **Parameters**:
- - `alooWidget *wid`
- - `int height`

### `setSize`

- **Returns**: alooWidget *
- **Description**: Set the Width and Height of widget.
- **Parameters**:
- - `alooWidget *wid`
- - `int width`
- - `int height`

### `widgetAddClass`

- **Returns**: alooWidget *
- **Description**: Adds class to widget.
- **Parameters**:
- - `alooWidget *widget`
- - `char *class`

### `widgetRemoveClass`

- **Returns**: alooWidget *
- **Description**: Removes class from widget.
- **Parameters**:
- - `alooWidget *widget`
- - `char *class`

### `getWidgetClasses`

- **Returns**: char **
- **Description**: Gets \classes of widget.
- **Parameters**:
- - `alooWidget *widget`

### `setWidgetClasses`

- **Returns**: alooWidget *
- **Description**: Sets classes of widget.
- **Parameters**:
- - `alooWidget *widget`
- - `char **classes`
