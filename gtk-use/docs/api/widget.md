# include/widget.h

SYNOPSIS:

-   `#include 'types.h'`
-   `#include <gtk/gtk.h>`

## Functions

### GTK_TO_ALOO

> Type: <key>alooWidget</key> \*
>
> <mark>Creates alooWidget from GtkWidget.</mark>
>
> Parameters:
>
> > <key>GtkWidget</key> \*widget

### OBJECT_TO_ALOO

> Type: <key>alooWidget</key> \*
>
> <mark>Create alooWidget from GObject.</mark>
>
> Parameters:
>
> > <key>GObject</key> \*obj

### OBJECT_TO_GTK_WIDGET

> Type: <key>GtkWidget</key> \*
>
> <mark>Creates GtkWidget from builder.</mark>
>
> Parameters:
>
> > <key>GtkBuilder</key> \*builder
> >
> > <res>const char</res> \*name

### alooWidgetFromBuilder

> Type: <key>alooWidget</key> \*
>
> <mark>Creates alooWidget from builder.</mark>
>
> Parameters:
>
> > <key>GtkBuilder</key> \*builder
> >
> > <res>const char</res> \*name

### alooSetOrientation

> Type: <key>alooWidget</key> \*
>
> <mark>Sets orientation of alooWidget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*widget
> >
> > <key>GtkOrientation</key> orien

### NewWidget

> Type: <key>alooWidget</key> \*
>
> <mark>Create a widget.</mark>
>
> Parameters:
>
> > <key>WidgetType</key> type
> >
> > <key>GtkWidget</key> \*child

### setWidgetName

> Type: <key>alooWidget</key> \*
>
> <mark>Set the Name of widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*widget
> >
> > <res>const char</res> \*name

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
