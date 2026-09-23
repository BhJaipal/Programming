typedef void (*read_on_swap_fn_t)(int[], int, int, int);
typedef void (*read_arr_fn_t)(int[], int);

// @read_on_iter can be NULL, allows use to check array after each iteration
// @read_after_swap can be NULL, allows use to check array after each swap
// but for radix_sort it is same as read_on_iter so recommended to not use it
int radix_sort(int arr[], int n, read_arr_fn_t read_on_iter,
               read_on_swap_fn_t read_after_swap);

// @read_on_iter can be NULL, allows use to check array after each iteration
// @read_after_swap can be NULL, allows use to check array after each swap
int selection_sort(int arr[], int n, read_arr_fn_t read_on_iter,
                   read_on_swap_fn_t read_after_swap);

// @read_on_iter can be NULL, allows use to check array after each iteration
// @read_after_swap can be NULL, allows use to check array after each swap
int bubble_sort(int arr[], int n, read_arr_fn_t read_on_iter,
                read_on_swap_fn_t read_after_swap);

// @read_on_iter can be NULL, allows use to check array after each iteration
// @read_after_swap can be NULL, allows use to check array after each swap
// but for insertion_sort it is same as read_on_iter so recommended to not use it
int insertion_sort(int arr[], int n, read_arr_fn_t read_on_iter,
                   read_on_swap_fn_t read_after_swap);

// @read_on_iter can be NULL, allows use to check array after each iteration
// @read_after_swap can be NULL, allows use to check array after each swap
int quick_sort(int arr[], int start, int end, int n, read_arr_fn_t read_on_iter,
               read_on_swap_fn_t read_after_swap);

// @read_on_iter can be NULL, allows use to check array after each iteration
// @read_after_swap can be NULL, allows use to check array after each swap
// but for merge_sort it is same as read_on_iter so recommended to not use it
int merge_sort(int arr[], int left, int right, int n,
               read_arr_fn_t read_on_iter, read_on_swap_fn_t read_after_swap);
