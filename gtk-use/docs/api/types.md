# include/types.h

SYNOPSIS:

-   `#include <gtk/gtk.h>`

## Classes

|                               |                            |
| ----------------------------- | -------------------------- |
| <key> struct alooWidget</key> | widget for my aloo library |

### Macros

|                                  |          |
| -------------------------------- | -------- |
| <key>ALOO_WIDGET_TO_GTK(x)</key> | x->child |

Typedefs
typedef enum WidgetType WidgetType
typedef struct alooWidget alooWidget
widget for my aloo library

## Enumerations

<key>enum WidgetType</key>:

-          ALOO_BOX
-          ALOO_GRID
-          ALOO_ROW
-          ALOO_COLUMN
-          ALOO_BUTTON
-          ALOO_LABEL
-          ALOO_NEW_WIDGET

<style>
	mark {
		background: transparent;
		font-weight: bold;
		color: skyblue;
	}
    key{
		font-weight: bold;
        color: lightseagreen;
    }
    res {
        font-weight: bold;
        color: #070ff7;
    }
</style>
