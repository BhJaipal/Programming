# include/button.h

SYNOPSIS:

-   `#include 'types.h'`

## Macros

|                                  |                      |
| -------------------------------- | -------------------- |
| <mark> ALOO_BTN_TO_GTK(x)</mark> | GTK_BUTTON(x->child) |

## Function

### newButton

> Type: <key>alooWidget\*</key>
>
> <mark>Creates an aloo button</mark>
>
> No Parameters

### newButtonWithLabel

> Type: <key>alooWidget\*</key>
>
> <mark>Creates an aloo button with a label</mark>
>
> Parameters:
>
> > <res>const char</res> \* label

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
