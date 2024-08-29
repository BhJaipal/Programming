# include/app.h

SYNOPSIS:

-   `#include 'types.h'`
-   `#include <gtk/gtk.h>`

## Classes

|                                     |                                         |
| ----------------------------------- | --------------------------------------- |
| <key>struct alooAppAndStatus </key> | Returns GtkApplication and status.      |
| <key>struct alooAppOptions </key>   | Takes GApplicationFlags, argc and argv. |

## Macros

|                                |                         |
| ------------------------------ | ----------------------- |
| <key> ALOO_IS_WINDOW(X) </key> | GTK_IS_WINDOW(X->child) |

## Functions

### CreateApp

> type: <key>struct alooAppAndStatus</key>
>
> <mark>Create a App object.</mark>
>
> Parameters:
>
> > <res>char</res> \*app_id
> >
> > <key>struct alooAppOptions</key> gAppOptions
> >
> > <res>void</res> activateFn(<key>GtkApplication</key> \*app, <key>gpointer</key> user\*data)

### alooHorizontalAlign

> type: <key>alooWidget</key> \*
>
> <mark>Sets horizontal alignment of alooWidget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*widget
> >
> > <key>GtkAlign</key> alignment

### alooVerticalAlign

> type: <key>alooWidget</key> \*
>
> <mark>Sets vertical alignment of alooWidget.</mark>
>
> Parameters:
>
> > <key>alooWidget </key>\*widget
> >
> > <key>GtkAlign</key> alignment

### alooAddEventListener

> Type: <key>alooWidget</key> \*
>
> <mark> Adds event listener to a widget.</mark>
>
> Paramters:
>
> > <key>alooWidget</key> \*widget_instance
> >
> > <res>char</res>\* event_name
> >
> > <key>GCallback </key>CallbackFn
> >
> > <key>gpointer</key> data

### alooSetWindowChild

> Type: <key>GtkWidget</key> \*
>
> <mark>Sets Window child.</mark>
>
> Parameters:
>
> > <key>GtkWidget</key> \*window
> >
> > <key>GtkWidget</key> child

### alooPresentWindow

> Type: <key>GtkWidget</key> \*
>
> <mark>Presents GtkWindow.</mark>
>
> Parameters:
>
> > <key>GtkWidget</key> \*window

### alooAddNewButtonLabel

> Type: <key>GtkWidget</key> \*
>
> <mark>Create new GtkButton.</mark>
>
> Parameters:
>
> > <res>const char</res> \*label

### alooApplicationNewWindow

> Type: <key>GtkWidget</key> \*
>
> <mark>Create a GtkWindow.</mark>
>
> Parameters:
>
> > <key>GtkApplication</key> \*app

### alooSetWindowTitle

> Type: <key>GtkWidget</key> \*
>
> <mark>Sets GtkWindow title.</mark>
>
> Parameters:
>
> > <key>GtkWidget</key> \*window
> >
> > <res>const char</res> title

### setWindowSize

> Type: <key>alooWidget</key> \*
>
> <mark>Sets aloo Window size.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> window
> >
> > <res>int</res> width
> >
> > <res>int</res> height

### alooGetBuilderObject

> Type: <key>GObject</key> \*
>
> <mark>Gets GObject from builder.</mark>
>
> Parameters:
>
> > <key>GtkBuilder</key> \*builder
> >
> > <res>const char</res> \*name

### setWindowApplication

> Type: <key>alooWidget</key> \*
>
> <mark>Set the Window for Application.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*window
> >
> > <key>GtkApplication</key> \*app

### showWindow

> Type: <res>void</res>
>
> <mark>Shows Window.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*window

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
