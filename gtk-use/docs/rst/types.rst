::: {#types_8h}
:::

[]{#types_8h label="types_8h"} #include $<$gtk/gtk.h$>$ Include
dependency graph for types.h: This graph shows which files directly or
indirectly include this file:

:::: DoxyCompactItemize
struct [alooWidget](#structalooWidget)

::: DoxyCompactList
*widget for my aloo library*
:::
::::

::: DoxyCompactItemize
#define
[ALOO_WIDGET_TO_GTK](#types_8h_a67f574a286eb62d2279853cb32e61d02)(x) x-$>$child
:::

:::: DoxyCompactItemize
typedef enum [WidgetType](#types_8h_a7b98518122eb2e94554d2b99d29d1452)
[WidgetType](#types_8h_a00a0e3c1177c07bd0a01d42dfc37ed86)

typedef struct [alooWidget](#structalooWidget)
[alooWidget](#types_8h_a740317088cd233e81015b298babff7be)

::: DoxyCompactList
*widget for my aloo library*
:::
::::

::: DoxyCompactItemize
enum [WidgetType](#types_8h_a7b98518122eb2e94554d2b99d29d1452) {
[ALOO_BOX](#types_8h_a7b98518122eb2e94554d2b99d29d1452a004cba47f0945b28929e400153b253eb)
,
[ALOO_GRID](#types_8h_a7b98518122eb2e94554d2b99d29d1452ad02eeb4ba7544b107bd085fa1eb480db)
,
[ALOO_ROW](#types_8h_a7b98518122eb2e94554d2b99d29d1452a3b0443429d57df8ac67888b5e0f1a363)
,
[ALOO_COLUMN](#types_8h_a7b98518122eb2e94554d2b99d29d1452a50f04c4702e68dab2bdac551b419ddeb)
,
[ALOO_BUTTON](#types_8h_a7b98518122eb2e94554d2b99d29d1452a00f836e2487ce6577a4d6aea17d76fcf)
,
[ALOO_LABEL](#types_8h_a7b98518122eb2e94554d2b99d29d1452a57d5914b4968e9bd7705c58fddbb868e)
,
[ALOO_NEW_WIDGET](#types_8h_a7b98518122eb2e94554d2b99d29d1452a6efdb808d59913a49baf1bed971ff1a0)
}
:::

[]{#types_8h_a67f574a286eb62d2279853cb32e61d02
label="types_8h_a67f574a286eb62d2279853cb32e61d02"}

#define ALOO_WIDGET_TO_GTK(

::: DoxyParamCaption
x
:::

) x-$>$child

[]{#types_8h_a740317088cd233e81015b298babff7be
label="types_8h_a740317088cd233e81015b298babff7be"} typedef struct
[alooWidget](#structalooWidget) [alooWidget](#structalooWidget)

widget for my aloo library

[]{#types_8h_a00a0e3c1177c07bd0a01d42dfc37ed86
label="types_8h_a00a0e3c1177c07bd0a01d42dfc37ed86"} typedef enum
[WidgetType](#types_8h_a7b98518122eb2e94554d2b99d29d1452)
[WidgetType](#types_8h_a7b98518122eb2e94554d2b99d29d1452)

[]{#types_8h_a7b98518122eb2e94554d2b99d29d1452
label="types_8h_a7b98518122eb2e94554d2b99d29d1452"} enum
[WidgetType](#types_8h_a7b98518122eb2e94554d2b99d29d1452)

::: DoxyEnumFields
Enumerator
\[0pt\]\[0pt\][]{#types_8h_a7b98518122eb2e94554d2b99d29d1452a004cba47f0945b28929e400153b253eb
label="types_8h_a7b98518122eb2e94554d2b99d29d1452a004cba47f0945b28929e400153b253eb"}
ALOO_BOX&Used for Gtk Box.\

\[0pt\]\[0pt\][]{#types_8h_a7b98518122eb2e94554d2b99d29d1452ad02eeb4ba7544b107bd085fa1eb480db
label="types_8h_a7b98518122eb2e94554d2b99d29d1452ad02eeb4ba7544b107bd085fa1eb480db"}
ALOO_GRID&Used for Gtk Grid.\

\[0pt\]\[0pt\][]{#types_8h_a7b98518122eb2e94554d2b99d29d1452a3b0443429d57df8ac67888b5e0f1a363
label="types_8h_a7b98518122eb2e94554d2b99d29d1452a3b0443429d57df8ac67888b5e0f1a363"}
ALOO_ROW&Used for Gtk Row.\

\[0pt\]\[0pt\][]{#types_8h_a7b98518122eb2e94554d2b99d29d1452a50f04c4702e68dab2bdac551b419ddeb
label="types_8h_a7b98518122eb2e94554d2b99d29d1452a50f04c4702e68dab2bdac551b419ddeb"}
ALOO_COLUMN&Used for Gtk Column.\

\[0pt\]\[0pt\][]{#types_8h_a7b98518122eb2e94554d2b99d29d1452a00f836e2487ce6577a4d6aea17d76fcf
label="types_8h_a7b98518122eb2e94554d2b99d29d1452a00f836e2487ce6577a4d6aea17d76fcf"}
ALOO_BUTTON&Used for Gtk Button.\

\[0pt\]\[0pt\][]{#types_8h_a7b98518122eb2e94554d2b99d29d1452a57d5914b4968e9bd7705c58fddbb868e
label="types_8h_a7b98518122eb2e94554d2b99d29d1452a57d5914b4968e9bd7705c58fddbb868e"}
ALOO_LABEL&Used for Gtk Label.\

\[0pt\]\[0pt\][]{#types_8h_a7b98518122eb2e94554d2b99d29d1452a6efdb808d59913a49baf1bed971ff1a0
label="types_8h_a7b98518122eb2e94554d2b99d29d1452a6efdb808d59913a49baf1bed971ff1a0"}
ALOO_NEW_WIDGET&Can be used to create new custom widget and used with
all.\
:::
