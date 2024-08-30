# style.h

## Functions

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
