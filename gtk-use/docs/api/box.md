# include/box.h

SYNOPSIS:

-   `#include 'types.h'`
-   `#include <gtk/gtk.h>`

## Macros

|                                    |                             |
| ---------------------------------- | --------------------------- |
| <key> ALOO_BOX_TO_GTK_BOX(x)</key> | GTK_BOX(ALOO_BOX_WIDGET(x)) |

## Functions

### ALOO_BOX_WIDGET

> Type: <key>GtkWidget</key> \*
>
> Parameters:
>
> > <key>alooWidget</key> \*x

### ALOO_IS_BOX

> Type: <key>gboolean</key>
>
> Parameters:
>
> > <key>alooWidget</key> \*x

### newAlooBox

> Type: <key>alooWidget</key> \*
>
> Parameters:
>
> > <key>GtkOrientation</key> orientation
> >
> > <res>int</res> spacing

### setBoxOrientation

> Type: <key>alooWidget</key> \*
>
> <mark>Sets Box Orientation.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>GtkOrientation</key> orientation

### getBoxOrientation

> Type: <key>GtkOrientation</key>
>
> <mark>Gets Box Orientation.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box

### boxAppendGtk

> Type: <key>alooWidget</key> \*
>
> <mark>Appends GtkWidget child to box.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>GtkWidget</key> \*widget

### boxPrependGtk

> Type: <key>alooWidget</key> \*
>
> <mark>Prepends GtkWidget child to box.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>GtkWidget</key> \*widget

### boxRemoveGtk

> Type: <key>alooWidget</key> \*
>
> <mark>Removes GtkWidget child from box.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>GtkWidget</key> \*widget

### boxAppend

> Type: <key>alooWidget</key> \*
>
> <mark>Appends alooWidget child to box.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>alooWidget</key> \*widget

### boxPrepend

> Type: <key>alooWidget</key> \*
>
> <mark>Prepends alooWidget child to box.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>alooWidget</key> \*widget

### boxRemove

> Type: <key>alooWidget</key> \*
>
> <mark>Removes alooWidget child from box.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>alooWidget</key> \*widget

### boxInsertChildAfter

> Type: <key>alooWidget</key> \*
>
> <mark>Adds child after a certain widget of box.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>alooWidget</key> \*child
> >
> > <key>alooWidget</key> \*after

### setBoxSpacing

> Type: <key>alooWidget</key> \*
>
> <mark>Set Box Spacing.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <res>int</res> spacing

### getBoxSpacing

> Type: <res>int</res>
>
> <mark>Gets box spacing.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box

### getBoxHomogeneous

> Type: <key>gboolean</key>
>
> <mark>Gets box homogeneous.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box

### setBoxHomogeneous

> Type: <key>alooWidget</key> \*
>
> <mark>Sets box homogeneous.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>gboolean</key> homogeneous

### getBoxBaselinePosition

> Type: <key>GtkBaselinePosition</key>
>
> <mark> Gets Box baseline position.</amrk>
>
> Parameters:
>
> > <key>alooWidget</key> \*box

### setBoxBaselinePosition

> Type: <key>alooWidget</key> \*
>
> <mark> Sets Box baseline position.</amrk>
>
> Parameters:
>
> > <key>alooWidget</key> \*box
> >
> > <key>GtkBaselinePosition</key> position

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
