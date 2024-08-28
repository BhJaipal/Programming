#ifndef ALOO_WIDGET_H
#define ALOO_WIDGET_H
#include "types.h"
#include <gtk/gtk.h>

alooWidget *GTK_TO_ALOO(GtkWidget *widget);

alooWidget *OBJECT_TO_ALOO(GObject *obj);

GtkWidget *OBJECT_TO_GTK_WIDGET(GtkBuilder *builder, const char *name);

alooWidget *alooWidgetFromBuilder(GtkBuilder *builder, const char *name);

alooWidget *alooSetOrientation(alooWidget *widget, GtkOrientation orien);

#endif // ALOO_WIDGET_H