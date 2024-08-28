#include "../include/style.h"

alooWidget *setWidth(alooWidget *wid, int width) {
	gtk_widget_set_size_request(wid->child, width, -1);
	return wid;
}
alooWidget *setHeight(alooWidget *wid, int height) {
	gtk_widget_set_size_request(wid->child, -1, height);
	return wid;
}
alooWidget *setSize(alooWidget *wid, int width, int height) {
	gtk_widget_set_size_request(wid->child, width, height);
	return wid;
}