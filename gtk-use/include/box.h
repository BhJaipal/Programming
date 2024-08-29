#ifndef ALOO_BOX_H
#define ALOO_BOX_H
#include "types.h"
#include <gtk/gtk.h>

GtkWidget *ALOO_BOX_WIDGET(alooWidget *x);
#define ALOO_BOX_TO_GTK_BOX(x) GTK_BOX(ALOO_BOX_WIDGET(x))

gboolean ALOO_IS_BOX(alooWidget *x);

alooWidget *new_alooBox(GtkOrientation orientation, int spacing);

/**
 * @brief Sets Box Orientation
 */
alooWidget *setBoxOrientation(alooWidget *box, GtkOrientation orientation);
/**
 * @brief Gets Box Orientation
 */
GtkOrientation getBoxOrientation(alooWidget *box);

// Adding and removing child
/**
 * @brief Appends `GtkWidget` child to box
 */
alooWidget *boxAppendGtk(alooWidget *box, GtkWidget *widget);
/**
 * @brief Prepends `GtkWidget` child to box
 */
alooWidget *boxPrependGtk(alooWidget *box, GtkWidget *widget);
/**
 * @brief Removes `GtkWidget` child from box
 */
alooWidget *boxRemoveGtk(alooWidget *box, GtkWidget *widget);

/**
 * @brief Appends `alooWidget` child to box
 */
alooWidget *boxAppend(alooWidget *box, alooWidget *widget);
/**
 * @brief Prepends `alooWidget` child to box
 */
alooWidget *boxPrepend(alooWidget *box, alooWidget *widget);
/**
 * @brief Removes `alooWidget` child from box
 */
alooWidget *boxRemove(alooWidget *box, alooWidget *widget);

/**
 * @brief Adds child after a certain widget of box
 * @return returns box
 */
alooWidget *boxInsertChildAfter(alooWidget *box, alooWidget *child,
								alooWidget *after);

// Box spacing
/**
 * @brief Set Box Spacing
 */
alooWidget *setBoxSpacing(alooWidget *box, int spacing);
/**
 * @brief Gets box spacing
 */
int getBoxSpacing(alooWidget *box);

// box homogeneous
/**
 * @brief Gets box homogeneous
 */
gboolean getBoxHomogeneous(alooWidget *box);
/**
 * @brief Sets box homogeneous
 */
alooWidget *setBoxHomogeneous(alooWidget *box, gboolean homogeneous);

// box baseline position
/**
 * @brief Gets Box baseline position
 */
GtkBaselinePosition getBoxBaselinePosition(alooWidget *box);
/**
 * @brief Sets Box baseline position
 */
alooWidget *setBoxBaselinePosition(alooWidget *box,
								   GtkBaselinePosition position);

#endif // ALOO_BOX_H