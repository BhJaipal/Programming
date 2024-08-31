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

typedef void (*__unrefBuilderType)(AlooBuilder *data);

typedef AlooBuilder *(*__createBuilderType)();

typedef int (*__builderAddFileType)(AlooBuilder *build, const char *filename,
									GError **err);

typedef int (*__builderAddContentType)(AlooBuilder *build, const char *content,
									   gssize length, GError **err);

typedef int (*__builderAddResourceType)(AlooBuilder *build,
										const char *resource_path,
										GError **err);

typedef GObject *(*__alooGetBuilderObjectType)(AlooBuilder *builder,
											   const char *name);

typedef alooWidget *(*__alooWidgetFromBuilderType)(AlooBuilder *builder,
												   const char *name);

/// @private
struct _AlooBuilder {
	/// @brief Unrefs aloo builder
	__unrefBuilderType unref;
	/// @brief Create a Builder object
	/// @return `AlooBuilder*`
	__createBuilderType create;
	/// @brief Adds a file with builder
	/// @param build AlooBuilder object
	/// @param filename UI file path with name
	/// @param err Error handler, Default `NULL` __builderAddFileType addFile;
	__builderAddFileType addFile;
	/// @brief Adds a file with builder
	/// @param build AlooBuilder object
	/// @param content UI data
	/// @param length UI data length
	/// @param err Error handler, Default `NULL` __builderAddContentType
	/// addContent
	__builderAddContentType addContent;
	/// @brief Adds a file with builder
	/// @param build AlooBuilder object
	/// @param resource_path UI resource path
	/// @param err Error handler, Default `NULL`
	__builderAddResourceType addResource;
	/// @brief Gets GObject from builder
	__alooGetBuilderObjectType getBuilderObject;
	/// @brief Creates alooWidget from builder
	__alooWidgetFromBuilderType alooFromBuilder;
};

/******************** Public ********************/

/// @public
extern struct _AlooBuilder Builder;

#endif // ALOO_BUILDER_H