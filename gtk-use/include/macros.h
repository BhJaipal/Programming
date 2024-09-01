/**
 * @file macros.h
 * @author Jaipal001
 * @brief Aloo Project Macros related functions
 */
#ifndef ALOO_MACROS_H
#define ALOO_MACROS_H
#include "types.h"

/**
 * @brief Returns GTK_GRID of alooWidget
 * @param x alooWidget with ALOO_GRID type
 */
#define ALOO_GRID_TO_GTK(x) GTK_GRID(x->child)
GtkWidget *ALOO_BOX_WIDGET(alooWidget *x);
#define ALOO_BOX_TO_GTK_BOX(x) GTK_BOX(ALOO_BOX_WIDGET(x))
gboolean ALOO_IS_BOX(alooWidget *x);

/**
 * @brief generates app options with APP_FLAGS_NONE
 */
#define NONE_FLAGS_OPTIONS(argc, argv)                                         \
	{ APP_FLAGS_NONE, argc, argv }
/**
 * @brief generates app options with APP_FLAGS_IS_LAUNCHER
 */
#define LAUNCHER_FLAGS_OPTIONS(argc, argv)                                     \
	{ APP_FLAGS_IS_LAUNCHER, argc, argv }
/**
 * @brief generates app options with APP_FLAGS_IS_SERVICE
 */
#define SERVICE_FLAGS_OPTIONS(argc, argv)                                      \
	{ APP_FLAGS_IS_SERVICE, argc, argv }

#endif // ALOO_MACROS_H