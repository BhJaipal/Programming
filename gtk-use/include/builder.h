/**
 * @file builder.h
 * @author Jaipal001
 * @brief This file contains UI Builder related functions
 */
#ifndef ALOO_BUILDER_H
#define ALOO_BUILDER_H
#include "types.h"

/******************** Private Funcs ********************/

/**
 * @brief Unrefs aloo builder
 */
void __unrefBuilder(AlooBuilder *data);

/**
 * @brief Create a Builder object
 * @return AlooBuilder*
 */
AlooBuilder *__createBuilder();

/**
 * @brief Adds a file with builder
 * @param build AlooBuilder object
 * @param filename UI file path with name
 * @param err Error handler, Default `NULL`
 */
int __builderAddFile(AlooBuilder *build, const char *filename, GError **err);

/**
 * @brief Adds a file with builder
 * @param build AlooBuilder object
 * @param content UI data
 * @param length UI data length
 * @param err Error handler, Default `NULL`
 */
int __builderAddContent(AlooBuilder *build, const char *content, gssize length,
						GError **err);

/**
 * @brief Adds a file with builder
 * @param build AlooBuilder object
 * @param resource_path UI resource path
 * @param err Error handler, Default `NULL`
 */
int __builderAddResource(AlooBuilder *build, const char *resource_path,
						 GError **err);

/**
 * @brief Gets GObject from builder
 */
GObject *__alooGetBuilderObject(AlooBuilder *builder, const char *name);

/**
 * @brief Creates alooWidget from builder
 */
alooWidget *__alooWidgetFromBuilder(AlooBuilder *builder, const char *name);

/******************** Private Types ********************/

struct _AlooBuilder {
	/// @brief Unrefs aloo builder
	void (*unref)(AlooBuilder *data);
	/// @brief Create a Builder object
	/// @return `AlooBuilder*`
	AlooBuilder *(*create)();
	/// @brief Adds a file with builder
	/// @param build AlooBuilder object
	/// @param filename UI file path with name
	/// @param err Error handler, Default `NULL` __builderAddFileType
	/// addFile;
	int (*addFile)(AlooBuilder *build, const char *filename, GError **err);
	/// @brief Adds a file with builder
	/// @param build AlooBuilder object
	/// @param content UI data
	/// @param length UI data length
	/// @param err Error handler, Default `NULL` __builderAddContentType
	/// addContent
	int (*addContent)(AlooBuilder *build, const char *content, gssize length,
					  GError **err);
	/// @brief Adds a file with builder
	/// @param build AlooBuilder object
	/// @param resource_path UI resource path
	/// @param err Error handler, Default `NULL`
	int (*addResource)(AlooBuilder *build, const char *resource_path,
					   GError **err);
	/// @brief Gets GObject from builder
	GObject *(*getBuilderObject)(AlooBuilder *builder, const char *name);
	/// @brief Creates alooWidget from builder
	alooWidget *(*alooFromBuilder)(AlooBuilder *builder, const char *name);
};

/******************** Public ********************/

/// @public
extern struct _AlooBuilder Builder;

#endif // ALOO_BUILDER_H