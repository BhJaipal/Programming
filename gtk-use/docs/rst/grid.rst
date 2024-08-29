::: {#grid_8h}
:::

[]{#grid_8h label="grid_8h"} #include '̈types.h'̈ #include $<$gtk/gtk.h$>$
Include dependency graph for grid.h: This graph shows which files
directly or indirectly include this file:

:::: DoxyCompactItemize
#define
[ALOO_GRID_TO_GTK](#grid_8h_abf08dd722dd5d05a2513522a8c1d9800)(x) GTK_GRID(x-$>$child)

::: DoxyCompactList
*Returns GTK_GRID of [alooWidget](#structalooWidget).*
:::
::::

:::::::::: DoxyCompactItemize
[alooWidget](#structalooWidget) $\ast$
[gridAttach](#grid_8h_a63d120e21e61dd6c60b73817c05a0a65)
([alooWidget](#structalooWidget) $\ast$grid,
[alooWidget](#structalooWidget) $\ast$child, int column, int row, int
width, int height)

::: DoxyCompactList
*Adds widget to aloo grid.*
:::

[alooWidget](#structalooWidget) $\ast$
[gridAttachGtk](#grid_8h_af73f05491a5e1ff7c5ba7c8a425cb04c)
([alooWidget](#structalooWidget) $\ast$grid, GtkWidget $\ast$child, int
column, int row, int width, int height)

::: DoxyCompactList
*Adds widget to aloo grid.*
:::

[alooWidget](#structalooWidget) $\ast$
[gridRemove](#grid_8h_a7a87945698bb503625c7926ab6717187)
([alooWidget](#structalooWidget) $\ast$grid,
[alooWidget](#structalooWidget) $\ast$child)

::: DoxyCompactList
*Removes child from grid.*
:::

[alooWidget](#structalooWidget) $\ast$
[gridRemoveGtk](#grid_8h_a6d34934989b423f380da0b3eac2a2bfb)
([alooWidget](#structalooWidget) $\ast$grid, GtkWidget $\ast$child)

::: DoxyCompactList
*Removes child from grid.*
:::

[alooWidget](#structalooWidget) $\ast$
[alooGridNew](#grid_8h_a48e1d5f03b179b82ebe0e7dc3eec17da) ()

::: DoxyCompactList
*Creates new Aloo Grid Widget.*
:::

[alooWidget](#structalooWidget) $\ast$
[setGridColumnSpacing](#grid_8h_a186013459d8639377da1abf0dc370f5b)
([alooWidget](#structalooWidget) $\ast$grid, int space)

::: DoxyCompactList
*Set the Grid Column Spacing.*
:::

[alooWidget](#structalooWidget) $\ast$
[setGridRowSpacing](#grid_8h_a7b4a1902ba701ecd6406795da6b9314c)
([alooWidget](#structalooWidget) $\ast$grid, int space)

::: DoxyCompactList
*Set the Grid Row Spacing.*
:::
::::::::::

[]{#grid_8h_abf08dd722dd5d05a2513522a8c1d9800
label="grid_8h_abf08dd722dd5d05a2513522a8c1d9800"}

#define ALOO_GRID_TO_GTK(

::: DoxyParamCaption
x
:::

) GTK_GRID(x-$>$child)

Returns GTK_GRID of [alooWidget](#structalooWidget).

::: DoxyParams
Parameters *x* & [alooWidget](#structalooWidget) with ALOO_GRID type\
:::

[]{#grid_8h_a48e1d5f03b179b82ebe0e7dc3eec17da
label="grid_8h_a48e1d5f03b179b82ebe0e7dc3eec17da"}

[alooWidget](#structalooWidget)$\ast$ alooGridNew (

::: DoxyParamCaption
:::

)

Creates new Aloo Grid Widget.

::: DoxyReturn
Returns returns grid
:::

[]{#grid_8h_a63d120e21e61dd6c60b73817c05a0a65
label="grid_8h_a63d120e21e61dd6c60b73817c05a0a65"}

[alooWidget](#structalooWidget)$\ast$ gridAttach (

::: DoxyParamCaption
grid,

child,

column,

row,

width,

height
:::

)

Adds widget to aloo grid.

::: DoxyParams
Parameters *grid* & grid in which child should be added\
*child* & child to be added\
*column* & column in which it should be added\
*row* & row in which it should be added\
*width* & column span of widget or how many column it takes\
*height* & row span of widget or how many row it takes\
:::

::: DoxyReturn
Returns returns grid back
:::

[]{#grid_8h_af73f05491a5e1ff7c5ba7c8a425cb04c
label="grid_8h_af73f05491a5e1ff7c5ba7c8a425cb04c"}

[alooWidget](#structalooWidget)$\ast$ gridAttachGtk (

::: DoxyParamCaption
grid,

child,

column,

row,

width,

height
:::

)

Adds widget to aloo grid.

::: DoxyParams
Parameters *grid* & grid in which child should be added\
*child* & child to be added\
*column* & column in which it should be added\
*row* & row in which it should be added\
*width* & column span of widget or how many column it takes\
*height* & row span of widget or how many row it takes\
:::

::: DoxyReturn
Returns returns grid back
:::

[]{#grid_8h_a7a87945698bb503625c7926ab6717187
label="grid_8h_a7a87945698bb503625c7926ab6717187"}

[alooWidget](#structalooWidget)$\ast$ gridRemove (

::: DoxyParamCaption
grid,

child
:::

)

Removes child from grid.

::: DoxyReturn
Returns returns grid back
:::

[]{#grid_8h_a6d34934989b423f380da0b3eac2a2bfb
label="grid_8h_a6d34934989b423f380da0b3eac2a2bfb"}

[alooWidget](#structalooWidget)$\ast$ gridRemoveGtk (

::: DoxyParamCaption
grid,

child
:::

)

Removes child from grid.

::: DoxyReturn
Returns returns grid back
:::

[]{#grid_8h_a186013459d8639377da1abf0dc370f5b
label="grid_8h_a186013459d8639377da1abf0dc370f5b"}

[alooWidget](#structalooWidget)$\ast$ setGridColumnSpacing (

::: DoxyParamCaption
grid,

space
:::

)

Set the Grid Column Spacing.

[]{#grid_8h_a7b4a1902ba701ecd6406795da6b9314c
label="grid_8h_a7b4a1902ba701ecd6406795da6b9314c"}

[alooWidget](#structalooWidget)$\ast$ setGridRowSpacing (

::: DoxyParamCaption
grid,

space
:::

)

Set the Grid Row Spacing.
