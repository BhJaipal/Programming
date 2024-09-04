#include "common/builder.h"
#include "common/macros.h"
#include "common/widget.h"

void __unrefBuilder(AlooBuilder *data) { g_object_unref(data->builder); }

AlooBuilder *__createBuilder() {
	AlooBuilder *out = malloc(sizeof(AlooBuilder));
	out->builder = gtk_builder_new();
	return out;
}

int __builderAddFile(AlooBuilder *build, const char *filename, GError **err) {
	return gtk_builder_add_from_file(build->builder, filename, err);
}
int __builderAddContent(AlooBuilder *build, const char *content, gssize length,
						GError **err) {
	return gtk_builder_add_from_string(build->builder, content, length, err);
}
int __builderAddResource(AlooBuilder *build, const char *resource_path,
						 GError **err) {
	return gtk_builder_add_from_resource(build->builder, resource_path, err);
}

GObject *__alooGetBuilderObject(AlooBuilder *builder, const char *name) {
	return gtk_builder_get_object(builder->builder, name);
}

alooWidget *__alooWidgetFromBuilder(AlooBuilder *builder, const char *name) {
	return Widget.obj_to_aloo(gtk_builder_get_object(builder->builder, name));
}

struct _AlooBuilder Builder = {
	__unrefBuilder,			 __createBuilder,	   __builderAddFile,
	__builderAddContent,	 __builderAddResource, __alooGetBuilderObject,
	__alooWidgetFromBuilder,
};

/******************** Private ********************/
