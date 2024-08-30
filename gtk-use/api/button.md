# button.h

## Macros

### `ALOO_BTN_TO_GTK(x)`

- **body**: `GTK_BUTTON(x->child)`
- **Description**: Returns GtkButton of widget
- **Parameters**: `alooWidget *x`

## Function

### `newButton`

- **Returns**: `alooWidget*`
- **Description**: Creates an aloo button
- **No Parameters**

### `newButtonWithLabel`

- **Returns**: `alooWidget*`
- **Description**: Creates an aloo button with a label
- **Parameters**:
- - `const char * label`
