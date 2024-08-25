#include "types.h"
#include <gtk/gtk.h>

GtkWidget **ALOO_BOX_WIDGET(alooWidget *x) { return x->child; }
#define ALOO_BOX_TO_GTK(x) GTK_BOX(ALOO_BOX_WIDGET(x))

gboolean ALOO_IS_BOX(alooWidget *x) {
	return x->type == ALOO_BOX || ALOO_NEW_WIDGET && GTK_IS_BOX(x->child);
}

alooWidget *new_alooBox(GtkOrientation orientation, int spacing);

alooWidget *setBoxOrientation(alooWidget *box, GtkOrientation orientation);
GtkOrientation getBoxOrientation(alooWidget *box);

alooWidget *boxAppend(alooWidget *box, GtkWidget *widget);
alooWidget *boxPrepend(alooWidget *box, GtkWidget *widget);
alooWidget *boxRemove(alooWidget *box, GtkWidget *widget);

alooWidget *setBoxSpacing(alooWidget *box, int spacing);
int getBoxSpacing(alooWidget *box);

gboolean getBoxHomogeneous(alooWidget *box);
alooWidget *setBoxHomogeneous(alooWidget *box, gboolean homogeneous);

GtkBaselinePosition getBoxBaselinePosition(alooWidget *box);
alooWidget *setBoxBaselinePosition(alooWidget *box,
								   GtkBaselinePosition position);

alooWidget *boxInsertChildAfter(alooWidget *box, alooWidget *child,
								alooWidget *after);