# include/style.h

SYNOPSIS:

-   `#include 'types.h'`

## Functions

### setWidth

> Type: <key>alooWidget \*</key>
>
> <mark>Set the Width of widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*wid
> >
> > <res>int</res> width

### setHeight

> Type: <key>alooWidget \*</key>
>
> <mark>Set the Height of widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*wid
> >
> > <res>int</res> height

### setSize

> Type: <key>alooWidget \*</key>
>
> <mark>Set the Width and Height of widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*wid
> >
> > <res>int</res> width
> >
> > <res>int</res> height

### widgetAddClass

> Type: <key>alooWidget \*</key>
>
> <mark>Adds class to widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*widget
> >
> > <res>char</res> \*class

### widgetRemoveClass

> Type: <key>alooWidget \*</key>
>
> <mark>Removes class from widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*widget
> >
> > <res>char</res> \*class

### getWidgetClasses

> Type: <res>char \*\*</res>
>
> <mark>Gets \classes of widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*widget

### setWidgetClasses

> Type: <key>alooWidget \*</key>
>
> <mark>Sets classes of widget.</mark>
>
> Parameters:
>
> > <key>alooWidget</key> \*widget
> >
> > <res>char</res> \*\*classes

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
