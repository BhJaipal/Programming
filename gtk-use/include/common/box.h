/**
 * @file box.h
 * @author Jaipal001
 * @brief Aloo Box functions
 */
#ifndef ALOO_BOX_H
#define ALOO_BOX_H
#include "types.h"
#include <gtk/gtk.h>

/******************** Private Funcs ********************/

/**
 * @brief Creates new aloo box
 * @param orientation Box orientation
 * @param spacing space in child
 */
alooWidget *__new_alooBox(GtkOrientation orientation, int spacing);
/**
 * @brief Sets Box Orientation
 */
alooWidget *__setBoxOrientation(alooWidget *box, GtkOrientation orientation);
/**
 * @brief Gets Box Orientation
 */
GtkOrientation __getBoxOrientation(alooWidget *box);
/**
 * @brief Appends `GtkWidget` child to box
 */
alooWidget *__boxAppendGtk(alooWidget *box, GtkWidget *widget);
/**
 * @brief Prepends `GtkWidget` child to box
 */
alooWidget *__boxPrependGtk(alooWidget *box, GtkWidget *widget);
/**
 * @brief Removes `GtkWidget` child from box
 */
alooWidget *__boxRemoveGtk(alooWidget *box, GtkWidget *widget);
/**
 * @brief Appends `alooWidget` child to box
 */
alooWidget *__boxAppend(alooWidget *box, alooWidget *widget);
/**
 * @brief Prepends `alooWidget` child to box
 */
alooWidget *__boxPrepend(alooWidget *box, alooWidget *widget);
/**
 * @brief Removes `alooWidget` child from box
 */
alooWidget *__boxRemove(alooWidget *box, alooWidget *widget);
/**
 * @brief Adds child after a certain widget of box
 * @return returns box
 */
alooWidget *__boxInsertChildAfter(alooWidget *box, alooWidget *child,
								  alooWidget *after);
/**
 * @brief Set Box Spacing
 */
alooWidget *__setBoxSpacing(alooWidget *box, int spacing);
/**
 * @brief Gets box spacing
 */
int __getBoxSpacing(alooWidget *box);
/**
 * @brief Gets box homogeneous
 */
gboolean __getBoxHomogeneous(alooWidget *box);
/**
 * @brief Sets box homogeneous
 */
alooWidget *__setBoxHomogeneous(alooWidget *box, gboolean homogeneous);

/**
 * @brief Gets Box baseline position
 */
GtkBaselinePosition __getBoxBaselinePosition(alooWidget *box);
/**
 * @brief Sets Box baseline position
 */
alooWidget *__setBoxBaselinePosition(alooWidget *box,
									 GtkBaselinePosition position);
/**
 * @brief Returns Gtk Box
 */
GtkBox *__toGtk(alooWidget *widget);

/******************** Private Types ********************/

struct _alooBox {
	alooWidget *(*new)(GtkOrientation orientation, int spacing);
	alooWidget *(*setOrientation)(alooWidget *box, GtkOrientation orientation);
	/// @brief Gets Box Orientation
	GtkOrientation (*getOrientation)(alooWidget *box);
	/// @brief Appends `GtkWidget` child to box
	alooWidget *(*appendGtk)(alooWidget *box, GtkWidget *widget);
	/// @brief Prepends `GtkWidget` child to box
	alooWidget *(*prependGtk)(alooWidget *box, GtkWidget *widget);
	/// @brief Removes `GtkWidget` child from box
	alooWidget *(*removeGtk)(alooWidget *box, GtkWidget *widget);
	/// @brief Appends `alooWidget` child to box
	alooWidget *(*append)(alooWidget *box, alooWidget *widget);
	/// @brief Prepends `alooWidget` child to box
	alooWidget *(*prepend)(alooWidget *box, alooWidget *widget);
	/// @brief Removes `alooWidget` child from box
	alooWidget *(*remove)(alooWidget *box, alooWidget *widget);
	/**
	 * @brief Adds child after a certain widget of box
	 * @return returns box
	 */
	alooWidget *(*insertChildAfter)(alooWidget *box, alooWidget *child,
									alooWidget *after);
	/// @brief Sets Box Spacing
	alooWidget *(*setSpacing)(alooWidget *box, int spacing);
	/// @brief Gets Box Spacing
	int (*getSpacing)(alooWidget *box);
	/// @brief Gets box homogeneous
	gboolean (*getHomogeneous)(alooWidget *box);
	/// @brief Sets box homogeneous
	alooWidget *(*setHomogeneous)(alooWidget *box, gboolean homogeneous);
	/// @brief Gets Box baseline position
	GtkBaselinePosition (*getBaselinePosition)(alooWidget *box);
	/// @brief Sets Box baseline position
	alooWidget *(*setBaselinePosition)(alooWidget *box,
									   GtkBaselinePosition position);
	/// @brief Returns Gtk Box
	GtkBox *(*toGtk)(alooWidget *widget);
};

/******************** Public ********************/

extern struct _alooBox Box;

#endif // ALOO_BOX_H