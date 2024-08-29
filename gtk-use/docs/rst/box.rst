::: {#box_8h}
:::

[]{#box_8h label="box_8h"} #include '̈types.h'̈ #include $<$gtk/gtk.h$>$
Include dependency graph for box.h: This graph shows which files
directly or indirectly include this file:

::: DoxyCompactItemize
#define
[ALOO_BOX_TO_GTK_BOX](#box_8h_a49c4948751bb9e2dd96cfa505b4b568c)(x) GTK_BOX([ALOO_BOX_WIDGET](#box_8h_a4a34a65a129d5c53b914ac34c3057d12)(x))
:::

:::::::::::::::::: DoxyCompactItemize
GtkWidget $\ast$
[ALOO_BOX_WIDGET](#box_8h_a4a34a65a129d5c53b914ac34c3057d12)
([alooWidget](#structalooWidget) $\ast$x)

gboolean [ALOO_IS_BOX](#box_8h_a8a6129175fffef1805056b1ab25526ab)
([alooWidget](#structalooWidget) $\ast$x)

[alooWidget](#structalooWidget) $\ast$
[new_alooBox](#box_8h_ade9c3d0a5b82172f2a2041811d9ae201) (GtkOrientation
orientation, int spacing)

[alooWidget](#structalooWidget) $\ast$
[setBoxOrientation](#box_8h_a68f215aee06f176862750ee188c554b7)
([alooWidget](#structalooWidget) $\ast$box, GtkOrientation orientation)

::: DoxyCompactList
*Sets Box Orientation.*
:::

GtkOrientation
[getBoxOrientation](#box_8h_afff8456a34365d3bef35e87790387761)
([alooWidget](#structalooWidget) $\ast$box)

::: DoxyCompactList
*Gets Box Orientation.*
:::

[alooWidget](#structalooWidget) $\ast$
[boxAppendGtk](#box_8h_a31523d1f2b3ffe3d96838b6bf73cf480)
([alooWidget](#structalooWidget) $\ast$box, GtkWidget $\ast$widget)

::: DoxyCompactList
*Appends GtkWidget child to box.*
:::

[alooWidget](#structalooWidget) $\ast$
[boxPrependGtk](#box_8h_aa110e6957ddf389f0c6633dda8fa3ce9)
([alooWidget](#structalooWidget) $\ast$box, GtkWidget $\ast$widget)

::: DoxyCompactList
*Prepends GtkWidget child to box.*
:::

[alooWidget](#structalooWidget) $\ast$
[boxRemoveGtk](#box_8h_a211967d647e887244da40a34376f0260)
([alooWidget](#structalooWidget) $\ast$box, GtkWidget $\ast$widget)

::: DoxyCompactList
*Removes GtkWidget child from box.*
:::

[alooWidget](#structalooWidget) $\ast$
[boxAppend](#box_8h_a2a788bd1fc20caa041d1cf6e3ce66b9b)
([alooWidget](#structalooWidget) $\ast$box,
[alooWidget](#structalooWidget) $\ast$widget)

::: DoxyCompactList
*Appends [alooWidget](#structalooWidget) child to box.*
:::

[alooWidget](#structalooWidget) $\ast$
[boxPrepend](#box_8h_acb90d5cfd95509ab12d7d03f27587a40)
([alooWidget](#structalooWidget) $\ast$box,
[alooWidget](#structalooWidget) $\ast$widget)

::: DoxyCompactList
*Prepends [alooWidget](#structalooWidget) child to box.*
:::

[alooWidget](#structalooWidget) $\ast$
[boxRemove](#box_8h_a269fe19de804eca2b0b62a39a7627084)
([alooWidget](#structalooWidget) $\ast$box,
[alooWidget](#structalooWidget) $\ast$widget)

::: DoxyCompactList
*Removes [alooWidget](#structalooWidget) child from box.*
:::

[alooWidget](#structalooWidget) $\ast$
[boxInsertChildAfter](#box_8h_a99fa2f7a6368ebf9b125d538c32e2511)
([alooWidget](#structalooWidget) $\ast$box,
[alooWidget](#structalooWidget) $\ast$child,
[alooWidget](#structalooWidget) $\ast$after)

::: DoxyCompactList
*Adds child after a certain widget of box.*
:::

[alooWidget](#structalooWidget) $\ast$
[setBoxSpacing](#box_8h_aa95cc7daa607b085429fe669696c8b95)
([alooWidget](#structalooWidget) $\ast$box, int spacing)

::: DoxyCompactList
*Set Box Spacing.*
:::

int [getBoxSpacing](#box_8h_aafb8d1d96e235cd0aa0fc5efbab2b435)
([alooWidget](#structalooWidget) $\ast$box)

::: DoxyCompactList
*Gets box spacing.*
:::

gboolean [getBoxHomogeneous](#box_8h_a5b03d8c43b572937353a35fd14706a64)
([alooWidget](#structalooWidget) $\ast$box)

::: DoxyCompactList
*Gets box homogeneous.*
:::

[alooWidget](#structalooWidget) $\ast$
[setBoxHomogeneous](#box_8h_a53dafacfaf24fb36d402158bb1957f09)
([alooWidget](#structalooWidget) $\ast$box, gboolean homogeneous)

::: DoxyCompactList
*Sets box homogeneous.*
:::

GtkBaselinePosition
[getBoxBaselinePosition](#box_8h_ae19afcb9a216631276a7946619de890f)
([alooWidget](#structalooWidget) $\ast$box)

::: DoxyCompactList
*Gets Box baseline position.*
:::

[alooWidget](#structalooWidget) $\ast$
[setBoxBaselinePosition](#box_8h_a7ca1f19ef934de0c3d9392f1c9d9a3f5)
([alooWidget](#structalooWidget) $\ast$box, GtkBaselinePosition
position)

::: DoxyCompactList
*Sets Box baseline position.*
:::
::::::::::::::::::

[]{#box_8h_a49c4948751bb9e2dd96cfa505b4b568c
label="box_8h_a49c4948751bb9e2dd96cfa505b4b568c"}

#define ALOO_BOX_TO_GTK_BOX(

::: DoxyParamCaption
x
:::

) GTK_BOX([ALOO_BOX_WIDGET](#box_8h_a4a34a65a129d5c53b914ac34c3057d12)(x))

[]{#box_8h_a4a34a65a129d5c53b914ac34c3057d12
label="box_8h_a4a34a65a129d5c53b914ac34c3057d12"}

GtkWidget$\ast$ ALOO_BOX_WIDGET (

::: DoxyParamCaption
x
:::

)

[]{#box_8h_a8a6129175fffef1805056b1ab25526ab
label="box_8h_a8a6129175fffef1805056b1ab25526ab"}

gboolean ALOO_IS_BOX (

::: DoxyParamCaption
x
:::

)

[]{#box_8h_a2a788bd1fc20caa041d1cf6e3ce66b9b
label="box_8h_a2a788bd1fc20caa041d1cf6e3ce66b9b"}

[alooWidget](#structalooWidget)$\ast$ boxAppend (

::: DoxyParamCaption
box,

widget
:::

)

Appends [alooWidget](#structalooWidget) child to box.

[]{#box_8h_a31523d1f2b3ffe3d96838b6bf73cf480
label="box_8h_a31523d1f2b3ffe3d96838b6bf73cf480"}

[alooWidget](#structalooWidget)$\ast$ boxAppendGtk (

::: DoxyParamCaption
box,

widget
:::

)

Appends GtkWidget child to box.

[]{#box_8h_a99fa2f7a6368ebf9b125d538c32e2511
label="box_8h_a99fa2f7a6368ebf9b125d538c32e2511"}

[alooWidget](#structalooWidget)$\ast$ boxInsertChildAfter (

::: DoxyParamCaption
box,

child,

after
:::

)

Adds child after a certain widget of box.

::: DoxyReturn
Returns returns box
:::

[]{#box_8h_acb90d5cfd95509ab12d7d03f27587a40
label="box_8h_acb90d5cfd95509ab12d7d03f27587a40"}

[alooWidget](#structalooWidget)$\ast$ boxPrepend (

::: DoxyParamCaption
box,

widget
:::

)

Prepends [alooWidget](#structalooWidget) child to box.

[]{#box_8h_aa110e6957ddf389f0c6633dda8fa3ce9
label="box_8h_aa110e6957ddf389f0c6633dda8fa3ce9"}

[alooWidget](#structalooWidget)$\ast$ boxPrependGtk (

::: DoxyParamCaption
box,

widget
:::

)

Prepends GtkWidget child to box.

[]{#box_8h_a269fe19de804eca2b0b62a39a7627084
label="box_8h_a269fe19de804eca2b0b62a39a7627084"}

[alooWidget](#structalooWidget)$\ast$ boxRemove (

::: DoxyParamCaption
box,

widget
:::

)

Removes [alooWidget](#structalooWidget) child from box.

[]{#box_8h_a211967d647e887244da40a34376f0260
label="box_8h_a211967d647e887244da40a34376f0260"}

[alooWidget](#structalooWidget)$\ast$ boxRemoveGtk (

::: DoxyParamCaption
box,

widget
:::

)

Removes GtkWidget child from box.

[]{#box_8h_ae19afcb9a216631276a7946619de890f
label="box_8h_ae19afcb9a216631276a7946619de890f"}

GtkBaselinePosition getBoxBaselinePosition (

::: DoxyParamCaption
box
:::

)

Gets Box baseline position.

[]{#box_8h_a5b03d8c43b572937353a35fd14706a64
label="box_8h_a5b03d8c43b572937353a35fd14706a64"}

gboolean getBoxHomogeneous (

::: DoxyParamCaption
box
:::

)

Gets box homogeneous.

[]{#box_8h_afff8456a34365d3bef35e87790387761
label="box_8h_afff8456a34365d3bef35e87790387761"}

GtkOrientation getBoxOrientation (

::: DoxyParamCaption
box
:::

)

Gets Box Orientation.

[]{#box_8h_aafb8d1d96e235cd0aa0fc5efbab2b435
label="box_8h_aafb8d1d96e235cd0aa0fc5efbab2b435"}

int getBoxSpacing (

::: DoxyParamCaption
box
:::

)

Gets box spacing.

[]{#box_8h_ade9c3d0a5b82172f2a2041811d9ae201
label="box_8h_ade9c3d0a5b82172f2a2041811d9ae201"}

[alooWidget](#structalooWidget)$\ast$ new_alooBox (

::: DoxyParamCaption
orientation,

spacing
:::

)

[]{#box_8h_a7ca1f19ef934de0c3d9392f1c9d9a3f5
label="box_8h_a7ca1f19ef934de0c3d9392f1c9d9a3f5"}

[alooWidget](#structalooWidget)$\ast$ setBoxBaselinePosition (

::: DoxyParamCaption
box,

position
:::

)

Sets Box baseline position.

[]{#box_8h_a53dafacfaf24fb36d402158bb1957f09
label="box_8h_a53dafacfaf24fb36d402158bb1957f09"}

[alooWidget](#structalooWidget)$\ast$ setBoxHomogeneous (

::: DoxyParamCaption
box,

homogeneous
:::

)

Sets box homogeneous.

[]{#box_8h_a68f215aee06f176862750ee188c554b7
label="box_8h_a68f215aee06f176862750ee188c554b7"}

[alooWidget](#structalooWidget)$\ast$ setBoxOrientation (

::: DoxyParamCaption
box,

orientation
:::

)

Sets Box Orientation.

[]{#box_8h_aa95cc7daa607b085429fe669696c8b95
label="box_8h_aa95cc7daa607b085429fe669696c8b95"}

[alooWidget](#structalooWidget)$\ast$ setBoxSpacing (

::: DoxyParamCaption
box,

spacing
:::

)

Set Box Spacing.
