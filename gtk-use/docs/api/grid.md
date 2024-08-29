# include/grid.h

SYNOPSIS:

-   `#include 'types.h'`
-   `#include <gtk/gtk.h>`

## Macros

|                                |                    |                                 |
| ------------------------------ | ------------------ | ------------------------------- |
| <key>ALOO_GRID_TO_GTK(x)</key> | GTK_GRID(x->child) | Returns GTK_GRID of alooWidget. |

## Functions

### gridAttach

> Type: <key>alooWidget</key> \*
>
> <mark>Adds widget to aloo grid.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*grid
> >
> > <key>alooWidget</key> \*child
> >
> > <res>int</res> column
> >
> > <res>int</res> row
> >
> > <res>int</res> width
> >
> > <res>int</res> height

### gridAttachGtk

> Type: <key>alooWidget</key> \*
>
> <mark>Adds widget to aloo grid.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*grid
> >
> > <key>GtkWidget</key> \*child
> >
> > <res>int</res> column
> >
> > <res>int</res> row
> >
> > <res>int</res> width
> >
> > <res>int</res> height

### gridRemove

> Type: <key>alooWidget</key> \*
>
> <mark>Removes child from grid.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*grid
> >
> > <key>alooWidget</key> \*child

### gridRemoveGtk

> Type: <key>alooWidget</key> \*
>
> <mark>Removes child from grid.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*grid
> >
> > <key>GtkWidget</key> \*child

### alooGridNew

> Type: <key>alooWidget</key> \*
>
> <mark>Creates new Aloo Grid Widget.</mark>
>
> No Parameters

### setGridColumnSpacing

> Type: <key>alooWidget</key> \*
>
> <mark>Set the Grid Column Spacing.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*grid
> >
> > <res>int</res> space

### setGridRowSpacing

> Type: <key>alooWidget</key> \*
>
> <mark>Set the Grid Row Spacing.</mark>
>
> Parameters
>
> > <key>alooWidget</key> \*grid
> >
> > <res>int</res> space

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
