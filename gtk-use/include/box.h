/**
 * @file box.h
 * @author Jaipal001 (@BhJaipal)
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

// box baseline position
/**
 * @brief Gets Box baseline position
 */
GtkBaselinePosition __getBoxBaselinePosition(alooWidget *box);
/**
 * @brief Sets Box baseline position
 */
alooWidget *__setBoxBaselinePosition(alooWidget *box,
									 GtkBaselinePosition position);

/******************** Private Types ********************/

typedef alooWidget *(*__new_alooBox_Type)(GtkOrientation orientation,
										  int spacing);
typedef alooWidget *(*__setBoxOrientation_Type)(alooWidget *box,
												GtkOrientation orientation);
typedef GtkOrientation (*__getBoxOrientation_Type)(alooWidget *box);
typedef alooWidget *(*__boxAppendGtk_Type)(alooWidget *box, GtkWidget *widget);
typedef alooWidget *(*__boxPrependGtk_Type)(alooWidget *box, GtkWidget *widget);
typedef alooWidget *(*__boxRemoveGtk_Type)(alooWidget *box, GtkWidget *widget);
typedef alooWidget *(*__boxAppend_Type)(alooWidget *box, alooWidget *widget);
typedef alooWidget *(*__boxPrepend_Type)(alooWidget *box, alooWidget *widget);
typedef alooWidget *(*__boxRemove_Type)(alooWidget *box, alooWidget *widget);
typedef alooWidget *(*__boxInsertChildAfter_Type)(alooWidget *box,
												  alooWidget *child,
												  alooWidget *after);
typedef alooWidget *(*__setBoxSpacing_Type)(alooWidget *box, int spacing);
typedef int (*__getBoxSpacing_Type)(alooWidget *box);
typedef gboolean (*__getBoxHomogeneous_Type)(alooWidget *box);
typedef alooWidget *(*__setBoxHomogeneous_Type)(alooWidget *box,
												gboolean homogeneous);

typedef GtkBaselinePosition (*__getBoxBaselinePosition_Type)(alooWidget *box);
typedef alooWidget *(*__setBoxBaselinePosition_Type)(
	alooWidget *box, GtkBaselinePosition position);

/******************** Public ********************/

struct _alooBox {
	__new_alooBox_Type new;
	__setBoxOrientation_Type setOrientation;
	__getBoxOrientation_Type getOrientation;
	__boxAppendGtk_Type appendGtk;
	__boxPrependGtk_Type prependGtk;
	__boxRemoveGtk_Type removeGtk;
	__boxAppend_Type append;
	__boxPrepend_Type prepend;
	__boxRemove_Type remove;
	__boxInsertChildAfter_Type insertChildAfter;
	__setBoxSpacing_Type setSpacing;
	__getBoxSpacing_Type getSpacing;
	__getBoxHomogeneous_Type getHomogeneous;
	__setBoxHomogeneous_Type setHomogeneous;
	__getBoxBaselinePosition_Type getBaselinePosition;
	__setBoxBaselinePosition_Type setBaselinePosition;
};

extern struct _alooBox Box;

#endif // ALOO_BOX_H