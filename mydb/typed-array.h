#ifndef TYPED_ARRAY_H
#define TYPED_ARRAY_H

#define TYPED_ARRAY(Name, name, Type)			\
	typedef struct {							\
		Type *arr;								\
		unsigned len_;							\
	} Name##Array;								\
												\
	Name##Array *name##_array_new ();							\
	void name##_array_free(Name##Array *arr);					\
	void name##_array_insert_at_index(Name##Array *arr,			\
			Type obj, unsigned index);							\
	void name##_array_push(Name##Array *arr, Type obj);			\
	Type name##_array_pop_at_index(Name##Array *arr, unsigned index);	\
	Type name##_array_pop_last(Name##Array *arr);

#endif // TYPED_ARRAY_H
